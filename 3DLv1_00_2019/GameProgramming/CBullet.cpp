#include "CBullet.h"

#define VELOCITY 1.0f //�e�� 2.0f

//���Ɖ��s���̐ݒ�
//Set(��, ���s)
void CBullet::Set(float w, float d) {
	mScale = CVector(1.0f, 1.0f, 1.0f);
	mT.SetVertex(CVector(w, 0.0f, 0.0f), CVector(0.0f, 0.0f, -d), CVector(-w, 0.0f, 0.0f));
	mT.SetNormal(CVector(0.0f, 1.0f, 0.0f));
}

//�X�V
void CBullet::Update() {
	CCharacter::Update();
	mPosition = CVector(0.0f, 0.0f, VELOCITY) * mMatrix;
}

//�`��
void CBullet::Render() {
	float c[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);

	mT.Render(mMatrix);
}
