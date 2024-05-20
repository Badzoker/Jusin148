#pragma once
#include "StateMynamespace.h"
#include "State_Player.h"
class State
{
public:
	State();
	virtual ~State();
	virtual void Initialize(State_Player* _pPlayer) {};
	virtual void Update(State_Player* _pPlayer) {};
	virtual void Release() {};
};

