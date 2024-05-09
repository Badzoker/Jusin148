#pragma once
#include "mynamespace.h"
#include "TR_Struct.h"

class CPlayer
{
private:
	INFO* m_pInfo;
	ITEM* m_pItem;
public:
	CPlayer();
	~CPlayer();
	void Initialize(int _iChoose);
	//void Update();
	void Render();
	void Release();
	int Attack() {return m_pInfo->iAttack;}
	void Damaged(int _iDamage, ATTACK_TYPE _eAttack_Type);
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
};