#include "CPlayer.h"
#include "CUI.h"
#include "CCollision.h"
#include "CEffect.h"
#include "CSceneGame.h"
#include "CBomb.h"

#define VELOCITY 4
#define SHOOTINTERVAL 30

CPlayer* CPlayer::mpInstance = 0;;

CPlayer::CPlayer()
	: mShootInterval(0)
	, mFx(0.0f)
	, mFy(0.0f)
{
	mpTexture = &TexBomberman;
	mTag = EPLAYER;
	mpInstance = this;
	CSceneGame::mCharacters.push_back(this);
}


CPlayer::CPlayer(float x, float y, float w, float h)
	: CPlayer()
{
	Set(x, y, w, h);
}


void CPlayer::Update() {
	if (mState == ECOLLISION) mState = EDISABLED;
	if (!mState) return;

	if (mShootInterval > 0) {
		mShootInterval--;
	}

	//Space�L�[��������Ă��邩���肷��
	if (mInput.Key(' ') == 1 && mShootInterval == 0) {
		mShootInterval = SHOOTINTERVAL;
		new CBomb(mX, mY, 30, 30);
		if (mPy > 0.0f) {
			mY -= mH;
		}
		else if (mPy < 0.0f) {
			mY += mH;
		}
		else if (mPx > 0.0f) {
			mX -= mW;
		}
		else if (mPx < 0.0f) {
			mX += mW;
		}
	}

	mPx = mX;
	mPy = mY;
	mFx = mFy = 0.0f;

	//S�L�[��������Ă��邩���肷��
	if (mInput.Key('S') == 1) {
		//�l�p�`�����ֈړ�������
		mFy -= VELOCITY;
	}
	//W�L�[��������Ă��邩���肷��
	if (mInput.Key('W') == 1) {
		//�l�p�`����ֈړ�������
		mFy += VELOCITY;
	}
	//A�L�[��������Ă��邩���肷��
	if (mInput.Key('A') == 1) {
		//�l�p�`�����ֈړ�������
		mFx -= VELOCITY;
	}
	//D�L�[��������Ă��邩���肷��
	if (mInput.Key('D') == 1) {
		//�l�p�`���E�ֈړ�������
		mFx += VELOCITY;
	}
	mX += mFx;
	mY += mFy;
}

void CPlayer::Collision(CCharacter* my, CCharacter* yc) {
	if (!mState) return;
	if (!yc->mState) return;
	float dx = 0.0f, dy = 0.0f;
	if (CCollision::Collision(my, yc, &dx, &dy)) {
		switch(yc->mTag) {
		case EENEMYSHOT:
		case EENEMY:
			new CEffect(mX, mY, 128, 128);
			CUI::mPlayerHit++;
			break;
		case EBLOCK:
		case EBOMB:
			mX += dx;
			mY += dy;
			break;
		default:
			break;
		}
	}
}

void CPlayer::Render() {
	mPx -= mX;
	mPy -= mY;
	if (mPy > 0.0f) {
		int y = mY + 270;
		y /= 20;
		y %= 4;
		switch (y) {
		case 0:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 4, 16 * 5, 16 - 1, 0.5f);
			break;
		case 1:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 3, 16 * 4, 16 - 1, 0.5f);
			break;
		case 2:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 4, 16 * 5, 16 - 1, 0.5f);
			break;
		case 3:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 5, 16 * 6, 16 - 1, 0.5f);
			break;
		}
	}
	else if (mPy < 0.0f) {
		int y = mY + 270;
		y /= 20;
		y %= 4;
		switch (y) {
		case 0:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 4, 16 * 5, 16*2-1, 16);
			break;
		case 1:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 3, 16 * 4, 16*2-1, 16);
			break;
		case 2:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 4, 16 * 5, 16*2-1, 16);
			break;
		case 3:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 5, 16 * 6, 16*2-1, 16);
			break;
		}
	}
	else if (mPx > 0.0f) {
		int x = mX + 360;
		x /= 20;
		x %= 4;
		switch (x) {
		case 0:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 1, 16 * 2, 16 - 1, 0.5f);
			break;
		case 1:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 0, 16 * 1, 16 - 1, 0.5f);
			break;
		case 2:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 1, 16 * 2, 16 - 1, 0.5f);
			break;
		case 3:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 2, 16 * 3, 16 - 1, 0.5f);
			break;
		}
	}
	else if (mPx < 0.0f) {
		int x = mX + 360;
		x /= 20;
		x %= 4;
		switch (x) {
		case 0:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 1, 16 * 2, 16*2-1, 16*1);
			break;
		case 1:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 0, 16 * 1, 16*2-1, 16*1);
			break;
		case 2:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 1, 16 * 2, 16*2-1, 16*1);
			break;
		case 3:
			CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 2, 16 * 3, 16*2-1, 16*1);
			break;
		}
	}
	else {
		CRectangle::Render(mX, mY, mW, mH, mpTexture, 16 * 4, 16 * 5, 16 - 1, 0.5f);
	}
}
