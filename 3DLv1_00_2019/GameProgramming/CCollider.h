#ifndef CCOLLIDER_H
#define CCOLLIDER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
//�g�����X�t�H�[���N���X�̃C���N���[�h
#include "CTransform.h"
/*
�R���C�_�N���X
�Փ˔���f�[�^
*/
class CCollider : public CTransform, public CTask {
public:
	//�R���C�_�̎��
	enum ETag {
		ENONE,
		EBODY,//�@��
		ESEARCH,//�T�[�`
	};
	ETag mTag;
	CCharacter *mpParent;//�e
	float mRadius;	//���a
	//�R���X�g���N�^
	//CCollider(�e, �ʒu, ��], �g�k, ���a)
	CCollider(CCharacter *parent, CVector position, CVector rotation, CVector scale, float radius);
	~CCollider();
	//�`��
	void Render();
	//�Փ˔���
	//Collision(�R���C�_1, �R���C�_2)
	//retrun:true�i�Փ˂��Ă���jfalse(�Փ˂��Ă��Ȃ�)
	static bool Collision(CCollider *m, CCollider *y);
};

#endif
