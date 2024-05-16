#include "TR_Obj.h"

CObj::CObj()
{
	m_Info = nullptr;
	m_pCToString = nullptr;
	m_Item = nullptr;
	iRandom_Armor = 0;
}

CObj::~CObj()
{
	cout << "parent eliminated" << endl;
	Release();
	system("pause");
}

void CObj::Damaged(CObj* _Attacker, int _iDamage) // _Target
{
	int iDamage_Final = _Attacker->m_Info->iAttack;
	switch (_Attacker->m_Info->eAttack_Type)
	{
	case ATTACK_NORMAL:
		if (ARMOR_MEDIUM == m_Info->eArmor_Type)
			iDamage_Final = _Attacker->m_Info->iAttack * 2;
		else if (ARMOR_LIGHT == m_Info->eArmor_Type)
			iDamage_Final = (int)(_Attacker->m_Info->iAttack / 2);
		break;
	case ATTACK_MAGIC:
		if (ARMOR_HEAVY == m_Info->eArmor_Type)
			iDamage_Final = _Attacker->m_Info->iAttack * 2;
		else if (ARMOR_MEDIUM == m_Info->eArmor_Type)
			iDamage_Final = (int)(_Attacker->m_Info->iAttack / 2);
		break;
	case ATTACK_LIGHT:
		if (ARMOR_LIGHT == m_Info->eArmor_Type)
			iDamage_Final = _Attacker->m_Info->iAttack * 2;
		else if (ARMOR_HEAVY == m_Info->eArmor_Type)
			iDamage_Final = (int)(_Attacker->m_Info->iAttack / 2);
		break;
	case ATTACK_CHAOS:
		iDamage_Final = (int)((float)_Attacker->m_Info->iAttack * 1.2f);
		break;
	case ATTACK_TYPE_END:
		break;
	default:
		break;
	}
	m_Info->iCurrentHp -= iDamage_Final;
	if (0 >= m_Info->iCurrentHp)
	{
		cout << m_Info->szName << " 가 " << iDamage_Final << " 만큼 피해를 입고 죽었다!" << endl;
		return;
	}
	cout << m_Info->szName << " 가 " << iDamage_Final << " 만큼 피해를 입었다!" << endl;
}
//void CObj::Damaged(int _iDamage, ATTACK_TYPE _eAttacked_Type, ARMOR_TYPE _eMyArmor_Type, INFO* _tTarget)
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
//	_tTarget->iCurrentHp -= iDamage_Final;
//	if (0 >= _tTarget->iCurrentHp)
//	{
//		cout << _tTarget->szName <<" 가 " << iDamage_Final << " 만큼 피해를 입고 죽었다!" << endl;
//		cout << "부모의 데미지 함수" << endl;
//		return;
//	}
//	cout << _tTarget->szName << " 가 " << iDamage_Final << " 만큼 피해를 입었다!" << endl;
//	cout << "부모의 데미지 함수" << endl;
//}

int CObj::Attack()
{
	return m_Info->iAttack;
}

void CObj::Initialize(int _iChoose)
{
}

void CObj::Render()
{
}

void CObj::Release()
{
	SAFE_DELETE(m_Info);
	SAFE_DELETE(m_Item);
}

void CObj::Level_Up()
{
}

void CObj::Load()
{
}

void CObj::Save()
{
}

void CObj::Check_Equip()
{
}

void CObj::Respawn()
{
}

void CObj::Take_Reward(int _iReward, int _iGold)
{
}

int CObj::Skill()
{
	return 0;
}

void CObj::Using_Tools()
{
}
