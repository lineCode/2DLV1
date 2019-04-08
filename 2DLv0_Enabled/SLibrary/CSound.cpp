#include "CSound.h"

CSound::CSound()
{
	result = 0;
}
/*
�T�E���h��WindowsAPI�����s����
*/
void CSound::sendstring(char* w) {
	if (!result) {
		//���ߕҏW�̈�̍쐬
		char	 buf[100];
		//���ߕҏW
		sprintf(buf, w, file);
		//���ߎ��s
		result = mciSendString(buf, NULL, 0, NULL);
	}
}
/*
�t�@�C���̓ǂݍ���
*/
void CSound::Load(char	*filename)
{
	//�t�@�C�����ۑ�
	strcpy(file, filename);
	sendstring("open %s");
}
/*
�T�E���h�Đ��i1��̂݁j
*/
void CSound::Play()
{
	sendstring("play %s from 0");
}
/*
�T�E���h�Đ��i���s�[�g�j
*/
void CSound::Repeat()
{
	sendstring("play %s from 0 repeat");
}
/*
�T�E���h��~
*/
void CSound::Stop()
{
	sendstring("stop %s");
}
/*
�t�@�C���̃N���[�Y
*/
void CSound::Close()
{
	sendstring("close %s");
}
/*
�f�X�g���N�^
*/
CSound::~CSound()
{
	Stop();		//��~����
	Close();	//�t�@�C�����N���[�Y����
}
