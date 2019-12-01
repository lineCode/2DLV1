#include "CEnemy.h"
//�G�t�F�N�g�N���X�̃C���N���[�h
#include "CEffect.h"
//
#include "CSceneGame.h"

//�X�}�[�g�|�C���^�̊O���Q��
extern std::shared_ptr<CTexture> TextureExp;

//�U���|�C���g
CPoint CEnemy::mPoint[3];

#define TURN_DEG 0.3f

//�R���X�g���N�^
//CEnemy(���f��, �ʒu, ��], �g�k)
CEnemy::CEnemy(CModel *model, CVector position, CVector rotation, CVector scale)
: mCollider(this, CVector(0.0f, 0.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f),
CVector(1.0f / scale.mX, 1.0f / scale.mY, 1.0f / scale.mZ), 0.8f)
//?SearchEnemy
//mSearch1(this, CVector(0.0f, 0.0f, 115.0f), CVector(0.0f, 0.0f, 0.0f),
//CVector(1.0f / scale.mX, 1.0f / scale.mY, 1.0f / scale.mZ), 7.0f),
//mSearch2(this, CVector(0.0f, 0.0f, 200.0f), CVector(0.0f, 0.0f, 0.0f),
//CVector(1.0f / scale.mX, 1.0f / scale.mY, 1.0f / scale.mZ), 10.0f),
,mHp(20)
//mRx(-0.1f),
, mPointCnt(0)
{
	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model;	//���f���̐ݒ�
	mPosition = position;	//�ʒu�̐ݒ�
	mRotation = rotation;	//��]�̐ݒ�
	mScale = scale;	//�g�k�̐ݒ�
	mPointCnt = 0;	//�ŏ��̃|�C���g��ݒ�
	mpPoint = &mPoint[mPointCnt];//�ڎw���|�C���g�̃|�C���^��ݒ�
}
//�X�V����
void CEnemy::Update() {
	//�|�C���g�ւ̃x�N�g�������߂�
	CVector dir = mpPoint->mPosition - mPosition;
	//�������̃x�N�g�������߂�
	CVector left = CVector(1.0f, 0.0f, 0.0f) * CMatrix().RotateY(mRotation.mY);
	//������̃x�N�g�������߂�
	CVector up = CVector(0.0f, 1.0f, 0.0f) * CMatrix().RotateX(mRotation.mX) * CMatrix().RotateY(mRotation.mY);
	//���E�̉�]�����iY���j
	if (left.Dot(dir) > 0.0f) {
		mRotation.mY += 0.3f;
	}
	else if (left.Dot(dir) < 0.0f) {
		mRotation.mY -= 0.3f;
	}
	//�㉺�̉�]�����iX���j
	if (up.Dot(dir) > 0.0f) {
		mRotation.mX -= 0.3f;
	}
	else if (up.Dot(dir) < 0.0f) {
		mRotation.mX += 0.3f;
	}

	//�s����X�V
	CCharacter::Update();
	//�ʒu���ړ�
	mPosition = CVector(0.0f, 0.0f, 1.0f) * mMatrix;
	//��]������
//	mRotation.mY += 0.5f;

	if (mHp < 0) {
		mHp--;
		mRotation.mX = 20;
		if (mHp % 10 == 0) {
			new CEffect(mPosition, 1.5f, 1.5f, TextureExp, 4, 4, 2);
		}
	}
}

void CEnemy::Collision(CCollider *m, CCollider *y) {
//	if (y->mpParent->mTag == CCollider::ESEARCH) return;
	if (CCollider::Collision(m, y)) {
		//�Փ˂����R���C�_�̐e�̎�ނ𔻒�
		switch (y->mpParent->mTag) {
		case EPOINT://�|�C���g�̎�
			//�Փ˂����|�C���^�Ɩڎw���Ă���|�C���^��������
			if (y->mpParent == mpPoint) {
				mPointCnt++;//���̃|�C���g�ɂ���
				//�Ōゾ������ŏ��ɂ���
				mPointCnt %= (sizeof(mPoint) / sizeof(mPoint[0]));
				//���̃|�C���g�̃|�C���^��ݒ�
				mpPoint = &mPoint[mPointCnt];
			}
			break;
		default:
			//�G�t�F�N�g����
			new CEffect(mPosition, 1.0f, 1.0f, TextureExp, 4, 4, 1);
//			mHp--;
		}
//�폜		mEnabled = false;
	}
}
