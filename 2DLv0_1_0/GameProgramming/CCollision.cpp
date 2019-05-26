#include "CCollision.h"
#include "CRectangle.h"

bool CCollision::Collision(const CRectangle& col1, const CRectangle& col2, float *mx, float*my) {
	//�l�p�`�Փˎ��̈ړ��ʂ����߂�
	float x = col1.CollisionX(col2);
	float y = col1.CollisionY(col2);
	if (x * y == 0.0f)
		return false;
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

bool CCollision::Collision(const CRectangle& col1, const CRectangle& col2) {
	//�l�p�`�Փˎ��̈ړ��ʂ����߂�
	float x = col1.CollisionX(col2);
	float y = col1.CollisionY(col2);
	if (x * y == 0.0f) return false;
	return true;
}

