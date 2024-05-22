#pragma once
#include "FSM_Player.h"
class FSM_State
{
public:
	FSM_State(FSM_Player* _pPlayer) : m_pPlayer(_pPlayer) {}
	virtual ~FSM_State() {}
	virtual void Initialize() {}
	virtual void Update() {}
	virtual void Render() {}
	virtual void Release() {}
	virtual void Set_State(FSM_Player* _pPlayer, STATE _eState) {}
protected:
	FSM_Player* m_pPlayer;
};
