#include "TR_Monster.h"
#include "mynamespace.h"
CMonster::CMonster()
{
	pInfo = nullptr;
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(int _iChoose)
{
	if (!pInfo)
	{
		pInfo = new INFO;
	}
	switch (_iChoose)
	{
	case 1:
		pInfo->iAttack = 3 * _iChoose;
		pInfo->iMaxHp = 25 * _iChoose;
		pInfo->iCurrentHp = pInfo->iMaxHp;
		pInfo->iExp = pInfo->iMaxHp;
		pInfo->iMaxMana = 10 * _iChoose;
		pInfo->iCurrentMana = pInfo->iMaxMana;
		pInfo->iMaxExp = 0;
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "����");
		break;
	case 2:
		pInfo->iAttack = 3 * _iChoose;
		pInfo->iMaxHp = 25 * _iChoose;
		pInfo->iCurrentHp = pInfo->iMaxHp;
		pInfo->iExp = pInfo->iMaxHp;
		pInfo->iMaxMana = 10 * _iChoose;
		pInfo->iCurrentMana = pInfo->iMaxMana;
		pInfo->iMaxExp = 0;
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "�β��β�");
		break;
	case 3:
		pInfo->iAttack = 3 * _iChoose;
		pInfo->iMaxHp = 25 * _iChoose;
		pInfo->iCurrentHp = pInfo->iMaxHp;
		pInfo->iExp = pInfo->iMaxHp;
		pInfo->iMaxMana = 10 * _iChoose;
		pInfo->iCurrentMana = pInfo->iMaxMana;
		pInfo->iMaxExp = 0;
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
	cout << "���� �Ҹ��� ȣ��" << endl;
	SAFE_DELETE(pInfo);
}

void CMonster::Damaged(int _iDamage)
{
	pInfo->iCurrentHp -= _iDamage;
	if (0 >= pInfo->iCurrentHp)
	{
		cout << "���Ͱ� " << _iDamage << " ��ŭ ���ظ� �԰� �׾���!\n******  Victory!!  ******" << endl;
	}
}
