#include "TR_GameManager.h"

CGameManager::CGameManager()
{
	m_pMonster_GameManager = nullptr;
	m_pPlayer_GameManager = nullptr;
	cout << "GameManager 생성자 호출" << endl;
	system("pause");
}

CGameManager::~CGameManager()
{
	cout << "GameManager 소멸자 호출" << endl;
	system("pause");
}
