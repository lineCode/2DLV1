#ifndef CCHARACTER_H
#define CCHARACTER_H

#include "CRectangle.h"

class CCharacter : public CRectangle {
public:
	//�^�O
	enum ETag {
		ENONE,
		EPLAYER,
		EBACKGROUND,
		EBOSS,
		ESHOOTPLAYER,
		ESHOOTBOSS,
		ESHOOTENEMY,
		EENEMY,
		EBLOCK,
	};
	ETag mTag;

	//�X�e�[�^�X
	enum EState {
		EDISABLED,	//����
		EENABLED,	//�L��
		ECOLLISION,	//�Փˍ�
	};
	EState mState;
	//�R���X�g���N�^
	CCharacter();
	virtual ~CCharacter();
	//�X�V����
	virtual void Update() {};
	//�`�揈��
	virtual void Render() {};
	//�Փˏ���
	virtual void Collision(CCharacter* mc, CCharacter* yc) {};

};

#endif
