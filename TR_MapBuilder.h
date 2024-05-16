#pragma once
#include "TR_Battle.h"
#include "TR_GameManager.h"
//->�� �κ� �ٽ��ѹ� ����
class CMapBuilder : public CGameManager 
{
private:
	//CBattle* m_pBattle; // <-Ȯ��
	
	//CObj* m_pMonster;
	//CObj* m_pPlayer;
	//CToString* m_pCToString;

public:
	CMapBuilder();
	~CMapBuilder();
	//void Initialize();
	//void Update();
	void Release();
	void Map_Home();
	void Map_Shop();
	void Map_Shop_Equip();
	void Map_Shop_Consumable();
	void Map_Dungeon();

	//void Set_Player(CObj* _pPlayer) { m_pPlayer = _pPlayer; }
	void Set_CToString(CToString* _pCTostring) { m_pCToString = _pCTostring; }
};