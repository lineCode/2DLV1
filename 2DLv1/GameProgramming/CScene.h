#ifndef CSCENE_H
#define CSCENE_H
#include "CRectangle.h"


//�V�[���N���X
class CScene {
public:
	CRectangle mRectangle;
	//��x�������s����郁�\�b�h
	void Init();
	//�J��Ԃ����s����郁�\�b�h
	void Update();
};

#endif
