#ifndef CPLAYER_H
#define CPLAYER_H
//�L�����N�^�N���X�̃C���N���[�h
#include "CCharacter.h"
//
#include "CCollider.h"
/*
�v���C���[�N���X
�L�����N�^�N���X���p��
*/
class CPlayer : public CCharacter {
public:
	//�R���C�_
	CCollider mLine[4];//�����R���C�_
//	CCollider mCollider;
	//�f�t�H���g�R���X�g���N�^
	CPlayer();
	//�X�V����
	void Update();
};

#endif
