#pragma once
#include "mynamespace.h"
#include "TR_Struct.h"
class CObj
{
public:
	INFO* m_Info;
public:
	CObj();
	~CObj();
	void Damaged(int _iDamage, ATTACK_TYPE _eAttacked_Type, ARMOR_TYPE _eMyArmor_Type, INFO* _tTarget);
	int Attack(int _iAttack_Damage);
};

