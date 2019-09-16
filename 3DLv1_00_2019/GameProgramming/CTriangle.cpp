#include "CTriangle.h"
#include "glut.h"

//���_���W�ݒ�
//SetVertex(���_1, ���_2, ���_3)
void CTriangle::SetVertex(const CVector &v0, const CVector &v1, const CVector &v2) {
	mV[0] = v0;
	mV[1] = v1;
	mV[2] = v2;
}

//�@���ݒ�
//SetNormal(�@���x�N�g��)
void CTriangle::SetNormal(const CVector &n) {
	mN = n;
}

//�`��
void CTriangle::Render() {
	glBegin(GL_TRIANGLES);
	glNormal3f(mN.mX, mN.mY, mN.mZ);
	glVertex3f(mV[0].mX, mV[0].mY, mV[0].mZ);
	glVertex3f(mV[1].mX, mV[1].mY, mV[1].mZ);
	glVertex3f(mV[2].mX, mV[2].mY, mV[2].mZ);
	glEnd();
}

//Render(�s��)
void CTriangle::Render(const CMatrix &m) {
	//���_�Ɩ@���̍쐬
	CVector V[3], N;
	//�s����|����
	V[0] = mV[0] * m;
	V[1] = mV[1] * m;
	V[2] = mV[2] * m;
	N = mN * m;
	//���Z��̍��W�ŕ`�悷��
	glBegin(GL_TRIANGLES);
	glNormal3f(N.mX, N.mY, N.mZ);
	glVertex3f(V[0].mX, V[0].mY, V[0].mZ);
	glVertex3f(V[1].mX, V[1].mY, V[1].mZ);
	glVertex3f(V[2].mX, V[2].mY, V[2].mZ);
	glEnd();
}
