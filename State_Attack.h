#pragma once
#include "State.h"
class State_Attack : public State
{
public:
	State_Attack();
	virtual ~State_Attack();
	void Initialize(State_Player* _pPlayer) override;
	void Update(State_Player* _pPlayer) override;
	void Release() override;
};

