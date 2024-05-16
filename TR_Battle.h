#pragma once
#include "TR_GameManager.h"
#include <ctime>

class CBattle : public CGameManager
{
private:
	//CPlayer* m_pPlayer;
	//CMonster* m_pMonster;
	int iRandom;
public:
	CBattle();
	~CBattle();
	void Update();
	//void Initialize();
	//void Release();
	void Battle_Normal();
	void Battle_Skill();
	void Battle_UsingTools();
	//void Set_Player(CPlayer* _pPlayer) { m_pPlayer = _pPlayer; }
	//void Set_Monster(CMonster* _pMonster) { m_pMonster = _pMonster; }
};