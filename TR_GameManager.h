#pragma once
#include "TR_Player.h"
#include "TR_Monster.h"

class CGameManager
{
public:
	CMonster* m_pMonster_GameManager;
	CPlayer* m_pPlayer_GameManager;
	
public:
	CGameManager();
	~CGameManager();
	void Set_Player(CPlayer* _pPlayer) { m_pPlayer_GameManager = _pPlayer; }
	void Set_Monster(CMonster* _pMonster) { m_pMonster_GameManager = _pMonster; }
};

