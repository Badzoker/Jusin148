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
	int iLevel;
	int iExp;
	int iMaxExp;
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

