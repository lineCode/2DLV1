#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
//1
#include "CModel.h"

/*
�Q�[���̃V�[��
*/
class CSceneGame : public CScene {
public:
	//1
	CModel mSky;
	CModel mRock;
	CModel mRover;

	~CSceneGame();
	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();

};

#endif
