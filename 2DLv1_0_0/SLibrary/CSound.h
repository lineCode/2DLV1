#pragma once

/*
�T�E���h�N���X
�T�E���h�t�@�C����ǂݍ��݁A�Đ�����B
*/
class CSound {
	//�I�[�f�B�I�t�@�C�����̕ۑ�
	char	 file[100];
	//�t�@�C���I�[�v���̌���
	int result;
	/*
	�T�E���h��WindowsAPI�����s����
	*/
	void sendstring(char* w);
public:
	CSound();
	/*
	�t�@�C���̓ǂݍ���
	*/
	void Load(char	*filename);
	/*
	�T�E���h�Đ��i1��̂݁j
	*/
	void Play();
	/*
	�T�E���h�Đ��i���s�[�g�j
	*/
	void Repeat();
	/*
	�T�E���h��~
	*/
	void Stop();
	/*
	�t�@�C���̃N���[�Y
	*/
	void Close();
	/*
	�f�X�g���N�^
	*/
	~CSound();
};
