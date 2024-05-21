#pragma once
#include "StateMynamespace.h"
#include <time.h>

class State;

class State_Player
{
public:
	State_Player();
	~State_Player();
	void Initialize();
	void Update();
	void Release();
	void Idle();
	void Attack();
	STATE Check_State() { return state; }
	void Change_State(STATE _eState) { state = _eState; }
	void Attack_Count_plus() { iAttack_Count++; }
	int Check_Attack_Count() { return iAttack_Count; }
private:
	STATE state;
	int iAttack_Count;
	bool bPlayer_Class;
};

