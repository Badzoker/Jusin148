#include "TR_MainGame.h"

CMainGame::CMainGame()
{
	m_pMonster = nullptr;
	m_pPlayer = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_pMonster = new CMonster;
	m_pPlayer = new CPlayer;
}

void CMainGame::Update()
{
	Menu();
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pMonster);
	SAFE_DELETE(m_pPlayer);
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
		fwrite(m_pPlayer->Get_Info(), sizeof(INFO), 1, pFileJob);
		fwrite(m_pPlayer->Get_Item(), sizeof(ITEM), 1, pFileItem);
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
			m_pPlayer->Initialize(iInput);
			Home();
			break;
		case 2:
			m_pPlayer->Load();
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
		m_pPlayer->Update();
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
			m_pPlayer->Check_Equip();
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
		m_pPlayer->Check_Equip();
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
		m_pPlayer->Check_Equip();
		if (!strcmp(m_pPlayer->Get_Info()->szName, "����"))
		{
			cout << "1. ���\t2. ����\t3. ���ư���" << endl;
		}
		else if (!strcmp(m_pPlayer->Get_Info()->szName, "������"))
		{
			cout << "1. ������\t2. ����å(��������)\t3. ���ư���" << endl;
		}
		else//(!strcmp(m_pPlayer->Get_Info()->szName, "����"))
		{
			cout << "1. ������ �ܰ�\t2. ���� �ܰ�\t3. ���ư���" << endl;
		}
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (!m_pPlayer->Get_Item()->bMain_Item)
			{
				cout << "����� ���ſϷ�!" << endl;
				m_pPlayer->Get_Item()->bMain_Item = true;
				m_pPlayer->Get_Info()->iAttack += 10; //�׳� ������ ��
			}
			else
			{
				cout << "�̹� ��������" << endl;
			}
			system("pause");
			break;
		case 2:
			if (!m_pPlayer->Get_Item()->bSub_Item)
			{
				cout << "������� ���ſϷ�!" << endl;
				m_pPlayer->Get_Item()->bSub_Item = true;
				m_pPlayer->Get_Info()->iMaxHp += 50;//�׳� ������ ��
				m_pPlayer->Get_Info()->iCurrentHp += 50;
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
		m_pPlayer->Check_Equip();
		cout << "1. ü������\t2. ��������\t3. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pPlayer->Get_Item()->iPotion += 1;
			cout << "ü������ ���ſϷ�!" << endl;
			cout << "���� ���Ǽ� : " << m_pPlayer->Get_Item()->iPotion << " ��" << endl;
			system("pause");
			break;
		case 2:
			m_pPlayer->Get_Item()->iManaPotion += 1;
			cout << "�������� ���ſϷ�!" << endl;
			cout << "���� �������Ǽ� : " << m_pPlayer->Get_Item()->iManaPotion << " ��" << endl;
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
		m_pPlayer->Update();
		cout << "1. �ʱ�\t2. �߱�\t3. ���\t4. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pMonster->Initialize(iInput);
			Fight();
			break;
		case 2:
			m_pMonster->Initialize(iInput);
			Fight();
			break;
		case 3:
			m_pMonster->Initialize(iInput);
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
		m_pPlayer->Update();
		cout << "===============  v    s  ===============" << endl;
		m_pMonster->Update();
		cout << "1. ����    2. ��ų    3. ����    4. ����" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pMonster->Damaged(m_pPlayer->Attack());
			if (0 >= m_pMonster->Get_Info()->iCurrentHp)
			{
				m_pPlayer->Take_Reward(m_pMonster->Reward());
				return;
			}
			m_pPlayer->Damaged(m_pMonster->Attack());
			if (0 >= m_pPlayer->Get_Info()->iCurrentHp)
			{
				m_pPlayer->Respawn();
				return;
			}
			system("pause");
			break;
		case 2:
			if (0 != m_pPlayer->Skill())
			{
				m_pMonster->Damaged(m_pPlayer->Skill());
				if (0 >= m_pMonster->Get_Info()->iCurrentHp)
				{
					m_pPlayer->Take_Reward(m_pMonster->Reward());
					return;
				}
				m_pPlayer->Damaged(m_pMonster->Attack());
				if (0 >= m_pPlayer->Get_Info()->iCurrentHp)
				{
					m_pPlayer->Respawn();
					return;
				}
				system("pause");
			}
			break;
		case 3:
			m_pPlayer->Using_Tools();
			break;
		case 4:
			return;
		default:
			break;
		}
	}
}
