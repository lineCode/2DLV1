#include "CCollider.h"
//
#include "CCollisionManager.h"

//�R���X�g���N�^
//CCollider(�e, �ʒu, ��], �g�k, ���a)
CCollider::CCollider(CCharacter *parent, CVector position, CVector rotation, CVector scale, float radius) {
	mpParent = parent;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	mRadius = radius;
	CTransform::Update();
	//
	CollisionManager.Add(this);
}

CCollider::~CCollider() {
	CollisionManager.Remove(this);
}

//�`��
void CCollider::Render() {
	glPushMatrix();
	glMultMatrixf((mMatrix * mpParent->mMatrix).mM[0]);
	//DIFFUSE�ԐF�ݒ�
	float c[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	//���`��
	glutWireSphere(mRadius, 16, 16);
	glPopMatrix();
}
