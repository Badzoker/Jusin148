#pragma once
#include "mynamespace.h"
class CItem
{
public:
	CItem() { m_pItemInfo = nullptr; }
	virtual ~CItem() { Release(); }
	void Initialize();
	//virtual void Update();
	virtual void Release() { Safe_Delete(m_pItemInfo); }
	virtual void Render() {}
protected:
	ITEMINFO* m_pItemInfo;
};

