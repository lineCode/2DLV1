#ifndef CCOLLIDER_H
#define CCOLLIDER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
//
#include "CTransform.h"
/*
�R���C�_�N���X
�Փ˔���f�[�^
*/
class CCollider : public CTask, public CTransform {
public:
	CCharacter *mpParent;
	float mRadius;	//���a
	//�R���X�g���N�^
	//CCollider(�e, �ʒu, ��], �g�k, ���a)
	CCollider(CCharacter *parent, CVector position, CVector rotation, CVector scale, float radius);
	~CCollider();
	//�`��
	void Render();
};

#endif
