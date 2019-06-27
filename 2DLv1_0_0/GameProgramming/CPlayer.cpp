#include "CPlayer.h"
#include "CRectangle.h"
#include "CCollision.h"
#include "CSceneGame.h"

#define VELOCITY 5
#define SHOOTINTERVAL 30

CPlayer* CPlayer::mpInstance = 0;;
CShootPlayer CPlayer::mShootPlayer[10];


CPlayer::CPlayer()
	: mShootInterval(0)
	, mpTexture(0)
{
	mTag = EPLAYER;
	mpInstance = this;
}


CPlayer::CPlayer(float x, float y, float w, float h)
	: CPlayer()
{
	Set(x, y, w, h);
}


void CPlayer::Update() {
	if (mState == EDISABLED) mState = EDISABLED;
	if (!mState) return;

	if (mShootInterval > 0) {
		mShootInterval--;
	}
	//S�L�[��������Ă��邩���肷��
	if (mInput.Key('S') == 1) {
		//�l�p�`�����ֈړ�������
		mY -= VELOCITY;
	}
	//W�L�[��������Ă��邩���肷��
	if (mInput.Key('W') == 1) {
		//�l�p�`����ֈړ�������
		mY += VELOCITY;
	}
	//A�L�[��������Ă��邩���肷��
	if (mInput.Key('A') == 1) {
		//�l�p�`�����ֈړ�������
		mX -= VELOCITY;
	}
	//D�L�[��������Ă��邩���肷��
	if (mInput.Key('D') == 1) {
		//�l�p�`���E�ֈړ�������
		mX += VELOCITY;
	}
	//Space�L�[��������Ă��邩���肷��
	if (mInput.Key(' ') == 1) {
		if (mShootInterval == 0) {
			mShootInterval = SHOOTINTERVAL;
			//�e�𔭎˂���
			for (int i = 0; i < 10; i++) {
				if (mShootPlayer[i].mState == EDELETE) {
					mShootPlayer[i].Set(mX, mY, 12, 32);
					mShootPlayer[i].mState = EENABLED;
					break;
				}
			}
		}
	}
}

void CPlayer::Collision(CCharacter* my, CCharacter* yc) {
	if (!mState) return;
	if (!yc->mState) return;
	if (CCollision::Collision(*this, *yc)) {
		switch(yc->mTag) {
		case ESHOOTENEMY:
		case EENEMY:
			//new CEffect(mX, mY, 64, 64);
			//CUI::mPlayerHit++;
			break;
		default:
			break;
		}
	}
}

void CPlayer::Render() {
	CRectangle::Render(mX, mY, mW, mH, mpTexture, 0.0f, 74.0f, 88.0f, 0.0f);
}
