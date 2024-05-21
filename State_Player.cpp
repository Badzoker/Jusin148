#include "State_Player.h"

State_Player::State_Player()
{
	state = STATE_IDLE;
	iAttack_Count = 0;
	//bPlayer_Class = false;//No Class
	bPlayer_Class = true;//Class
}

State_Player::~State_Player()
{
	Release();
}

void State_Player::Initialize()
{
	cout << "player initialize" << endl;
	Update();
}

void State_Player::Update() //player 안에서 모두 다 컨트롤
{
	State_Idle* idle = nullptr;		// 동영왈 single
	State_Attack* attack = nullptr; // 동영왈 single
	//while (bPlayer_Class)
	//{
	//	cout << "player YC update" << endl;
	//	switch (currentState->Get_State())
	//	{
	//	case STATE_IDLE:
	//		//idle = new State_Idle;
	//		//idle->Initialize(this);
	//		currentState->Initialize(currentState);
	//		SAFE_DELETE(idle);
	//		break;
	//	case STATE_RUN:
	//		break;
	//	case STATE_ATTACK:
	//		//attack = new State_Attack;
	//		//attack->Initialize(this);
	//		currentState->Initialize(currentState);
	//		SAFE_DELETE(attack);
	//		break;
	//	case STATE_DEAD:
	//		cout << "class player dead" << endl;
	//		return;
	//	case STATE_END:
	//		break;
	//	default:
	//		break;
	//	}
	//}
	while (!bPlayer_Class)
	{
		cout << "player NC update" << endl;
		switch (state)
		{
		case STATE_IDLE:
			Idle();
			break;
		case STATE_RUN:
			break;
		case STATE_ATTACK:
			Attack();
			break;
		case STATE_DEAD:
			cout << "dead" << endl;
			return;
		case STATE_END:
			break;
		default:
			break;
		}
	}
}

void State_Player::Release()
{
	cout << "player release" << endl;
}

void State_Player::Idle()
{
	cout << "player idle" << endl; // class 화 시키면 initialize
	clock_t start = clock();
	clock_t end;
	int iTimer = 5;
	while (true)
	{
		end = clock();
		if ((end - start) / CLOCKS_PER_SEC == iTimer)
		{
			cout << "5sec" << endl;
			state = STATE_ATTACK;
			break;
		}
	}
}

void State_Player::Attack()
{
	cout << "player attack , ouch" << endl;
	clock_t start = clock();
	clock_t end;
	int iTimer = 2;
	while (true)
	{
		end = clock();
		if ((end - start) / CLOCKS_PER_SEC == iTimer)
		{
			cout << "2sec" << endl;
			iAttack_Count++;
			if (5 < iAttack_Count)
			{
				state = STATE_DEAD;
				break;
			}
			state = STATE_IDLE;
			break;
		}
	}
}

