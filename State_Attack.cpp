#include "State_Attack.h"

State_Attack::State_Attack()
{
	cout << "attack class ������" << endl;
}

State_Attack::~State_Attack()
{
	Release();
}

void State_Attack::Initialize(State_Player* _pPlayer)
{
	cout << "attack class Initialize" << endl;
	Update(_pPlayer);
}

void State_Attack::Update(State_Player* _pPlayer)
{
	cout << "Attack class Update , ouch" << endl;
	clock_t start = clock();
	clock_t end;
	int iTimer = 2;
	int iTimer_Reverse = 0;
	while (true)
	{
		end = clock();
		if ((end - start) / CLOCKS_PER_SEC == iTimer_Reverse)
		{
			//system("cls");
			cout << "���� �� ������ ��..  " << iTimer_Reverse << " �� ����" << endl;
			iTimer_Reverse++;
		}
		if ((end - start) / CLOCKS_PER_SEC == iTimer)
		{
			cout << "2sec" << endl;
			_pPlayer->Attack_Count_plus();
			if (2 < _pPlayer->Check_Attack_Count())
			{
				_pPlayer->Change_State(STATE_DEAD);
				break;
			}
			_pPlayer->Change_State(STATE_IDLE);
			break;
		}
	}
}

void State_Attack::Release()
{
	cout << "attack class �Ҹ���" << endl;
}
