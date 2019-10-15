//�v���C���[�N���X�̃C���N���[�h
#include "CPlayer.h"
//�L�[���̓N���X�̃C���N���[�h
#include "CKey.h"

#include "CBullet.h"
extern CBullet Bullet;

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
	//W�L�[���͂ŏ����
	if (CKey::Push(VK_SPACE)) {
		Bullet.Set(0.1f, 1.5f);
		Bullet.mPosition = mPosition;
 		Bullet.mRotation = mRotation;
	}
	//CCharacter�̍X�V
	CCharacter::Update();
}
