#include "State_Idle.h"

State_Idle::State_Idle()
{
	cout << "idle class 생성자" << endl;
}

State_Idle::~State_Idle()
{
	Release();
}

void State_Idle::Initialize(State_Player* _pPlayer)
{
	cout << "Idle class Initialize" << endl;
	Update(_pPlayer);
}

void State_Idle::Update(State_Player* _pPlayer)
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
			//_pState->Change_State(STATE_ATTACK);
			break;
		}
	}
}

void State_Idle::Release()
{
	cout << "Idle class 소멸자" << endl;
}
