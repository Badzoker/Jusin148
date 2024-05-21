#include "CFSM.h"

CFSM::CFSM()
{
	currentState = STATE_IDLE;
	m_pPlayer = nullptr;
	m_eState = nullptr;
}

CFSM::~CFSM()
{
	Release();
}

void CFSM::Initialize()
{
	cout << "FSM initialize" << endl;
	m_eState = new State;
	m_pPlayer = new State_Player;
	Update();
}

void CFSM::Update()
{
	cout << "FSM update" << endl;
	while (true)
	{
		switch (currentState)
		{
		case STATE_IDLE:
			Action_Idle();
			break;
		case STATE_RUN:
			break;
		case STATE_ATTACK:
			Action_Attack();
			break;
		case STATE_DEAD:
			Action_Dead();
			SAFE_DELETE(m_pPlayer);
			SAFE_DELETE(m_eState);
			return;
		case STATE_END:
			break;
		default:
			break;
		}
	}
}

void CFSM::Release()
{
	cout << "FSM release" << endl;
}

void CFSM::Change_State(STATE _eState)
{
	currentState = _eState;
	m_pPlayer->Change_State(_eState);
}

void CFSM::Action_Idle()
{
	dynamic_cast<State_Idle*>(m_eState)->Initialize(m_pPlayer);
}

void CFSM::Action_Attack()
{
	dynamic_cast<State_Attack*>(m_eState)->Initialize(m_pPlayer);
}

void CFSM::Action_Dead()
{
	cout << "dead" << endl;
}
