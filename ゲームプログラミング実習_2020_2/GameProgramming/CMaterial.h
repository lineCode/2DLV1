#ifndef CMATERIAL_H
#define CMATERIAL_H
//テクスチャクラスのインクルード
#include "CTexture.h"
//shared_ptrのインクルード
#include <memory>
//
#include "CModelX.h"

/*
マテリアルクラス
マテリアルのデータを扱う
*/
class CMaterial {
public:
	//マテリアル名
	char mName[64];
	//拡散光の色RGBA
	float mDiffuse[4];
	//テクスチャのスマートポインタ
	std::shared_ptr<CTexture> mpTexture;
	//マテリアル毎の頂点数
	int mVertexNum;

	//09
	float mPower;
	float mSpecular[3];
	float mEmissive[3];
	//テクスチャファイル名
	char *mpTextureFilename;

	CMaterial(CModelX *model);
	~CMaterial() {
		if (mpTextureFilename) {
			delete[] mpTextureFilename;
		}
		mpTextureFilename = 0;
	}

	//デフォルトコンストラクタ
	CMaterial();
	//マテリアルを有効にする
	void Enabled();
	//マテリアルを無効にする
	void Disabled();
};

#endif
