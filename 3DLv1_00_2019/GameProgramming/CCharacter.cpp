//�L�����N�^�N���X�C���N���[�h
#include "CCharacter.h"

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
}
//�`�揈��
void CCharacter::Render() {
	//�s��̑ޔ�
	glPushMatrix();
	//���f���̕`��
	mpModel->Render(mMatrix);
	//�s������ɖ߂�
	glPopMatrix();
}
