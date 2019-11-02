#include "CEnemy.h"

//�R���X�g���N�^
//CEnemy(���f��, �ʒu, ��], �g�k)
CEnemy::CEnemy(CModel *model, CVector position, CVector rotation, CVector scale) {
	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model;
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
}
//�X�V����
void CEnemy::Update() {
	//�s����X�V
	CCharacter::Update();
	//�ʒu���ړ�
	mPosition = CVector(0.0f, 0.0f, 1.0f) * mMatrix;
	//��]������
	mRotation.mY += 0.5f;
}
