/*
�C���N���[�h�K�[�h
2�d�ɃC���N���[�h�����Ȃ��悤�ɂ���d�g��
#ifndef �}�N����
#define �}�N����
�@�`�@
#endif
*/

#ifndef CSCENE_H
/*
#ifndef CSCENE_H

�}�N����`�̃`�F�b�N
#ifndef �}�N����
�}�N������`����Ă��Ȃ����#endif�܂ŗL��
�}�N������`����Ă����#endif�܂Ŗ���
*/

#define CSCENE_H
/*
#define CSCENE_H

�}�N�����`����
#define �}�N����
*/

//CScene�N���X�̐錾�ƒ�`
class CScene {
/*
class CScene {

�N���X�̐錾�ƒ�`
class �N���X�� {
	�N���X�̒�`
};
*/

public:
/*
public:

�A�N�Z�X�w��q
public:
�@����ȍ~�̃����o�͂���ł��g�p�ł���
protected:
�@����ȍ~�̃����o�͎����Ǝq�����g�p�ł���
private:
�@����ȍ~�̃����o�͎����������g�p�ł���
*/

	/* �����o�̐錾
	�N���X�Ő錾�����ϐ��⃁�\�b�h���A
	�N���X�̃����o�ƌĂ�
	*/

	//��x�������s�����Init���\�b�h�̐錾
	void Init();
	/*
	void Init();

	���\�b�h�̐錾
	���\�b�h�̖߂�l�̌^ ���\�b�h��(����)
	void �߂�l�Ȃ��̃��\�b�h
	���\�b�h��() �����Ȃ��̃��\�b�h
	*/

	//�J��Ԃ����s�����Update���\�b�h�̐錾
	void Update();
};

//#ifndef�̏I���
#endif
