#include "TR_Obj.h"

CObj::CObj()
{
	cout << "부모생성자" << endl;
	m_Info = nullptr;
	system("pause");
}

CObj::~CObj()
{
	cout << "부모소멸자" << endl;
	system("pause");
}

void CObj::Damaged(int _iDamage, ATTACK_TYPE _eAttacked_Type, ARMOR_TYPE _eMyArmor_Type, INFO* _tTarget)
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
	_tTarget->iCurrentHp -= iDamage_Final;
	if (0 >= _tTarget->iCurrentHp)
	{
		cout << _tTarget->szName <<" 가 " << iDamage_Final << " 만큼 피해를 입고 죽었다!" << endl;
		cout << "부모의 데미지 함수" << endl;
		return;
	}
	cout << _tTarget->szName << " 가 " << iDamage_Final << " 만큼 피해를 입었다!" << endl;
	cout << "부모의 데미지 함수" << endl;
}

int CObj::Attack(int _iAttack_Damage)
{
	cout << "부모의 공격 함수" << endl;
	return _iAttack_Damage;
}
