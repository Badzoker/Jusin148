#pragma once
#include "mynamespace.h"
#include "TR_Struct.h"
#include "TR_Enum.h"

class CPlayer
{
private:
	INFO* pInfo;
	ITEM* pItem;
public:
	CPlayer();
	~CPlayer();
	void Initialize(int _iChoose);
	void Update();
	void Release();
	int Attack() {return pInfo->iAttack;}
	void Damaged(int _iDamage);
	void Level_Up(int _iExp);
	void Load();
};