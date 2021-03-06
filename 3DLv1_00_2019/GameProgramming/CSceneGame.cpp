#include "CSceneGame.h"
//OpenGL
#include "glut.h"
//CVectorクラスのインクルード
#include "CVector.h"
//CMatrixクラスのインクルード
#include "CMatrix.h"
//CTriangleクラスのインクルード
#include "CTriangle.h"
//数学関数のインクルード
#include <math.h>
//モデルクラスのインクルード
#include "CModel.h"
//キャラクタクラスのインクルード
#include "CCharacter.h"
//プレイヤークラスのインクルード
#include "CPlayer.h"
//タスクマネージャのインクルード
#include "CTaskManager.h"
//エネミークラスのインクルード
#include "CEnemy.h"
//
#include "CCollisionManager.h"
//
#include "CCamera.h"
//ビルボードクラスのインクルード
#include "CBillBoard.h"
#include "CEffect.h"
//空軍基地
#include "CAirBase.h"
//
#include "CText.h"
//
#include "CRes.h"

//モデルクラスのインスタンス作成
CModel Model;
CModel BackGround; //背景モデル
CModel ModelEnemy;//エネミーモデル
//30
CModel ModelAirBase;//空軍基地モデル

//スマートポインタの生成
std::shared_ptr<CTexture> TextureExp(new CTexture());

CSceneGame::~CSceneGame() {
	delete[] CEnemy::mPoint;
}


void CSceneGame::Init() {
	//
	CRes::mMissileM.Load("missile.obj", "missile.mtl");

	//テキストフォントの読み込みと設定
	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);
//	CText::mFont.Load("Font.tga");
//	CText::mFont.SetRowCol(8, 16);

	//ポイントの設定
	CEnemy::mPointSize = 3;//ポイント数の設定
	CEnemy::mPoint = new CPoint[CEnemy::mPointSize];
	CEnemy::mPoint[0].Set(CVector(35.0f, 25.0f, 100.0f), 10.0f);
	CEnemy::mPoint[1].Set(CVector(35.0f, 5.0f, 0.0f), 10.0f);
	CEnemy::mPoint[2].Set(CVector(-35.0f, 45.0f, 50.0f), 10.0f);

	CMatrix matrix;
	//平行移動行列の作成
	matrix.Translate(1.0f, 2.0f, 3.0f);
	matrix.Print();
	//モデルファイルの入力
	Model.Load("f14.obj", "f14.mtl");
	BackGround.Load("sky.obj", "sky.mtl");

	//キャラクタの設定
	Player.mpModel = &Model;
	//スケールを0.2倍を変更
	Player.mScale = CVector(0.2f, 0.2f, 0.2f);
	//位置(0.0, 0.0, 55.0)にする
	Player.mPosition = CVector(-19.5f, 1.0f, -55.0f);

	//エネミーモデルの入力
	ModelEnemy.Load("f16.obj", "f16.mtl");

	//敵機の生成
	//爆発テクスチャの読み込み
	TextureExp->Load("exp.tga");

	//?
//	mMap.mpModel = &BackGround;
//	mMap.mScale = CVector(2.0f, 2.0f, 2.0f);
//	mMap.SetTriangleCollider();

	//?
	//36
	//空軍基地モデルの読み込み
	ModelAirBase.Load("airbase.obj", "airbase.mtl");
	//空軍基地クラスのインスタンスを生成
	mpAirBase = new CAirBase(&ModelAirBase, CVector(0.0f, 0.0f, 180.0f), CVector(), CVector(0.1f, 0.1f, 0.1f));
}


void CSceneGame::Update() {
	//static変数の作成
	static int degree = 0;//回転角度の作成
	degree++;//角度に1加算

	//static変数の作成
	static int frame = 0;//フレーム数のカウント
	frame++;//フレーム数に1加算
	if (frame < 1000 && frame % 150 == 0) {
		//敵機の生成
		new CEnemy(&ModelEnemy, CVector(-10.0f, 7.0f, 200.0f), CVector(0.0f, 180.0f, -30.0f), CVector(0.2f, 0.2f, 0.2f));
	}

	//タスクマネージャの更新
	TaskManager.Update();

	//描画処理

	//カメラのパラメータを作成する
	CVector e, c, u;//視点、注視点、上方向
	//視点を求める
	e = CVector(-2.0f, 10.0f, -30.0f) * Player.mMatrix;
	//注視点を求める
	c = Player.mPosition;
	//上方向を求める
	u = CVector(0.0f, 1.0f, 0.0f) * Player.mMatrixRotate;
	//カメラクラスの設定
	Camera.Set(e, c, u);
	Camera.Render();

	//コリジョンマネージャの衝突処理
	CollisionManager.Collision();

	BackGround.Render(CMatrix());

	//タスクリストの削除
	TaskManager.Delete();
	//タスクマネージャの描画
	TaskManager.Render();
	//コライダの描画
//	CollisionManager.Render();

	//2D描画開始
	Start2D(0, 800, 0, 600);

	if (frame < 150) {
		//2D描画
		CText::DrawString("MISSION START", 170, 400, 20, 20);
	}

	CText::DrawString("PLAYER DAMAGE ", 20, 50, 10, 12);
	CText::DrawString("AIRBASE DAMAGE", 20, 20, 10, 12);
	//char buf[10];
	//sprintf(buf, "%d", mpAirBase->mDamage);
	//CText::DrawString(buf, 320, 20, 10, 12);

	//2D描画終了
	End2D();

	return;

/*
	CMatrix matrix;//行列作成

	//頂点1､頂点2､頂点3,法線データの作成
	CVector v0, v1, v2, n;

	//法線を上向きで設定する
	n.mX = 0.0f; n.mY = 1.0f; n.mZ = 0.0f;

	//頂点1の座標を設定する
	v0.mX = 0.0f; v0.mY = 0.0f; v0.mZ = 0.5f;
	//頂点2の座標を設定する
	v1.mX = 1.0f; v1.mY = 0.0f; v1.mZ = 0.0f;
	//頂点3の座標を設定する
	v2.mX = 0.0f; v2.mY = 0.0f; v2.mZ = -0.5f;

	//視点の設定
	//gluLookAt(視点X, 視点Y, 視点Z, 中心X, 中心Y, 中心Z, 上向X, 上向Y, 上向Z)
	gluLookAt(1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	//描画開始
	//glBegin(形)
	//GL_TRIANGLES：三角形
	glBegin(GL_TRIANGLES);

	//Y軸中心に角度だけ回転させる行列を設定
	matrix.RotateY(degree);
	//法線と頂点を回転させる
	//n = n.Multi(matrix);
	v0 = v0.Multi(matrix);
	v1 = v1.Multi(matrix);
	v2 = v2.Multi(matrix);

	//法線（面の向き）の設定
	//glNormal3f(X座標, Y座標, Z座標)
	glNormal3f(n.mX, n.mY, n.mZ);
	//頂点座標の設定
	//glVertex3f(X座標, Y座標, Z座標)
	glVertex3f(v0.mX, v0.mY, v0.mZ);
	glVertex3f(v1.mX, v1.mY, v1.mZ);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	//法線と頂点の設定
	n.Set(0.0f, 0.0f, 1.0f);
	v0.Set(0.5f, 0.0f, 0.0f);
	v1.Set(0.0f, 1.0f, 0.0f);
	v2.Set(-0.5f, 0.0f, 0.0f);

	matrix.RotateZ(degree);
	//法線と頂点を回転させる
	n = n.Multi(matrix);
	v0 = v0.Multi(matrix);
	v1 = v1.Multi(matrix);
	v2 = v2.Multi(matrix);

	//三角形2の描画
	glNormal3f(n.mX, n.mY, n.mZ);
	glVertex3f(v0.mX, v0.mY, v0.mZ);
	glVertex3f(v1.mX, v1.mY, v1.mZ);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	//法線と頂点の設定
	n.Set(1.0f, 0.0f, 0.0f);
	v0.Set(0.0f, 0.5f, 0.0f);
	v1.Set(0.0f, 0.0f, 1.0f);
	v2.Set(0.0f, -0.5f, 0.0f);

	matrix.RotateX(degree);
	//法線と頂点を回転させる
	n = n.Multi(matrix);
	v0 = v0.Multi(matrix);
	v1 = v1.Multi(matrix);
	v2 = v2.Multi(matrix);

	//三角形3の描画
	glNormal3f(n.mX, n.mY, n.mZ);
	glVertex3f(v0.mX, v0.mY, v0.mZ);
	glVertex3f(v1.mX, v1.mY, v1.mZ);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	//描画終了
	glEnd();

	//三角形クラスのインスタンス作成
	CTriangle t0;
	//法線と頂点の設定
	t0.SetVertex(CVector(0.0f, 0.0f, 0.5f), CVector(1.0f, 0.0f, 0.0f), CVector(0.0f, 0.0f, -0.5f));
	t0.SetNormal(CVector(0.0f, 1.0f, 0.0f));
	//三角形の描画
//	t0.Render(matrix.Translate(degree*0.01, 0.0f, 0.0f));
//	t0.Render(matrix.Scale(sinf(degree*0.01) + 1.5, sinf(degree*0.01) + 1.5, sinf(degree*0.01) +1.5));
	//回転行列と移動行列を掛けて合成行列を作る
	matrix = matrix.RotateY(degree) * matrix.Translate(2.0f, 0.0f, 0.0f);
	t0.Render(matrix);

	CTriangle t1;
	//法線と頂点の設定
	t1.SetVertex(CVector(0.5f, 0.0f, 0.0f), CVector(0.0f, 1.0f, 0.0f), CVector(-0.5f, 0.0f, 0.0f));
	t1.SetNormal(CVector(0.0f, 0.0f, 1.0f));
	//三角形の描画
//	t1.Render();
	matrix.Translate(0.0f, degree*0.01, 0.0f);
//	t1.Render(matrix.RotateZ(degree));
//	t1.Render(matrix);
//	t1.Render(matrix.Scale(sinf(degree*0.01) + 1.5, sinf(degree*0.01) + 1.5, sinf(degree*0.01) + 1.5));
	matrix = matrix.RotateZ(degree) * matrix.Translate(0.0f, 2.0f, 0.0f);
	t1.Render(matrix);

	CTriangle t2;
	//法線と頂点の設定
	t2.SetVertex(CVector(0.0f, 0.5f, 0.0f), CVector(0.0f, 0.0f, 1.0f), CVector(0.0f, -0.5f, 0.0f));
	t2.SetNormal(CVector(1.0f, 0.0f, 0.0f));
	//三角形の描画
//	t2.Render();
//	matrix.Translate(0.0f, 0.0f, degree*0.01);
//	t2.Render(matrix.RotateX(degree));
//	t2.Render(matrix);
//	t2.Render(matrix.Scale(sinf(degree*0.01) + 1.5, sinf(degree*0.01) + 1.5, sinf(degree*0.01) + 1.5));
	matrix = matrix.RotateX(degree) * matrix.Translate(0.0f, 0.0f, 2.0f);
	t2.Render(matrix);
*/

}

//2D描画スタート
//Start2D(左座標, 右座標, 下座標, 上座標)
void CSceneGame::Start2D(float left, float right, float bottom, float top) {
	//モデルビュー行列の退避
	glPushMatrix();
	//モデルビュー行列の初期化
	glLoadIdentity();

	//モデルビュー行列から
	//プロジェクション行列へ切り替え
	glMatrixMode(GL_PROJECTION);
	//プロジェクション行列の退避
	glPushMatrix();
	//プロジェクション行列の初期化
	glLoadIdentity();
	//2D描画の設定
	gluOrtho2D(left, right, bottom, top);
	//Depthテストオフ
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glColor3f(1.0f, 1.0f, 1.0f);
}

//2D描画終了
void CSceneGame::End2D() {
	//プロジェクション行列を戻す
	glPopMatrix();
	//モデルビューモードへ切り替え
	glMatrixMode(GL_MODELVIEW);
	//モデルビュー行列を戻す
	glPopMatrix();
	//Depthテストオン
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

}
