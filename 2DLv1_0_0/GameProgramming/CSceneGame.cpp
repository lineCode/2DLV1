//CSceneGame�N���X�̃C���N���[�h
#include "CSceneGame.h"
//CRectangle�N���X�̃C���N���[�h
#include "CRectangle.h"
/*
Update���\�b�h
1�t���[���̍X�V�������s��
*/
void CSceneGame::Update() {
	//���߂̋L�q
	/*
	�ϐ��̍쐬
	x:�����`�̒��Sx���W
	y:�����`�̒��Sy���W 
	w:�����`�̕��̔��� 
	h:�����`�̍����̔���
	*/
	float x;	//float�^�̕ϐ�x���쐬����
	float y = 270.0;	//float�^�̕ϐ�y���쐬��150.0��������
	float w, h = 30.0;	//float�^�̕ϐ�w�ƕϐ�h��,��؂�ň�x�ɍ쐬����

	x = 0.0;	//�ϐ�x�ɒl��������
	w = 400.0;	//�ϐ�w�ɒl��������

	//��̒����`��`�悷��
	//�ϐ��ɑ������Ă���l�Ŗ��߂����s����
	CRectangle::Render(x, y, w, h);

	//���̒����`��`�悷��
	y = -270.0;	//��������ƑO�̒l�͏㏑�������
	CRectangle::Render(x, y, w, h);

	//���̒����`��`�悷��
	x = -370.0;
	w = 30.0;
	y = 0.0;
	h = 300.0;
	CRectangle::Render(x, y, w, h);

	//�E�̒����`��`�悷��
	x = 370.0;
	CRectangle::Render(x, y, w, h);
}

