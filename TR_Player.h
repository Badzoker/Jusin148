#pragma once
#include "mynamespace.h"
#include "TR_Struct.h"
#include "TR_Obj.h"
class CPlayer : public CObj
{
private:
	//INFO* m_pInfo;
	ITEM* m_pItem;
	CToString* m_pCToString;
public:
	CPlayer();
	~CPlayer();
	void Initialize(int _iChoose);
	//void Update();
	void Render();
	void Release();
	//int Attack() {return m_Info->iAttack;}
	//void Damaged(int _iDamage, ATTACK_TYPE _eAttacked_Type, ARMOR_TYPE _eMyArmor_Type);
	void Level_Up();
	void Load();
	void Save();
	void Check_Equip();
	void Respawn();
	void Take_Reward(int _iReward, int _iGold);
	int Skill();
	void Using_Tools();
	INFO* Get_Info();
	ITEM* Get_Item();
	void Set_CToString(CToString* _pCToString) { m_pCToString = _pCToString; }
};