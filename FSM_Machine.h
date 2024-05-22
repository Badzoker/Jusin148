#pragma once
#include "FSM_Dead.h"
#include "FSM_Attack.h"
#include "FSM_Idle.h"

class FSM_Machine
{
public:
	FSM_Machine();
	~FSM_Machine();
	void Initialize();
	void Update();
	void Render() {}
	void Release();
	void Action_Idle();
	void Action_Attack();
	void Action_Dead();
private:
	FSM_Player* m_pPlayer;
	FSM_State* m_pState_Idle;
	FSM_State* m_pState_Attack;
	FSM_State* m_pState_Dead;
};

