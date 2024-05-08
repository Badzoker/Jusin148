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
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "����");
		break;
	case 2:
		pInfo->iAttack = 3 * _iChoose;
		pInfo->iCurrentHp = 5 * _iChoose;
		pInfo->iMaxHp = 5 * _iChoose;
		pInfo->iExp = pInfo->iMaxHp;
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "����");
		break;
	case 3:
		pInfo->iAttack = 3 * _iChoose;
		pInfo->iCurrentHp = 5 * _iChoose;
		pInfo->iMaxHp = 5 * _iChoose;
		pInfo->iExp = pInfo->iMaxHp;
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "����");
		break;
	
	default:
		cout << "�߸� �Է��߽��ϴ�." << endl;
		break;
	}
}

void CMonster::Update()
{
	cout << "\n+++++++++++++\n���� : " << pInfo->szName << "\nü�� : " << pInfo->iCurrentHp << "\n���� : " << pInfo->iCurrentMana << "\t  ���ݷ� : " << pInfo->iAttack << endl;
}

void CMonster::Release()
{
}

void CMonster::Damaged(int _iDamage)
{
}
