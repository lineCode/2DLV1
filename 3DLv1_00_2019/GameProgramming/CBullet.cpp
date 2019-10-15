#include "CBullet.h"

#define VELOCITY 1.0f //弾速 1.0f

//幅と奥行きの設定
//Set(幅, 奥行)
void CBullet::Set(float w, float d) {
	//スケール設定
	mScale = CVector(1.0f, 1.0f, 1.0f);
	//三角形頂点設定
	mT.SetVertex(CVector(w, 0.0f, 0.0f), CVector(0.0f, 0.0f, -d), CVector(-w, 0.0f, 0.0f));
	//法線設定
	mT.SetNormal(CVector(0.0f, 1.0f, 0.0f));
}

//更新
void CBullet::Update() {
	CCharacter::Update();
	//位置更新
	mPosition = CVector(0.0f, 0.0f, VELOCITY) * mMatrix;
}

//描画
void CBullet::Render() {
	//黄色設定
	float c[] = { 1.0f, 1.0f, 0.0f, 1.0f };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, c);
	//三角形描画
	mT.Render(mMatrix);
}
