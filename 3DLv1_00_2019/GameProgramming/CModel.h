#ifndef CMODEL_H
#define CMODEL_H
//vector�̃C���N���[�h
#include <vector>
#include "CTriangle.h"
/*
���f���N���X
���f���f�[�^�̓��͂�\��
*/
class CModel {
public:
	//�O�p�`�̉ϒ��z��
	std::vector<CTriangle> mTriangles;
	//���f���t�@�C���̓���
	//Load(���f���t�@�C����, �}�e���A���t�@�C����)
	void Load(char *model,char *mtl);
	//�`��
	void Render();
};

#endif
