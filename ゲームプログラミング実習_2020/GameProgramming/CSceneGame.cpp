#include "CSceneGame.h"
//
#include "CCamera.h"
//
#include "CText.h"


CSceneGame::~CSceneGame() {

}


void CSceneGame::Init() {
	//�e�L�X�g�t�H���g�̓ǂݍ��݂Ɛݒ�
	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);
	//1
	mSky.Load("sky.obj", "sky.mtl");
	mRock.Load("Rock1.obj", "Rock1.mtl");
	mRover.Load("Rover1.obj", "Rover1.mtl");
}


void CSceneGame::Update() {
	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A�����_�A�����
	//���_�����߂�
	e = CVector(-2.0f, 10.0f, -30.0f);
	//�����_�����߂�
	c = CVector();
	//����������߂�
	u = CVector(0.0f, 1.0f, 0.0f);

	//�J�����̐ݒ�
	Camera3D(e.mX, e.mY, e.mZ, c.mX, c.mY, c.mZ, u.mX, u.mY, u.mZ);


	//1
	mSky.Render(CMatrix().Scale(1.0f, 1.0f, 1.0f));
	mRock.Render(CMatrix().Scale(4.0f, 4.0f, 4.0f));
//	mRover.Render(CMatrix().Scale(1.0f, 1.0f, 1.0f));

	//2D�`��J�n
	Start2D(0, 800, 0, 600);

	CText::DrawString("3D PROGRAMMING", 20, 20, 10, 12);

	//2D�`��I��
	End2D();

	return;
}

