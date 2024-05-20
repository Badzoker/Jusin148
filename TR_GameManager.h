#pragma once
#include "TR_Player.h"
#include "TR_Monster.h"
#include "TR_Obj.h"
//상속후 오버라이딩 완료 -> 할당해제할 때 문제가 가장 자주 일어나므로 자주 확인 및 정확히 확인하슈
//매니저의 상속시킨 자식들과 이름이 뭔가 애매모호, 즉 다 뒤집어 엎어야함
class CGameManager
{
public:
	CObj* m_pMonster;
	CObj* m_pPlayer;
	//Battle==========
	int iRandom;
	//MapBuilder==========
	//CBattle* m_pBattle; <-확인
	CGameManager* m_pBattle;
	CToString* m_pCToString;
	SHOP* m_pShop;
public:
	CGameManager();
	virtual ~CGameManager();
	void Set_Player(CObj* _pPlayer) { m_pPlayer = _pPlayer; }//		공
	void Set_Monster(CObj* _pMonster) { m_pMonster = _pMonster; }// 용
	//Battle========
	virtual void Update();
	//void Initialize();
	//void Release();
	virtual void Battle_Normal();
	virtual void Battle_Skill();
	virtual void Battle_UsingTools();
	//MapBuilder===========
	//void Initialize();
	//void Update();
	/*virtual*/ void Release();
	virtual void Map_Home();
	virtual void Map_Shop();
	virtual void Map_Shop_Equip();
	virtual void Map_Shop_Consumable();
	virtual void Map_Shop_Manager();
	virtual void Map_Shop_Save();
	virtual void Map_Shop_Load();
	virtual void Map_Dungeon();
	//void Set_Player(CObj* _pPlayer) { m_pPlayer = _pPlayer; }
	virtual void Set_CToString(CToString* _pCTostring);
};

