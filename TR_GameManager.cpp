#include "TR_GameManager.h"

CGameManager::CGameManager()
{
	m_pMonster = nullptr;
	m_pPlayer = nullptr;
	iRandom = 0;
	m_pBattle = nullptr;
	m_pCToString = nullptr;
	m_pShop = nullptr;
}

CGameManager::~CGameManager()
{
	Release();
}

void CGameManager::Release()
{
	Safe_Delete(m_pBattle);
	Safe_Delete(m_pCToString);
}
