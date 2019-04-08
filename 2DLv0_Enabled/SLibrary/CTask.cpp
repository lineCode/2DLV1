#include <stdio.h>
#include "CTask.h"



void CTask::Enable() {
	switch (mStatus) {
	case EREMOVED:
		mStatus = EENABLED;
		CTaskManager::Get()->Add(this);
		break;
	case EDISABLED:
		mStatus = EENABLED;
		break;
	}
}

void CTask::Auto() {
	switch (mStatus) {
	case EREMOVED:
		mStatus = EAUTO;
		CTaskManager::Get()->Add(this);
		break;
	case EDISABLED:
		mStatus = EAUTO;
		break;
	}
}

void CTask::Disable() {
	mStatus = EDISABLED;
}

void CTask::Delete() {
	mStatus = EDELETE;
}

CTask::~CTask() {
	CTaskManager::Get()->Remove(this);
}



//�V���O���g���@�B��̃C���X�^���X
CTaskManager *CTaskManager::mInstance = 0;

CTaskManager* CTaskManager::Get() {
	if (!mInstance) {
		//�C���X�^���X�������ꍇ�͐���
		mInstance = new CTaskManager();
	}
	return mInstance;
}
/*
Add
���X�g�ɒǉ�����
�D��x�͑傫���l����
*/
void CTaskManager::Add(CTask *task) {
	if (mpHead) {
		//2���ڈȍ~�̏���
		//�J�����gc�ɐ擪��������
		CTask *c = mpHead;
		//�擪�ɒǉ��̏ꍇ
		if (task->mPriority >= c->mPriority) {
			//�擪�͈����̃^�X�N
			mpHead = task;
			//�擪�̑O�͂Ȃ�
			task->mpPrev = 0;
			//�擪�̎��́A�J�����gc
			task->mpNext = c;
			//���̑O�͈����̃^�X�N
			c->mpPrev = task;
			return;
		} //�擪�ɒǉ��̏I���
		c = c->mpNext;
		//�擪�ȍ~�ɒǉ�
		while (c) {
			if (task->mPriority >= c->mPriority) {
				//�J�����g�̑O�̎��������̃^�X�N�ɂ���
				c->mpPrev->mpNext = task;
				//�����̃^�X�N�̑O���J�����g�̑O��
				task->mpPrev = c->mpPrev;
				//�����̃^�X�N�̎����J�����g��
				task->mpNext = c;
				//�J�����g�̑O�������̃^�X�N��
				c->mpPrev = task;
				return;
			}
			c = c->mpNext;
		} //�r���ɒǉ��I��
		//�Ō�ɒǉ�
		//�Ō�̎��������̃^�X�N�ɂ���
		mpTail->mpNext = task;
		//�����̃^�X�N�̑O���A���̍Ō�ɂ���
		task->mpPrev = mpTail;
		//�����̃^�X�N�̎���0�ɂ���
		task->mpNext = 0;
		//�Ō�Ɉ����̃^�X�N��������
		mpTail = task;
	}
	else {	//0�͋U
		//1���ڂ̏���
		//�擪�������̃^�X�N�ɂ���
		mpHead = task;
		//�擪�̑O��0�ɂ���
		task->mpPrev = 0;
		//�擪�̎���0�ɂ���
		task->mpNext = 0;
		//�Ō�Ɉ����̃^�X�N��������
		mpTail = task;
	}
}

/*
Update
�X�V����
*/
void CTaskManager::Update(){
	//�J�����gc��擪�ɂ���
	CTask *c = mpHead;
	//�J�����gc��0�ɂȂ�����I��
	while (c) {
		//�X�V����
//		if (c->mStatus == CTask::EENABLED)
			c->Update();
		//�J�����g������
		c = c->mpNext;
	}
}

/*
Collision
�Փˏ���
*/
void CTaskManager::Collision(){
	//�J�����gc��擪�ɂ���
	CTask *c = mpHead;
	//�J�����gc��0�ɂȂ�����I��
	while (c) {
//		if (c->mStatus == CTask::EENABLED) {
			//�Փˏ���
			CTask *collider = c->mpNext;
			//�J�����gcollider��0�ɂȂ�����I��
			while (collider) {
//				if (collider->mStatus != CTask::EDISABLED) {
					if (c != collider) {
						//�Փˏ���
						c->Collision(*collider);
						collider->Collision(*c);
					}
//				}
				//�J�����g������
				collider = collider->mpNext;
			}
//		}
		//�J�����g������
		c = c->mpNext;
	}
}

/*
Render
�X�V����
*/
void CTaskManager::Render(){
	//�J�����gc���Ō�ɂ���
	CTask *c = mpTail;
	//�J�����gc��0�ɂȂ�����I��
	while (c) {
		//�`�悷��
//		if (c->mStatus == CTask::EENABLED)
			c->Render();
		//�J�����g��O��
		c = c->mpPrev;
	}
}

/*
Destory
���X�g��S�č폜���A
���g���폜����
*/
void CTaskManager::Destroy(){
	//�J�����gc��擪�ɂ���
	CTask *c = mpHead;
	//�J�����g��0�ɂȂ�����I��
	while (c) {
		//�J�����g�����ɂ���
		c = c->mpNext;
		//�擪���폜
		if (mpHead->mStatus != CTask::EAUTO)
			delete mpHead;
		//�擪�ɃJ�����g��������
		mpHead = c;
	}
	//�Ō��0�ɂ���
	mpTail = 0;
	//�������g���폜
	if (mInstance)
		delete mInstance;
	mInstance = 0;
}
/*
�����̃^�X�N�����X�g����폜���܂�
*/
CTask* CTaskManager::Remove(CTask *task) {
	//�폜���鎟�̃^�X�N��ޔ�
	CTask *rtn = task->mpNext;
	//�폜���X�g���擪�̎�
	if (mpHead == task) {
		//����擪�ɂ���
		mpHead = task->mpNext;
	}
	//�폜���X�g���Ō�̎�
	if (mpTail == task) {
		//�O���Ō�ɂ���
		mpTail = task->mpPrev;
	}
	//�폜���X�g�ɑO�����鎞
	if (task->mpPrev) {
		//�O�̎����A�폜���X�g�̎��ɂ���
		task->mpPrev->mpNext = task->mpNext;
	}
	//�폜���X�g�Ɏ�������ꍇ
	if (task->mpNext) {
		//���̑O���A�폜���X�g�̑O�ɂ���
		task->mpNext->mpPrev = task->mpPrev;
	}
	if (task->mStatus == CTask::EDELETE) {
		task->mStatus = CTask::EREMOVED;
		delete task;
	}
	else {
		task->mpNext = 0;
		task->mpPrev = 0;
		task->mStatus = CTask::EREMOVED;
	}
	//����Ԃ�
	return rtn;
}
/*
�����ȃ^�X�N�����X�g����폜���܂�
*/
void CTaskManager::Remove() {
	//�J�����gc��擪�ɂ���
	CTask *c = (CTask*)mpHead;
	//�J�����gc��0�ɂȂ�����I��
	while (c) {
		if (c->mStatus == CTask::EENABLED
			|| c->mStatus == CTask::EAUTO) {
				//�L���Ȏ��͎���
			c = c->mpNext;
		}
		//else if(c->mStatus == CTask::EDELETE) {
		//	CTask *next = c->mpNext;
		//	delete c;
		//	c = next;
		//}
		else {
			//�����ȃ^�X�N�͍폜
			c = Remove(c);
		}
	}
}

////�V���O���g���@�B��̃C���X�^���X
//CCollisionManager *CCollisionManager::mInstance = 0;
//
//CCollisionManager* CCollisionManager::Get() {
//	if (!mInstance) {
//		//�C���X�^���X�������ꍇ�͐���
//		mInstance = new CCollisionManager();
//	}
//	return mInstance;
//}
///*
//Update
//�X�V����
//*/
//void CCollisionManager::Update(CTask& character){
//	//�J�����gcollider��擪�ɂ���
//	CTask *collider = mpHead;
//	//�J�����gcollider��0�ɂȂ�����I��
//	while (collider) {
//		//�X�V����
//		character.Collision(*collider);
//		//�J�����g������
//		collider = collider->mpNext;
//	}
//}
/*
Add
���X�g�ɒǉ�����
�D��x�͑傫���l����
*//*
void CCollisionManager::Add(CTask *task) {
	if (mpHead) {
		//2���ڈȍ~�̏���
		//�J�����gc�ɐ擪��������
		CTask *c = mpHead;
		//�擪�ɒǉ��̏ꍇ
		if (task->mPriority >= c->mPriority) {
			//�擪�͈����̃^�X�N
			mpHead = task;
			//�擪�̑O�͂Ȃ�
			task->mpPrev = 0;
			//�擪�̎��́A�J�����gc
			task->mpNext = c;
			//���̑O�͈����̃^�X�N
			c->mpPrev = task;
			return;
		} //�擪�ɒǉ��̏I���
		c = c->mpNext;
		//�擪�ȍ~�ɒǉ�
		while (c) {
			if (task->mPriority >= c->mPriority) {
				//�J�����g�̑O�̎��������̃^�X�N�ɂ���
				c->mpPrev->mpNext = task;
				//�����̃^�X�N�̑O���J�����g�̑O��
				task->mpPrev = c->mpPrev;
				//�����̃^�X�N�̎����J�����g��
				task->mpNext = c;
				//�J�����g�̑O�������̃^�X�N��
				c->mpPrev = task;
				return;
			}
			c = c->mpNext;
		} //�r���ɒǉ��I��
		//�Ō�ɒǉ�
		//�Ō�̎��������̃^�X�N�ɂ���
		mpTail->mpNext = task;
		//�����̃^�X�N�̑O���A���̍Ō�ɂ���
		task->mpPrev = mpTail;
		//�����̃^�X�N�̎���0�ɂ���
		task->mpNext = 0;
		//�Ō�Ɉ����̃^�X�N��������
		mpTail = task;
	}
	else {	//0�͋U
		//1���ڂ̏���
		//�擪�������̃^�X�N�ɂ���
		mpHead = task;
		//�擪�̑O��0�ɂ���
		task->mpPrev = 0;
		//�擪�̎���0�ɂ���
		task->mpNext = 0;
		//�Ō�Ɉ����̃^�X�N��������
		mpTail = task;
	}
}
/*
�����̃^�X�N�����X�g����폜���܂�

CTask* CCollisionManager::Remove(CTask *task) {
	//�폜���鎟�̃^�X�N��ޔ�
	CTask *rtn = task->mpNext;
	//�폜���X�g���擪�̎�
	if (mpHead == task) {
		//����擪�ɂ���
		mpHead = task->mpNext;
	}
	//�폜���X�g���Ō�̎�
	if (mpTail == task) {
		//�O���Ō�ɂ���
		mpTail = task->mpPrev;
	}
	//�폜���X�g�ɑO�����鎞
	if (task->mpPrev) {
		//�O�̎����A�폜���X�g�̎��ɂ���
		task->mpPrev->mpNext = task->mpNext;
	}
	//�폜���X�g�Ɏ�������ꍇ
	if (task->mpNext) {
		//���̑O���A�폜���X�g�̑O�ɂ���
		task->mpNext->mpPrev = task->mpPrev;
	}
	//�^�X�N�̍폜
	//	delete task;
	//����Ԃ�
	return rtn;
}
/*
Destory
���X�g��S�č폜���A
���g���폜����

void CCollisionManager::Destroy(){
	//�J�����gc��擪�ɂ���
	CTask *c = mpHead;
	//�J�����g��0�ɂȂ�����I��
	while (c) {
		//�J�����g�����ɂ���
		c = c->mpNext;
		//�擪���폜
		//		delete mpHead;
		//�擪�ɃJ�����g��������
		mpHead = c;
	}
	//�Ō��0�ɂ���
	mpTail = 0;
	//�������g���폜
	if (mInstance)
		delete mInstance;
	mInstance = 0;
}
*/