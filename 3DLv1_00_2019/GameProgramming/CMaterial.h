#ifndef CMATERIAL_H
#define CMATERIAL_H
/*
�}�e���A���N���X
�}�e���A���̃f�[�^������
*/
class CMaterial {
public:
	char mName[64];
	//diffuse
	float mDiffuse[4];
	//
	CMaterial();
	//�}�e���A���̓K�p
	void SetMaterial();
};


#endif
