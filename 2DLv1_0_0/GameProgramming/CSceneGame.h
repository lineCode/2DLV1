#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CPlayer.h"
#include "CBackGround.h"
#include "CBoss.h"
#include "CTexture.h"
#include "CEnemy.h"
#include "CCamera.h"

//�N���X�̒�`
class CSceneGame: public CScene {
public:
	//�J�����̍쐬
	CCamera mCamera;
	//�ϐ��̍쐬
	CBackGround mBackGround;
	CPlayer mPlayer;
	CEnemy mEnemy;
	CBoss mBoss;

	//�R���X�g���N�^
	CSceneGame();

	//���\�b�h�i�v���O�����j�̐錾
	void Update();
	void Render();
};

#endif
