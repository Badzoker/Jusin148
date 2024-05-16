#include "TR_Monster.h"
#include "mynamespace.h"

CMonster::CMonster()
{
	m_Info = nullptr;
	srand(unsigned(time(NULL)));
	iRandom_Armor = 0;
	m_pCToString = nullptr;
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(int _iChoose)
{
	if (!m_Info)
	{
		m_Info = new INFO;
	}
	m_Info->iAttack = 3 * _iChoose;
	m_Info->iCritical_Percent = 5 * _iChoose;
	m_Info->iMaxHp = 25 * _iChoose;
	m_Info->iCurrentHp = m_Info->iMaxHp;
	m_Info->iMaxMana = 10 * _iChoose;
	m_Info->iCurrentMana = m_Info->iMaxMana;
	m_Info->iExp = m_Info->iMaxHp;//보
	m_Info->iGold = 500 * _iChoose;//상
	iRandom_Armor = rand() % 4;
	switch (_iChoose)
	{
	case 1:
		strcpy_s(m_Info->szName, sizeof(m_Info->szName), "굼바");
		m_Info->eArmor_Type = ARMOR_LIGHT;
		m_Info->eAttack_Type = (ATTACK_TYPE)iRandom_Armor;
		break;
	case 2:
		strcpy_s(m_Info->szName, sizeof(m_Info->szName), "부끄부끄");
		m_Info->eArmor_Type = ARMOR_MEDIUM;
		m_Info->eAttack_Type = (ATTACK_TYPE)iRandom_Armor;
		break;
	case 3:
		strcpy_s(m_Info->szName, sizeof(m_Info->szName), "쿠파");
		m_Info->eArmor_Type = ARMOR_HEAVY;
		m_Info->eAttack_Type = (ATTACK_TYPE)iRandom_Armor;
		break;
	
	default:
		cout << "잘못 입력했습니다." << endl;
		break;
	}
}

void CMonster::Render()
{
	cout << "\n+++++++++++++\n괴물 : " << m_Info->szName << "\n체력 : " << m_Info->iCurrentHp << endl;
	cout << "마나 : " << m_Info->iCurrentMana << "\t  공격력 : " << m_Info->iAttack << "\t  치명타 확률 : " << m_Info->iCritical_Percent << " %" << endl;
	m_pCToString->Attack_ToString(m_Info->eAttack_Type);
	cout << "공격타입 : " << m_pCToString->Get_cToString() << endl;
	m_pCToString->Armor_ToString(m_Info->eArmor_Type);
	cout << "방어타입 : " << m_pCToString->Get_cToString() << endl;
}

void CMonster::Release()
{
	cout << "몬스터 소멸자 호출" << endl;
	SAFE_DELETE(m_Info);
}

//void CMonster::Damaged(int _iDamage, ATTACK_TYPE _eAttacked_Type, ARMOR_TYPE _eMyArmor_Type)
//{
//	int iDamage_Final = _iDamage;
//	switch (_eAttacked_Type)
//	{
//	case ATTACK_NORMAL:
//		if (ARMOR_MEDIUM == _eMyArmor_Type)
//			iDamage_Final = _iDamage * 2;
//		else if (ARMOR_LIGHT == _eMyArmor_Type)
//			iDamage_Final = (int)(_iDamage / 2);
//		break;
//	case ATTACK_MAGIC:
//		if (ARMOR_HEAVY == _eMyArmor_Type)
//			iDamage_Final = _iDamage * 2;
//		else if (ARMOR_MEDIUM == _eMyArmor_Type)
//			iDamage_Final = (int)(_iDamage / 2);
//		break;
//	case ATTACK_LIGHT:
//		if (ARMOR_LIGHT == _eMyArmor_Type)
//			iDamage_Final = _iDamage * 2;
//		else if (ARMOR_HEAVY == _eMyArmor_Type)
//			iDamage_Final = (int)(_iDamage / 2);
//		break;
//	case ATTACK_CHAOS:
//		iDamage_Final = (int)((float)_iDamage * 1.2f);
//		break;
//	case ATTACK_TYPE_END:
//		break;
//	default:
//		break;
//	}
//	m_Info->iCurrentHp -= iDamage_Final;
//	if (0 >= m_Info->iCurrentHp)
//	{
//		cout << "몬스터가 " << iDamage_Final << " 만큼 피해를 입고 죽었다!\n******  Victory!!  ******" << endl;
//		return;
//	}
//	cout << "몬스터가 " << iDamage_Final << " 만큼 피해를 입었다!" << endl;
//}
