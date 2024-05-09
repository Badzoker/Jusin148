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
		m_pInfo = new INFOMON;
	}
	m_pInfo->iAttack = 3 * _iChoose;
	m_pInfo->iCritical_Percent = 5 * _iChoose;
	m_pInfo->iMaxHp = 25 * _iChoose;
	m_pInfo->iCurrentHp = m_pInfo->iMaxHp;
	m_pInfo->iMaxMana = 10 * _iChoose;
	m_pInfo->iCurrentMana = m_pInfo->iMaxMana;
	m_pInfo->iExp = m_pInfo->iMaxHp;//보
	m_pInfo->iGold = 500 * _iChoose;//상
	switch (_iChoose)
	{
	case 1:
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "굼바");
		break;
	case 2:
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "부끄부끄");
		break;
	case 3:
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "쿠파");
		break;
	
	default:
		cout << "잘못 입력했습니다." << endl;
		break;
	}
}

void CMonster::Render()
{
	cout << "\n+++++++++++++\n괴물 : " << m_pInfo->szName << "\n체력 : " << m_pInfo->iCurrentHp << endl;
	cout <<"마나 : " << m_pInfo->iCurrentMana << "\t  공격력 : " << m_pInfo->iAttack << "\t  치명타 확률 : " << m_pInfo->iCritical_Percent << " %" << endl;
}

void CMonster::Release()
{
	cout << "몬스터 소멸자 호출" << endl;
	SAFE_DELETE(m_pInfo);
}

void CMonster::Damaged(int _iDamage, ATTACK_TYPE _eAttack_Type)
{
	m_pInfo->iCurrentHp -= _iDamage;
	if (0 >= m_pInfo->iCurrentHp)
	{
		cout << "몬스터가 " << _iDamage << " 만큼 피해를 입고 죽었다!\n******  Victory!!  ******" << endl;
		return;
	}
	cout << "몬스터가 " << _iDamage << " 만큼 피해를 입었다!" << endl;
}
