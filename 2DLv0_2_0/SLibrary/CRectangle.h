#ifndef CRECTANGLE_H
#define CRECTANGLE_H

#include "CTexture.h"

/*
CRectangle�N���X
�����`�v���O�����̒�`
*/
class CRectangle {
protected:
	CTexture mTexture;
	CTexture* mpTexture;
public:
	float mX;//���S��X���W
	float mY;//���S��Y���W
	float mW;//���̔���
	float mH;//�����̔���
	float mR;//��]�l

	//	int mRow, mCol; //�e�N�X�`�����̍s���Ɨ�

	//�`�揈���̐錾
	void Render();
	void Render(int index);
	void Render(CTexture& texture);
	void Render(CTexture& texture, int index);
	//�R���X�g���N�^�̐錾
	CRectangle();
	CRectangle(float x, float y, float w, float h);
	//���S���W(0,0)�ŕ��ƍ������w�肷��R���X�g���N�^
	CRectangle(float w, float h);
	//Y���ł̏Փˏ���
	float CollisionY(const CRectangle &r) const;
	//X���ł̏Փˏ���
	float CollisionX(const CRectangle &r) const;
	//SetXYWH
	void SetXYWH(int posx, int posy, int width, int height);
	/*
	Set
	posx:X���W posy:Y���W width:�� height:����
	*/
	void Set(int posx, int posy, int width, int height);
	//LoadTexture
	void LoadTexture(char* filename);
	void LoadTexture(char* filename, int row, int col);
	//SetTexture
	void SetTexture(CTexture *texture);
	//SetPosition
	void SetPosition(float x, float y);
	void SetSize(float sx, float sy);
	void Translate(float x, float y);
	void Scale(float sx, float sy);

};

#endif
