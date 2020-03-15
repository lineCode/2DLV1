#ifndef CMODELX_H	//�C���N���[�h�K�[�h
#define CMODELX_H

#define MODEL_FILE "sample.blend.x"	//���̓t�@�C����

//�̈������}�N����
#define SAFE_DELETE_ARRAY(a) { if(a) delete[] a; a = 0;}
/*
CModelX
X�t�@�C���`����3D���f���f�[�^���v���O�����ŔF������
*/
class CModelX {
public:
	char* mpPointer;	//�ǂݍ��݈ʒu
	char mToken[1024];	//���o�����P��̗̈�

	CModelX()
		: mpPointer(0)
	{}
	//�t�@�C���ǂݍ���
	void Load(char* file);
	//�P��̎��o��
	void GetToken();
};

#endif
