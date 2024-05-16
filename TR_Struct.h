#pragma once
#include "TR_Enum.h"

typedef struct tagInfo
{
	tagInfo();
	~tagInfo();
	char szName[32];
	int iCurrentHp;
	int iMaxHp;
	int iCurrentMana;
	int iMaxMana;
	int iAttack;
	int iCritical_Percent;
	int iLevel;//
	int iExp;
	int iMaxExp;//
	int iGold;

	ATTACK_TYPE eAttack_Type;
	ARMOR_TYPE eArmor_Type;
}INFO;

typedef struct tagItem
{
	tagItem();
	~tagItem();
	bool bMain_Item;
	bool bSub_Item;
	int iPotion;
	int iManaPotion;
}ITEM;

//typedef struct tagInfo_Mon
//{
//	tagInfo_Mon();
//	~tagInfo_Mon();
//	char szName[32];
//	int iCurrentHp;
//	int iMaxHp;
//	int iCurrentMana;
//	int iMaxMana;
//	int iAttack;
//	int iCritical_Percent;
//	int iExp;
//	int iGold;
//	ATTACK_TYPE eAttack_Type;
//	ARMOR_TYPE eArmor_Type;
//}INFOMON;
