#include "CSceneGame.h"
//OpenGL
#include "glut.h"
//CVector�N���X�̃C���N���[�h
#include "CVector.h"
//CMatrix�N���X�̃C���N���[�h
#include "CMatrix.h"
//CTriangle�N���X�̃C���N���[�h
#include "CTriangle.h"

void CSceneGame::Init() {
	CMatrix mMatrix;
	//��]�s��̍쐬
	mMatrix.RotateZ(30);
	mMatrix.Print();
}

void CSceneGame::Update() {
	//static�ϐ��̍쐬
	static int degree = 0;//��]�p�x�̍쐬
	degree++;//�p�x��1���Z
	CMatrix matrix;//�s��쐬

	//���_1����_2����_3,�@���f�[�^�̍쐬
	CVector v0, v1, v2, n;

	//�@����������Őݒ肷��
	n.mX = 0.0f; n.mY = 1.0f; n.mZ = 0.0f;

	//���_1�̍��W��ݒ肷��
	v0.mX = 0.0f; v0.mY = 0.0f; v0.mZ = 0.5f;
	//���_2�̍��W��ݒ肷��
	v1.mX = 1.0f; v1.mY = 0.0f; v1.mZ = 0.0f;
	//���_3�̍��W��ݒ肷��
	v2.mX = 0.0f; v2.mY = 0.0f; v2.mZ = -0.5f;

	//���_�̐ݒ�
	//gluLookAt(���_X, ���_Y, ���_Z, ���SX, ���SY, ���SZ, ���X, ���Y, ���Z)
	gluLookAt(1.0f, 2.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	//�`��J�n
	//glBegin(�`)
	//GL_TRIANGLES�F�O�p�`
	glBegin(GL_TRIANGLES);

	//Y�����S�Ɋp�x������]������s���ݒ�
	matrix.RotateY(degree);
	//�@���ƒ��_����]������
	n = n.Multi(matrix);
	v0 = v0.Multi(matrix);
	v1 = v1.Multi(matrix);
	v2 = v2.Multi(matrix);

	//�@���i�ʂ̌����j�̐ݒ�
	//glNormal3f(X���W, Y���W, Z���W)
	glNormal3f(n.mX, n.mY, n.mZ);
	//���_���W�̐ݒ�
	//glVertex3f(X���W, Y���W, Z���W)
	glVertex3f(v0.mX, v0.mY, v0.mZ);
	glVertex3f(v1.mX, v1.mY, v1.mZ);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	//�@���ƒ��_�̐ݒ�
	n.Set(0.0f, 0.0f, 1.0f);
	v0.Set(0.5f, 0.0f, 0.0f);
	v1.Set(0.0f, 1.0f, 0.0f);
	v2.Set(-0.5f, 0.0f, 0.0f);

	matrix.RotateZ(degree);
	//�@���ƒ��_����]������
	n = n.Multi(matrix);
	v0 = v0.Multi(matrix);
	v1 = v1.Multi(matrix);
	v2 = v2.Multi(matrix);

	//�O�p�`2�̕`��
	glNormal3f(n.mX, n.mY, n.mZ);
	glVertex3f(v0.mX, v0.mY, v0.mZ);
	glVertex3f(v1.mX, v1.mY, v1.mZ);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	//�@���ƒ��_�̐ݒ�
	n.Set(1.0f, 0.0f, 0.0f);
	v0.Set(0.0f, 0.5f, 0.0f);
	v1.Set(0.0f, 0.0f, 1.0f);
	v2.Set(0.0f, -0.5f, 0.0f);

	matrix.RotateX(degree);
	//�@���ƒ��_����]������
	n = n.Multi(matrix);
	v0 = v0.Multi(matrix);
	v1 = v1.Multi(matrix);
	v2 = v2.Multi(matrix);

	//�O�p�`3�̕`��
	glNormal3f(n.mX, n.mY, n.mZ);
	glVertex3f(v0.mX, v0.mY, v0.mZ);
	glVertex3f(v1.mX, v1.mY, v1.mZ);
	glVertex3f(v2.mX, v2.mY, v2.mZ);

	//�`��I��
	glEnd();

	//�O�p�`�N���X�̃C���X�^���X�쐬
	CTriangle t0;
	//�@���ƒ��_�̐ݒ�
	t0.SetVertex(CVector(1.0f, 0.0f, 0.5f), CVector(2.0f, 0.0f, 0.0f), CVector(1.0f, 0.0f, -0.5f));
	t0.SetNormal(CVector(0.0f, 1.0f, 0.0f));
	//�O�p�`�̕`��
	t0.Render(matrix.RotateY(degree));

	CTriangle t1;
	//�@���ƒ��_�̐ݒ�
	t1.SetVertex(CVector(0.5f, 1.0f, 0.0f), CVector(0.0f, 2.0f, 0.0f), CVector(-0.5f, 1.0f, 0.0f));
	t1.SetNormal(CVector(0.0f, 0.0f, 1.0f));
	//�O�p�`�̕`��
//	t1.Render();
	t1.Render(matrix.RotateZ(degree));

	CTriangle t2;
	//�@���ƒ��_�̐ݒ�
	t2.SetVertex(CVector(0.0f, 0.5f, 1.0f), CVector(0.0f, 0.0f, 2.0f), CVector(0.0f, -0.5f, 1.0f));
	t2.SetNormal(CVector(1.0f, 0.0f, 0.0f));
	//�O�p�`�̕`��
//	t2.Render();
	t2.Render(matrix.RotateX(degree));
}
