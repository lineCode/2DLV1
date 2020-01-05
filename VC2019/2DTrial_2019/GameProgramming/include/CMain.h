#ifndef CMAIN_H
#define CMAIN_H
#include <Windows.h>
#include "glew.h"
#include "glut.h"
#include "GLFW/glfw3.h"
#include "CScene.h"

//#define WINDOW_WIDTH 800	//�E�B���h�E�̕�
//#define WINDOW_HEIGHT 600	//�E�B���h�E�̍���

class CMain {
	//
	LARGE_INTEGER last_time;	//�O��̃J�E���^�l
	LARGE_INTEGER freq;		//��b������̃J�E���^��
	LARGE_INTEGER time;		//����̃J�E���^�l

	/* display�֐�
	1�b�Ԃ�60����s�����
	*/
	void display();
	//�P�b�ԂɂU�O��`�悷��悤�ɒ��߂���
	void idle();
	GLFWwindow* window;
	CScene* mpScene;
public:
	static int mWindowWidth;
	static int mWindowHeight;
	CMain();
	virtual ~CMain();
	int Init2D(int width = 800, int height = 600);
	int Main(CScene* pscene);
};

#endif
