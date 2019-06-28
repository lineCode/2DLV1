#include "CCollision.h"
#include "CCharacter.h"

bool CCollision::Collision(const CCharacter *col1, const CCharacter *col2, float *mx, float*my) {
	//�l�p�`�Փˎ��̈ړ��ʂ����߂�
	float x = col1->mX - col2->mX;
	if (x < 0.0f) x = -x;
	x = x - col1->mW - col2->mW;
	if (x > 0.0f) return false;

	float y = col1->mY - col2->mY;
	if (y < 0.0f) y = -y;
	y = y - col1->mH - col2->mH;
	if (y > 0.0f) return false;

	//�ړ��ʂ����߂�
	if (col2->mX < col1->mX) {
		x = -x;
	}
	if (col2->mY < col1->mY) {
		y = -y;
	}
	//�ړ��ʂ̐�Βl�����߂�
	float absx = x, absy = y;
	if (x < 0) absx = -x;
	if (y < 0) absy = -y;
	//��Βl�̏����������Ɉړ��ʂ����Z����
	if (absx < absy) {
		*mx += x;
	}
	else {
		*my += y;
	}
	return true;
}

bool CCollision::Collision(const CCharacter *col1, const CCharacter *col2) {
	//�l�p�`�Փˎ��̈ړ��ʂ����߂�
	float x = col1->mX - col2->mX;
	if (x < 0.0f) x = -x;
	x = x - col1->mW - col2->mW;
	if (x > 0.0f) return false;
	float y = col1->mY - col2->mY;
	if (y < 0.0f) y = -y;
	y = y - col1->mH - col2->mH;
	if (y > 0.0f) return false;
	return true;
}

