#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
//22
#include "CPlayer.h"
//?
#include "CMap.h"

/*
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
public:
	//�L�����N�^�̍쐬
//	CCharacter Character;
	CPlayer Player;
	CMap mMap;//�}�b�v�̃C���X�^���X

	~CSceneGame();
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
};

#endif
