#ifndef CTEXTURE_H
#define CTEXTURE_H
#include "glew.h"
#include "glut.h"
#include <stdio.h>	//�t�@�C���̓��͂Ɏg�p
#include <string.h>
/*
TGA�t�@�C���̃w�b�_�t�H�[�}�b�g
*/
struct STgamHeader {
	unsigned char	dummy1[12];
	unsigned short	width;	//��
	unsigned short	height;	//����
	unsigned char	depth;	//�r�b�g�̐[��
	unsigned char	dummy2;
};
/*
�e�N�X�`���[�N���X
*/
//#include <map>

class CTexture {
//	static std::map<std::string, CTexture>mTexFile;
	//�t�@�C����
	char* mpName;
public:
	//TGA�t�@�C���̃w�b�_���
	STgamHeader mHeader;
	//�e�N�X�`��ID
	GLuint mId;
	//
	int mCol;
	int mRow;
	/*
	�f�t�H���g�R���X�g���N�^
	*/
	CTexture();
	CTexture(char *file);
	/*
	�f�X�g���N�^�i���̃C���X�^���X���j�������Ƃ��Ɏ��s�����j
	*/
	~CTexture();
	/*
	�摜�t�@�C���̓ǂݍ��݁i�e�N�X�`���t�@�C���̓ǂݍ��݁j
	*/
	void Load(const char* filename);
	/*
	DrawImage
	left:�l�p�`�����W
	right:�l�p�`�E���W
	bottom:�l�p�`�����W
	top:�l�p�`����W
	tleft:�摜�����W
	tright:�摜�E���W
	tbottom:�摜�����W
	ttop:�摜����W
	*/
	void DrawImage(float left, float right, float bottom, float top, float tleft, float tright, float tbottom, float ttop);
	void DrawImage(float left, float right, float bottom, float top, int index);
	void Destory();
	void SetParts(int row, int col);
};

#endif