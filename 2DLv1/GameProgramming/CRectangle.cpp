#include "CRectangle.h"
#include "glut.h"

//�`�揈���̒�`
void CRectangle::Render() {
	//�`��J�n(�l�p�`)
	glBegin(GL_QUADS);
	//���_���W�̐ݒ�
	glVertex2d(mPx - mSx, mPy + mSy);
	glVertex2d(mPx - mSx, mPy - mSy);
	glVertex2d(mPx + mSx, mPy - mSy);
	glVertex2d(mPx + mSx, mPy + mSy);
	//�`��I��
	glEnd();
}
