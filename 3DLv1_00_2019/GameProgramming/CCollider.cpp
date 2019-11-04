#include "CCollider.h"
//�R���W�����}�l�[�W���̃C���N���[�h
#include "CCollisionManager.h"

//�R���X�g���N�^
//CCollider(�e, �ʒu, ��], �g�k, ���a)
CCollider::CCollider(CCharacter *parent, CVector position, CVector rotation, CVector scale, float radius) {
	//�e�ݒ�
	mpParent = parent;
	//CTransform�ݒ�
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	CTransform::Update();//�s��X�V
	//���a�ݒ�
	mRadius = radius;
	//�R���W�������X�g�ɒǉ�
	CollisionManager.Add(this);
}

CCollider::~CCollider() {
	//�R���W�������X�g����폜
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

//�Փ˔���
//Collision(�R���C�_1, �R���C�_2)
//retrun:true�i�Փ˂��Ă���jfalse(�Փ˂��Ă��Ȃ�)
bool CCollider::Collision(CCollider *m, CCollider *y) {
	//�e�R���C�_�̒��S���W�����߂�
	//���_�~�R���C�_�̕ϊ��s��~�e�̕ϊ��s��
	CVector mpos = CVector() * m->mMatrix * m->mpParent->mMatrix;
	CVector ypos = CVector() * y->mMatrix * y->mpParent->mMatrix;
	//���S���璆�S�ւ̃x�N�g�������߂�
	mpos = mpos - ypos;
	//���S�̋��������a�̍��v��菬�����ƏՓ�
	if (m->mRadius + y->mRadius > mpos.Length()) {
		//�Փ˂��Ă���
		return  true;
	}
	//�Փ˂��Ă��Ȃ�
	return false;
}
