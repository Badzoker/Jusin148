#pragma once
#include "TR_Struct.h"

class CMonster
{
public:
	CMonster();
	~CMonster();
	void Initialize(int _iChoose);
	void Update();
	void Release();
	int Attack() { return pInfo->iAttack; }
	void Damaged(int _iDamage);
private:
	INFO* pInfo;
};