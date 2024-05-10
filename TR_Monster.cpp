#include "TR_Monster.h"
#include "mynamespace.h"
CMonster::CMonster()
{
	m_pInfo = nullptr;
	srand(unsigned(time(NULL)));
	iRandom = 0;
	m_pCToString = nullptr;
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
	iRandom = rand() % 4;
	switch (_iChoose)
	{
	case 1:
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "굼바");
		m_pInfo->eArmor_Type = ARMOR_LIGHT;
		m_pInfo->eAttack_Type = (ATTACK_TYPE)iRandom;
		break;
	case 2:
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "부끄부끄");
		m_pInfo->eArmor_Type = ARMOR_MEDIUM;
		m_pInfo->eAttack_Type = (ATTACK_TYPE)iRandom;
		break;
	case 3:
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "쿠파");
		m_pInfo->eArmor_Type = ARMOR_HEAVY;
		m_pInfo->eAttack_Type = (ATTACK_TYPE)iRandom;
		break;
	
	default:
		cout << "잘못 입력했습니다." << endl;
		break;
	}
}

void CMonster::Render()
{
	cout << "\n+++++++++++++\n괴물 : " << m_pInfo->szName << "\n체력 : " << m_pInfo->iCurrentHp << endl;
	cout << "마나 : " << m_pInfo->iCurrentMana << "\t  공격력 : " << m_pInfo->iAttack << "\t  치명타 확률 : " << m_pInfo->iCritical_Percent << " %" << endl;
	m_pCToString->Attack_ToString(m_pInfo->eAttack_Type);
	cout << "공격타입 : " << m_pCToString->Get_cToString() << endl;
	m_pCToString->Armor_ToString(m_pInfo->eArmor_Type);
	cout << "방어타입 : " << m_pCToString->Get_cToString() << endl;
}

void CMonster::Release()
{
	cout << "몬스터 소멸자 호출" << endl;
	SAFE_DELETE(m_pInfo);
}

void CMonster::Damaged(int _iDamage, ATTACK_TYPE _eAttacked_Type, ARMOR_TYPE _eMyArmor_Type)
{
	int iDamage_Final = _iDamage;
	switch (_eAttacked_Type)
	{
	case ATTACK_NORMAL:
		if (ARMOR_MEDIUM == _eMyArmor_Type)
			iDamage_Final = _iDamage * 2;
		else if (ARMOR_LIGHT == _eMyArmor_Type)
			iDamage_Final = (int)(_iDamage / 2);
		break;
	case ATTACK_MAGIC:
		if (ARMOR_HEAVY == _eMyArmor_Type)
			iDamage_Final = _iDamage * 2;
		else if (ARMOR_MEDIUM == _eMyArmor_Type)
			iDamage_Final = (int)(_iDamage / 2);
		break;
	case ATTACK_LIGHT:
		if (ARMOR_LIGHT == _eMyArmor_Type)
			iDamage_Final = _iDamage * 2;
		else if (ARMOR_HEAVY == _eMyArmor_Type)
			iDamage_Final = (int)(_iDamage / 2);
		break;
	case ATTACK_CHAOS:
		iDamage_Final = (int)((float)_iDamage * 1.2f);
		break;
	case ATTACK_TYPE_END:
		break;
	default:
		break;
	}
	m_pInfo->iCurrentHp -= iDamage_Final;
	if (0 >= m_pInfo->iCurrentHp)
	{
		cout << "몬스터가 " << iDamage_Final << " 만큼 피해를 입고 죽었다!\n******  Victory!!  ******" << endl;
		return;
	}
	cout << "몬스터가 " << iDamage_Final << " 만큼 피해를 입었다!" << endl;
}
