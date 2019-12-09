#include "CCollider.h"
//コリジョンマネージャのインクルード
#include "CCollisionManager.h"

//コンストラクタ
//CCollider(親, 位置, 回転, 拡縮, 半径)
CCollider::CCollider(CCharacter *parent, CVector position, CVector rotation, CVector scale, float radius)
: CCollider()
{
	//親設定
	mpParent = parent;
	//CTransform設定
	mPosition = position;
	mRotation = rotation;
	mScale = scale;
	CTransform::Update();//行列更新
	//半径設定
	mRadius = radius;
	//コリジョンリストに追加
	CollisionManager.Add(this);
}

CCollider::~CCollider() {
	//コリジョンリストから削除
	CollisionManager.Remove(this);
}

//描画
void CCollider::Render() {
	glPushMatrix();
	glMultMatrixf((mMatrix * mpParent->mMatrix).mM[0]);

	//アルファブレンドを有効にする
	glEnable(GL_BLEND);
	//ブレンド方法を指定
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//ライトオフ
	glDisable(GL_LIGHTING);

	//DIFFUSE赤色設定
	float c[] = { 1.0f, 0.0f, 0.0f, 0.5f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	glColor4fv(c);

	//?
	//コライダタイプの判定
	switch (mType) {
	case ESPHERE:
		//球描画
		glutWireSphere(mRadius, 16, 16);
		break;
	case ETRIANGLE:
		//三角形描画
		glBegin(GL_TRIANGLES);
		glVertex3f(mV[0].mX, mV[0].mY, mV[0].mZ);
		glVertex3f(mV[1].mX, mV[1].mY, mV[1].mZ);
		glVertex3f(mV[2].mX, mV[2].mY, mV[2].mZ);
		glEnd();
		break;
	case ELINE:
//		glLineWidth(2);
		glBegin(GL_LINES);
		glVertex3f(mV[0].mX, mV[0].mY, mV[0].mZ);
		glVertex3f(mV[1].mX, mV[1].mY, mV[1].mZ);
		glEnd();
		break;
	}

	//ライトオン
	glEnable(GL_LIGHTING);
	//アルファブレンド無効
	glDisable(GL_ALPHA);

	glPopMatrix();
}

//衝突判定
//Collision(コライダ1, コライダ2)
//retrun:true（衝突している）false(衝突していない)
bool CCollider::Collision(CCollider *m, CCollider *y) {
	//各コライダの中心座標を求める
	//原点×コライダの変換行列×親の変換行列
	CVector mpos = CVector() * m->mMatrix * m->mpParent->mMatrix;
	CVector ypos = CVector() * y->mMatrix * y->mpParent->mMatrix;
	//中心から中心へのベクトルを求める
	mpos = mpos - ypos;
	//中心の距離が半径の合計より小さいと衝突
	if (m->mRadius + y->mRadius > mpos.Length()) {
		//衝突している
		return  true;
	}
	//衝突していない
	return false;
}

//?
CCollider::CCollider()
: mpParent(0)
, mTag(ENONE)
, mType(ESPHERE)
{

}

//コンストラクタ（三角コライダ）
//CCollider(親, 頂点1, 頂点2, 頂点3)
CCollider::CCollider(CCharacter *parent, const CVector &v0, const CVector &v1, const CVector &v2)
: CCollider()
{
	//
	SetTriangle(parent, v0, v1, v2);
}

void CCollider::SetTriangle(CCharacter *parent, const CVector &v0, const CVector &v1, const CVector &v2) {
	mType = ETRIANGLE;
	mpParent = parent;//親設定
	//三角形頂点設定
	mV[0] = v0;
	mV[1] = v1;
	mV[2] = v2;
	//スケール1倍
	mScale = CVector(1.0f, 1.0f, 1.0f);
	CTransform::Update();//行列更新
	//コリジョンリストに追加
	CollisionManager.Add(this);
}

//コンストラクタ（線コライダ）
//CCollider(親, 頂点1, 頂点2)
CCollider::CCollider(CCharacter *parent, const CVector &v0, const CVector &v1) {
	SetLine(parent, v0, v1);
}

//線コライダの設定
//SetLine(親, 頂点1, 頂点2)
void CCollider::SetLine(CCharacter *parent, const CVector &v0, const CVector &v1) {
	mType = ELINE;
	mpParent = parent;//親設定
	//線の頂点設定
	mV[0] = v0;
	mV[1] = v1;
	//スケール1倍
	mScale = CVector(1.0f, 1.0f, 1.0f);
	CTransform::Update();//行列更新
	//コリジョンリストに追加
	CollisionManager.Add(this);
}
