#include "TR_Item_Equip.h"

CItem_Equip::CItem_Equip()
{
	m_pItemInfo = nullptr;
}

CItem_Equip::~CItem_Equip()
{
	Release();
}

void CItem_Equip::Initialize(bool _isMain, JOB _eJob)
{
	m_pItemInfo = new ITEMINFO;
	if (_isMain)
	{
		m_pItemInfo->eItem_Type = MAIN_EQUIP;
		m_pItemInfo->iGold = 1000;
		switch (_eJob)
		{
		case WARRIOR:
			strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "장검");
			m_pItemInfo->iAttack = 10;
			m_pItemInfo->iHealth = 0;
			break;
		case WIZARD:
			strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "지팡이");
			m_pItemInfo->iAttack = 5;
			m_pItemInfo->iHealth = 0;
			break;
		case THIEF:
			strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "단검");
			m_pItemInfo->iAttack = 15;
			m_pItemInfo->iHealth = 0;
			break;
		}
	}
	else
	{
		m_pItemInfo->eItem_Type = SUB_EQUIP;
		m_pItemInfo->iGold = 1500;
		switch (_eJob)
		{
		case WARRIOR:
			strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "방패");
			m_pItemInfo->iAttack = 0;
			m_pItemInfo->iHealth = 50;
			break;
		case WIZARD:
			strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "마법서");
			m_pItemInfo->iAttack = 5;
			m_pItemInfo->iHealth = 25;
			break;
		case THIEF:
			strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "날쌘 장갑");
			m_pItemInfo->iAttack = 10;
			m_pItemInfo->iHealth = 10;
			break;
		}
	}
}

void CItem_Equip::Update()
{
}

void CItem_Equip::Release()
{
	Safe_Delete(m_pItemInfo);
}

void CItem_Equip::Render()
{
	switch (m_pItemInfo->eItem_Type)
	{
	case MAIN_EQUIP:
		cout << "아이템 타입 : 주장비" << endl;
		break;
	case SUB_EQUIP:
		cout << "아이템 타입 : 보조장비" << endl;
		break;
	default:
		break;
	}
	cout << "아이템 이름 : " << m_pItemInfo->szName << endl;
	cout << "아이템 공격력 : " << m_pItemInfo->iAttack << endl;
	cout << "아이템 체력 : " << m_pItemInfo->iHealth << endl;
	cout << "아이템 가격 : " << m_pItemInfo->iGold << endl;
}
