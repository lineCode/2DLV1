#ifndef CTASKMANAGER_H
#define CTASKMANAGER_H
//�^�X�N�N���X�̃C���N���[�h
#include "CTask.h"

/*
�^�X�N�}�l�[�W��
�^�X�N���X�g�̊Ǘ�
*/
class CTaskManager {
public:
	CTask *mpHead;	//�擪�|�C���^
	CTask *mpTail;	//�Ō�|�C���^
	//�f�t�H���g�R���X�g���N�^
	CTaskManager();
	//�f�X�g���N�^
	virtual ~CTaskManager();
	//���X�g�ɒǉ�
	//Add(�^�X�N�̃|�C���^)
	void Add(CTask *task);
	//���X�g����폜
	//Remove(�^�X�N�̃|�C���^)
	void Remove(CTask *task);
	//�X�V
	void Update();
	//�`��
	void Render();
};

//�^�X�N�}�l�[�W��y�̊O���Q��
extern CTaskManager TaskManager;

#endif
