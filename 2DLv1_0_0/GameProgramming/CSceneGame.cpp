#include "CSceneGame.h"
#include "CUI.h"
#include "CShootBoss.h"
#include "CEnemyShot.h"
#include "CEffect.h"

//�e�N�X�`���̕ϐ����쐬
CTexture TexPlayer;	//�v���C���[
CTexture TexEnemy;	//�G
CTexture TexShot;	//�V���b�g
CTexture TexBackGround;	//�w�i
CTexture TexExplosion;	//����
CTexture TexBoss;	//�{�X

/*
�f�t�H���g�R���X�g���N�^
�C���X�^���X�̏�������
*/
CSceneGame::CSceneGame() 
{
	//�J�����̐ݒ�
	mCamera.Camera2D(400.0f, 300.0f, 400.0f, 300.0f);
	//�e�N�X�`���̓ǂݍ���
	TexBackGround.Load("BackGround.tga");	//�w�i
	TexShot.Load("Shoot.tga");	//�V���b�g
	TexEnemy.Load("Enemy.tga");	//�G
	TexPlayer.Load("Player.tga");	//�v���C���[
	TexExplosion.Load("Explosion.tga");	//����
	TexBoss.Load("Boss.tga");	//�{�X

	//�I�u�W�F�N�g�̔z�u�ƃe�N�X�`���̐ݒ�
	//�w�i
	mBackGround.Set(400, 300, 640, 512);
	mBackGround.mpTexture = &TexBackGround;
	//�v���C���[
	mPlayer.Set(400, 100, 32, 32);
	mPlayer.mpTexture = &TexPlayer;
	mPlayer.mEffect.mpTexture = &TexExplosion;
	//�G
	mEnemy.Set(500, 300, 24, 36);
	mEnemy.mpTexture = &TexEnemy;
	mEnemy.mEffect.mpTexture = &TexExplosion;
	//�{�X
	mBoss.Set(300, 450, 80, 120);
	mBoss.mpTexture = &TexBoss;
	mBoss.mEffect.mpTexture = &TexExplosion;
	//�V���b�g
	for (int i = 0; i < 5; i++) {
		CPlayerShot::mShot[i].mpTexture = &TexShot;
		CEnemyShot::mShot[i].mpTexture = &TexShot;
	}
}

/*
Update���\�b�h
1�t���[���̍X�V�������s��
*/
void CSceneGame::Update() {
	//�X�V����
	mPlayer.Update();
	mEnemy.Update();
	mBoss.Update();
	for (int i = 0; i < 5; i++) {
		CPlayerShot::mShot[i].Update();
		CEnemyShot::mShot[i].Update();
	}
	//�Փˏ���
	mPlayer.Collision(&mPlayer, &mEnemy);
	for (int i = 0; i < 5; i++) {
		mPlayer.Collision(&mPlayer, &CEnemyShot::mShot[i]);
		mEnemy.Collision(&mEnemy, &CPlayerShot::mShot[i]);
		mBoss.Collision(&mBoss, &CPlayerShot::mShot[i]);
	}
}

/*
Render���\�b�h
1�t���[���̕`����s��
*/
void CSceneGame::Render() {
	//�J�����ݒ�
	mCamera.Camera2D();
	//�`�揈��
	mBackGround.Render();
	mPlayer.Render();
	mEnemy.Render();
	mBoss.Render();
	for (int i = 0; i < 5; i++) {
		CPlayerShot::mShot[i].Render();
		CEnemyShot::mShot[i].Render();
	}
}
