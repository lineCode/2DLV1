#ifndef CSCENE_H
#define CSCENE_H

class CScene {
public:
	//���z�֐��̐錾
	//�f�X�g���N�^
	virtual ~CScene();
	//Init�F����������
	virtual void Init();
	//Update�F�X�V����
	virtual void Update();
	//Render�F�`�揈��
	virtual void Render();
};

#endif
