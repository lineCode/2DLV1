#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CPlayer.h"
#include "CBackGround.h"
#include "CBoss.h"
#include "CTexture.h"

//�N���X�̒�`
class CSceneGame: public CScene {
public:
	//�ϐ��̐錾
	CPlayer mPlayer;
	CBoss mBoss;
	CBackGround mBackGround;
	int mFrame;
	//�e�N�X�`��
	CTexture mTexEnemy;

	//���\�b�h�i�v���O�����j�̐錾
	void Init();
	void Update();
	void Render();
};

#endif
