#pragma once
#include "mynamespace.h"
#include "TR_Struct.h"

class CObj
{
public:
	INFO* m_Info;
	ITEM* m_Item;
	CToString* m_pCToString;
	int iRandom_Armor;
public:
	CObj();
	virtual ~CObj();
	void Damaged(CObj* _Attacker, int _iDamage);//  ��
	int Attack();
	void Set_CToString(CToString* _pCToString) { m_pCToString = _pCToString; }
	INFO* Get_Info() { return m_Info; }
	virtual void Initialize(int _iChoose);
	virtual void Render();
	virtual void Release();//						��
};

