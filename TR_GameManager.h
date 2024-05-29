#pragma once
#include "TR_Player.h"
#include "TR_Monster.h"
#include "TR_Obj.h"
//�Ŵ����� ��ӽ�Ų �ڽĵ�� �̸��� ���� �ָŸ�ȣ, �� �� ������ �������
class CGameManager
{
public:
	CObj* m_pMonster;
	CObj* m_pPlayer;
	int iRandom;
	CGameManager* m_pBattle;
	CToString* m_pCToString;
	SHOP* m_pShop;
public:
	CGameManager();
	virtual ~CGameManager();
	void Set_Player(CObj* _pPlayer) { m_pPlayer = _pPlayer; }//		��
	void Set_Monster(CObj* _pMonster) { m_pMonster = _pMonster; }// ��
	virtual void Update() {}
	virtual void Battle_Normal() {}
	virtual void Battle_Skill() {}
	virtual void Battle_UsingTools() {}
	void Release();
	virtual void Map_Home() {}
	virtual void Map_Shop() {}
	virtual void Map_Shop_Equip() {}
	virtual void Map_Shop_Consumable() {}
	virtual void Map_Shop_Manager() {}
	virtual void Map_Shop_Save() {}
	virtual void Map_Shop_Load() {}
	virtual void Map_Dungeon() {}
	virtual void Set_CToString(CToString* _pCTostring) {}
};

