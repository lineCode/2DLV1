#include "CScene.h"
#include "CRectangle.h"
#include <stdio.h>

//��x�������s����郁�\�b�h
void CScene::Init() {
	printf("CMain::Init()\n");
	mRectangle.mPx = 370;
	mRectangle.mPy = 270;
	mRectangle.mSx = 30;
	mRectangle.mSy = 30;
}

//�J��Ԃ����s����郁�\�b�h
void CScene::Update() {
	printf("CMain::Update()\n");
	mRectangle.Render();
}