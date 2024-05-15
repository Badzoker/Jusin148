#pragma once
#include "mynamespace.h"
#include "TR_Struct.h"
class CObj
{
public:
	INFO* m_Info;
	//char szName[32];
	//int iCurrentHp;
	//int iMaxHp;
	//int iCurrentMana;
	//int iMaxMana;
	//int iAttack;
	//int iCritical_Percent;
	//int iLevel;//
	//int iExp;
	//int iMaxExp;//
	//int iGold;

	//ATTACK_TYPE eAttack_Type;
	//ARMOR_TYPE eArmor_Type;
public:
	CObj();
	~CObj();
	void Damaged(CObj* _Attacker, int _iDamage);
	int Attack();
};

