#pragma once
#include "TR_GameManager.h"
#include <ctime>

class CBattle : public CGameManager
{
private:

public:
	CBattle();
	virtual ~CBattle() {}
	void Update();
	void Battle_Normal();
	void Battle_Skill();
	void Battle_UsingTools();
};