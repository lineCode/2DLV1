#include "CScene.h"
#include "CRectangle.h"
#include <stdio.h>

//��x�������s����郁�\�b�h
void CScene::Init() {
	printf("CMain::Init()\n");
}

//�J��Ԃ����s����郁�\�b�h
void CScene::Update() {
	printf("CMain::Update()\n");
	mRectangle.Render();
}