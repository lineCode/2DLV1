#include "CMain2D.h"

#include "CScene.h"
#include "CTexture.h"
#include "CCamera.h"
#include "CRectangle.h"
#include "CInput.h"

//�N���X�̒�`
//�Q�[���V�[���N���X�̒�`
class CSceneGame : public CScene {
public:
	//�ϐ��̐錾
	CCamera mCamera;//��ʐݒ�̃C���X�^���X
	CTexture mTexBackGround;//�w�i�摜�̃C���X�^���X
	CRectangle mBackGround;//�w�i�l�p�`�̃C���X�^���X
	CTexture mTexFighters;//�퓬�@�摜�̃C���X�^���X
	CRectangle mPlayer;//�v���C���[�l�p�`�̃C���X�^���X
	CRectangle mEnemy;//�G�l�p�`�̃C���X�^���X
	CInput mInput;//���͏����̃C���X�^���X

	//�f�t�H���g�R���X�g���N�^
	CSceneGame();

	//���\�b�h�i�v���O�����j�̐錾
	void Update();//�X�V����
	void Render();//�`�揈��
};

//�f�t�H���g�R���X�g���N�^
//�ŏ��ɂP�x�������s���鏈��
CSceneGame::CSceneGame()
{
	mTexBackGround.Load("bg_space_seamless.tga");
	mTexFighters.Load("4_fighters_sprites.tga");

	mBackGround.Set(200, 300, 640, 512);

	mPlayer.Set(200, 100, 32, 32);

	mEnemy.Set(100, 600, 18, 32);

	mCamera.Camera2D(200.0f, 300.0f, 200.0f, 300.0f);
}

//�X�V����
//�J��Ԃ����s���鏈��
void CSceneGame::Update() {
	//Enemy
	mEnemy.mX += 2;
	mEnemy.mY -= 4;
	if (mEnemy.mY < mCamera.GetBottom2D()) {
		mEnemy.mY = mCamera.GetTop2D();
	}
	if (mEnemy.mX > mCamera.GetRight2D()) {
		mEnemy.mX = mCamera.GetLeft2D();
	}

	//Player
	if (mInput.Key('A')) {
		mPlayer.mX -= 3.0f;
	}
	if (mInput.Key('D')) {
		mPlayer.mX += 3.0f;
	}
}

//�`�揈��
//�J��Ԃ��`�悷�鏈��
void CSceneGame::Render() {
	//��ʐݒ�
	mCamera.Camera2D(200.0f, 300.0f, 200.0f, 300.0f);
	//�`�揈��
	mBackGround.Render(&mTexBackGround);
	mPlayer.Render(&mTexFighters, 1, 46, 63, 0);
	mEnemy.Render(&mTexFighters, 165, 200, 0, 63);
}

/*
main�֐�
C����v���O�����̊J�n
*/
int main(void)
{
	//2D��ʐݒ� ���F400�@�c�F600
	CMain2D main(400, 600);
	//�Q�[���V�[���̃C���X�^���X����
	main.SetScene(new CSceneGame());
}
