#ifndef CCAMERA_H
#define CCAMERA_H

class CCamera {
	float mX, mY, mW, mH;
public:
	/*
	Camera2D
	2D�̃J������ݒ肷��
	x:�`�悷��G���A�̒��S���W
	y:�`�悷��G���A�̒��S���W
	w:�`�悷��G���A�̕�
	h:�`�悷��G���A�̍���
	*/
	void Camera2D(float x, float y, float w, float h);
	void Camera2D();
};


#endif
