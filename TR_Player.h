#pragma once
#include "TR_Obj.h"

class CPlayer : public CObj
{
private:
	//INFO* m_pInfo;
	//CToString* m_pCToString;
	//ITEM* m_pItem;
public:
	CPlayer();
	virtual ~CPlayer();
	void Initialize(int _iChoose);
	//void Update();
	void Render();
	void Release();
	void Level_Up();
	void Load();
	void Save();
	void Check_Equip();
	void Respawn();
	void Take_Reward(int _iReward, int _iGold);
	int Skill();
	void Using_Tools();
	ITEM* Get_Item() { return m_Item; }//{ return m_pItem; }
	//INFO* Get_Info() {return m_Info;}
	//void Set_CToString(CToString* _pCToString) { m_pCToString = _pCToString; }
	//int Attack() {return m_Info->iAttack;}
	//void Damaged(int _iDamage, ATTACK_TYPE _eAttacked_Type, ARMOR_TYPE _eMyArmor_Type);
};