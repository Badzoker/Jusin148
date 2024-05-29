#include "TR_Item_Consumable.h"

CItem_Consumable::CItem_Consumable()
{
	m_pItemInfo = nullptr;
}

CItem_Consumable::~CItem_Consumable()
{
	Release();
}

void CItem_Consumable::Initialize(bool _isHealPotion)
{
	m_pItemInfo = new ITEMINFO;
	if (_isHealPotion)
	{
		m_pItemInfo->eItem_Type = HEAL;
		strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "체력포션");
		m_pItemInfo->iGold = 100;
		m_pItemInfo->iAttack = 0;
		m_pItemInfo->iHealth = 20;
	}
	else
	{
		m_pItemInfo->eItem_Type = MANA;
		strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "마나포션");
		m_pItemInfo->iGold = 150;
		m_pItemInfo->iAttack = 0;
		m_pItemInfo->iHealth = 20;
	}
}

void CItem_Consumable::Update()
{
}

void CItem_Consumable::Release()
{
	Safe_Delete(m_pItemInfo);
}

void CItem_Consumable::Render()
{
	switch (m_pItemInfo->eItem_Type)
	{
	case HEAL:
		cout << "아이템 타입 : 체력포션" << endl;
		break;
	case MANA:
		cout << "아이템 타입 : 마나포션" << endl;
		break;
	default:
		break;
	}
	cout << "아이템 이름 : " << m_pItemInfo->szName << endl;
	cout << "아이템 공격력 : " << m_pItemInfo->iAttack << endl;
	cout << "아이템 체력 : " << m_pItemInfo->iHealth << endl;
	cout << "아이템 가격 : " << m_pItemInfo->iGold << endl;
}
