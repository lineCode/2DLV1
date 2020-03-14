#include "CSceneGame.h"
//OpenGL
#include "glut.h"
//
#include "CCamera.h"
//
#include "CText.h"
//
#include "CRes.h"


//�X�}�[�g�|�C���^�̐���
std::shared_ptr<CTexture> TextureExp(new CTexture());

CSceneGame::~CSceneGame() {

}


void CSceneGame::Init() {
	//�e�L�X�g�t�H���g�̓ǂݍ��݂Ɛݒ�
	CText::mFont.Load("FontG.tga");
	CText::mFont.SetRowCol(1, 4096 / 64);
	//���f���t�@�C���̓���
	CRes::sBackGround.Load("sky.obj", "sky.mtl");
}


void CSceneGame::Update() {
	//�J�����̃p�����[�^���쐬����
	CVector e, c, u;//���_�A�����_�A�����
	//���_�����߂�
	e = CVector(-2.0f, 10.0f, -30.0f);
	//�����_�����߂�
	c = CVector();
	//����������߂�
	u = CVector(0.0f, 1.0f, 0.0f);
	//�J�����N���X�̐ݒ�
	Camera.Set(e, c, u);
	Camera.Render();

	CRes::sBackGround.Render(CMatrix());

	//2D�`��J�n
	Start2D(0, 800, 0, 600);

	CText::DrawString("PLAYER DAMAGE ", 20, 50, 10, 12);
	CText::DrawString("AIRBASE DAMAGE", 20, 20, 10, 12);

	//2D�`��I��
	End2D();

	return;
}

//2D�`��X�^�[�g
//Start2D(�����W, �E���W, �����W, ����W)
void CSceneGame::Start2D(float left, float right, float bottom, float top) {
	//���f���r���[�s��̑ޔ�
	glPushMatrix();
	//���f���r���[�s��̏�����
	glLoadIdentity();

	//���f���r���[�s�񂩂�
	//�v���W�F�N�V�����s��֐؂�ւ�
	glMatrixMode(GL_PROJECTION);
	//�v���W�F�N�V�����s��̑ޔ�
	glPushMatrix();
	//�v���W�F�N�V�����s��̏�����
	glLoadIdentity();
	//2D�`��̐ݒ�
	gluOrtho2D(left, right, bottom, top);
	//Depth�e�X�g�I�t
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_LIGHTING);
	glColor3f(1.0f, 1.0f, 1.0f);
}

//2D�`��I��
void CSceneGame::End2D() {
	//�v���W�F�N�V�����s���߂�
	glPopMatrix();
	//���f���r���[���[�h�֐؂�ւ�
	glMatrixMode(GL_MODELVIEW);
	//���f���r���[�s���߂�
	glPopMatrix();
	//Depth�e�X�g�I��
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);

}
