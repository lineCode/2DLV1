#include "CVector.h"
/*
//�R���X�g���N�^
//�e�l��0�ɏ�����
CVector::CVector()
: mX(0.0f), mY(0.0f), mZ(0.0f) {}
*/

//Set(X���W, Y���W, Z���W)
void CVector::Set(float x, float y, float z) {
	//�e���̒l�������܂�
	mX = x;
	mY = y;
	mZ = z;
}

//�s��Ƃ̊|���Z
//Multi(�s��)
CVector CVector::Multi(const CMatrix &m) {
	CVector v;
	v.mX = mX * m.mM[0][0] + mY * m.mM[1][0] + mZ * m.mM[2][0] + m.mM[3][0];
	v.mY = mX * m.mM[0][1] + mY * m.mM[1][1] + mZ * m.mM[2][1] + m.mM[3][1];
	v.mZ = mX * m.mM[0][2] + mY * m.mM[1][2] + mZ * m.mM[2][2] + m.mM[3][2];
	return v;
}

