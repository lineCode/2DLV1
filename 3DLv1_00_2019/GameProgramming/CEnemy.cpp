#include "CEnemy.h"
//�G�t�F�N�g�N���X�̃C���N���[�h
#include "CEffect.h"

//�X�}�[�g�|�C���^�̊O���Q��
extern std::shared_ptr<CTexture> TextureExp;

//�R���X�g���N�^
//CEnemy(���f��, �ʒu, ��], �g�k)
CEnemy::CEnemy(CModel *model, CVector position, CVector rotation, CVector scale)
: mCollider(this, CVector(0.0f, 0.0f, 1.0f), CVector(0.0f, 0.0f, 0.0f),
CVector(1.0f / scale.mX, 1.0f / scale.mY, 1.0f / scale.mZ), 0.8f),
mHp(20)
{
	//���f���A�ʒu�A��]�A�g�k��ݒ肷��
	mpModel = model;	//���f���̐ݒ�
	mPosition = position;	//�ʒu�̐ݒ�
	mRotation = rotation;	//��]�̐ݒ�
	mScale = scale;	//�g�k�̐ݒ�
}
//�X�V����
void CEnemy::Update() {
	//�s����X�V
	CCharacter::Update();
	//�ʒu���ړ�
	mPosition = CVector(0.0f, 0.0f, 1.0f) * mMatrix;
	//��]������
	mRotation.mY += 0.5f;

	if (mHp < 0) {
		mHp--;
		mRotation.mX += 0.1;
		if (mHp % 10 == 0) {
			new CEffect(mPosition, 1.5f, 1.5f, TextureExp, 4, 4, 2);
		}
	}
}

void CEnemy::Collision(CCollider *m, CCollider *y) {
	if (CCollider::Collision(m, y)) {
		//�G�t�F�N�g����
		new CEffect(mPosition, 1.0f, 1.0f, TextureExp, 4, 4, 1);
		mHp--;
//�폜		mEnabled = false;
	}
}
