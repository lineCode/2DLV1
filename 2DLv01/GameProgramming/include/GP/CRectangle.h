#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "CTask.h"
#include "CTexture.h"

/*
CRectangle�N���X
�����`�v���O�����̒�`
*/
class CRectangle : public CTask {
public:
	float mX;//���S��X���W
	float mY;//���S��Y���W
	float mW;//���̔���
	float mH;//�����̔���

	CTexture mTexture;
//	int mRow, mCol; //�e�N�X�`�����̍s���Ɨ�

	//�`�揈���̐錾
	void Render();
	void Render(int index);
	//�R���X�g���N�^�̐錾
	CRectangle();
	CRectangle(float x, float y, float w, float h);
	//���S���W(0,0)�ŕ��ƍ������w�肷��R���X�g���N�^
	CRectangle(float w, float h);
	//Y���ł̏Փˏ���
	float CollisionY(const CRectangle &r) const;
	//6
	//X���ł̏Փˏ���
	float CollisionX(const CRectangle &r) const;
	//7
	//�l�p�`�̏Փˏ���
//	void Collision(CRectangle &r, float &mx, float &my);
//	bool Collision(CRectangle &r);
	//SetXYWH
	void SetXYWH(int posx, int posy, int width, int height);
	//LoadTexture
	void LoadTexture(char* filename);
	void LoadTexture(char* filename, int row, int col);
};

#endif
