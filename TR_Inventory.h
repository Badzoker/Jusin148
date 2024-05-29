#pragma once
#include "mynamespace.h"
#include "TR_Item_Consumable.h"
#include "TR_Item_Equip.h"
class CInventory
{
public:
	CInventory();
	~CInventory();
	void Initialize();
	void Update();
	void Release();
	void Render();
	void Create_Main(JOB _eJob);
	void Create_Sub(JOB _eJob);
	void Create_Potion();
	void Create_ManaPotion();
	void Sell_Item();
private:
	const int m_iSize;
	int iCount_Item;
	vector<CItem*> m_vecItem;
	vector<CItem*>::iterator m_Itemiter;

};

