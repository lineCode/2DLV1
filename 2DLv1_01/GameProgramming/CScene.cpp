/*
�w�b�_�t�@�C���̃C���N���[�h
#include "�C���N���[�h�t�@�C����"
*/
#include "CScene.h"
//printf�֐��̃C���N���[�h
#include <stdio.h>
//gl�֐��̃C���N���[�h
#include "glut.h"

//��x�������s�����Init���\�b�h�̒�`
void CScene::Init() {
	/*
	printf(������);
	��������R���\�[����ʂ֏o�͂���
	*/
	printf("Init()");
}

//�J��Ԃ����s�����Update���\�b�h�̒�`
void CScene::Update() {
	printf("Update()\n");
	/*
	�l�p�`�̕`��
	*/
	/*
	�`��w��̊J�n
	glBegin(mode)
	mode:GL_QUADS �l�p�`�̕`��
	*/
	glBegin(GL_QUADS);
	/*
	���_���W�̎w��
	glVertex2f(x,y)
	x�FX���W
	y�FY���W
	*/
	glVertex2f(-50.0f, 50.0f);
	glVertex2f(-50.0f, -50.0f);
	glVertex2f(50.0f, -50.0f);
	glVertex2f(50.0f, 50.0f);
	/*
	�`��w��̏I��
	glEnd()
	*/
	glEnd();
}
