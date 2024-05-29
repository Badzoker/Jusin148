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
		strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "ü������");
		m_pItemInfo->iGold = 100;
		m_pItemInfo->iAttack = 0;
		m_pItemInfo->iHealth = 20;
	}
	else
	{
		m_pItemInfo->eItem_Type = MANA;
		strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "��������");
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
		cout << "������ Ÿ�� : ü������" << endl;
		break;
	case MANA:
		cout << "������ Ÿ�� : ��������" << endl;
		break;
	default:
		break;
	}
	cout << "������ �̸� : " << m_pItemInfo->szName << endl;
	cout << "������ ���ݷ� : " << m_pItemInfo->iAttack << endl;
	cout << "������ ü�� : " << m_pItemInfo->iHealth << endl;
	cout << "������ ���� : " << m_pItemInfo->iGold << endl;
}
