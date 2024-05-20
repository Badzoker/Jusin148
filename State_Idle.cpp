#include "State_Idle.h"

State_Idle::State_Idle()
{
	cout << "idle class ������" << endl;
}

State_Idle::~State_Idle()
{
	Release();
}

void State_Idle::Initialize(State_Player* _pPlayer)
{
	if (_pPlayer->Check_State() == STATE_IDLE)
	{
		cout << "Idle class Initialize" << endl;
		Update(_pPlayer);
	}
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
			cout << "���ð�..  " << iTimer_Reverse << " �� ����" << endl;
			iTimer_Reverse++;
		}
		if ((end - start) / CLOCKS_PER_SEC == iTimer)
		{
			cout << "5sec" << endl;
			_pPlayer->Change_State(STATE_ATTACK);
			break;
		}
	}
}

void State_Idle::Release()
{
	cout << "Idle class �Ҹ���" << endl;
}
