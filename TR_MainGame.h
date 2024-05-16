#pragma once
#include "TR_MapBuilder.h"
#include "TR_GameManager.h"
class CMainGame
{
private:
	CObj* m_pPlayer;
	CGameManager* m_pMapBuilder;
	//CToString* m_pCToString;
public:
	CMainGame();
	~CMainGame();
	void Initialize();
	void Update();
	void Release();
	void Menu();
};