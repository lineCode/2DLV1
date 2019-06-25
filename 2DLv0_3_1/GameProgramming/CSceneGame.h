#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CPlayer.h"
#include "CBackGround.h"
#include "CBoss.h"
#include "CTexture.h"
#include "CEnemy.h"
#include <vector>
#include "CInput.h"
#include "CCamera.h"

//�N���X�̒�`
class CSceneGame: public CScene {
public:
	CCamera mCamera;
	static std::vector<CCharacter*> mCharacters;
	//�ϐ��̐錾
	CBackGround mBackGround;
	CPlayer mPlayer;
	CEnemy mEnemy[10];

	//CBoss mBoss;
	int mFrame;
	CInput mInput;
	int mPlayerShootCount;

	CSceneGame();

	~CSceneGame();

	//���\�b�h�i�v���O�����j�̐錾
	void Init();
	void Update();
	void Render();
};

#endif
