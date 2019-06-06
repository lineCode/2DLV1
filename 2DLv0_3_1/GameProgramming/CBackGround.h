#ifndef CBACKGROUNG_H
#define CBACKGROUNG_H

#include "CCharacter.h"
#include "CTexture.h"

class CBackGround : public CCharacter {
	CTexture *mpTexture;
public:
	CBackGround();
	CBackGround(float x, float y, float w, float h);
	void Render();
};


#endif
