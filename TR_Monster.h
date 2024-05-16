#pragma once
#include "TR_Obj.h"

class CMonster : public CObj
{
private:
	//CToString* m_pCToString;
	//int iRandom_Armor;
public:
	CMonster();
	~CMonster();
	void Initialize(int _iChoose);
	void Render();
	//void Update();
	void Release();
	int Reward() { return m_Info->iMaxHp; }
	//int Attack() { return m_Info->iAttack; }
	//void Damaged(int _iDamage, ATTACK_TYPE _eAttacked_Type, ARMOR_TYPE _eMyArmor_Type);
	//INFO* Get_Info() { return m_Info; }
	//void Set_CToString(CToString* _pCToString) { m_pCToString = _pCToString; }
};