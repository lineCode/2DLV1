#ifndef CEFFECT_H
#define CEFFECT_H

#include "CCharacter.h"
#include "CTexture.h"

class CEffect : public CCharacter {
	int mIndex;
public:
	static CEffect mEffect[5];
	CTexture *mpTexture;
	CEffect();
	CEffect(float x, float y, float w, float h);
	void Update();
	void Render();
};

#endif