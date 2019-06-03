#include "CSceneGame.h"
#include "CUI.h"
#include "CEnemy.h"
#include "CShootBoss.h"


std::vector<CCharacter*> CSceneGame::mCharacters;

//���\�b�h�i�v���O�����j�̒�`

CSceneGame::CSceneGame() 
{
	new CBackGround(0, 0, 1280, 1024);
	new CPlayer(0, -200, 64, 64);
//	new CBoss(-300, 200, 179, 240);
}

CSceneGame::~CSceneGame() {
	//�����ȃL�����폜
	std::vector<CCharacter*>::iterator itr = mCharacters.begin();
	while (itr != mCharacters.end()) {
		delete *itr;
		itr = mCharacters.erase(itr);
	}
}


void CSceneGame::Init() {
	mFrame = 0;
	CUI::mFont.Set("Font.tga", 1, 64, 16, 33);
}

void CSceneGame::Update() {
	mFrame++;
	mFrame %= 40;
	if (mFrame == 0) {
		CEnemy *e = new CEnemy();
		e->SetPosition(-400, 250);
		e->SetSize(48, 72);
	}
	//�X�V����
	for (int i = 0; i < mCharacters.size(); i++) {
		mCharacters[i]->Update();
	}
	//�Փˏ���
	for (int i = 0; i < mCharacters.size() - 1; i++) {
		for (int j = i + 1; j < mCharacters.size(); j++) {
			mCharacters[i]->Collision(mCharacters[i], mCharacters[j]);
			mCharacters[j]->Collision(mCharacters[j], mCharacters[i]);
		}
	}
	//�����ȃL�����폜
	std::vector<CCharacter*>::iterator itr = mCharacters.begin();
	while ( itr != mCharacters.end() ) {
		if ((*itr)->mState == CCharacter::EDELETE) {
			delete *itr;
			itr = mCharacters.erase(itr);
		}
		else if ((*itr)->mState == CCharacter::EDISABLED) {
			itr = mCharacters.erase(itr);
		}
		else {
			itr++;
		}
	}
}

void CSceneGame::Render() {
	//�`�揈��
	for (int i = 0; i < mCharacters.size(); i++) {
		mCharacters[i]->Render();
	}
	CUI::Render();
}
