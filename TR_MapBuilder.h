#pragma once
#include "TR_Monster.h"
#include "TR_Player.h"
#include "TR_Battle.h"

class CMapBuilder
{
private:
	CBattle* m_pBattle;
	CMonster* m_pMonster;
public:
	CMapBuilder();
	~CMapBuilder();
	void Initialize();
	void Update();
	void Release();
	void Map_Home(CPlayer* _pPlayer);
	void Map_Shop(CPlayer* _pPlayer);
	void Map_Shop_Equip(CPlayer* _pPlayer);
	void Map_Shop_Consumable(CPlayer* _pPlayer);
	void Map_Dungeon(CPlayer* _pPlayer);
};