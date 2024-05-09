#pragma once
#include "TR_Battle.h"
#include "TR_MapBuilder.h"
class CMainGame
{
private:
	CMonster* m_pMonster;
	CPlayer* m_pPlayer;
	CMapBuilder* m_pMapBuilder;
public:
	CMainGame();
	~CMainGame();
	void Initialize();
	void Update();
	void Release();
	void Menu();
	void Home();
	void Shop();
	void Shop_Equip();
	void Shop_Consumable();
	void Dungeon();
	void Fight();
};