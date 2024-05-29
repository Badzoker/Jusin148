#pragma once
#include "TR_Battle.h"
#include "TR_GameManager.h"
//->이 부분 다시한번 질문
class CMapBuilder : public CGameManager 
{
private:

public:
	CMapBuilder();
	virtual ~CMapBuilder();
	void Release();
	void Map_Home();
	void Map_Shop();
	void Map_Shop_Equip();
	void Map_Shop_Consumable();
	void Map_Shop_Inventory();
	void Map_Shop_Manager();
	void Map_Shop_Save();
	void Map_Shop_Load();
	void Map_Dungeon();
	void Set_CToString(CToString* _pCTostring) { m_pCToString = _pCTostring; }
};