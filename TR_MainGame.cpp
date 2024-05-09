#include "TR_MainGame.h"

CMainGame::CMainGame()
{
	m_pMonster = nullptr;
	m_pPlayer = nullptr;
	m_pBattle = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_pMonster = new CMonster;
	m_pPlayer = new CPlayer;
	m_pBattle = new CBattle;
}

void CMainGame::Update()
{
	Menu();
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pMonster);
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pBattle);
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
			m_pPlayer->Save();
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
	m_pBattle->Battle_Map(m_pPlayer, m_pMonster);
}
