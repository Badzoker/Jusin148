#pragma once
#include "TR_Item.h"
class CItem_Equip : public CItem
{
public:
	CItem_Equip();
	virtual ~CItem_Equip();
	void Initialize(bool _isMain, JOB _eJob);
	virtual void Update();
	virtual void Release();
	virtual void Render();
private:
	
};

