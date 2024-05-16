#pragma once
#include "TR_Player.h"
#include "TR_Monster.h"
#include "TR_Obj.h"

class CGameManager
{
public:
	CObj* m_pMonster_GameManager;
	CObj* m_pPlayer_GameManager;
	//Battle
	int iRandom;
	//MapBuilder
	//CBattle* m_pBattle; <-È®ÀÎ
	CGameManager* m_pBattle;
	CToString* m_pCToString;
public:
	CGameManager();
	~CGameManager();
	void Set_Player(CObj* _pPlayer) { m_pPlayer_GameManager = _pPlayer; }
	void Set_Monster(CObj* _pMonster) { m_pMonster_GameManager = _pMonster; }
	//Battle
	virtual void Update();
	//void Initialize();
	//void Release();
	virtual void Battle_Normal();
	virtual void Battle_Skill();
	virtual void Battle_UsingTools();
	//MapBuilder
	//void Initialize();
	//void Update();
	virtual void Release();
	virtual void Map_Home();
	virtual void Map_Shop();
	virtual void Map_Shop_Equip();
	virtual void Map_Shop_Consumable();
	virtual void Map_Dungeon();

	//void Set_Player(CObj* _pPlayer) { m_pPlayer = _pPlayer; }
	virtual void Set_CToString(CToString* _pCTostring);
};

