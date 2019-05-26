#include "CRectangle.h"
#include "glut.h"

//�`�揈���̒�`
void CRectangle::Render() {
	if (mpTexture) {
		Render(*mpTexture, 0);
	}
	else {
		Render(0);
	}
}

void CRectangle::Render(int index) {
	if (mpTexture) {
		Render(*mpTexture, index);
	}
	else if (mTexture.mId) {
		mTexture.DrawImage(mX - mW, mX + mW, mY - mH, mY + mH, index);
	}
	else {
		//�`��J�n(�l�p�`)
		glBegin(GL_QUADS);
		//���_���W�̐ݒ�
		glVertex2d(mX - mW, mY + mH);
		glVertex2d(mX - mW, mY - mH);
		glVertex2d(mX + mW, mY - mH);
		glVertex2d(mX + mW, mY + mH);
		//�`��I��
		glEnd();
	}
}
//�R���X�g���N�^�̒�`
CRectangle::CRectangle()
: mX(0.0f)
, mY(0.0f)
, mW(1.0f)
, mH(1.0f)
, mpTexture(0)
{
}

CRectangle::CRectangle(float x, float y, float w, float h)
	: mX(x)//X���W�̑��
	, mY(y)//Y���W�̑��
	, mW(w / 2.0f)//���̑��
	, mH(h / 2.0f)//�����̑��
	, mpTexture(0)
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
//6
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
	mX = posx;
	mY = posy;
	mW = width / 2.0f;
	mH = height / 2.0f;
}

void CRectangle::Set(int posx, int posy, int width, int height) {
	SetXYWH(posx, posy, width, height);
}

void CRectangle::LoadTexture(char* filename) {
	if (mTexture.mId) {
		mTexture.Destory();
	}
	mTexture.Load(filename);
}

void CRectangle::LoadTexture(char* filename, int row, int col) {
	if (mTexture.mId) {
		mTexture.Destory();
	}
	mTexture.Load(filename);
	mTexture.SetParts(row, col);
}

void CRectangle::Render(CTexture& texture) {
	Render(texture, 0);
}

void CRectangle::Render(CTexture& texture, int index) {
	if (texture.mId) {
		texture.DrawImage(mX - mW, mX + mW, mY - mH, mY + mH, index);
	}
	else {
		//�`��J�n(�l�p�`)
		glBegin(GL_QUADS);
		//���_���W�̐ݒ�
		glVertex2d(mX - mW, mY + mH);
		glVertex2d(mX - mW, mY - mH);
		glVertex2d(mX + mW, mY - mH);
		glVertex2d(mX + mW, mY + mH);
		//�`��I��
		glEnd();
	}
}

void CRectangle::SetTexture(CTexture *texture) {
	mpTexture = texture;
}

void CRectangle::SetPosition(float x, float y) {
	mX = x;
	mY = y;
}

void CRectangle::SetSize(float sx, float sy) {
	mW = sx / 2.0f;
	mH = sy / 2.0f;
}

void CRectangle::Translate(float x, float y) {
	mX += x;
	mY += y;
}

void CRectangle::Scale(float sx, float sy) {
	mW *= sx;
	mH *= sy;
}
