#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CPlayer.h"
#include "CBackGround.h"
#include "CBoss.h"
#include "CTexture.h"

//クラスの定義
class CSceneGame: public CScene {
public:
	//変数の宣言
	CBackGround mBackGround;
	CPlayer mPlayer;
	CBoss mBoss;
	int mFrame;

	//メソッド（プログラム）の宣言
	void Init();
	void Update();
	void Render();
};

#endif
