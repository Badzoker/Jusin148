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
	~CObj();
	void Damaged(CObj* _Attacker, int _iDamage);
	int Attack();
	void Set_CToString(CToString* _pCToString) { m_pCToString = _pCToString; }
	INFO* Get_Info() { return m_Info; }
	//====player
	virtual void Initialize(int _iChoose);
	virtual void Render();
	virtual void Release();
	virtual void Level_Up();
	virtual void Load();
	virtual void Save();
	virtual void Check_Equip();
	virtual void Respawn();
	virtual void Take_Reward(int _iReward, int _iGold);
	virtual int Skill();
	virtual void Using_Tools();
	ITEM* Get_Item() { return m_Item; }
	//====monster
	virtual int Reward() { return m_Info->iMaxHp; }
};

