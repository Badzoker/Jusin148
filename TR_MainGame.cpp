#include "TR_MainGame.h"

CMainGame::CMainGame()
{
	pMonster = nullptr;
	pPlayer = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	pMonster = new CMonster;
	pPlayer = new CPlayer;
}

void CMainGame::Update()
{
	Menu();
}

void CMainGame::Release()
{
	SAFE_DELETE(pMonster);
	SAFE_DELETE(pPlayer);
}

void CMainGame::Save()
{
	FILE* pFileJob = NULL;
	FILE* pFileItem = NULL;
	errno_t errWriteJob = 0;
	errno_t errWriteItem = 0;
	errWriteJob = fopen_s(&pFileJob, "./Data/Info/Job.txt", "wb");
	errWriteItem = fopen_s(&pFileItem, "./Data/Info/Item.txt", "wb");
	if (0 == errWriteJob && 0 == errWriteItem)
	{
		cout << "job�����" << endl;
		fwrite(pPlayer->Get_Info(), sizeof(INFO), 1, pFileJob);
		fwrite(pPlayer->Get_Item(), sizeof(ITEM), 1, pFileItem);
		fclose(pFileJob);
		fclose(pFileItem);
	}
	else
	{
		cout << "job�������忡��" << endl;
	}
	system("pause");
}

void CMainGame::Menu()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		cout << "1. ���ӽ���\t2. �ҷ�����\t3. ����" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			system("cls");
			cout << "������ �����Ͻÿ�.(1. ���� , 2. ������ , 3. ����) :" << endl;
			cin >> iInput;
			pPlayer->Initialize(iInput);
			Home();
			break;
		case 2:
			pPlayer->Load();
			Home();
			break;
		case 3:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}

void CMainGame::Home()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		pPlayer->Update();
		cout << "1. �����    2. ����    3. ����â    4. �������� �� ����    5. �޴�" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Dungeon();
			break;
		case 2:
			Shop();
			break;
		case 3:
			pPlayer->Check_Equip();
			system("pause");
			break;
		case 4:
			Save();
			return;
		case 5:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}

void CMainGame::Shop()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		pPlayer->Check_Equip();
		cout << "1. ���\t2. ����\t3. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Shop_Equip();
			break;
		case 2:
			Shop_Consumable();
			break;
		case 3:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}

void CMainGame::Shop_Equip()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		pPlayer->Check_Equip();
		if (!strcmp(pPlayer->Get_Info()->szName, "����"))
		{
			cout << "1. ���\t2. ����\t3. ���ư���" << endl;
		}
		else if (!strcmp(pPlayer->Get_Info()->szName, "������"))
		{
			cout << "1. ������\t2. ����å(��������)\t3. ���ư���" << endl;
		}
		else//(!strcmp(pPlayer->Get_Info()->szName, "����"))
		{
			cout << "1. ������ �ܰ�\t2. ���� �ܰ�\t3. ���ư���" << endl;
		}
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (!pPlayer->Get_Item()->bMain_Item)
			{
				cout << "����� ���ſϷ�!" << endl;
				pPlayer->Get_Item()->bMain_Item = true;
				pPlayer->Get_Info()->iAttack += 10; //�׳� ������ ��
			}
			else
			{
				cout << "�̹� ��������" << endl;
			}
			system("pause");
			break;
		case 2:
			if (!pPlayer->Get_Item()->bSub_Item)
			{
				cout << "������� ���ſϷ�!" << endl;
				pPlayer->Get_Item()->bSub_Item = true;
				pPlayer->Get_Info()->iMaxHp += 50;//�׳� ������ ��
				pPlayer->Get_Info()->iCurrentHp += 50;
			}
			else
			{
				cout << "�̹� ��������" << endl;
			}
			system("pause");
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}

void CMainGame::Shop_Consumable()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		pPlayer->Check_Equip();
		cout << "1. ü������\t2. ��������\t3. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			pPlayer->Get_Item()->iPotion += 1;
			cout << "ü������ ���ſϷ�!" << endl;
			cout << "���� ���Ǽ� : " << pPlayer->Get_Item()->iPotion << " ��" << endl;
			system("pause");
			break;
		case 2:
			pPlayer->Get_Item()->iManaPotion += 1;
			cout << "�������� ���ſϷ�!" << endl;
			cout << "���� �������Ǽ� : " << pPlayer->Get_Item()->iManaPotion << " ��" << endl;
			system("pause");
			break;
		case 3:
			return;
		default:
			cout << "�߸� �Է��߽��ϴ�." << endl;
			break;
		}
	}
}

void CMainGame::Dungeon()
{
	int iInput(0);
	while (true)
	{
		pPlayer->Update();
		cout << "1. �ʱ�\t2. �߱�\t3. ���\t4. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			pMonster->Initialize(iInput);
			Fight();
			break;
		case 2:
			pMonster->Initialize(iInput);
			Fight();
			break;
		case 3:
			pMonster->Initialize(iInput);
			Fight();
			break;
		case 4:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}

void CMainGame::Fight()
{
	int iInput(0);
	while (true)
	{
		pPlayer->Update();
		cout << "===============  v    s  ===============" << endl;
		pMonster->Update();
		cout << "1. ����    2. ��ų    3. ����    4. ����" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			pMonster->Damaged(pPlayer->Attack());
			if (0 >= pMonster->Get_Info()->iCurrentHp)
			{
				pPlayer->Take_Reward(pMonster->Reward());
				return;
			}
			pPlayer->Damaged(pMonster->Attack());
			if (0 >= pPlayer->Get_Info()->iCurrentHp)
			{
				pPlayer->Respawn();
				return;
			}
			system("pause");
			break;
		case 2:
			return;
		case 3:
			return;
		case 4:
			return;
		default:
			break;
		}
	}
}
