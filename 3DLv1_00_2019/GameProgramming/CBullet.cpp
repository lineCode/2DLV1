#include "CBullet.h"
//
#include "CTaskManager.h"

//���Ɖ��s���̐ݒ�
//Set(��, ���s)
void CBullet::Set(float w, float d) {
	//�X�P�[���ݒ�
	mScale = CVector(1.0f, 1.0f, 1.0f);
	//�O�p�`�̒��_�ݒ�
	mT.SetVertex(CVector(w, 0.0f, 0.0f), CVector(0.0f, 0.0f, -d), CVector(-w, 0.0f, 0.0f));
	//�O�p�`�̖@���ݒ�
	mT.SetNormal(CVector(0.0f, 1.0f, 0.0f));
}

//�X�V
void CBullet::Update() {
	//�������Ԃ̔���
	if (mLife-- > 0) {
		CCharacter::Update();
		//�ʒu�X�V
		mPosition = CVector(0.0f, 0.0f, 1.0f) * mMatrix;
	}
	else {
		//�����ɂ���
		mEnabled = false;
	}
}

//�`��
void CBullet::Render() {
	//DIFFUSE���F�ݒ�
	float c[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	//�O�p�`�`��
	mT.Render(mMatrix);
}
//22
CBullet::CBullet()
: mLife(50)
, mCollider(this, CVector(0.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, 0.0f), CVector(1.0f, 1.0f, 1.0f), 0.1f)
{
}

void CBullet::Collision(CCollider *m, CCollider *y) {
	if (CCollider::Collision(m, y)) {
		mEnabled = false;
//		printf("Bullet Hit!\n");
	}
}