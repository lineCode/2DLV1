#ifndef CCHARACTER_H
#define CCHARACTER_H

class CCharacter {
public:
	float mX;//���S��X���W
	float mY;//���S��Y���W
	float mW;//���̔���
	float mH;//�����̔���
	//�^�O
	enum ETag {
		ENONE,
		EPLAYER,
		EBACKGROUND,
		EBOSS,
		EPLAYERSHOT,
		ESHOOTBOSS,
		EENEMYSHOT,
		EENEMY,
		EBLOCK,
		EBOMB,
	};
	ETag mTag;

	//�X�e�[�^�X
	enum EState {
		EDELETE,
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
	void Set(int posx, int posy, int width, int height);

};

#endif
