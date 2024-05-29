#pragma once
#include "TR_Enum.h"

typedef struct tagInfo
{
	tagInfo();
	~tagInfo() {}
	char szName[32];
	int iCurrentHp;
	int iMaxHp;
	int iCurrentMana;
	int iMaxMana;
	int iAttack;
	int iCritical_Percent;
	int iExp;
	int iLevel;// 몬스터한텐
	int iMaxExp;// 필요없음
	int iGold;
	JOB eJob;
	ATTACK_TYPE eAttack_Type;
	ARMOR_TYPE eArmor_Type;
}INFO;

typedef struct tagItem
{
	tagItem();
	~tagItem() {}
	bool bMain_Item;
	bool bMain_Item_Equiped;
	bool bSub_Item;
	bool bSub_Item_Equiped;
	int iPotion;
	int iManaPotion;
}ITEM;

typedef struct tagShop
{
	tagShop();
	~tagShop() {}
	bool bIs_Main; // main이냐 sub냐
	char szName[32];
	int iGold;
	int iCount;
}SHOP;

typedef struct tagItemInfo
{
	tagItemInfo();
	~tagItemInfo() {}
	char szName[32];
	int iAttack;
	int iHealth;
	int iGold;
	ITEM_TYPE eItem_Type;
}ITEMINFO;