#include "TR_MapBuilder.h"

CMapBuilder::CMapBuilder()
{
	m_pPlayer_GameManager = nullptr;
	m_pBattle = nullptr;
	m_pMonster_GameManager = nullptr;
	m_pCToString = nullptr;
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
		cout << "1. ���\t2. ����\t3. ���ư���     4.������" << endl;
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
		case 4:
			Map_Shop_Manager();
			break;
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

void CMapBuilder::Map_Shop_Manager()
{
	Map_Shop_Load();
	char szTemp[32] = {};
	int iInput(0);
	if (!m_pShop)
	{
		m_pShop = new SHOP;
	}
	SHOP* tTemp = nullptr;
	while (true)
	{
		system("cls");
		cout << "1. ������ �߰�   2. ����   3. ���   4. ����" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (0 != m_pShop->iCount)
			{
				tTemp = new SHOP[(m_pShop->iCount) + 1];
				memcpy(tTemp, m_pShop, sizeof(SHOP) * (m_pShop->iCount));
				SAFE_DELETE_ARRAY(m_pShop);
				m_pShop = tTemp;
			}
			cout << "����� �Դϱ�?  1. Y  2. N" << endl;
			cin >> iInput;
			if (1 == iInput)
				m_pShop[m_pShop->iCount].bIs_Main = true;
			else
				m_pShop[m_pShop->iCount].bIs_Main = false;

			
			cout << "������ �̸��� ���ϱ�? :" << endl;
			cin >> m_pShop[m_pShop->iCount].szName;
			//gets_s(m_pShop[m_pShop->iCount].szName, sizeof(m_pShop[m_pShop->iCount].szName));
			//fgets(szTemp, sizeof(szTemp), stdin);
			//strcpy_s()
			cout << "�̸� �Է¿Ϸ�" << endl;
			cout << "������ �󸿴ϱ�? :" << endl;
			cin >> iInput;
			m_pShop[m_pShop->iCount].iGold = iInput;
			cout << "��ϵ� ��ǰ��\n�����? : " << m_pShop[m_pShop->iCount].bIs_Main << "\n�̸� : " << m_pShop[m_pShop->iCount].szName << "\n���� : " << m_pShop[m_pShop->iCount].iGold << endl;
			m_pShop->iCount += 1;
			cout << "��ϵ� ��ǰ�� �� " << m_pShop->iCount << "�� �Դϴ�." << endl;
			system("pause");
			break;
		case 2:
			SAFE_DELETE_ARRAY(m_pShop);
			return;
		case 3:
			for (int i = 0; i < m_pShop->iCount; i++)
			{
				cout << "��ϵ� ��ǰ��\n�����? : " << m_pShop[i].bIs_Main << "\n�̸� : " << m_pShop[i].szName << "\n���� : " << m_pShop[i].iGold << endl << endl;
			}
			cout << "��ϵ� ��ǰ�� �� " << m_pShop->iCount << "�� �Դϴ�." << endl;
			system("pause");
			break;
		case 4:
			Map_Shop_Save();
			break;
		default:
			break;
		}
	}
}

void CMapBuilder::Map_Shop_Save()
{
	FILE* pFileShop = NULL;
	errno_t errReadItem = 0;
	errReadItem = fopen_s(&pFileShop, "./Data/Info/Shop.txt", "wb");
	if (0 == errReadItem)
	{
		fwrite(m_pShop, sizeof(SHOP), m_pShop->iCount, pFileShop);
		fclose(pFileShop);
		cout << "���� ���� ����" << endl;
		system("pause");
	}
	else
	{
		cout << "���� ���� ����" << endl;
		system("pause");
	}
}

void CMapBuilder::Map_Shop_Load()
{
	SHOP* pTemp = new SHOP;
	FILE* pFileShopCount = NULL;
	FILE* pFileShop = NULL;
	errno_t errReadItemCount = 0;
	errno_t errReadItem = 0;
	errReadItemCount = fopen_s(&pFileShopCount, "./Data/Info/Shop.txt", "rb");
	errReadItem = fopen_s(&pFileShop, "./Data/Info/Shop.txt", "rb");
	if (0 == errReadItem)
	{
		fread(pTemp, sizeof(SHOP), 1, pFileShopCount);
		fclose(pFileShopCount);
		cout << "���� ���� �ҷ����� ����" << endl;
		system("pause");
		if (0 == errReadItem)
		{
			m_pShop = new SHOP[pTemp->iCount];
			fread(m_pShop, sizeof(SHOP), pTemp->iCount, pFileShop);
			fclose(pFileShop);
			cout << "���� �ҷ����� ����" << endl;
			//SAFE_DELETE(pTemp);
			system("pause");
		}
		else
		{
			cout << "���� �ҷ����� ����" << endl;
			system("pause");
		}
	}
	else
	{
		cout << "���� ���� �ҷ����� ����" << endl;
		system("pause");
	}
	if (nullptr != pTemp)
	{
		SAFE_DELETE(pTemp);
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
