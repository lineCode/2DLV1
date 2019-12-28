#include "CRectangle.h"
#include "glut.h"

//�`�揈���̒�`
void CRectangle::Render() {
	glPushMatrix();
	glTranslatef(mX, mY, 0.0f);
	glRotatef(mR, 0.0f, 0.0f, 1.0f);
	//�`��J�n(�l�p�`)
	glBegin(GL_QUADS);
	//���_���W�̐ݒ�
	glVertex2d(-mW, mH);
	glVertex2d(-mW, -mH);
	glVertex2d(mW, -mH);
	glVertex2d(mW, mH);
	//�`��I��
	glEnd();
	glPopMatrix();
}

void CRectangle::Render(CTexture* pTexture, float left, float right, float bottom, float top) {
	glPushMatrix();
	glTranslatef(mX, mY, 0.0f);
	glRotatef(mR, 0.0f, 0.0f, 1.0f);
	//�`��J�n(�l�p�`)

	//�e�N�X�`����L���ɂ���
	glEnable(GL_TEXTURE_2D);
	//�A���t�@�u�����h��L���ɂ���
	glEnable(GL_BLEND);
	//�u�����h���@���w��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//�e�N�X�`�����w��
	glBindTexture(GL_TEXTURE_2D, pTexture->mId);

	float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	//�F�̐ݒ�
	glColor4fv(diffuse);

	glBegin(GL_QUADS);
	glTexCoord2f(left / pTexture->mHeader.width, (pTexture->mHeader.height - top) / pTexture->mHeader.height);
	glVertex2d(-mW, mH);
	glTexCoord2f(left / pTexture->mHeader.width, (pTexture->mHeader.height - bottom) / pTexture->mHeader.height);
	glVertex2d(-mW, -mH);
	glTexCoord2f(right / pTexture->mHeader.width, (pTexture->mHeader.height - bottom) / pTexture->mHeader.height);
	glVertex2d(mW, -mH);
	glTexCoord2f(right / pTexture->mHeader.width, (pTexture->mHeader.height - top) / pTexture->mHeader.height);
	glVertex2d(mW, mH);
	glEnd();

	//�e�N�X�`�������
	glBindTexture(GL_TEXTURE_2D, 0);
	//�A���t�@�u�����h�𖳌�
	glDisable(GL_BLEND);
	//�e�N�X�`���𖳌�
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

//�R���X�g���N�^�̒�`
CRectangle::CRectangle()
: mX(0.0f)
, mY(0.0f)
, mW(1.0f)
, mH(1.0f)
, mR(0.0f)
{
}

CRectangle::CRectangle(float x, float y, float w, float h)
	: mX(x)//X���W�̑��
	, mY(y)//Y���W�̑��
	, mW(w)//���̑��
	, mH(h)//�����̑��
	, mR(0.0f)
{
}

//���S���W(0,0)�ŕ��ƍ������w�肷��R���X�g���N�^
CRectangle::CRectangle(float w, float h)
	: CRectangle(0, 0, w, h)//���̃R���X�g���N�^�̌Ăяo��
{}//���ɏ����Ȃ�

/*
CollisionY���\�b�h
�����Ǝl�p�`r��Y���ŏd�Ȃ��Ă��邩���肷��B
�d�Ȃ��Ă���ꍇ�A�d�Ȃ�Ȃ��ʒu�܂ł̈ړ��ʂ�߂��B
�d�Ȃ��Ă��Ȃ��ꍇ�A0��߂��B
*/
float CRectangle::CollisionY(const CRectangle &r) const {
	//df:�l�p�`�Ǝl�p�`�̒��S��Y�������̋��������߂�
	float df;
	//mY��r��mY���傫�������肷��
	if (mY > r.mY) {
		//�傫���l���珬�����l�������ċ��������߂�
		df = mY - r.mY;
	}
	else {
		//r��mY�̕����傫���ꍇ
		df = r.mY - mY;
	}
	//�������l�p�`�̍����̍��v��菬������ΏՓ˂��Ă���
	df = mH + r.mH - df;
	if (df > 0) {
		//�Փ˂��Ȃ��ʒu�܂Ŗ߂�
		//��ɂ��邩
		if (mY > r.mY) {
			//��Ɉړ�
			return df;
		}
		else {
			//���Ɉړ�
			return -df;
		}
	}
	//�Փ˂��Ă��Ȃ�
	return 0;
}

/*
CollisionX���\�b�h
�����Ǝl�p�`r��X���ŏd�Ȃ��Ă��邩���肷��B
�d�Ȃ��Ă���ꍇ�A�d�Ȃ�Ȃ��ʒu�܂ł̈ړ��ʂ�߂��B
�d�Ȃ��Ă��Ȃ��ꍇ�A0��߂��B
*/
float CRectangle::CollisionX(const CRectangle &r) const {
	//df:�l�p�`�Ǝl�p�`�̒��S��X�������̋��������߂�
	float df;
	//mX��r��mC���傫�������肷��
	if (mX > r.mX) {
		//�傫���l���珬�����l�������ċ��������߂�
		df = mX - r.mX;
	}
	else {
		//r��mX�̕����傫���ꍇ
		df = r.mX - mX;
	}
	//�������l�p�`�̕��̍��v��菬������ΏՓ˂��Ă���
	df = mW + r.mW - df;
	if (df > 0) {
		//�Փ˂��Ȃ��ʒu�܂Ŗ߂�
		//�E�ɂ��邩
		if (mX > r.mX) {
			//�E�Ɉړ�
			return df;
		}
		else {
			//���Ɉړ�
			return -df;
		}
	}
	//�Փ˂��Ă��Ȃ�
	return 0;
}
//7
//�l�p�`�̏Փˏ���
//void CRectangle::Collision(CRectangle &r, float &mx, float &my) {
//	//�l�p�`�Փˎ��̈ړ��ʂ����߂�
//	float x = CollisionX(r);
//	float y = CollisionY(r);
//	//�ړ��ʂ̐�Βl�����߂�
//	float absx = x, absy = y;
//	if (x < 0) absx = -x;
//	if (y < 0) absy = -y;
//	//��Βl�̏����������Ɉړ��ʂ����Z����
//	if (absx < absy) {
//		mx += x;
//	}
//	else {
//		my += y;
//	}
//}

//bool CRectangle::Collision(CRectangle &r) {
//	//�l�p�`�Փˎ��̈ړ��ʂ����߂�
//	float x = CollisionX(r);
//	float y = CollisionY(r);
//	if (x * y == 0.0f) return false;
//	return true;
//}


void CRectangle::SetXYWH(int posx, int posy, int width, int height) {
	Set(posx, posy, width, height);
}

void CRectangle::Set(int posx, int posy, int width, int height) {
	mX = posx;
	mY = posy;
	mW = width;
	mH = height;
}

//
void CRectangle::SetPosition(float x, float y) {
	mX = x;
	mY = y;
}

void CRectangle::SetSize(float sx, float sy) {
	mW = sx;
	mH = sy;
}

void CRectangle::Translate(float x, float y) {
	mX += x;
	mY += y;
}

void CRectangle::Scale(float sx, float sy) {
	mW *= sx;
	mH *= sy;
}

void CRectangle::Render(float x, float y, float w, float h, CTexture *pTexture, float left, float right, float bottom, float top) {
	glPushMatrix();
	glTranslatef(x, y, 0.0f);

	//�e�N�X�`����L���ɂ���
	glEnable(GL_TEXTURE_2D);
	//�A���t�@�u�����h��L���ɂ���
	glEnable(GL_BLEND);
	//�u�����h���@���w��
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//�e�N�X�`�����w��
	glBindTexture(GL_TEXTURE_2D, pTexture->mId);

	float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	//�F�̐ݒ�
	glColor4fv(diffuse);

	//�`��J�n(�l�p�`)
	glBegin(GL_QUADS);
	glTexCoord2f(left / pTexture->mHeader.width, (pTexture->mHeader.height - top) / pTexture->mHeader.height);
	glVertex2d(-w, h);
	glTexCoord2f(left / pTexture->mHeader.width, (pTexture->mHeader.height - bottom) / pTexture->mHeader.height);
	glVertex2d(-w, -h);
	glTexCoord2f(right / pTexture->mHeader.width, (pTexture->mHeader.height - bottom) / pTexture->mHeader.height);
	glVertex2d(w, -h);
	glTexCoord2f(right / pTexture->mHeader.width, (pTexture->mHeader.height - top) / pTexture->mHeader.height);
	glVertex2d(w, h);
	glEnd();

	//�e�N�X�`�������
	glBindTexture(GL_TEXTURE_2D, 0);
	//�A���t�@�u�����h�𖳌�
	glDisable(GL_BLEND);
	//�e�N�X�`���𖳌�
	glDisable(GL_TEXTURE_2D);

	glPopMatrix();
}

void CRectangle::Render(float x, float y, float w, float h) {
	glPushMatrix();
	glTranslatef(x, y, 0.0f);

	float diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	//�F�̐ݒ�
	glColor4fv(diffuse);

	//�`��J�n(�l�p�`)
	glBegin(GL_QUADS);
	glVertex2d(-w, h);
	glVertex2d(-w, -h);
	glVertex2d(w, -h);
	glVertex2d(w, h);
	glEnd();

	glPopMatrix();
}
