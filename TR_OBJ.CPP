#include "TR_Obj.h"

CObj::CObj()
{
	cout << "�θ������" << endl;
	m_Info = nullptr;
	system("pause");
}

CObj::~CObj()
{
	cout << "�θ�Ҹ���" << endl;
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
		cout << m_Info->szName << " �� " << iDamage_Final << " ��ŭ ���ظ� �԰� �׾���!" << endl;
		cout << "�θ��� ������ �Լ�" << endl;
		return;
	}
	cout << m_Info->szName << " �� " << iDamage_Final << " ��ŭ ���ظ� �Ծ���!" << endl;
	cout << "�θ��� ������ �Լ�" << endl;
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
//		cout << _tTarget->szName <<" �� " << iDamage_Final << " ��ŭ ���ظ� �԰� �׾���!" << endl;
//		cout << "�θ��� ������ �Լ�" << endl;
//		return;
//	}
//	cout << _tTarget->szName << " �� " << iDamage_Final << " ��ŭ ���ظ� �Ծ���!" << endl;
//	cout << "�θ��� ������ �Լ�" << endl;
//}

int CObj::Attack()
{
	cout << "�θ��� ���� �Լ�" << endl;
	return m_Info->iAttack;
}