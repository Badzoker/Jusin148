#pragma once
#include "State_Attack.h"
#include "State_Idle.h"
#include "StateMynamespace.h"
#include "State.h"

class CFSM
{
private:
	State* m_eState;
	State_Player* m_pPlayer;
	STATE currentState;
public:
	CFSM();
	~CFSM();
	void Initialize();
	void Update();
	void Release();
	void Change_State(STATE _eState);
	void Action_Idle();
	void Action_Attack();
	void Action_Dead();
};

