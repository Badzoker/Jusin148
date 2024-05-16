#pragma once
#include "mynamespace.h"
#include "TR_Struct.h"

class CObj
{
public:
	INFO* m_Info;
	CToString* m_pCToString;
	
public:
	CObj();
	~CObj();
	void Damaged(CObj* _Attacker, int _iDamage);
	int Attack();
	void Set_CToString(CToString* _pCToString) { m_pCToString = _pCToString; }
	INFO* Get_Info() { return m_Info; }
};

