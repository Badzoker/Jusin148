#include "TR_Monster.h"
#include "mynamespace.h"
CMonster::CMonster()
{
	pInfo->iCurrentMana = 0;
	pInfo->iMaxMana = 0;
	pInfo->iMaxExp = 0;
}

CMonster::~CMonster()
{
}

void CMonster::Initialize(int _iChoose)
{
	switch (_iChoose)
	{
	case 1:
		pInfo->iAttack = 3 * _iChoose;
		pInfo->iCurrentHp = 5 * _iChoose;
		pInfo->iMaxHp = 5 * _iChoose;
		pInfo->iExp = pInfo->iMaxHp;
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "±À¹Ù");
		break;
	case 2:
		pInfo->iAttack = 3 * _iChoose;
		pInfo->iCurrentHp = 5 * _iChoose;
		pInfo->iMaxHp = 5 * _iChoose;
		pInfo->iExp = pInfo->iMaxHp;
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "²¿ºÏ");
		break;
	case 3:
		pInfo->iAttack = 3 * _iChoose;
		pInfo->iCurrentHp = 5 * _iChoose;
		pInfo->iMaxHp = 5 * _iChoose;
		pInfo->iExp = pInfo->iMaxHp;
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "ÄíÆÄ");
		break;
	
	default:
		cout << "Àß¸ø ÀÔ·ÂÇß½À´Ï´Ù." << endl;
		break;
	}
}

void CMonster::Update()
{
	cout << "\n+++++++++++++\n±«¹° : " << pInfo->szName << "\nÃ¼·Â : " << pInfo->iCurrentHp << "\n¸¶³ª : " << pInfo->iCurrentMana << "\t  °ø°İ·Â : " << pInfo->iAttack << endl;
}

void CMonster::Release()
{
}

void CMonster::Damaged(int _iDamage)
{
}
