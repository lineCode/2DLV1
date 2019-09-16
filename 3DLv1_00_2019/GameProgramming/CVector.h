#ifndef CVECTOR_H
#define CVECTOR_H
//CMatrix�N���X�̃C���N���[�h
#include "CMatrix.h"
/*
 �x�N�g���N���X
 �x�N�g���f�[�^�������܂�
*/
class CVector {
public:
	//3D�e���ł̒l��ݒ�
	float mX, mY, mZ;
	//�e���ł̒l�̐ݒ�
	//Set(X���W, Y���W, Z���W)
	void Set(float x, float y, float z);
	//�s��Ƃ̊|���Z
	//Multi(�s��)
	CVector Multi(const CMatrix &m);
	//�f�t�H���g�R���X�g���N�^
	CVector();
	//�R���X�g���N�^
	//CVector(X���W, Y���W, Z���W)
	CVector(float x, float y, float z);
	//*���Z�q�̃I�[�o�[���[�h
	//CVector * CMatrix �̉��Z���ʂ�Ԃ�
	CVector operator*(const CMatrix &m);
};

#endif
