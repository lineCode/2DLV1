#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CPlayer.h"
#include "CBackGround.h"
#include "CTexture.h"
#include "CEnemy.h"
#include <vector>
#include "CInput.h"
#include "CCamera.h"

#define CHIPSIZE 16

//�N���X�̒�`
class CSceneGame: public CScene {
	CCamera mCamera;
public:
	static std::vector<CCharacter*> mCharacters;
	//�ϐ��̐錾
	CInput mInput;

	CSceneGame();

	~CSceneGame();

	//���\�b�h�i�v���O�����j�̐錾
	void Init();
	void Update();
	void Render();
};

extern CTexture TexBomberman;;

#endif
