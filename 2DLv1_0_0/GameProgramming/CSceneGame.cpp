//CSceneGame�N���X�̃C���N���[�h
#include "CSceneGame.h"
//CRectangle�N���X�̃C���N���[�h
#include "CRectangle.h"
/*
Update���\�b�h
1�t���[���̍X�V�������s��
*/
void CSceneGame::Update() {
	//���߂̋L�q
	/*
	�����`��`�悷�郁�\�b�h���Ă�
	���S���W(80,60)�A��160�A����120
	*/
	CRectangle::Render(80, 60, 80, 60);
	//�����`�̒ǉ�
	CRectangle::Render(-80, -60, 80, 60);
	CRectangle::Render(-80-160, 60, 80, 60);
	CRectangle::Render(80 + 160, -60, 80, 60);
}

