#pragma once
#include "TR_Obj.h"

class CMonster : public CObj
{
private:

public:
	CMonster();
	virtual ~CMonster();
	void Initialize(int _iChoose);
	void Render();
	void Release();
	int Reward() { return m_Info->iMaxHp; }
};