#ifndef CCUBE_H
#define CCUBE_H

#include "CCharacter.h"
//06
#include "CCollider.h"

#include <vector>

class CCube : public CCharacter {
public:
	//�R���C�_�̒ǉ�
	CCollider mColTriangle[12];
	//�R���X�g���N�^�ŏ����ݒ�
	CCube(CModel *model, const CVector &position, const CVector &rotation, const CVector &scale);
	~CCube();

//	void Render() {}
};



#endif
