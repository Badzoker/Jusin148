#pragma once
#include "TR_MapBuilder.h"
#include "TR_GameManager.h"
#include "TR_Inventory.h"
#include "TR_Quest.h"
class CMainGame
{
private:
	CObj* m_pPlayer;
	CGameManager* m_pMapBuilder;
	CInventory* m_pInven;
	CQuest* m_pQuest;
public:
	CMainGame();
	~CMainGame();
	void Initialize();
	void Update();
	void Release();
	void Menu();
};