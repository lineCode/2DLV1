#include "CInput.h"
#include "windows.h"//WindowsAPI���g�p����
/*
int CInput::Key(char key)
key�̃L�[���A������Ă�����1��߂�
key�̃L�[���A������Ă��Ȃ����0��߂�
key:�L�[�̒l
*/
int CInput::Key(char key) {
	//key��������Ă����0�ȊO�ɂȂ�
	if ((GetKeyState(key) & 0x8000) != 0) {
		//������Ă���̂�1��߂�
		return 1;
	}
	//������Ă��Ȃ��̂�0��߂�
	return 0;
}
