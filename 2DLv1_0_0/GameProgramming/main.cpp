#include "CMain2D.h"
#include "CSceneGame.h"

/*
main�֐�
�v���O�����ōŏ��ɌĂ΂��֐�
*/
int main(void)
{
	//2D�p���C���v���O�����̃C���X�^���Xmain���쐬
	CMain2D main;
	//CSceneGame�N���X�̃C���X�^���X�𐶐����A
	//���C���v���O�����̃V�[����ݒ肷��
	main.SetScene(new CSceneGame());
}
