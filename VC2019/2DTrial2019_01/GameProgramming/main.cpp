#include "CMain2D.h" //CMain2D�N���X�̃C���N���[�h
#include "CScene.h" //CScene�N���X�̃C���N���[�h
#include "CRectangle.h" //�l�p�`�N���X�̃C���N���[�h

//�Q�[���V�[���N���X�̒�`
class CSceneGame : public CScene {
public:
	//�ϐ��̐錾
	CRectangle mPlayer; //CRectangle�N���X�̕ϐ�mPlayer��錾

	//�f�t�H���g�R���X�g���N�^�̐錾
	CSceneGame();
	//�X�V���\�b�h�̐錾
	void Update();
	//�`�惁�\�b�h�̐錾
	void Render();
};

/*
�f�t�H���g�R���X�g���N�^�̒�`
�ŏ��ɂP�x�������s���鏈��
*/
CSceneGame::CSceneGame() {
	//�v���C���[�̐ݒ�
	//X���W�F0 Y���W�F-200 ���F32 �����F32
	mPlayer.Set(0, -200, 32, 32);
}

/*
�X�V���\�b�h�̒�`
�J��Ԃ����s���鏈��
*/
void CSceneGame::Update() {
}

/*
�`�惁�\�b�h�̒�`
�J��Ԃ��`�悷�鏈��
*/
void CSceneGame::Render() {
	//�v���C���[�̕`��
	mPlayer.Render();

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
