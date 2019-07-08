#ifndef CFONT_H
#define CFONT_H

#include "CRectangle.h"
/*
CFont
�����̕\��
*/
class CFont : public CRectangle {
	static CTexture mTexture;
	int mStartNumIndex;
	int mStartAlphaIndex;
	int mCol, mRow;
public:
	CFont();
	/*
	�t�H���g�N���X�̍쐬
	filename:�摜�t�@�C���̎w��
	row:�����f�[�^�̍s��
	col:�����f�[�^�̗�
	num:�����f�[�^�̊J�n�����ʒu
	alpha:�p���f�[�^�̊J�n�����ʒu
	*/
	CFont(char* filename, int row, int col, int num, int alpha);
	/*
	�t�H���g�N���X�̐ݒ�
	filename:�摜�t�@�C���̎w��
	row:�����f�[�^�̍s��
	col:�����f�[�^�̗�
	num:�����f�[�^�̊J�n�����ʒu
	alpha:�p���f�[�^�̊J�n�����ʒu
	*/
	void Set(char* filename, int row, int col, int num, int alpha);
	/*
	�f�[�^�ʒu�̐ݒ�
	num:�����f�[�^�̊J�n�����ʒu
	alpha:�p���f�[�^�̊J�n�����ʒu
	*/
	void SetNumAlphaIndex(int num, int alpha);
	/*
	�����̕`��
	string:�`�悷�镶����
	x:��ʂɕ`�悷��ʒu��X���W
	y:��ʂɕ`�悷��ʒu��Y���W
	w:��ʂɕ`�悷�镶���̕�
	h:��ʂɕ`�悷�镶���̍���
	*/
	void Render(char *string, int x, int y, int w, int h);
};

#endif
