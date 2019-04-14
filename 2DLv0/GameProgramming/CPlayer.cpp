#include "CPlayer.h"
#include "CShootPlayer2.h"
#include "CUI.h"

#define VELOCITY 5
#define SHOOTINTERVAL 30

CPlayer* CPlayer::mpInstance = 0;;


CPlayer::CPlayer()
	: mHit(0)
	, mFont("Font.tga", 1, 64, 16, 33)
	, mShootInterval(0)
{
	LoadTexture("Player.tga");
	mPriority = 1;
	mTag = EPLAYER;
//	Enable();
	mpInstance = this;
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
			CShootPlayer2 *s = new CShootPlayer2();
			s->SetXYWH(mX, mY, 60, 54);
		}
	}
//	mEffect.SetXYWH(mX, mY, 128, 128);
}

void CPlayer::Collision(CTask& r) {
	CCharacter& c = (CCharacter&)r;
	if (c.mTag == ESHOOTBOSS) {
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
	CRectangle::Render();
	char buf[10];
	sprintf(buf, "%d", mHit);
	mFont.Render(buf, mX + mW, mY - mH, 24, 32);
}
