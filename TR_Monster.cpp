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
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "굼바");
		break;
	case 2:
		m_pInfo->iAttack = 3 * _iChoose;
		m_pInfo->iMaxHp = 25 * _iChoose;
		m_pInfo->iCurrentHp = m_pInfo->iMaxHp;
		m_pInfo->iExp = m_pInfo->iMaxHp;
		m_pInfo->iMaxMana = 10 * _iChoose;
		m_pInfo->iCurrentMana = m_pInfo->iMaxMana;
		m_pInfo->iMaxExp = 0;
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "부끄부끄");
		break;
	case 3:
		m_pInfo->iAttack = 3 * _iChoose;
		m_pInfo->iMaxHp = 25 * _iChoose;
		m_pInfo->iCurrentHp = m_pInfo->iMaxHp;
		m_pInfo->iExp = m_pInfo->iMaxHp;
		m_pInfo->iMaxMana = 10 * _iChoose;
		m_pInfo->iCurrentMana = m_pInfo->iMaxMana;
		m_pInfo->iMaxExp = 0;
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "쿠파");
		break;
	
	default:
		cout << "잘못 입력했습니다." << endl;
		break;
	}
}

void CMonster::Update()
{
	cout << "\n+++++++++++++\n괴물 : " << m_pInfo->szName << "\n체력 : " << m_pInfo->iCurrentHp << "\n마나 : " << m_pInfo->iCurrentMana << "\t  공격력 : " << m_pInfo->iAttack << endl;
}

void CMonster::Release()
{
	cout << "몬스터 소멸자 호출" << endl;
	SAFE_DELETE(m_pInfo);
}

void CMonster::Damaged(int _iDamage)
{
	m_pInfo->iCurrentHp -= _iDamage;
	if (0 >= m_pInfo->iCurrentHp)
	{
		cout << "몬스터가 " << _iDamage << " 만큼 피해를 입고 죽었다!\n******  Victory!!  ******" << endl;
	}
}
