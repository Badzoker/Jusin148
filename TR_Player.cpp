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
	cout << "�÷��̾ " << _iDamage << " ��ŭ ���ظ� �Ծ���!" << endl;

	if (0 >= pInfo->iCurrentHp)
	{
		cout << "�÷��̾ " << _iDamage << " ��ŭ ���ظ� �԰� �׾���!" << endl;
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
		cout << "�ҷ����� ����" << endl;
		system("pause");
	}
	cout << "�ҷ����� ����" << endl;

}

void CPlayer::Check_Equip()
{
	char cTemp[32] = {};
	if (pItem->bMain_Item)
		strcpy_s(cTemp, sizeof(cTemp), "������");
	else
		strcpy_s(cTemp, sizeof(cTemp), "����");
	cout << "����� : " << cTemp << endl;

	if (pItem->bSub_Item)
		strcpy_s(cTemp, sizeof(cTemp), "������");
	else
		strcpy_s(cTemp, sizeof(cTemp), "����");
	cout << "������� : " << cTemp << endl;

	cout << "ü������ : " << pItem->iPotion << " ��" << endl;
	cout << "�������� : " << pItem->iManaPotion << " ��" << endl;
}

void CPlayer::Respawn()
{
	cout << "��Ȱ! ü�°� ������ ���� ä������!" << endl;
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
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "����");
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
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "������");
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
		strcpy_s(pInfo->szName, sizeof(pInfo->szName), "����");
		break;
	default:
		break;
	}
}

void CPlayer::Update()
{
	system("cls");
	cout << "================\n���� : " << pInfo->szName << endl;
	cout << "ü�� : " << pInfo->iCurrentHp << " / " << pInfo->iMaxHp << endl;
	cout << "���� : " << pInfo->iCurrentMana << " / " << pInfo->iMaxMana << "\t  ���ݷ� : " << pInfo->iAttack << endl;
	cout << "����ġ : " << pInfo->iExp << " / " << pInfo->iMaxExp << endl;
	cout << "���� : " << pInfo->iLevel << endl;
}

void CPlayer::Release()
{
	cout << "�÷��̾� �Ҹ��� ȣ��" << endl;
	SAFE_DELETE(pInfo);
	SAFE_DELETE(pItem);
}