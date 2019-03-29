#ifndef CTASK_H
#define CTASK_H

/*
�^�X�N�̊��N���X
*/
class CTask {
	CTask *mpPrev;	//�O
	CTask *mpNext;	//��
public:
	enum EStatus {
		EREMOVED,
		EDISABLED,
		EENABLED,
		EDELETE,
	};
	EStatus mStatus;//�X�e�[�^�X
	int mPriority;	//�D��x ��F����

	CTask()
		: mpPrev(0), mpNext(0), mPriority(0), mStatus(EREMOVED) {
	}
	virtual ~CTask();

	virtual void Render(){}
	virtual void Collision(CTask&){}
	virtual void Update(){}
	void Enable();
	void Disable();
	void Delete();

	friend class CTaskManager;
};

/*
�^�X�N�}�l�[�W��
*/
class CTaskManager {
	//�V���O���g���@�B��̃C���X�^���X
	static CTaskManager *mInstance;
protected:
	CTaskManager()
		: mpHead(0), mpTail(0) {
	}
	CTask *mpHead;	//�擪
	CTask *mpTail;	//�Ō�
public:
	//�C���X�^���X�̎擾
	static CTaskManager* Get();
	//�^�X�N�ǉ�
	void Add(CTask*);
	//�X�V����
	void Update();
	//�Փˏ���
	void Collision();
	//�S�Ă��폜
	void Destroy();
	//�`�揈��
	void Render();
	//�폜����
	CTask* Remove(CTask*);
	//�폜����
	void Remove();
};
/*
�R���W�����}�l�[�W��
*/
//class CCollisionManager : public CTaskManager {
//	//�V���O���g���@�B��̃C���X�^���X
//	static CCollisionManager *mInstance;
//	CCollisionManager()
//		: CTaskManager() {
////		: mpHead(0), mpTail(0) {
//	}
////	CTask *mpHead;	//�擪
////	CTask *mpTail;	//�Ō�
//public:
//	//�C���X�^���X�̎擾
//	static CCollisionManager* Get();
//	//�X�V����
//	void Update(CTask&);
//	//�^�X�N�ǉ�
////	void Add(CTask*);
//	//�S�Ă��폜
////	void Destroy();
//	//�폜����
////	CTask* Remove(CTask*);
//};

#endif
