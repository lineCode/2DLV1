#ifndef CSCENEGAME_H	//�C���N���[�h�K�[�h
#define CSCENEGAME_H	//�C���N���[�h�K�[�h

//CScene�N���X�̃C���N���[�h
#include "CScene.h"

/*
�N���X�̒�`
class �N���X�� : public �e�N���X�� {
public:
    ����
};
�N���X���FCSceneGame
�e�N���X���FCScene
CScene�N���X���p������
CSceneGame�N���X���`����
*/
class CSceneGame: public CScene {
public:
	/*
	�f�t�H���g�R���X�g���N�^�̐錾
	�N���X��()
	�N���X�̃C���X�^���X�̐������ɌĂ΂��
	*/
	CSceneGame();

	/*
	���\�b�h�̐錾
	�߂�l�̌^�@���\�b�h��(����);
	�߂�l�̌^�Fvoid:�߂�l�Ȃ�
	���\�b�h���FUpdate
	�����F():�����Ȃ�
	�C���X�^���X�̍X�V�������L�q
	*/
	void Update();
	/*
	���\�b�h�̐錾
	Render()
	�C���X�^���X�̕`�揈�����L�q
	*/
	void Render();
};

#endif	//�C���N���[�h�K�[�h
