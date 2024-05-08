#include "TR_Player.h"

CPlayer::CPlayer()
{
	pInfo->iLevel = 1;
	pInfo->iExp = 0;
	pInfo->iMaxExp = 100;
	pItem->bMain_Item = false;
	pItem->bSub_Item = false;
	pItem->iPotion = 0;
	pItem->iManaPotion = 0;
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Damaged(int _iDamage)
{
	pInfo->iCurrentHp -= _iDamage;
	cout << "플레이어가 " << _iDamage << " 만큼 피해를 입었다!" << endl;

	if (0 >= pInfo->iCurrentHp)
	{
		cout << "플레이어가 " << _iDamage << " 만큼 피해를 입고 죽었다!" << endl;
	}
	
}

void CPlayer::Level_Up(int _iExp)
{
	pInfo->iMaxExp += 50;
	pInfo->iLevel += 1;
	pInfo->iAttack += 10;
	pInfo->iMaxHp += 10;
	pInfo->iMaxMana += 10;
	pInfo->iCurrentHp = pInfo->iMaxHp;
	pInfo->iCurrentMana = pInfo->iMaxMana;
}

void CPlayer::Load()
{
	FILE* pFileJob = NULL;
	FILE* pFileItem = NULL;
	errno_t errReadJob = 0;
	errno_t errReadItem = 0;
	errReadJob = fopen_s(&pFileJob, "./Data/Info/Job.txt", "rb");
	errReadItem = fopen_s(&pFileItem, "./Data/Info/Item.txt", "rb");
	if (0 == errReadJob && 0 == errReadItem)
	{
		fread(pInfo, sizeof(INFO), 1, pFileJob);
		fread(pItem, sizeof(ITEM), 1, pFileItem);
		fclose(pFileJob);
		fclose(pFileItem);
	}
	else
	{
		cout << "불러오기 실패" << endl;
		system("pause");
	}
	cout << "불러오기 성공" << endl;

}

void CPlayer::Initialize(int _iChoose)
{
	switch (_iChoose)
	{
	case 1:
		pInfo->iAttack = 10;
		pInfo->iCurrentHp = 10;
		pInfo->iCurrentMana = 10;
		pInfo->iMaxHp = 10;
		pInfo->iMaxMana = 10;
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "전사");
		break;
	case 2:
		pInfo->iAttack = 20;
		pInfo->iCurrentHp = 20;
		pInfo->iCurrentMana = 20;
		pInfo->iMaxHp = 20;
		pInfo->iMaxMana = 20;
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "마법사");
		break;
	case 3:
		pInfo->iAttack = 30;
		pInfo->iCurrentHp = 30;
		pInfo->iCurrentMana = 30;
		pInfo->iMaxHp = 30;
		pInfo->iMaxMana = 30;
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "도적");
		break;
	default:
		break;
	}
}

void CPlayer::Update()
{
	system("cls");
	cout << "================\n직업 : " << pInfo->szName << endl;
	cout << "체력 : " << pInfo->iCurrentHp << " / " << pInfo->iMaxHp << endl;
	cout << "마나 : " << pInfo->iCurrentMana << " / " << pInfo->iMaxMana << "\t  공격력 : " << pInfo->iAttack << endl;
	cout << "경험치 : " << pInfo->iExp << " / " << pInfo->iMaxExp << endl;
	cout << "레벨 : " << pInfo->iLevel << endl;
}

void CPlayer::Release()
{
	cout << "플레이어 릴리즈->소멸자 호출" << endl;
}