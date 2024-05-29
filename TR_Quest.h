#pragma once
#include "mynamespace.h"
#include "TR_Player.h"
class CQuest
{
public:
	CQuest();
	~CQuest();
	void Initialize();
	void Render();
	void Release();
	void Quest_Level();
	void Quest_Hunt();
	void Set_Player(CObj* _pPlayer) { m_pPlayer = _pPlayer; }
	int Get_iCount_Hunting() { return iCount_Hunting; }
private:
	CObj* m_pPlayer;
	bool isBegin_Level;
	bool isBegin_Hunt;
	int iLevel_Current;
	int iCount_Hunting;
};

