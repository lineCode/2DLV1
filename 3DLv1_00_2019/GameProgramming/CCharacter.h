#ifndef CCHARACTER_H
#define CCHARACTER_H
//�x�N�g���N���X�̃C���N���[�h
#include "CVector.h"
//���f���N���X�̃C���N���[�h
#include "CModel.h"
//�}�g���N�X�N���X�̃C���N���[�h
#include "CMatrix.h"
//�^�X�N�N���X�̃C���N���[�h
#include "CTask.h"
/*
�L�����N�^�[�N���X
�Q�[���L�����N�^�̊�{�I�ȋ@�\���`����
*/
class CCharacter : public CTask {
public:
	CVector mPosition; //�ʒu
	CVector mRotation; //��]
	CVector mScale; //�g��k��
	CModel *mpModel; //���f���̃|�C���^
	CMatrix mMatrix; //�����s��
	CMatrix mMatrixTranslate; //���s�ړ��s��
	CMatrix mMatrixRotate; //��]�s��
	CMatrix mMatrixScale; //�g��k���s��
	//�X�V����
	void Update();
	//�`�揈��
	void Render();
};

#endif
