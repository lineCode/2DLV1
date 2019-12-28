#include "CCamera.h"
#include "glut.h"

void CCamera::Camera2D() {
	glMatrixMode(GL_PROJECTION);	//�s����v���W�F�N�V�������[�h�֕ύX
	glLoadIdentity();				//�s���������
	gluOrtho2D(mX - mW, mX + mW, mY - mH, mY + mH);	//2D�̉�ʂ�ݒ�
	glMatrixMode(GL_MODELVIEW);		//�s������f���r���[���[�h�֕ύX
	glLoadIdentity();				//�s���������
}

void CCamera::Camera2D(float x, float y, float w, float h) {
	mX = x;
	mY = y;
	mW = w;
	mH = h;
	Camera2D();
}
