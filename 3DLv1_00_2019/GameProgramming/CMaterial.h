#ifndef CMATERIAL_H
#define CMATERIAL_H
/*
�}�e���A���N���X
�}�e���A���̃f�[�^������
*/
class CMaterial {
public:
	//�}�e���A����
	char mName[64];
	//�g�U���̐FRGBA
	float mDiffuse[4];
	//�f�t�H���g�R���X�g���N�^
	CMaterial();
	//�}�e���A����L���ɂ���
	void Enabled();
};

#endif
