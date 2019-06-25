#include "CSceneGame.h"
#include "CUI.h"
#include "CEnemy.h"
#include "CShootBoss.h"

//���\�b�h�i�v���O�����j�̒�`
CTexture TexPlayer;
CTexture TexEnemy;
CTexture TexShoot;
CTexture TexBackGround;
CTexture TexExplosion;
CTexture TexBoss;

CSceneGame::CSceneGame() 
{
	TexBackGround.Load("BackGround.tga");
	TexShoot.Load("Shoot.tga");
	TexEnemy.Load("Enemy.tga");
	TexPlayer.Load("Player.tga");
	TexExplosion.Load("Explosion.tga");
	TexBoss.Load("Boss.tga");

	int enemyPos[][2] = {
		{ -300, 300 },
		{ -150, 300 },
		{ 0, 300 },
		{ 150, 300 },
		{ 300, 300 },

		{ -250, 200 },
		{ -100, 200 },
//		{ -50, 200 },
//		{ 50, 200 },
		{ 100, 200 },
		{ 250, 200 },
	};
	mBackGround.Set(400, 300, 640, 512);
	mPlayer.Set(400, 100, 32, 32);
	mEnemy.Set(500, 300, 24, 36);
	mBoss.Set(300, 450, 80, 120);
//	CUI::mFont.Set("Font.tga", 1, 64, 16, 33);
}

CSceneGame::~CSceneGame() {
}


void CSceneGame::Init() {
}

void CSceneGame::Update() {
	//�X�V����
	mPlayer.Update();
	mEnemy.Update();
	mBoss.Update();
}

void CSceneGame::Render() {
	mCamera.Camera2D(400.0f, 300.0f, 400.0f, 300.0f);
	//�`�揈��
	mBackGround.Render();
	mPlayer.Render();
	mEnemy.Render();
	mBoss.Render();
//	CUI::Render();
}
