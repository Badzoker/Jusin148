#include "TR_GameManager.h"

CGameManager::CGameManager()
{
	m_pMonster_GameManager = nullptr;
	m_pPlayer_GameManager = nullptr;
	cout << "GameManager ������ ȣ��" << endl;
	system("pause");
}

CGameManager::~CGameManager()
{
	cout << "GameManager �Ҹ��� ȣ��" << endl;
	system("pause");
}
