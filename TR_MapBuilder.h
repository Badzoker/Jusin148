#pragma once
#include "TR_Monster.h"
#include "TR_Player.h"
#include "TR_Battle.h"
#include "mynamespace.h"

class CMapBuilder
{
private:
	CBattle* m_pBattle;
	CMonster* m_pMonster;
	CPlayer* m_pPlayer;
	CToString* m_pCToString;
	
public:
	CMapBuilder();
	~CMapBuilder();
	void Initialize();
	void Update();
	void Release();
	void Map_Home();
	void Map_Shop();
	void Map_Shop_Equip();
	void Map_Shop_Consumable();
	void Map_Dungeon();

	void Set_Player(CPlayer* _pPlayer);
};