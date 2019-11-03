//�L�����N�^�N���X�C���N���[�h
#include "CCharacter.h"
//
#include "CTaskManager.h"

//�X�V����
void CCharacter::Update() {
	//�g��k���s��̐ݒ�
	mMatrixScale.Scale(mScale.mX, mScale.mY, mScale.mZ);
	//��]�s��̐ݒ�
	mMatrixRotate = 
		CMatrix().RotateZ(mRotation.mZ) *
		CMatrix().RotateX(mRotation.mX) *
		CMatrix().RotateY(mRotation.mY);
	//���s�ړ��s��̐ݒ�
	mMatrixTranslate.Translate(mPosition.mX, mPosition.mY, mPosition.mZ);
	//�����s��̐ݒ�
	mMatrix = mMatrixScale * mMatrixRotate * mMatrixTranslate;
	//�e������΁A�e�̍s��ƍ���
	if (mpParent) {
		mMatrix = mMatrix * mpParent->mMatrix;
	}
}
//�`�揈��
void CCharacter::Render() {
	//���f���̕`��
	mpModel->Render(mMatrix);
}

//22
CCharacter::CCharacter()
: mpParent(0)
{
	//�^�X�N���X�g�ɒǉ�
	TaskManager.Add(this);
}
//22
CCharacter::~CCharacter() {
	//�^�X�N���X�g����폜
	TaskManager.Remove(this);
}
