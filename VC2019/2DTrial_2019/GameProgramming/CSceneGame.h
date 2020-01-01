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
	CCamera mCamera;
	//�ϐ��̐錾
	CBackGround mBackGround;
	CPlayer mPlayer;
	CEnemy mEnemy;
	CBoss mBoss;

	CSceneGame();

	//���\�b�h�i�v���O�����j�̐錾
	void Update();
	void Render();
};

extern CTexture TexPlayer;
extern CTexture TexEnemy;
extern CTexture TexShoot;
extern CTexture TexBackGround;
extern CTexture TexExplosion;
extern CTexture TexBoss;

#endif
