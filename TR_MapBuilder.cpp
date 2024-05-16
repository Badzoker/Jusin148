#include "TR_MapBuilder.h"

CMapBuilder::CMapBuilder()
{
	m_pPlayer_GameManager = nullptr;
	m_pBattle = nullptr;
	m_pMonster_GameManager = nullptr;
	m_pCToString = nullptr;
	cout << "mapbuilder creator" << endl;
	system("pause");
}

CMapBuilder::~CMapBuilder()
{
	Release();
}

//void CMapBuilder::Initialize()
//{
//	
//}
//
//void CMapBuilder::Update()
//{
//}

void CMapBuilder::Release()
{
	SAFE_DELETE(m_pMonster_GameManager);
	SAFE_DELETE(m_pBattle);
	SAFE_DELETE(m_pCToString);
	SAFE_DELETE(m_pPlayer_GameManager);
	cout << "mapbuilder eliminated" << endl; //�ȺҸ�..
	system("pause");
}

void CMapBuilder::Map_Home()
{
	int iInput(0);
	if (!m_pCToString)
	{
		m_pCToString = new CToString;
		m_pPlayer_GameManager->Set_CToString(m_pCToString);
	}
	while (true)
	{
		system("cls");
		m_pPlayer_GameManager->Render();
		cout << "1. �����    2. ����    3. ����â    4. �������� �� ����    5. �޴�" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Map_Dungeon();
			break;
		case 2:
			Map_Shop();
			break;
		case 3:
			m_pPlayer_GameManager->Check_Equip();
			system("pause");
			break;
		case 4:
			m_pPlayer_GameManager->Save();
			SAFE_DELETE(m_pPlayer_GameManager);
			return;
		case 5:
			SAFE_DELETE(m_pPlayer_GameManager);
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}

void CMapBuilder::Map_Shop()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pPlayer_GameManager->Check_Equip();
		cout << "1. ���\t2. ����\t3. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Map_Shop_Equip();
			break;
		case 2:
			Map_Shop_Consumable();
			break;
		case 3:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}

void CMapBuilder::Map_Shop_Equip()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pPlayer_GameManager->Check_Equip();
		if (!strcmp(PLAYER_G->szName, "����"))
		{
			cout << "1. ���(1000G)\t2. ����(1500G)\t3. ���ư���" << endl;
		}
		else if (!strcmp(PLAYER_G->szName, "������"))
		{
			cout << "1. ������(1000G)\t2. ����å(1500G)\t3. ���ư���" << endl;
		}
		else//(!strcmp(PLAYER_G->szName, "����"))
		{
			cout << "1. ������ �ܰ�(1000G)\t2. ���� �尩(1500G)\t3. ���ư���" << endl;
		}
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (!(PLAYER_G_ITEM->bMain_Item))
			{
				
				if (WEAPON <= PLAYER_G->iGold)
				{
					PLAYER_G->iGold -= 1000;
					cout << "����� ���ſϷ�!" << endl;
					PLAYER_G_ITEM->bMain_Item = true;
					if (!strcmp(PLAYER_G->szName, "����"))
					{
						PLAYER_G->iAttack += 15; //����� ���ݷ� +++
					}
					else if (!strcmp(PLAYER_G->szName, "������"))
					{
						PLAYER_G->iAttack += 10; //������� ���ݷ�++ 
						PLAYER_G->iCritical_Percent += 5; //ġ��Ÿ+
					}
					else//(!strcmp(PLAYER_G->szName, "����"))
					{
						PLAYER_G->iAttack += 5; //������ ���ݷ�+
						PLAYER_G->iCritical_Percent += 10; //ġ��Ÿ++
					}
				}
				else
				{
					cout << "��尡 ������!" << endl;
				}
			}
			else
			{
				cout << "�̹� ��������" << endl;
			}
			system("pause");
			break;
		case 2:
			if (!(PLAYER_G_ITEM->bSub_Item))
			{
				if (SUB_WEAPON <= PLAYER_G->iGold)
				{
					PLAYER_G->iGold -= 1500;
					cout << "������� ���ſϷ�!" << endl;
					PLAYER_G_ITEM->bSub_Item = true;
					if (!strcmp(PLAYER_G->szName, "����"))
					{
						PLAYER_G->iMaxHp += 50; // ����� ü��+
						PLAYER_G->iCurrentHp += 50;
					}
					else if (!strcmp(PLAYER_G->szName, "������"))
					{
						PLAYER_G->iMaxMana += 50; // ������� ����+
						PLAYER_G->iCurrentMana += 50;
					}
					else//(!strcmp(PLAYER_G->szName, "����"))
					{
						PLAYER_G->iCritical_Percent += 10; //������ ġ��Ÿ+
					}
					
				}
				else
				{
					cout << "��尡 ������" << endl;
				}
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

void CMapBuilder::Map_Shop_Consumable()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pPlayer_GameManager->Check_Equip();
		cout << "1. ü������\t2. ��������\t3. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (HEAL_POTION <= PLAYER_G->iGold)
			{
				PLAYER_G->iGold -= 100;
				PLAYER_G_ITEM->iPotion += 1;
				cout << "ü������ ���ſϷ�!" << endl;
				cout << "���� ���Ǽ� : " << PLAYER_G_ITEM->iPotion << " ��" << endl;
			}
			else
			{
				cout << "��尡 ������" << endl;
			}
			
			system("pause");
			break;
		case 2:
			if (MANA_POTION <= PLAYER_G->iGold)
			{
				PLAYER_G->iGold -= 150;
				PLAYER_G_ITEM->iManaPotion += 1;
				cout << "�������� ���ſϷ�!" << endl;
				cout << "���� �������Ǽ� : " << PLAYER_G_ITEM->iManaPotion << " ��" << endl;
			}
			else
			{
				cout << "��尡 ������" << endl;
			}
			
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

void CMapBuilder::Map_Dungeon()
{
	int iInput(0);
	if (!m_pBattle)
	{
		m_pBattle = new CBattle;
		m_pBattle->Set_Player(m_pPlayer_GameManager);
	}
	if (!m_pMonster_GameManager)
	{
		m_pMonster_GameManager = new CMonster;
		m_pBattle->Set_Monster(m_pMonster_GameManager);
		m_pMonster_GameManager->Set_CToString(m_pCToString);
	}
	while (true)
	{
		m_pPlayer_GameManager->Render();
		cout << "1. �ʱ�\t2. �߱�\t3. ���\t4. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pMonster_GameManager->Initialize(iInput);
			m_pBattle->Update();
			break;
		case 2:
			m_pMonster_GameManager->Initialize(iInput);
			m_pBattle->Update();
			break;
		case 3:
			m_pMonster_GameManager->Initialize(iInput);
			m_pBattle->Update();
			break;
		case 4:
			SAFE_DELETE(m_pMonster_GameManager);
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}
