#pragma once
#include "TR_Struct.h"

class CMonster
{
private:
	INFOMON* m_pInfo;
public:
	CMonster();
	~CMonster();
	void Initialize(int _iChoose);
	void Render();
	//void Update();
	void Release();
	int Attack() { return m_pInfo->iAttack; }
	void Damaged(int _iDamage);
	int Reward() { return m_pInfo->iMaxHp; }
	INFOMON* Get_Info() { return m_pInfo; }
};