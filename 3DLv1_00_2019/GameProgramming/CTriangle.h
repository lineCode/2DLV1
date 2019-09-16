#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CVector.h"
#include "CMatrix.h"

/*
�O�p�`�N���X
*/
class CTriangle {
public:
	CVector mV[3]; //���_���W
	CVector mN; //�@��
	//���_���W�ݒ�
	//SetVertex(���_1, ���_2, ���_3)
	void SetVertex(const CVector &v0, const CVector &v1, const CVector &v2);
	//�@���ݒ�
	//SetNormal(�@���x�N�g��)
	void SetNormal(const CVector &n);
	//�`��
	void Render();
	//Render(�s��)
	void Render(const CMatrix &m);
};

#endif
