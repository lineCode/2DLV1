#ifndef CBULLET_H
#define CBULLET_H

#include "CCharacter.h"
#include "CTriangle.h"

class CBullet : public CCharacter {
public:
	//�O�p�`
	CTriangle mT;
	//���Ɖ��s���̐ݒ�
	//Set(��, ���s)
	void Set(float w, float d);
	//�X�V
	void Update();
	//�`��
	void Render();
};


#endif
