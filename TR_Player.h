#pragma once
#include "TR_Obj.h"

class CPlayer : public CObj
{
private:

public:
	CPlayer();
	virtual ~CPlayer();
	void Initialize(int _iChoose);
	void Render();
	void Release();
	void Level_Up();
	void Load();
	void Save();
	void Check_Equip();
	void Render_Equip();
	void Respawn();
	void Take_Reward(int _iReward, int _iGold);
	int Skill();
	void Using_Tools();
	ITEM* Get_Item() { return m_Item; }//{ return m_pItem; }
};