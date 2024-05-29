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
			strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "���");
			m_pItemInfo->iAttack = 10;
			m_pItemInfo->iHealth = 0;
			break;
		case WIZARD:
			strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "������");
			m_pItemInfo->iAttack = 5;
			m_pItemInfo->iHealth = 0;
			break;
		case THIEF:
			strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "�ܰ�");
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
			strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "����");
			m_pItemInfo->iAttack = 0;
			m_pItemInfo->iHealth = 50;
			break;
		case WIZARD:
			strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "������");
			m_pItemInfo->iAttack = 5;
			m_pItemInfo->iHealth = 25;
			break;
		case THIEF:
			strcpy_s(m_pItemInfo->szName, sizeof(m_pItemInfo->szName), "���� �尩");
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
		cout << "������ Ÿ�� : �����" << endl;
		break;
	case SUB_EQUIP:
		cout << "������ Ÿ�� : �������" << endl;
		break;
	default:
		break;
	}
	cout << "������ �̸� : " << m_pItemInfo->szName << endl;
	cout << "������ ���ݷ� : " << m_pItemInfo->iAttack << endl;
	cout << "������ ü�� : " << m_pItemInfo->iHealth << endl;
	cout << "������ ���� : " << m_pItemInfo->iGold << endl;
}
