#pragma once
#include "TR_Battle.h"
class CMainGame
{
private:
	CMonster* m_pMonster;
	CPlayer* m_pPlayer;
	CBattle* m_pBattle;
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