#pragma once
#include "mynamespace.h"
#include "TR_Struct.h"
#include "TR_Enum.h"

class CPlayer
{
private:
	INFO* m_pInfo;
	ITEM* m_pItem;
public:
	CPlayer();
	~CPlayer();
	void Initialize(int _iChoose);
	void Update();
	void Release();
	int Attack() {return m_pInfo->iAttack;}
	void Damaged(int _iDamage);
	void Level_Up();
	void Load();
	void Save();
	void Check_Equip();
	void Respawn();
	void Take_Reward(int _iReward);
	int Skill();
	void Using_Tools();
	INFO* Get_Info();
	ITEM* Get_Item();
};