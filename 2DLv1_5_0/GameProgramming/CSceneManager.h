#ifndef CSCENEMANGER
#define CSCENEMANGER
#include "CScene.h"
#include "CInput.h"

//�N���X�̒�`
class CSceneManager : public CScene {
	CScene *mpScene;
public:
	//�ϐ��̐錾
	CInput mInput;

	CSceneManager();

	~CSceneManager();

	//���\�b�h�i�v���O�����j�̐錾
	void Init();
	void Update();
	void Render();
};

#endif
