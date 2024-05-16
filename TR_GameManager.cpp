#include "TR_GameManager.h"

CGameManager::CGameManager()
{
	m_pMonster_GameManager = nullptr;
	m_pPlayer_GameManager = nullptr;
	iRandom = 0;
	m_pBattle = nullptr;
	m_pCToString = nullptr;
	cout << "gamemanager creator" << endl;
	system("pause");
}

CGameManager::~CGameManager()
{
	Release();
	system("pause");
}

void CGameManager::Update()
{
}

void CGameManager::Battle_Normal()
{
}

void CGameManager::Battle_Skill()
{
}

void CGameManager::Battle_UsingTools()
{
}

void CGameManager::Release()
{
	SAFE_DELETE(m_pBattle);
	SAFE_DELETE(m_pCToString);
	cout << "gamemanager eliminated" << endl;
}

void CGameManager::Map_Home()
{
}

void CGameManager::Map_Shop()
{
}

void CGameManager::Map_Shop_Equip()
{
}

void CGameManager::Map_Shop_Consumable()
{
}

void CGameManager::Map_Dungeon()
{
}

void CGameManager::Set_CToString(CToString* _pCTostring)
{
}
