#include "CBomb.h"
#include "CRectangle.h"
#include "CCollision.h"
#include "CSceneGame.h"
#include "CExplosion.h"
#include "Define.h"

CBomb::CBomb()
	: mFrame(0)
{
	mpTexture = &TexBomberman;
	mTag = EBACKGROUND;
	CSceneGame::mCharacters.push_back(this);
}


CBomb::CBomb(float x, float y, float w, float h)
	: CBomb()
{
	Set(x, y, w, h);
}

void CBomb::Update() {
	if (mTag == EPLAYER) {
		mTag = EBACKGROUND;
	}
	mFrame++;
	//5�@���e���j
	if (mFrame > BOMBTIME) {
		new CExplosion(mX, mY, mW, mH, BOMBSIZE);
		mState = EDELETE;
	}
}

void CBomb::Collision(CCharacter* my, CCharacter* yc) {
	if (!mState) return;
	float dx = 0.0f, dy = 0.0f;
	if (CCollision::Collision(my, yc, &dx, &dy)) {
		switch(yc->mTag) {
		case EBOMB:
			yc->mState = EDELETE;
			break;
		case EBLOCK:
			mX += dx;
			mY += dy;
			break;
		case EPLAYER:
			if (mTag == EBACKGROUND) {
				mTag = EPLAYER;
			}
			break;
		//6�@�����Փ�
		case EEXPLOSION:
			new CExplosion(mX, mY, mW, mH, BOMBSIZE);
			mState = EDELETE;
			break;
		}
	}
}

void CBomb::Render() {
	if (mTag == EBACKGROUND) {
		mTag = EBOMB;
	}
	int f = mFrame / 20;
	f %= 4;
	switch (f) {
	case 0:
		CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 0, 16 * 1, 16 * 4, 16 * 3);
		break;
	case 1:
		CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 1, 16 * 2, 16 * 4, 16 * 3);
		break;
	case 2:
		CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 2, 16 * 3 - 1, 16 * 4, 16 * 3);
		break;
	case 3:
		CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 1, 16 * 2, 16 * 4, 16 * 3);
		break;
	}
}
