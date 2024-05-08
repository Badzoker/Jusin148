#pragma once
#include "mynamespace.h"
#include "TR_Player.h"
#include "TR_Monster.h"
class CMainGame
{
private:
	CMonster* m_pMonster;
	CPlayer* m_pPlayer;
public:
	CMainGame();
	~CMainGame();
	void Initialize();
	void Update();
	void Release();
	void Save();
	void Menu();
	void Home();
	void Shop();
	void Shop_Equip();
	void Shop_Consumable();
	void Dungeon();
	void Fight();
};