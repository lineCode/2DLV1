#ifndef CMODEL_H
#define CMODEL_H
//vector�̃C���N���[�h
#include <vector>
#include "CTriangle.h"
#include "CMatrix.h"
//CMaterial�̃C���N���[�h
#include "CMaterial.h"
/*
���f���N���X
���f���f�[�^�̓��͂�\��
*/
class CModel {
public:
	//�O�p�`�̉ϒ��z��
	std::vector<CTriangle> mTriangles;
	//�O�p�`�̉ϒ��z��
	std::vector<CMaterial> mMaterials;
	//���f���t�@�C���̓���
	//Load(���f���t�@�C����, �}�e���A���t�@�C����)
	void Load(char *obj, char *mtl);
	//�`��
	void Render();
	void Render(const CMatrix &m);
};

#endif
