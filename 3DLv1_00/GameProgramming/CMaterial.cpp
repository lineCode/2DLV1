#include "CMaterial.h"
#include "glut.h"

CMaterial::CMaterial()
: mpName(0)
, mVertexNo(0)
{
}

CMaterial::~CMaterial() {
	if (mpName) {
		delete mpName;
	}
}

void CMaterial::SetMaterial() {
	
//	glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, mAmbient);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, mDiffuse);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, mSpecular);
//	glMaterialfv(GL_FRONT_AND_BACK, GL_EMISSION, mEmission);
//	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, mShinness);
//	glMaterialfv(GL_FRONT, GL_AMBIENT, mAmbient);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mDiffuse);
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mSpecular);
//	glMaterialfv(GL_FRONT, GL_EMISSION, mEmission);
//	glMaterialf(GL_FRONT, GL_SHININESS, mShinness);
	if (mTexture.mId) {
		//�e�N�X�`�����g�p�\�ɂ���
		glEnable(GL_TEXTURE_2D);
		//�e�N�X�`�����o�C���h����
		glBindTexture(GL_TEXTURE_2D, mTexture.mId);
	}
}

void CMaterial::UnSetMaterial() {
	if (mTexture.mId) {
		//�e�N�X�`���̃o�C���h������
		glBindTexture(GL_TEXTURE_2D, 0);
		//�e�N�X�`���𖳌��ɂ���
		glDisable(GL_TEXTURE_2D);
	}
}

void CMaterial::SetTexture(char *file) {
	mTexture.Load(file);
}


