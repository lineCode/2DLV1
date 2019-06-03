#include "CPlayer.h"
#include "CShootPlayer.h"
#include "CShootPlayer2.h"
#include "CUI.h"
#include "CCollision.h"
#include "CEffect.h"

#define VELOCITY 5
#define SHOOTINTERVAL 30

CPlayer* CPlayer::mpInstance = 0;;
CTexture CPlayer::mTexture;

CPlayer::CPlayer()
	: mHit(0)
	, mShootInterval(0)
{
	if (mTexture.mId == 0) {
		mTexture.Load("Player.tga");
	}
	mTag = EPLAYER;
	mpInstance = this;
}


CPlayer::CPlayer(float x, float y, float w, float h)
	: CPlayer()
{
	Set(x, y, w, h);
}


void CPlayer::Update() {
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
//			CShootPlayer2 *s = new CShootPlayer2();
//			s->SetXYWH(mX, mY, 60, 54);
			new CShootPlayer(mX, mY, 24, 64);
		}
	}
//	mEffect.SetXYWH(mX, mY, 128, 128);
}

void CPlayer::Collision(CCharacter* my, CCharacter* you) {
	CCharacter& c = (CCharacter&)*you;
	if (c.mTag == ESHOOTENEMY) {
		if (CCollision::Collision(*this, c)) {
			new CEffect(mX, mY, 128, 128);
			//mEffect.mIndex = 0;
			//mEffect.Enable();
			mHit++;
			CUI::mPlayerHit++;
		}
	}
	if (c.mTag == EBOSS) {
		if (CCollision::Collision(*this, c)) {
			new CEffect(mX, mY, 128, 128);
//			mEffect.mIndex = 0;
//			mEffect.Enable();
			mHit++;
			CUI::mPlayerHit++;
		}
	}
}

void CPlayer::Render() {
	CRectangle::Render(&mTexture, 0.0f, 74.0f, 88.0f, 0.0f);
	char buf[10];
	sprintf(buf, "%d", mHit);
//	mFont.Render(buf, mX + mW, mY - mH, 24, 32);
}
