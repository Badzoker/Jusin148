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
	Release();
}

void CObj::Damaged(CObj* _Attacker, int _iDamage) // _Target
{
	int iDamage_Final = _iDamage;
	switch (_Attacker->m_Info->eAttack_Type)
	{
	case ATTACK_NORMAL:
		if (ARMOR_MEDIUM == m_Info->eArmor_Type)
			iDamage_Final *= 2;
		else if (ARMOR_LIGHT == m_Info->eArmor_Type)
			iDamage_Final /= 2;
		break;
	case ATTACK_MAGIC:
		if (ARMOR_HEAVY == m_Info->eArmor_Type)
			iDamage_Final *= 2;
		else if (ARMOR_MEDIUM == m_Info->eArmor_Type)
			iDamage_Final /= 2;
		break;
	case ATTACK_LIGHT:
		if (ARMOR_LIGHT == m_Info->eArmor_Type)
			iDamage_Final *= 2;
		else if (ARMOR_HEAVY == m_Info->eArmor_Type)
			iDamage_Final /=2;
		break;
	case ATTACK_CHAOS:
		iDamage_Final = iDamage_Final + (int)(iDamage_Final * 0.2f);
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
	Safe_Delete(m_Info);
	Safe_Delete(m_Item);
}
