#include "FSM_Machine.h"


FSM_Machine::FSM_Machine()
{
	m_pPlayer = nullptr;
	m_pState_Idle = nullptr;
	m_pState_Attack = nullptr;
	m_pState_Dead = nullptr;
}

FSM_Machine::~FSM_Machine()
{
	Release();
}

void FSM_Machine::Initialize()
{
	m_pPlayer = new FSM_Player;
	if (!m_pState_Idle)
	{
		m_pState_Idle = new FSM_Idle(m_pPlayer);
	}
	if (!m_pState_Attack)
	{
		m_pState_Attack = new FSM_Attack(m_pPlayer);
	}
	if (!m_pState_Dead)
	{
		m_pState_Dead = new FSM_Dead(m_pPlayer);
	}
	Update();
}

void FSM_Machine::Update()
{
	while (true)
	{
		switch (m_pPlayer->Get_State())
		{
		case STATE_IDLE:
			Action_Idle();
			break;
		case STATE_ATTACK:
			Action_Attack();
			break;
		case STATE_DEAD:
			Action_Dead();
			return;
		case STATE_END:
			break;
		default:
			break;
		}
	}
}

void FSM_Machine::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pState_Idle);
	SAFE_DELETE(m_pState_Attack);
	SAFE_DELETE(m_pState_Dead);
}


void FSM_Machine::Action_Idle()
{
	
	m_pState_Idle->Initialize();
}

void FSM_Machine::Action_Attack()
{
	m_pState_Attack->Initialize();
}

void FSM_Machine::Action_Dead()
{
	m_pState_Dead->Initialize();
}
