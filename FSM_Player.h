#pragma once
#include "FSM_mynamespace.h"
class FSM_Player
{
public:
	FSM_Player();
	~FSM_Player() {}
	void Initialize() {}
	void Update() {}
	void Render() {}
	void Release() {}
	STATE Get_State() const { return m_eState; }
	STATE Change_State(STATE _eState) { m_eState = _eState; return m_eState; }
	int Damaged() { --m_iLife; return m_iLife; }
	int Get_Life() const { return m_iLife; }
private:
	STATE m_eState;
	int m_iLife;
};
