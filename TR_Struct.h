#pragma once
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
	int iLevel;
	int iExp;
	int iMaxExp;
}INFO;

typedef struct tagInfo_Mon
{
	tagInfo_Mon();
	~tagInfo_Mon();
	char szName[32];
	int iCurrentHp;
	int iMaxHp;
	int iCurrentMana;
	int iMaxMana;
	int iAttack;
	int iCritical_Percent;
	int iExp;
	int iGold;
}INFOMON;

typedef struct tagItem
{
	tagItem();
	~tagItem();
	bool bMain_Item;
	bool bSub_Item;
	int iPotion;
	int iManaPotion;
	int iGold;
}ITEM;

