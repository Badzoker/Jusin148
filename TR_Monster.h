#pragma once
#include "TR_Struct.h"

class CMonster
{
private:
	INFO* pInfo;
public:
	CMonster();
	~CMonster();
	void Initialize(int _iChoose);
	void Update();
	void Release();
	int Attack() { return pInfo->iAttack; }
	void Damaged(int _iDamage);
	int Reward() { return pInfo->iMaxHp; }
	INFO* Get_Info() { return pInfo; }
};