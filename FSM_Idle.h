#pragma once
#include "FSM_State.h"

class FSM_Idle : public FSM_State
{
public:
	FSM_Idle(FSM_Player* _pPlayer) : FSM_State(m_pPlayer) { m_pPlayer = _pPlayer; }
	~FSM_Idle();
	virtual void Initialize();
	virtual void Update();
	virtual void Render() {}
	virtual void Release();
	virtual void Set_State(FSM_Player* _pPlayer, STATE _eState);
};