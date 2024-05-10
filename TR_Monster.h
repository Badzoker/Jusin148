#pragma once
#include "TR_Struct.h"
#include "mynamespace.h"
class CMonster
{
private:
	INFOMON* m_pInfo;
	int iRandom;
	CToString* m_pCToString;
public:
	CMonster();
	~CMonster();
	void Initialize(int _iChoose);
	void Render();
	//void Update();
	void Release();
	int Attack() { return m_pInfo->iAttack; }
	void Damaged(int _iDamage, ATTACK_TYPE _eAttacked_Type, ARMOR_TYPE _eMyArmor_Type);
	int Reward() { return m_pInfo->iMaxHp; }
	INFOMON* Get_Info() { return m_pInfo; }
	void Set_CToString(CToString* _pCToString) { m_pCToString = _pCToString; }
};