#include "CRectangle.h"
#include "glut.h"

//�`�揈���̒�`
void CRectangle::Render() {
	//�`��J�n(�l�p�`)
	glBegin(GL_QUADS);
	//���_���W�̐ݒ�
	glVertex2d(300, 300);
	glVertex2d(300, 200);
	glVertex2d(400, 200);
	glVertex2d(400, 300);
	//�`��I��
	glEnd();
}
