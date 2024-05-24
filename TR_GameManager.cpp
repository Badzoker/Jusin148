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
	Safe_Delete(m_pBattle);
	Safe_Delete(m_pCToString);
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

void CGameManager::Map_Shop_Manager()
{
}

void CGameManager::Map_Shop_Save()
{
}

void CGameManager::Map_Shop_Load()
{
}

void CGameManager::Map_Dungeon()
{
}

void CGameManager::Set_CToString(CToString* _pCTostring)
{
}
