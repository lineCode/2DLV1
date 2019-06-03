#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CPlayer.h"
#include "CBackGround.h"
#include "CBoss.h"
#include "CTexture.h"
#include <vector>

//クラスの定義
class CSceneGame: public CScene {
public:
	static std::vector<CCharacter*> mCharacters;
	//変数の宣言
	//CBackGround mBackGround;
	//CPlayer mPlayer;
	//CBoss mBoss;
	int mFrame;

	CSceneGame();

	~CSceneGame();

	//メソッド（プログラム）の宣言
	void Init();
	void Update();
	void Render();
};

#endif
