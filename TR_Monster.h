#pragma once
#include "TR_Struct.h"
#include "mynamespace.h"
#include "TR_Obj.h"
class CMonster : public CObj
{
private:
	//INFOMON* m_pInfo;
	int iRandom;
	CToString* m_pCToString;
public:
	CMonster();
	~CMonster();
	void Initialize(int _iChoose);
	void Render();
	//void Update();
	void Release();
	//int Attack() { return m_Info->iAttack; }
	//void Damaged(int _iDamage, ATTACK_TYPE _eAttacked_Type, ARMOR_TYPE _eMyArmor_Type);
	int Reward() { return m_Info->iMaxHp; }
	INFO* Get_Info() { return m_Info; }
	void Set_CToString(CToString* _pCToString) { m_pCToString = _pCToString; }
};