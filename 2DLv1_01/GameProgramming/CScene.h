/*
�C���N���[�h�K�[�h
2�d�ɃC���N���[�h�����Ȃ��悤�ɂ���d�g��
#ifndef
#define
�@�`�@
#endif
*/
/*
#ifndef �}�N����
�}�N������`����Ă��Ȃ����#endif�܂ŗL��
�}�N������`����Ă����#endif�܂Ŗ���
*/
#ifndef CSCENE_H
/*
#define �}�N����
�}�N�����`����
*/
#define CSCENE_H

/*
class �N���X�� {
�N���X�̒�`
};
�N���X�̐錾�ƒ�`
*/
class CScene {
/*
�A�N�Z�X�w��q
public:
�@����ȍ~�̃����o�͂���ł��g�p�ł���
protected:
�@����ȍ~�̃����o�͎����Ǝq�����g�p�ł���
private:
�@����ȍ~�̃����o�͎����������g�p�ł���
*/
public:
	/*
	�����o�̐錾
	�N���X�ɐ錾�����ϐ��⃁�\�b�h���A
	�N���X�̃����o�ƌĂ�
	*/
	/*
	���\�b�h�̐錾
	���\�b�h�̖߂�l�̌^ ���\�b�h��(����)
	void �߂�l�Ȃ��̃��\�b�h
	���\�b�h��() �����Ȃ��̃��\�b�h
	*/
	//��x�������s�����Init���\�b�h�̐錾
	void Init();
	//�J��Ԃ����s�����Update���\�b�h�̐錾
	void Update();
};

//#ifndef�̏I���
#endif
