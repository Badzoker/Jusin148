#pragma once
#include "TR_Item.h"
class CItem_Consumable : public CItem
{
public:
	CItem_Consumable();
	virtual ~CItem_Consumable();
	void Initialize(bool _isHealPotion);
	virtual void Update();
	virtual void Release();
	virtual void Render();
};

