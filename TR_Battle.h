#pragma once
#include "mynamespace.h"
#include "TR_Monster.h"
#include "TR_Player.h"

class CBattle
{
private:
	
public:
	CBattle();
	~CBattle();
	void Initialize();
	void Update();
	void Release();
	void Battle_Map(CPlayer* _pPlayer, CMonster* _pMonster);
	void Battle_Normal(CPlayer* _pPlayer, CMonster* _pMonster);
	void Battle_Skill(CPlayer* _pPlayer, CMonster* _pMonster);
	void Battle_UsingTools(CPlayer* _pPlayer);
};