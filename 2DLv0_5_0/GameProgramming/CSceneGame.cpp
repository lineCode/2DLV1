#include "CSceneGame.h"
#include "CUI.h"
#include "CTextureManager.h"
#include "CBlock.h"

std::vector<CCharacter*> CSceneGame::mCharacters;

CTexture TexBG;
CTexture TexTile;
CTexture TexPlayer;

//���\�b�h�i�v���O�����j�̒�`

CSceneGame::CSceneGame() 
{
	CTextureManager::Load();
	TexBG.Load("BG.tga");
	TexTile.Load("Tile.tga");
	TexPlayer.Load("Player2.tga");
	for (int i = -360; i < 400; i += 80) {
		for (int j = 280; j > -300; j -= 80) {
			if (j == 280 || j == -280) {
				new CBlock(i, j, 80.0f, 80.0f);
			}
			else if (i == -360 || i == 360) {
				new CBlock(i, j, 80.0f, 80.0f);
			}
		}
	}
}

CSceneGame::~CSceneGame() {
	//�S�ẴL�����폜
	std::vector<CCharacter*>::iterator itr = mCharacters.begin();
	while (itr != mCharacters.end()) {
		delete *itr;
		itr = mCharacters.erase(itr);
	}
}


void CSceneGame::Init() {
	CUI::mFont.Set("Font.tga", 1, 64, 16, 33);
}

void CSceneGame::Update() {
	//�X�V����
	for (int i = 0; i < mCharacters.size(); i++) {
		mCharacters[i]->Update();
	}
	//�Փˏ���
	for (int i = 0; i < mCharacters.size(); i++) {
		for (int j = i + 1; j < mCharacters.size(); j++) {
			mCharacters[i]->Collision(mCharacters[i], mCharacters[j]);
			mCharacters[j]->Collision(mCharacters[j], mCharacters[i]);
		}
	}
	//�����ȃL�����폜
	std::vector<CCharacter*>::iterator itr = mCharacters.begin();
	while ( itr != mCharacters.end() ) {
		if ((*itr)->mState == CCharacter::EENABLED) {
			itr++;
		}
		else {
			delete *itr;
			itr = mCharacters.erase(itr);
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
