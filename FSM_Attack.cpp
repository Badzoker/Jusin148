#include "FSM_Attack.h"

FSM_Attack::~FSM_Attack()
{
	Release();
}

void FSM_Attack::Initialize()
{
	Update();
}

void FSM_Attack::Update()
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
			cout << "공격 후 딜레이 중..  " << iTimer_Reverse << " 초 지남" << endl;
			iTimer_Reverse++;
		}
		if ((end - start) / CLOCKS_PER_SEC == iTimer)
		{
			cout << "2sec" << endl;
			m_pPlayer->Damaged();
			if (0 >= m_pPlayer->Get_Life())
			{
				Set_State(m_pPlayer, STATE_DEAD); // transition
				break;
			}
			Set_State(m_pPlayer, STATE_IDLE); // transition
			break;
		}
	}
}

void FSM_Attack::Release()
{
}

void FSM_Attack::Set_State(FSM_Player* _pPlayer, STATE _eState)
{
	_pPlayer->Change_State(_eState);
}
