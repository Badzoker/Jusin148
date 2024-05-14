#include "CToString.h"

CToString::CToString()
{
	cToString[0] = {};
}

CToString::~CToString()
{
}

void CToString::Attack_ToString(int _eAttack)
{
	switch ((ATTACK_TYPE)_eAttack)
	{
	case ATTACK_NORMAL:
		strcpy_s(cToString, sizeof(cToString), "�Ϲ�");
		break;
	case ATTACK_MAGIC:
		strcpy_s(cToString, sizeof(cToString), "����");
		break;
	case ATTACK_LIGHT:
		strcpy_s(cToString, sizeof(cToString), "���");
		break;
	case ATTACK_CHAOS:
		strcpy_s(cToString, sizeof(cToString), "ī����");
		break;
	case ATTACK_TYPE_END:
		break;
	default:
		break;
	}
}

void CToString::Armor_ToString(int _eArmor)
{
	switch ((ARMOR_TYPE)_eArmor)
	{
	case ARMOR_HEAVY:
		strcpy_s(cToString, sizeof(cToString), "�߰�");
		break;
	case ARMOR_LIGHT:
		strcpy_s(cToString, sizeof(cToString), "õ");
		break;
	case ARMOR_MEDIUM:
		strcpy_s(cToString, sizeof(cToString), "����");
		break;
	case ARMOR_TYPE_END:
		break;
	default:
		break;
	}
}
