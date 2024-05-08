#include "TR_Monster.h"
#include "mynamespace.h"
CMonster::CMonster()
{
	m_pInfo = nullptr;
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(int _iChoose)
{
	if (!m_pInfo)
	{
		m_pInfo = new INFO;
	}
	switch (_iChoose)
	{
	case 1:
		m_pInfo->iAttack = 3 * _iChoose;
		m_pInfo->iMaxHp = 25 * _iChoose;
		m_pInfo->iCurrentHp = m_pInfo->iMaxHp;
		m_pInfo->iExp = m_pInfo->iMaxHp;
		m_pInfo->iMaxMana = 10 * _iChoose;
		m_pInfo->iCurrentMana = m_pInfo->iMaxMana;
		m_pInfo->iMaxExp = 0;
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "����");
		break;
	case 2:
		m_pInfo->iAttack = 3 * _iChoose;
		m_pInfo->iMaxHp = 25 * _iChoose;
		m_pInfo->iCurrentHp = m_pInfo->iMaxHp;
		m_pInfo->iExp = m_pInfo->iMaxHp;
		m_pInfo->iMaxMana = 10 * _iChoose;
		m_pInfo->iCurrentMana = m_pInfo->iMaxMana;
		m_pInfo->iMaxExp = 0;
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "�β��β�");
		break;
	case 3:
		m_pInfo->iAttack = 3 * _iChoose;
		m_pInfo->iMaxHp = 25 * _iChoose;
		m_pInfo->iCurrentHp = m_pInfo->iMaxHp;
		m_pInfo->iExp = m_pInfo->iMaxHp;
		m_pInfo->iMaxMana = 10 * _iChoose;
		m_pInfo->iCurrentMana = m_pInfo->iMaxMana;
		m_pInfo->iMaxExp = 0;
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "����");
		break;
	
	default:
		cout << "�߸� �Է��߽��ϴ�." << endl;
		break;
	}
}

void CMonster::Update()
{
	cout << "\n+++++++++++++\n���� : " << m_pInfo->szName << "\nü�� : " << m_pInfo->iCurrentHp << "\n���� : " << m_pInfo->iCurrentMana << "\t  ���ݷ� : " << m_pInfo->iAttack << endl;
}

void CMonster::Release()
{
	cout << "���� �Ҹ��� ȣ��" << endl;
	SAFE_DELETE(m_pInfo);
}

void CMonster::Damaged(int _iDamage)
{
	m_pInfo->iCurrentHp -= _iDamage;
	if (0 >= m_pInfo->iCurrentHp)
	{
		cout << "���Ͱ� " << _iDamage << " ��ŭ ���ظ� �԰� �׾���!\n******  Victory!!  ******" << endl;
	}
}
