#include "CSceneGame.h"
//OpenGL
#include "glut.h"

void CSceneGame::Init() {
}

void CSceneGame::Update() {
	//���_�̐ݒ�
	//gluLookAt(���_X, ���_Y, ���_Z, �ڕWX, �ڕWY, �ڕWZ, ���X, ���Y, ���Z)
	gluLookAt(1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	//�`��J�n
	//glBegin(�`)
	//GL_TRIANGLES�F�O�p�`
	glBegin(GL_TRIANGLES);

	//�@���i�ʂ̌����j�̐ݒ�
	//glNormal3f(X���W, Y���W, Z���W)
	glNormal3f(0.0f, 1.0f, 0.0f);

	//���_���W�̐ݒ�
	//glVertex3f(X���W, Y���W, Z���W)
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, -0.5f);

	//�ʂ̌�����Z������
	glNormal3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glVertex3f(-0.5f, 0.0f, 0.0f);

	glNormal3f(1.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(0.0f, 0.0f, 1.0f);
	glVertex3f(0.0f, -0.5f, 0.0f);

	//�`��I��
	glEnd();
}
