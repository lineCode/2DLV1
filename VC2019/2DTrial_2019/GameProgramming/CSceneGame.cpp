#include "CScene.h"
#include "CUI.h"
#include "CShootBoss.h"
#include "CEnemyShot.h"
#include "CEffect.h"
#include "CScene.h"
#include "CPlayer.h"
#include "CBackGround.h"
#include "CBoss.h"
#include "CTexture.h"
#include "CEnemy.h"
#include "CCamera.h"

//���\�b�h�i�v���O�����j�̒�`
CTexture TexPlayer;
CTexture TexEnemy;
CTexture TexShot;
CTexture TexBackGround;
CTexture TexExplosion;
CTexture TexBoss;

//�N���X�̒�`
class CSceneGame : public CScene {
public:
	CCamera mCamera;
	//�ϐ��̐錾
	CTexture mTexBackGround;
	CRectangle mBackGround;
	CTexture mTexFighters;
	CRectangle mPlayer;
	CRectangle mEnemy;
	CBoss mBoss;
	CInput mInput;

	CSceneGame();

	//���\�b�h�i�v���O�����j�̐錾
	void Update();
	void Render();
};


CSceneGame::CSceneGame() 
{
//	TexBackGround.Load("BackGround.tga");
	mTexBackGround.Load("bg_space_seamless.tga");
	TexShot.Load("Shoot.tga");
	TexEnemy.Load("Enemy.tga");
//	TexPlayer.Load("Player.tga");
	mTexFighters.Load("4_fighters_sprites.tga");
	TexExplosion.Load("Explosion.tga");
	TexBoss.Load("Boss.tga");

	mBackGround.Set(400, 300, 640, 512);
//	mBackGround.mpTexture = &TexBackGround;

	mPlayer.Set(400, 100, 32, 32);

	mEnemy.Set(100, 600, 18, 32);


	mBoss.Set(300, 450, 80, 120);
	mBoss.mpTexture = &TexBoss;

	for (int i = 0; i < 5; i++) {
		CPlayerShot::mShot[i].mpTexture = &TexShot;
		CEnemyShot::mShot[i].mpTexture = &TexShot;
	}

//	CUI::mFont.Set("Font.tga", 1, 64, 16, 33);
}

//CSceneGame::~CSceneGame() {
//}


//void CSceneGame::Init() {
//}

void CSceneGame::Update() {
	//�X�V����

	//Enemy
	mEnemy.mX += 2;
	mEnemy.mY -= 2;
	if (mEnemy.mY < 0.0f) {
		mEnemy.mX -= 300;
		mEnemy.mY = 600.0f;
	}
	if (mEnemy.mX > 800.0f) {
		mEnemy.mX -= 700;
		mEnemy.mY = 600.0f;
	}

	//Player
	if (mInput.Key('A')) {
		mPlayer.mX -= 3;
	}
	if (mInput.Key('D')) {
		mPlayer.mX += 3;
	}



}

void CSceneGame::Render() {
	mCamera.Camera2D(400.0f, 300.0f, 400.0f, 300.0f);
	//�`�揈��
	mBackGround.Render(&mTexBackGround);
	mPlayer.Render(&mTexFighters, 1, 46, 63, 0);
	mEnemy.Render(&mTexFighters, 165, 200, 0, 63);
//	mBoss.Render();
}
