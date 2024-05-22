#include "FSM_Idle.h"

FSM_Idle::~FSM_Idle()
{
	Release();
}

void FSM_Idle::Initialize()
{
	Update();
}

void FSM_Idle::Update()
{
	cout << "Idle class Update" << endl;
	clock_t start = clock();
	clock_t end;
	int iTimer = 5;
	int iTimer_Reverse = 0;
	while (true)
	{
		end = clock();
		if ((end - start) / CLOCKS_PER_SEC == iTimer_Reverse)
		{
			system("cls");
			cout << "대기시간..  " << iTimer_Reverse << " 초 지남" << endl;
			iTimer_Reverse++;
		}
		if ((end - start) / CLOCKS_PER_SEC == iTimer)
		{
			cout << "5sec" << endl;
			Set_State(m_pPlayer, STATE_ATTACK);
			break;
		}
	}
}

void FSM_Idle::Release()
{
}

void FSM_Idle::Set_State(FSM_Player* _pPlayer, STATE _eState)
{
	_pPlayer->Change_State(_eState);
}
