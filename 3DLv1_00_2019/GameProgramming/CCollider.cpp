#include "CCollider.h"
//�R���W�����}�l�[�W���̃C���N���[�h
#include "CCollisionManager.h"

//�R���X�g���N�^
//CCollider(�e, �ʒu, ��], �g�k, ���a)
CCollider::CCollider(CCharacter *parent, CVector position, CVector rotation, CVector scale, float radius)
: CCollider()
{
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

	//�A���t�@�u�����h��L���ɂ���
	glEnable(GL_BLEND);
	//�u�����h���@���w��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//���C�g�I�t
	glDisable(GL_LIGHTING);

	//DIFFUSE�ԐF�ݒ�
	float c[] = { 1.0f, 0.0f, 0.0f, 0.5f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	glColor4fv(c);

	//?
	//�R���C�_�^�C�v�̔���
	switch (mType) {
	case ESPHERE:
		//���`��
		glutWireSphere(mRadius, 16, 16);
		break;
	case ETRIANGLE:
		//�O�p�`�`��
		glBegin(GL_TRIANGLES);
		glVertex3f(mV[0].mX, mV[0].mY, mV[0].mZ);
		glVertex3f(mV[1].mX, mV[1].mY, mV[1].mZ);
		glVertex3f(mV[2].mX, mV[2].mY, mV[2].mZ);
		glEnd();
		break;
	case ELINE:
//		glLineWidth(2);
		glBegin(GL_LINES);
		glVertex3f(mV[0].mX, mV[0].mY, mV[0].mZ);
		glVertex3f(mV[1].mX, mV[1].mY, mV[1].mZ);
		glEnd();
		break;
	}

	//���C�g�I��
	glEnable(GL_LIGHTING);
	//�A���t�@�u�����h����
	glDisable(GL_ALPHA);

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

//?
CCollider::CCollider()
: mpParent(0)
, mTag(ENONE)
, mType(ESPHERE)
{

}

//�R���X�g���N�^�i�O�p�R���C�_�j
//CCollider(�e, ���_1, ���_2, ���_3)
CCollider::CCollider(CCharacter *parent, const CVector &v0, const CVector &v1, const CVector &v2)
: CCollider()
{
	//
	SetTriangle(parent, v0, v1, v2);
}

void CCollider::SetTriangle(CCharacter *parent, const CVector &v0, const CVector &v1, const CVector &v2) {
	mType = ETRIANGLE;
	mpParent = parent;//�e�ݒ�
	//�O�p�`���_�ݒ�
	mV[0] = v0;
	mV[1] = v1;
	mV[2] = v2;
	//�X�P�[��1�{
	mScale = CVector(1.0f, 1.0f, 1.0f);
	CTransform::Update();//�s��X�V
	//�R���W�������X�g�ɒǉ�
	CollisionManager.Add(this);
}

//�R���X�g���N�^�i���R���C�_�j
//CCollider(�e, ���_1, ���_2)
CCollider::CCollider(CCharacter *parent, const CVector &v0, const CVector &v1) {
	SetLine(parent, v0, v1);
}

//���R���C�_�̐ݒ�
//SetLine(�e, ���_1, ���_2)
void CCollider::SetLine(CCharacter *parent, const CVector &v0, const CVector &v1) {
	mType = ELINE;
	mpParent = parent;//�e�ݒ�
	//���̒��_�ݒ�
	mV[0] = v0;
	mV[1] = v1;
	//�X�P�[��1�{
	mScale = CVector(1.0f, 1.0f, 1.0f);
	CTransform::Update();//�s��X�V
	//�R���W�������X�g�ɒǉ�
	CollisionManager.Add(this);
}
