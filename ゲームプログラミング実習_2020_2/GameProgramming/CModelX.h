#ifndef CMODELX_H	//�C���N���[�h�K�[�h
#define CMODELX_H

#define MODEL_FILE "sample.blend.x"	//���̓t�@�C����

//�̈������}�N����
#define SAFE_DELETE_ARRAY(a) { if(a) delete[] a; a = 0;}
//�z��̃T�C�Y�擾���}�N����
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

#include <vector>	//vector�N���X�̃C���N���[�h�i���I�z��j
#include "CMatrix.h"	//�}�g���N�X�N���X�̃C���N���[�h
#include "CVector.h"
//09
class CMaterial;

class CModelX;	// CModelX�N���X�̐錾


//CMesh�N���X�̒�`
class CMesh {
public:
	int mVertexNum;	//���_��
	CVector *mpVertex;	//���_�f�[�^
	int mFaceNum;	//�ʐ�
	int *mpVertexIndex;	//�ʂ��\�����钸�_�ԍ�
	int mNormalNum;	//�@����
	CVector *mpNormal;//�@���f�[�^

	//09
	int mMaterialNum;	//�}�e���A����
	int mMaterialIndexNum;//�}�e���A���ԍ����i�ʐ��j
	int *mpMaterialIndex;	  //�}�e���A���ԍ�
	std::vector<CMaterial*> mMaterial;//�}�e���A���f�[�^


	//�R���X�g���N�^
	CMesh()
		: mVertexNum(0)
		, mpVertex(0)
		, mFaceNum(0)
		, mpVertexIndex(0)
		, mNormalNum(0)
		, mpNormal(0)
		//
		, mMaterialNum(0)
		, mMaterialIndexNum(0)
		, mpMaterialIndex(0)
	{}
	//�f�X�g���N�^
	~CMesh() {
		SAFE_DELETE_ARRAY(mpVertex);
		SAFE_DELETE_ARRAY(mpVertexIndex);
		SAFE_DELETE_ARRAY(mpNormal);
		SAFE_DELETE_ARRAY(mpMaterialIndex);
	}
	//�ǂݍ��ݏ���
	void Init(CModelX *model);
	void Render();
};


//CModelXFrame�N���X�̒�`
class CModelXFrame {
public:
	std::vector<CModelXFrame*> mChild;	//�q�t���[���̔z��
	CMatrix mTransformMatrix;	//�ϊ��s��
	char* mpName;	//�t���[�����O
	int mIndex;		//�t���[���ԍ�

	CMesh mMesh;	//Mesh�f�[�^

	//�R���X�g���N�^
	CModelXFrame(CModelX* model);
	//�f�X�g���N�^
	~CModelXFrame() {
		//�q�t���[����S�ĉ������
		std::vector<CModelXFrame*>::iterator itr;
		for (itr = mChild.begin(); itr != mChild.end(); itr++) {
			delete *itr;
		}
		//���O�̃G���A���������
		SAFE_DELETE_ARRAY(mpName);
	}
	void Render();
};
/*
CModelX
X�t�@�C���`����3D���f���f�[�^���v���O�����ŔF������
*/
class CModelX {
public:
	char* mpPointer;	//�ǂݍ��݈ʒu
	char mToken[1024];	//���o�����P��̗̈�
	std::vector<CModelXFrame*> mFrame;	//�t���[���̔z��

	CModelX() 
		: mpPointer(0)
	{}

	~CModelX() {
		delete mFrame[0];
	}
	//�t�@�C���ǂݍ���
	void Load(char* file);
	//�P��̎��o��
	void GetToken();
	//�m�[�h�̓ǂݔ�΂�
	void SkipNode();
	//���������_�f�[�^�̎擾
	float GetFloatToken();
	//�����f�[�^�̎擾
	int GetIntToken();
	void Render();

};

#endif
