#ifndef CPLAYER_H
#define CPLAYER_H

#include "CCharacter.h"
//06
#include "CCollider.h"

class CPlayer : public CCharacter {
public:
	//06
	//コライダの追加
	CCollider mColBody;
	//コンストラクタで初期設定
	CPlayer();

	void Update();

};

#endif
