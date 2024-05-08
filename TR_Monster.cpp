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
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "굼바");
		break;
	case 2:
		pInfo->iAttack = 3 * _iChoose;
		pInfo->iMaxHp = 25 * _iChoose;
		pInfo->iCurrentHp = pInfo->iMaxHp;
		pInfo->iExp = pInfo->iMaxHp;
		pInfo->iMaxMana = 10 * _iChoose;
		pInfo->iCurrentMana = pInfo->iMaxMana;
		pInfo->iMaxExp = 0;
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "부끄부끄");
		break;
	case 3:
		pInfo->iAttack = 3 * _iChoose;
		pInfo->iMaxHp = 25 * _iChoose;
		pInfo->iCurrentHp = pInfo->iMaxHp;
		pInfo->iExp = pInfo->iMaxHp;
		pInfo->iMaxMana = 10 * _iChoose;
		pInfo->iCurrentMana = pInfo->iMaxMana;
		pInfo->iMaxExp = 0;
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "쿠파");
		break;
	
	default:
		cout << "잘못 입력했습니다." << endl;
		break;
	}
}

void CMonster::Update()
{
	cout << "\n+++++++++++++\n괴물 : " << pInfo->szName << "\n체력 : " << pInfo->iCurrentHp << "\n마나 : " << pInfo->iCurrentMana << "\t  공격력 : " << pInfo->iAttack << endl;
}

void CMonster::Release()
{
	cout << "몬스터 소멸자 호출" << endl;
	SAFE_DELETE(pInfo);
}

void CMonster::Damaged(int _iDamage)
{
	pInfo->iCurrentHp -= _iDamage;
	if (0 >= pInfo->iCurrentHp)
	{
		cout << "몬스터가 " << _iDamage << " 만큼 피해를 입고 죽었다!\n******  Victory!!  ******" << endl;
	}
}
