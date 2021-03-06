#include "CEnemy.h"
//エフェクトクラスのインクルード
#include "CEffect.h"
//
#include "CSceneGame.h"
//
#include "CBullet.h"

//スマートポインタの外部参照
extern std::shared_ptr<CTexture> TextureExp;

//誘導ポイント
CPoint *CEnemy::mPoint;
int CEnemy::mPointSize = 0;

#define TURN_DEG 0.3f

//コンストラクタ
//CEnemy(モデル, 位置, 回転, 拡縮)
CEnemy::CEnemy(CModel *model, CVector position, CVector rotation, CVector scale)
: mCollider(this, CVector(0.0f, 0.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f),
CVector(1.0f / scale.mX, 1.0f / scale.mY, 1.0f / scale.mZ), 0.8f)
//?SearchEnemy
, mSearch(this, CVector(0.0f, 0.0f, 60.0f), CVector(0.0f, 0.0f, 0.0f),
CVector(1.0f / scale.mX, 1.0f / scale.mY, 1.0f / scale.mZ), 10.0f)
,mHp(20)
, mPointCnt(0)
{
	//
	mCollider.mTag = CCollider::EBODY;
	mSearch.mTag = CCollider::ESEARCH;
	//モデル、位置、回転、拡縮を設定する
	mpModel = model;	//モデルの設定
	mPosition = position;	//位置の設定
	mRotation = rotation;	//回転の設定
	mScale = scale;	//拡縮の設定
	mPointCnt = 0;	//最初のポイントを設定
	mpPoint = &mPoint[mPointCnt];//目指すポイントのポインタを設定
	mTag = EENEMY;
}
//更新処理
void CEnemy::Update() {
	//ポイントへのベクトルを求める
	CVector dir = mpPoint->mPosition - mPosition;
	//左方向のベクトルを求める
	CVector left = CVector(1.0f, 0.0f, 0.0f) * CMatrix().RotateY(mRotation.mY);
	//上方向のベクトルを求める
	CVector up = CVector(0.0f, 1.0f, 0.0f) * CMatrix().RotateX(mRotation.mX) * CMatrix().RotateY(mRotation.mY);
	//左右の回転処理（Y軸）
	if (left.Dot(dir) > 0.0f) {
		mRotation.mY += 0.3f;
	}
	else if (left.Dot(dir) < 0.0f) {
		mRotation.mY -= 0.3f;
	}
	//上下の回転処理（X軸）
	if (up.Dot(dir) > 0.0f) {
		mRotation.mX -= 0.3f;
	}
	else if (up.Dot(dir) < 0.0f) {
		mRotation.mX += 0.3f;
	}

	//行列を更新
	CCharacter::Update();
	//位置を移動
	mPosition = CVector(0.0f, 0.0f, 1.0f) * mMatrix;
	//回転させる
//	mRotation.mY += 0.5f;

	if (mHp < 0) {
		mHp--;
		mRotation.mX = 20;
		if (mHp % 10 == 0) {
			new CEffect(mPosition, 1.5f, 1.5f, TextureExp, 4, 4, 2);
		}
	}
}

void CEnemy::Collision(CCollider *m, CCollider *y) {
	//共に球コライダの時
	if (m->mType == CCollider::ESPHERE
		&& y->mType == CCollider::ESPHERE) {
		if (CCollider::Collision(m, y)) {
			//コライダがサーチか判定
			if (m->mTag == CCollider::ESEARCH) {
				//衝突したコライダの親の種類を判定
				switch (y->mpParent->mTag) {
				case EAIRBASE://空軍基地
				case EPLAYER://プレイヤーの時
					if (y->mTag == CCollider::EBODY) {
						CBullet *bullet = new CBullet();
						bullet->Set(0.1f, 1.5f);
						bullet->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
						bullet->mRotation = mRotation;
					}
					break;
				}
			}
			else  {
				//衝突したコライダの親の種類を判定
				switch (y->mpParent->mTag) {
				case EPOINT://ポイントの時
					//衝突したポインタと目指しているポインタが同じ時
					if (y->mpParent == mpPoint) {
						mPointCnt++;//次のポイントにする
						//最後だったら最初にする
						mPointCnt %= mPointSize;
						//次のポイントのポインタを設定
						mpPoint = &mPoint[mPointCnt];
					}
					break;
				case EMISSILE:
					mEnabled = false;
				default:
					if (y->mTag == CCollider::EBODY) {
						//エフェクト生成
						new CEffect(mPosition, 1.0f, 1.0f, TextureExp, 4, 4, 1);
						//			mHp--;
					}
				}
			}
			//削除		mEnabled = false;
		}
	}
}
