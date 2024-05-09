#pragma once
#include "TR_Monster.h"
#include "TR_Player.h"
#include "TR_Battle.h"

class CMapBuilder
{
private:
	CBattle* m_pBattle;
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
};