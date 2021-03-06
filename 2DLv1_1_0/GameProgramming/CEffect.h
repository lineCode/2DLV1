#ifndef CEFFECT_H
#define CEFFECT_H

#include "CCharacter.h"

class CEffect : public CCharacter {
	CTexture *mpTexture;
	int mIndex;
public:
	CEffect();
	CEffect(float x, float y, float w, float h);
	void Update();
	void Render();
};

#endif
