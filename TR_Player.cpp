#include "TR_Player.h"

CPlayer::CPlayer()
{
	pInfo = nullptr;
	pItem = nullptr;
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

void CPlayer::Level_Up()
{
	pInfo->iMaxExp += 50;
	pInfo->iExp = 0;
	pInfo->iLevel += 1;
	pInfo->iAttack += 10;
	pInfo->iMaxHp += 10;
	pInfo->iMaxMana += 10;
	pInfo->iCurrentHp = pInfo->iMaxHp;
	pInfo->iCurrentMana = pInfo->iMaxMana;
	cout << "Level up!" << endl;
}

void CPlayer::Load()
{
	pInfo = new INFO;
	pItem = new ITEM;
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

void CPlayer::Check_Equip()
{
	char cTemp[32] = {};
	if (pItem->bMain_Item)
		strcpy_s(cTemp, sizeof(cTemp), "착용중");
	else
		strcpy_s(cTemp, sizeof(cTemp), "없음");
	cout << "주장비 : " << cTemp << endl;

	if (pItem->bSub_Item)
		strcpy_s(cTemp, sizeof(cTemp), "착용중");
	else
		strcpy_s(cTemp, sizeof(cTemp), "없음");
	cout << "보조장비 : " << cTemp << endl;

	cout << "체력포션 : " << pItem->iPotion << " 개" << endl;
	cout << "마나포션 : " << pItem->iManaPotion << " 개" << endl;
}

void CPlayer::Respawn()
{
	cout << "부활! 체력과 마나가 가득 채워졌다!" << endl;
	pInfo->iCurrentHp = pInfo->iMaxHp;
	pInfo->iCurrentMana = pInfo->iMaxMana;
	system("pause");
}

void CPlayer::Take_Reward(int _iReward)
{
	pInfo->iExp += _iReward;
	if (pInfo->iMaxExp <= pInfo->iExp)
	{
		Level_Up();
	}
	system("pause");
}

INFO* CPlayer::Get_Info()
{
	return pInfo;
}

ITEM* CPlayer::Get_Item()
{
	return pItem;
}

void CPlayer::Initialize(int _iChoose)
{
	pInfo = new INFO;
	pItem = new ITEM;
	switch (_iChoose)
	{
	case 1:
		pInfo->iAttack = 10;
		pInfo->iMaxHp = 100;
		pInfo->iCurrentHp = pInfo->iMaxHp;
		pInfo->iMaxMana = 20;
		pInfo->iCurrentMana = pInfo->iMaxMana;
		pInfo->iLevel = 1;
		pInfo->iExp = 0;
		pInfo->iMaxExp = 100;
		pItem->bMain_Item = false;
		pItem->bSub_Item = false;
		pItem->iPotion = 0;
		pItem->iManaPotion = 0;
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "전사");
		break;
	case 2:
		pInfo->iAttack = 20;
		pInfo->iMaxHp = 50;
		pInfo->iCurrentHp = pInfo->iMaxHp;
		pInfo->iMaxMana = 50;
		pInfo->iCurrentMana = pInfo->iMaxMana;
		pInfo->iLevel = 1;
		pInfo->iExp = 0;
		pInfo->iMaxExp = 100;
		pItem->bMain_Item = false;
		pItem->bSub_Item = false;
		pItem->iPotion = 0;
		pItem->iManaPotion = 0;
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "마법사");
		break;
	case 3:
		pInfo->iAttack = 15;
		pInfo->iMaxHp = 75;
		pInfo->iCurrentHp = pInfo->iMaxHp;
		pInfo->iMaxMana = 35;
		pInfo->iCurrentMana = pInfo->iMaxMana;
		pInfo->iLevel = 1;
		pInfo->iExp = 0;
		pInfo->iMaxExp = 100;
		pItem->bMain_Item = false;
		pItem->bSub_Item = false;
		pItem->iPotion = 0;
		pItem->iManaPotion = 0;
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
	cout << "플레이어 소멸자 호출" << endl;
	SAFE_DELETE(pInfo);
	SAFE_DELETE(pItem);
}