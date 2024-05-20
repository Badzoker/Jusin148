#pragma once
#include "State.h"
class State_Idle : public State
{
public:
	State_Idle();
	virtual ~State_Idle();
	void Initialize(State_Player* _pPlayer) override;
	void Update(State_Player* _pPlayer) override;
	void Release() override;
};

