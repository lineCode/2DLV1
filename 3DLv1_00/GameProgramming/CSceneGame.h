#ifndef CSCENEGAME_H
#define CSCENEGAME_H
#include "CScene.h"
#include "CVector.h"
#include "CTriangle.h"
#include "CRectangle.h"
#include "CMatrix.h"
#include "CBox.h"
#include "CModel.h"
#include "CCamera.h"
#include "CCharacter.h"
#include "CPlayer.h"
#include "CBullet.h"
#include "CTaskManager.h"
#include "CCollisionManager.h"

/*
�Q�[���̃V�[��
*/
//CScene�N���X���p������
class CSceneGame : public CScene {
public:
	CVector mCameraEye;
	CVector mCameraCenter;
	CVector mCameraUp;

	CTriangle mTriangle[2];
	CRectangle mRectangle;
	float mDegree;
	CMatrix mMatrix;

//	CBox mBox;

	CModel mModel;
	CModel mSky;

	CCamera mCamera;

//	CCharacter mCharacter;

	CPlayer mPlayer;

//	CBullet mBullet;

	CModel mF16;

	//�����������̃I�[�o�[���C�h
	void Init();
	//�X�V�����̃I�[�o�[���C�h
	void Update();
//	CSceneGame();
	//�f�X�g���N�^�̐錾
	~CSceneGame();
};

extern CTaskManager TaskManager;
extern CCollisionManager CollisionManager;

#endif
