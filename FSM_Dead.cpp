#include "FSM_Dead.h"

FSM_Dead::~FSM_Dead()
{
	Release();
}

void FSM_Dead::Initialize()
{
	cout << "dead" << endl;
}

void FSM_Dead::Set_State(FSM_Player* _pPlayer, STATE _eState)
{
	_pPlayer->Change_State(_eState);
}
