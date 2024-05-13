#pragma once
#include "mynamespace.h"
#include "TR_Monster.h"
#include "TR_Player.h"
#include <ctime>

class CBattle
{
private:
	CPlayer* m_pPlayer;
	CMonster* m_pMonster;
	int iRandom;
public:
	CBattle();
	~CBattle();
	void Initialize();
	void Update();
	void Release();
	void Battle_Normal();
	void Battle_Skill();
	void Battle_UsingTools();
	void Set_Player(CPlayer* _pPlayer);
	void Set_Monster(CMonster* _pMonster);
};