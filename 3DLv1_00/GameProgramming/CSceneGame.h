#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CMatrix.h"

/*
ゲームのシーン
*/
//CSceneクラスを継承する
class CSceneGame : public CScene {
public:
	CVector mCameraEye;
	CVector mCameraCenter;
	CVector mCameraUp;

	CTriangle mTriangle[2];
	CRectangle mRectangle;
	float mDegree;
	CMatrix mMatrix;

	//初期化処理のオーバーライド
	void Init();
	//更新処理のオーバーライド
	void Update();
//	CSceneGame();
	//デストラクタの宣言
	~CSceneGame();
};

#endif
