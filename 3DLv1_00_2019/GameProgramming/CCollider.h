#ifndef CCOLLIDER_H
#define CCOLLIDER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
/*
�R���C�_�N���X
�Փ˔���f�[�^
*/
class CCollider : public CCharacter {
public:
	float mRadius;	//���a
	//�R���X�g���N�^
	//CCollider(�e, �ʒu, ��], �g�k, ���a)
	CCollider(CCharacter *parent, CVector position, CVector rotation, CVector scale, float radius);
	//�`��
	void Render();
};

#endif
