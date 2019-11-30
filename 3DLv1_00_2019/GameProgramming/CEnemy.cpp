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
CVector(1.0f / scale.mX, 1.0f / scale.mY, 1.0f / scale.mZ), 0.8f),
//?SearchEnemy
//mSearch1(this, CVector(0.0f, 0.0f, 115.0f), CVector(0.0f, 0.0f, 0.0f),
//CVector(1.0f / scale.mX, 1.0f / scale.mY, 1.0f / scale.mZ), 7.0f),
//mSearch2(this, CVector(0.0f, 0.0f, 200.0f), CVector(0.0f, 0.0f, 0.0f),
//CVector(1.0f / scale.mX, 1.0f / scale.mY, 1.0f / scale.mZ), 10.0f),
mHp(20),
mRx(-0.1f),
mPointCnt(0)
{
	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model;	//���f���̐ݒ�
	mPosition = position;	//�ʒu�̐ݒ�
	mRotation = rotation;	//��]�̐ݒ�
	mScale = scale;	//�g�k�̐ݒ�
	mpPoint = &mPoint[mPointCnt];
}
//�X�V����
void CEnemy::Update() {
	//?
	//CVector dir = mpPoint->mPosition - mPosition;
	//CVector left = CVector(1.0f, 0.0f, 0.0f) * CMatrix().RotateY(mRotation.mY);
	//CVector up = CVector(0.0f, 1.0f, 0.0f) * CMatrix().RotateX(mRotation.mX) * CMatrix().RotateY(mRotation.mY);

	//if (left.Dot(dir) > 0.0f) {
	//	mRotation.mY += TURN_DEG;
	//}
	//else if (left.Dot(dir) < 0.0f) {
	//	mRotation.mY -= TURN_DEG;
	//}
	//if (up.Dot(dir) > 0.0f) {
	//	mRotation.mX -= TURN_DEG;
	//}
	//else if (up.Dot(dir) < 0.0f) {
	//	mRotation.mX += TURN_DEG;
	//}

	//�s����X�V
	CCharacter::Update();
	//�ʒu���ړ�
	mPosition = CVector(0.0f, 0.0f, 1.0f) * mMatrix;
	//��]������
	mRotation.mY += 0.5f;

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
		switch (y->mpParent->mTag) {
		case EPOINT:
			if (y->mpParent == mpPoint) {
				mPointCnt++;
//				mPointCnt %= 3;
				mPointCnt %= (sizeof(mPoint) / sizeof(mPoint[0]));
				mpPoint = &mPoint[mPointCnt];
			}
			break;
		default:
			//�G�t�F�N�g����
			new CEffect(mPosition, 1.0f, 1.0f, TextureExp, 4, 4, 1);
			mHp--;
		}
//�폜		mEnabled = false;
	}
}
