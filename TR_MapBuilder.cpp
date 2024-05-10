#include "TR_MapBuilder.h"

CMapBuilder::CMapBuilder()
{
	m_pPlayer = nullptr;
	m_pBattle = nullptr;
	m_pMonster = nullptr;
	m_pCToString = nullptr;
}

CMapBuilder::~CMapBuilder()
{
	Release();
}

void CMapBuilder::Initialize()
{
	
}

void CMapBuilder::Update()
{
}

void CMapBuilder::Release()
{
	SAFE_DELETE(m_pBattle);
	SAFE_DELETE(m_pMonster);
	//SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pCToString);
}

void CMapBuilder::Map_Home()
{
	int iInput(0);
	if (!m_pCToString)
	{
		m_pCToString = new CToString;
		m_pPlayer->Set_CToString(m_pCToString);
	}
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
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

void CMapBuilder::Map_Shop()
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
		m_pPlayer->Check_Equip();
		if (!strcmp(m_pPlayer->Get_Info()->szName, "����"))
		{
			cout << "1. ���(1000G)\t2. ����(1500G)\t3. ���ư���" << endl;
		}
		else if (!strcmp(m_pPlayer->Get_Info()->szName, "������"))
		{
			cout << "1. ������(1000G)\t2. ����å(1500G)\t3. ���ư���" << endl;
		}
		else//(!strcmp(m_pPlayer->Get_Info()->szName, "����"))
		{
			cout << "1. ������ �ܰ�(1000G)\t2. ���� �尩(1500G)\t3. ���ư���" << endl;
		}
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (!(m_pPlayer->Get_Item()->bMain_Item))
			{
				
				if (WEAPON <= m_pPlayer->Get_Item()->iGold)
				{
					m_pPlayer->Get_Item()->iGold -= 1000;
					cout << "����� ���ſϷ�!" << endl;
					m_pPlayer->Get_Item()->bMain_Item = true;
					if (!strcmp(m_pPlayer->Get_Info()->szName, "����"))
					{
						m_pPlayer->Get_Info()->iAttack += 15; //����� ���ݷ� +++
					}
					else if (!strcmp(m_pPlayer->Get_Info()->szName, "������"))
					{
						m_pPlayer->Get_Info()->iAttack += 10; //������� ���ݷ�++ 
						m_pPlayer->Get_Info()->iCritical_Percent += 5; //ġ��Ÿ+
					}
					else//(!strcmp(m_pPlayer->Get_Info()->szName, "����"))
					{
						m_pPlayer->Get_Info()->iAttack += 5; //������ ���ݷ�+
						m_pPlayer->Get_Info()->iCritical_Percent += 10; //ġ��Ÿ++
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
			if (!(m_pPlayer->Get_Item()->bSub_Item))
			{
				if (SUB_WEAPON <= m_pPlayer->Get_Item()->iGold)
				{
					m_pPlayer->Get_Item()->iGold -= 1500;
					cout << "������� ���ſϷ�!" << endl;
					m_pPlayer->Get_Item()->bSub_Item = true;
					if (!strcmp(m_pPlayer->Get_Info()->szName, "����"))
					{
						m_pPlayer->Get_Info()->iMaxHp += 50; // ����� ü��+
						m_pPlayer->Get_Info()->iCurrentHp += 50;
					}
					else if (!strcmp(m_pPlayer->Get_Info()->szName, "������"))
					{
						m_pPlayer->Get_Info()->iMaxMana += 50; // ������� ����+
						m_pPlayer->Get_Info()->iCurrentMana += 50;
					}
					else//(!strcmp(m_pPlayer->Get_Info()->szName, "����"))
					{
						m_pPlayer->Get_Info()->iCritical_Percent += 10; //������ ġ��Ÿ+
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
		m_pPlayer->Check_Equip();
		cout << "1. ü������\t2. ��������\t3. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (HEAL_POTION <= m_pPlayer->Get_Item()->iGold)
			{
				m_pPlayer->Get_Item()->iGold -= 100;
				m_pPlayer->Get_Item()->iPotion += 1;
				cout << "ü������ ���ſϷ�!" << endl;
				cout << "���� ���Ǽ� : " << m_pPlayer->Get_Item()->iPotion << " ��" << endl;
			}
			else
			{
				cout << "��尡 ������" << endl;
			}
			
			system("pause");
			break;
		case 2:
			if (MANA_POTION <= m_pPlayer->Get_Item()->iGold)
			{
				m_pPlayer->Get_Item()->iGold -= 150;
				m_pPlayer->Get_Item()->iManaPotion += 1;
				cout << "�������� ���ſϷ�!" << endl;
				cout << "���� �������Ǽ� : " << m_pPlayer->Get_Item()->iManaPotion << " ��" << endl;
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
		m_pBattle->Set_Player(m_pPlayer);
	}
	if (!m_pMonster)
	{
		m_pMonster = new CMonster;
		m_pBattle->Set_Monster(m_pMonster);
		m_pMonster->Set_CToString(m_pCToString);

	}
	while (true)
	{
		m_pPlayer->Render();
		cout << "1. �ʱ�\t2. �߱�\t3. ���\t4. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pMonster->Initialize(iInput);
			m_pBattle->Battle_Map();
			break;
		case 2:
			m_pMonster->Initialize(iInput);
			m_pBattle->Battle_Map();
			break;
		case 3:
			m_pMonster->Initialize(iInput);
			m_pBattle->Battle_Map();
			break;
		case 4:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}

void CMapBuilder::Set_Player(CPlayer* _pPlayer)
{
	m_pPlayer = _pPlayer;
}
