#ifndef CCOLLISION_H
#define CCOLLISION_H

class CRectangle;
/*
CCollision
�Փ˔�����s���܂�
*/
class CCollision {
public:
	/*
	�l�p�`�Ǝl�p�`�̏Փ˔�����s���܂�
	�߂�l�F�Փ˂��Ă���ꍇ��true�B�Փ˂��Ă��Ȃ��ꍇ��false
	col1:�l�p�`�̃C���X�^���X
	col2:�l�p�`�̃C���X�^���X
	*x,*y:�Փ˂��Ă���ꍇ�́AX����Y���ŏd�Ȃ��Ă���傫�����r���āA
	�@�@�@���������̎����A�傫�������Z����B
	*/
	static bool Collision(const CRectangle& col1, const CRectangle& col2, float *x, float*y);
	/*
	�l�p�`�Ǝl�p�`�̏Փ˔�����s���܂�
	�߂�l�F�Փ˂��Ă���ꍇ��true�B�Փ˂��Ă��Ȃ��ꍇ��false
	col1:�l�p�`�̃C���X�^���X
	col2:�l�p�`�̃C���X�^���X
	*/
	static bool Collision(const CRectangle& col1, const CRectangle& col2);
	/*
	�l�p�`�Ɖ~�̏Փ˔���
	�߂�l�F�Փ˂��Ă���ꍇ��true�B�Փ˂��Ă��Ȃ��ꍇ��false
	circ:�~�̃C���X�^���X
	rect:�l�p�`�̃C���X�^���X
	*mx,*my:�Փ˂��Ă���ꍇ�́AX����Y���ŏd�Ȃ��Ă���傫�����r���āA
	�@�@�@���������̎����A�傫�������Z����B
	 */
	static bool CollisionCR(const CRectangle& circ, const CRectangle& rect, float *mx, float*my);
};


#endif
