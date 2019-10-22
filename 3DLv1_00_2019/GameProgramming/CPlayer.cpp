//�v���C���[�N���X�̃C���N���[�h
#include "CPlayer.h"
//�L�[���̓N���X�̃C���N���[�h
#include "CKey.h"
//�o���b�g�N���X�̃C���N���[�h
#include "CBullet.h"
//22extern CBullet Bullet;
//�^�X�N�}�l�[�W���̃C���N���[�h
#include "CTaskManager.h"

//�X�V����
void CPlayer::Update() {
	//A�L�[���͂ŉ�]
	if (CKey::Push('A')) {
		//Y���̉�]�l�𑝉�
		mRotation.mY += 1;
	}
	//I�L�[���͂őO�i
	if (CKey::Push('I')) {
		//Z��������1�i�񂾒l����]�ړ�������
		mPosition = CVector(0.0f, 0.0f, 1.0f) * mMatrix;
	}
	//D�L�[���͂ŉ�]
	if (CKey::Push('D')) {
		//Y���̉�]�l�����Z
		mRotation.mY -= 1;
	}
	//S�L�[���͂ŏ����
	if (CKey::Push('S')) {
		//X���̉�]�l�����Z
		mRotation.mX -= 1;
	}
	//W�L�[���͂ŏ����
	if (CKey::Push('W')) {
		//X���̉�]�l�����Z
		mRotation.mX += 1;
	}
	//�X�y�[�X�L�[���͂Œe����
	if (CKey::Push(VK_SPACE)) {
		CBullet *bullet = new CBullet();
		bullet->Set(0.1f, 1.5f);
		bullet->mPosition = CVector(0.0f, 0.0f, 10.0f) * mMatrix;
 		bullet->mRotation = mRotation;
//		TaskManager.Add(bullet);
	}
	//CCharacter�̍X�V
	CCharacter::Update();
}
