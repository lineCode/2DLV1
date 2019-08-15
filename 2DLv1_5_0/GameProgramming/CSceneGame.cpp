#include "CSceneGame.h"
#include "CBlock.h"
#include "CBackGround.h"
#include "CEnemy.h"
#include "CPlayer.h"
#include "Define.h"

std::vector<CCharacter*> CSceneGame::mCharacters;

CTexture TexBomberman;


//���\�b�h�i�v���O�����j�̒�`

#define MAP_ROW		11	//�}�b�v�̍s��
#define MAP_COL		13	//�}�b�v�̗�

CSceneGame::CSceneGame() 
{
	TexBomberman.Load("Bomberman.tga");
	int map[MAP_ROW][MAP_COL] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 1 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
	};
	for (int i = 0; i < MAP_ROW; i++) {
		for (int j = 0; j < MAP_COL; j++) {
			int x = j * CHIPSIZE * 2 + CHIPSIZE;
			int y = (-i - 1) * CHIPSIZE * 2 + CHIPSIZE;
			//�}�b�v�̍쐬
			switch (map[i][j]) {
			case 1:		// 1�̎��̓u���b�N��z�u
				//�u���b�N�̔z�u
				new CBlock(x, y, CHIPSIZE, CHIPSIZE);
				break;
			//1�@�}�b�v�̍쐬
			default:
				new CBackGround(x, y, CHIPSIZE, CHIPSIZE);
			}
		}
	}
	for (int i = 0; i < MAP_ROW; i++) {
		for (int j = 0; j < MAP_COL; j++) {
			int x = j * CHIPSIZE * 2 + CHIPSIZE;
			int y = (-i - 1) * CHIPSIZE * 2 + CHIPSIZE;
			//2�@�v���C���[�̔z�u
			if (map[i][j] == 2) {
				new CPlayer(x, y, CHIPSIZE, CHIPSIZE);
			}
			//7�@�G�̔z�u
			if (map[i][j] == 3) {
				new CEnemy(x, y, CHIPSIZE, CHIPSIZE);
			}
		}
	}
	mCamera.Camera2D(400.0f, -300.0f, 400.0f, 300.0f);
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
}
