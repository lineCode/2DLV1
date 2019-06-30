#include "CMain.h"
//#include "CTask.h"
#include "CCamera.h"

//////////////////////////////WinInet http connection
#include <windows.h>
#include <Wininet.h>

#include <assert.h>
#include <string>
#include <sstream>
#include <locale.h>
#include <conio.h>
//#include "NhConversion.h"

#pragma comment( lib, "Wininet.lib" )

typedef std::basic_string<TCHAR>		tstring;
typedef std::basic_stringstream<TCHAR>	tstringstream;

#define URLBUFFER_SIZE		(4096)
#define	READBUFFER_SIZE		(4096)

bool HttpRequest(tstring strUserAgent,
	tstring strUrl,
	bool bIsHttpVerbGet,
	tstring strParameter,
	tstring& rstrResult)
{
	// �A�E�g�v�b�g�̏�����
	rstrResult = tstring();

	// �C���v�b�g�̃`�F�b�N
	if (0 == strUrl.length())
	{
		assert(!"URL���s��");
		return false;
	}

	// �ϐ�
	HINTERNET			hInternetOpen = NULL;
	HINTERNET			hInternetConnect = NULL;
	HINTERNET			hInternetRequest = NULL;
	char*				pszOptional = NULL;
	URL_COMPONENTS		urlcomponents;
	tstring				strServer;
	tstring				strObject;
	INTERNET_PORT		nPort;
	tstring				strVerb;
	tstring				strHeaders;
	tstringstream		ssRead;

	// URL���
	ZeroMemory(&urlcomponents, sizeof(URL_COMPONENTS));
	urlcomponents.dwStructSize = sizeof(URL_COMPONENTS);
	TCHAR szHostName[URLBUFFER_SIZE];
	TCHAR szUrlPath[URLBUFFER_SIZE];
	urlcomponents.lpszHostName = szHostName;
	urlcomponents.lpszUrlPath = szUrlPath;
	urlcomponents.dwHostNameLength = URLBUFFER_SIZE;
	urlcomponents.dwUrlPathLength = URLBUFFER_SIZE;
	if (!InternetCrackUrl(strUrl.c_str(),
		(DWORD)strUrl.length(),
		0,
		&urlcomponents))
	{	// URL�̉�͂Ɏ��s
		assert(!"URL��͂Ɏ��s");
		return false;
	}
	strServer = urlcomponents.lpszHostName;
	strObject = urlcomponents.lpszUrlPath;
	nPort = urlcomponents.nPort;

	// HTTP��HTTPS������ȊO��
	DWORD dwFlags = 0;
	if (INTERNET_SCHEME_HTTP == urlcomponents.nScheme)
	{	// HTTP
		dwFlags = INTERNET_FLAG_RELOAD				// �v�����ꂽ�t�@�C���A�I�u�W�F�N�g�A�܂��̓t�H���_�ꗗ���A�L���b�V������ł͂Ȃ��A���̃T�[�o�[���狭���I�Ƀ_�E�����[�h���܂��B
			| INTERNET_FLAG_DONT_CACHE			// �Ԃ��ꂽ�G���e�B�e�B���L���V���֒ǉ����܂���B
			| INTERNET_FLAG_NO_AUTO_REDIRECT;	// HTTP �����Ŏg�p����A���_�C���N�g�� HttpSendRequest �ŏ�������Ȃ����Ƃ��w�肵�܂��B
	}
	else if (INTERNET_SCHEME_HTTPS == urlcomponents.nScheme)
	{	// HTTPS
		dwFlags = INTERNET_FLAG_RELOAD				// �v�����ꂽ�t�@�C���A�I�u�W�F�N�g�A�܂��̓t�H���_�ꗗ���A�L���b�V������ł͂Ȃ��A���̃T�[�o�[���狭���I�Ƀ_�E�����[�h���܂��B
			| INTERNET_FLAG_DONT_CACHE			// �Ԃ��ꂽ�G���e�B�e�B���L���V���֒ǉ����܂���B
			| INTERNET_FLAG_NO_AUTO_REDIRECT	// HTTP �����Ŏg�p����A���_�C���N�g�� HttpSendRequest �ŏ�������Ȃ����Ƃ��w�肵�܂��B
			| INTERNET_FLAG_SECURE						// ���S�ȃg�����U�N�V�������g�p���܂��B����ɂ��ASSL/PCT ���g���悤�ɕϊ�����AHTTP �v�������ŗL���ł��B 
			| INTERNET_FLAG_IGNORE_CERT_DATE_INVALID	// INTERNET_FLAG_IGNORE_CERT_DATE_INVALID�AINTERNET_FLAG_IGNORE_CERT_CN_INVALID
			| INTERNET_FLAG_IGNORE_CERT_CN_INVALID;		// �́A�ؖ����Ɋւ���x���𖳎�����t���O
	}
	else
	{
		assert(!"HTTP�ł�HTTPS�ł��Ȃ�");
		return false;
	}

	// GET��POST��
	if (bIsHttpVerbGet)
	{	// GET
//		strVerb = _T("GET");
		strVerb = ("GET");
//		strHeaders = _T("");
		strHeaders = ("");
		if (0 != strParameter.length())
		{	// �I�u�W�F�N�g�ƃp�����[�^���u?�v�ŘA��
//			strObject += _T("?") + strParameter;
			strObject += ("?") + strParameter;
		}
	}
	else
	{	// POST
//		strVerb = _T("POST");
		strVerb = ("POST");
//		strHeaders = _T("Content-Type: application/x-www-form-urlencoded");
		strHeaders = ("Content-Type: application/x-www-form-urlencoded");
		if (0 != strParameter.length())
		{	// �p�����[�^���A���M����I�v�V�����f�[�^�ɕϊ�����
//			pszOptional = NhT2M(strParameter.c_str());	// char������ɕϊ�
			pszOptional = (char *)(strParameter.c_str());	// char������ɕϊ�
		}
	}

	// WinInet�̏�����
	hInternetOpen = InternetOpen(strUserAgent.c_str(),
		INTERNET_OPEN_TYPE_PRECONFIG,
		NULL, NULL, 0);
	if (NULL == hInternetOpen)
	{
		assert(!"WinInet�̏������Ɏ��s");
		goto LABEL_ERROR;
	}

	// HTTP�ڑ�
	hInternetConnect = InternetConnect(hInternetOpen,
		strServer.c_str(),
		nPort,
		NULL,
		NULL,
		INTERNET_SERVICE_HTTP,
		0,
		0);
	if (NULL == hInternetConnect)
	{
		assert(!"HTTP�ڑ��Ɏ��s");
		goto LABEL_ERROR;
	}

	// HTTP�ڑ����J��
	hInternetRequest = HttpOpenRequest(hInternetConnect,
		strVerb.c_str(),
		strObject.c_str(),
		NULL,
		NULL,
		NULL,
		dwFlags,
		NULL);
	if (NULL == hInternetRequest)
	{
		assert(!"HTTP�ڑ����J���Ɏ��s");
		goto LABEL_ERROR;
	}

	// HTTP�v�����M
	if (!HttpSendRequest(hInternetRequest,
		strHeaders.c_str(),
		(DWORD)strHeaders.length(),
		(LPVOID)((char*)pszOptional),
		pszOptional ? (DWORD)(strlen(pszOptional) * sizeof(char)) : 0))
	{
		assert(!"HTTP�v�����M�Ɏ��s");
		goto LABEL_ERROR;
	}

	// HTTP�v���ɑΉ�����X�e�[�^�X�R�[�h�̎擾
	DWORD dwStatusCode;
	DWORD dwLength = sizeof(DWORD);
	if (!HttpQueryInfo(hInternetRequest,
		HTTP_QUERY_STATUS_CODE | HTTP_QUERY_FLAG_NUMBER,
		&dwStatusCode,
		&dwLength,
		0))
	{
		assert(!"HTTP�v���ɑΉ�����X�e�[�^�X�R�[�h�̎擾�Ɏ��s");
		goto LABEL_ERROR;
	}
	if (HTTP_STATUS_OK != dwStatusCode)
	{
		assert(!"�X�e�[�^�X�R�[�h��OK�łȂ�");
		goto LABEL_ERROR;
	}

	// HTTP�t�@�C���ǂݍ���
	char szReadBuffer[READBUFFER_SIZE + 1];
	while (1)
	{
		DWORD dwRead = 0;
		if (!InternetReadFile(hInternetRequest, szReadBuffer, READBUFFER_SIZE, &dwRead))
		{
			assert(!"HTTP�t�@�C���ǂݍ��݂Ɏ��s");
			goto LABEL_ERROR;
		}
		if (0 == dwRead)
		{
			break;
		}
		szReadBuffer[dwRead] = '\0';	// �I�[�����u\0�v�̕t��
		size_t length = dwRead + 1;
//		LPWSTR	pszWideChar = (LPWSTR)malloc(length * sizeof(WCHAR));
		//MultiByteToWideChar(CP_UTF8,	// CODE PAGE: UTF-8
		//	0,
		//	szReadBuffer,
		//	-1,
		//	pszWideChar,
		//	(int)length);	// UTF-8�������ANSI������ɕϊ�
//		TCHAR* pszTchar = NhW2T(pszWideChar);	// WideChar�������TCHAR������ɕϊ�
//		TCHAR* pszTchar = (TCHAR*)(pszWideChar);	// WideChar�������TCHAR������ɕϊ�
//		ssRead << pszTchar;	// �X�g���[��������ɗ�������
		ssRead << szReadBuffer;	// �X�g���[��������ɗ�������
//		free(pszTchar);
//		free(pszWideChar);
	}

	// �X�g���[����������A�o�͕�����ɕϊ�
	rstrResult = ssRead.str().c_str();

	if (pszOptional){ free(pszOptional); }
	InternetCloseHandle(hInternetRequest);
	InternetCloseHandle(hInternetConnect);
	InternetCloseHandle(hInternetOpen);
	return true;

LABEL_ERROR:
	if (pszOptional){ free(pszOptional); }
	InternetCloseHandle(hInternetRequest);
	InternetCloseHandle(hInternetConnect);
	InternetCloseHandle(hInternetOpen);
	return false;
}




/*�E�B���h�E�T�C�Y�ύX���̏���
void reshape(int width, int height)
width:��ʕ�
height:��ʍ���
*/
void reshape2D(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);	//��ʂ̕`��G���A�̎w��
	CCamera camera;
	camera.Camera2D(0.0f, 0.0f, width / 2.0f, height / 2.0f);
	//glMatrixMode(GL_PROJECTION);	//�s����v���W�F�N�V�������[�h�֕ύX
	//glLoadIdentity();				//�s���������
	//gluOrtho2D(-width / 2, width / 2, -height / 2, height / 2);	//2D�̉�ʂ�ݒ�
	////	gluPerspective(75.0, (double)width / (double)height, 1.0, 1000.0);	//3D�̉�ʂ�ݒ�

	//glMatrixMode(GL_MODELVIEW);		//�s������f���r���[���[�h�֕ύX
	//glLoadIdentity();				//�s���������
}


CMain::CMain() 
	: mpScene(0)
{
//	last_time.QuadPart = 0;
	//��b�Ԃ̃J�E���^�����擾
	QueryPerformanceFrequency(&freq);

	QueryPerformanceCounter(&last_time);
}

CMain::~CMain() {
//	CTaskManager::Get()->Destroy();
	glfwTerminate();
	if (mpScene) {
		delete mpScene;
		mpScene = 0;
	}
}

#include <stdio.h>
int CMain::Init2D(int width, int height) {
	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Programming GP", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);


	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	// GLEW ������������
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		// GLEW �̏������Ɏ��s����
		//		std::cerr << "Can't initialize GLEW" << std::endl;
		return 1;
	}
	// ���������̃^�C�~���O��҂�  
	//glfwSwapInterval(1); 


	//	glEnable(GL_DEPTH_TEST);	//3D�K�v 2D�s�v
	glEnable(GL_CULL_FACE);

	// �E�B���h�E�̃T�C�Y�ύX���ɌĂяo�������̓o�^
	glfwSetWindowSizeCallback(window, reshape2D);
	reshape2D(window, width, height);

	//���C�g�̐ݒ�i3D�K�v 2D�s�v�j
	//�Œ�V�F�[�_�[�p
	//	glEnable(GL_LIGHTING);
	//	glEnable(GL_LIGHT0);
	//���b�V���V�F�[�_�[�p
	//	CLight::getLight(0)->setDir(CVector3(0, -1, 1).GetNormalize());
	//	CLight::getLight(0)->setColor(CVector3(0.9f, 0.9f, 0.9f), CVector3(1.0f, 1.0f, 1.0f));

	printf("Copyright 2019 Programming GP\n");

	return 0;
}

/* display�֐�
1�b�Ԃ�60����s�����
*/
void CMain::display() {

	//�e�o�b�t�@�[���N���A
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
	//�s��̃��[�h�����f���r���[�ɂ���
	glMatrixMode(GL_MODELVIEW);
	//���f���r���[�̍s���P�ʍs��ɂ���
	glLoadIdentity();

//	CTaskManager::Get()->Update();
	mpScene->Update();
//	CTaskManager::Get()->Collision();
//	CTaskManager::Get()->Remove();
//	CTaskManager::Get()->Render();
	mpScene->Render();
}

//�P�b�ԂɂU�O��`�悷��悤�ɒ��߂���
void CMain::idle() {

	//��b�Ԃ̃J�E���^�����擾
	//QueryPerformanceFrequency(&freq);

	//if (last_time.QuadPart == 0) {
	//	QueryPerformanceCounter(&last_time);
	//}
	do{
		//���݂̃V�X�e���̃J�E���g�����擾
		QueryPerformanceCounter(&time);

		//���̃J�E���g-�O��̃J�E���g < 1�b������̃J�E���g����60�Ŋ���(1/60�b������̃J�E���g��)
	} while (time.QuadPart - last_time.QuadPart < freq.QuadPart / 60);
	last_time = time;

	//�`�悷��֐����Ă�
	display();
}

int CMain::Main2D(CScene* pscene)
{
/////////////////////////////////////////////////////////////////
//	tstring strUserAgent = _T("HttpRequestTest");
	tstring strUserAgent = ("HttpRequestTest");
//	tstring strUrl = _T("http://weather.livedoor.com/forecast/webservice/json/v1");
	tstring strUrl = ("http://gama-programming-jp.jupk2ppz9p.us-west-2.elasticbeanstalk.com/");
	bool bIsHttpVerbGet = true;
//	tstring strParameter = _T("city=400040");
	tstring strParameter = ("city=400040");

	tstring strResult;

	goto Skip;

	if (!HttpRequest(strUserAgent,
		strUrl,
		bIsHttpVerbGet,
		strParameter,
		strResult))
	{
		return false;
	}

	setlocale(LC_ALL, "Japanese");
//	_tprintf(_T("%s"), strResult.c_str());
	printf("%s", strResult.c_str());
////////////////////////////////////////////////////
Skip:
	mpScene = pscene;

	mpScene->Init();
	//mScene.Init();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{

		idle();

		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

//	CTaskManager::Get()->Destroy();

//	delete mpScene;

//	glfwTerminate();

	return 0;
}
