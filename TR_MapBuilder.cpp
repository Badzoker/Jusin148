#include "TR_MapBuilder.h"

CMapBuilder::CMapBuilder()
{
	m_pBattle = nullptr;
	m_pMonster = nullptr;
}

CMapBuilder::~CMapBuilder()
{
	Release();
}

void CMapBuilder::Initialize()
{
	m_pBattle = new CBattle;
}

void CMapBuilder::Update()
{
}

void CMapBuilder::Release()
{
	SAFE_DELETE(m_pBattle);
	SAFE_DELETE(m_pMonster);
}

void CMapBuilder::Map_Home(CPlayer* _pPlayer)
{
	int iInput(0);
	while (true)
	{
		system("cls");
		_pPlayer->Update();
		cout << "1. �����    2. ����    3. ����â    4. �������� �� ����    5. �޴�" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Map_Dungeon(_pPlayer);
			break;
		case 2:
			Map_Shop(_pPlayer);
			break;
		case 3:
			_pPlayer->Check_Equip();
			system("pause");
			break;
		case 4:
			_pPlayer->Save();
			return;
		case 5:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}

void CMapBuilder::Map_Shop(CPlayer* _pPlayer)
{
	int iInput(0);
	while (true)
	{
		system("cls");
		_pPlayer->Check_Equip();
		cout << "1. ���\t2. ����\t3. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Map_Shop_Equip(_pPlayer);
			break;
		case 2:
			Map_Shop_Consumable(_pPlayer);
			break;
		case 3:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}

void CMapBuilder::Map_Shop_Equip(CPlayer* _pPlayer)
{
	int iInput(0);
	while (true)
	{
		system("cls");
		_pPlayer->Check_Equip();
		if (!strcmp(_pPlayer->Get_Info()->szName, "����"))
		{
			cout << "1. ���\t2. ����\t3. ���ư���" << endl;
		}
		else if (!strcmp(_pPlayer->Get_Info()->szName, "������"))
		{
			cout << "1. ������\t2. ����å(��������)\t3. ���ư���" << endl;
		}
		else//(!strcmp(_pPlayer->Get_Info()->szName, "����"))
		{
			cout << "1. ������ �ܰ�\t2. ���� �ܰ�\t3. ���ư���" << endl;
		}
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (!_pPlayer->Get_Item()->bMain_Item)
			{
				cout << "����� ���ſϷ�!" << endl;
				_pPlayer->Get_Item()->bMain_Item = true;
				_pPlayer->Get_Info()->iAttack += 10; //�׳� ������ ��
			}
			else
			{
				cout << "�̹� ��������" << endl;
			}
			system("pause");
			break;
		case 2:
			if (!_pPlayer->Get_Item()->bSub_Item)
			{
				cout << "������� ���ſϷ�!" << endl;
				_pPlayer->Get_Item()->bSub_Item = true;
				_pPlayer->Get_Info()->iMaxHp += 50;//�׳� ������ ��
				_pPlayer->Get_Info()->iCurrentHp += 50;
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

void CMapBuilder::Map_Shop_Consumable(CPlayer* _pPlayer)
{
	int iInput(0);
	while (true)
	{
		system("cls");
		_pPlayer->Check_Equip();
		cout << "1. ü������\t2. ��������\t3. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			_pPlayer->Get_Item()->iPotion += 1;
			cout << "ü������ ���ſϷ�!" << endl;
			cout << "���� ���Ǽ� : " << _pPlayer->Get_Item()->iPotion << " ��" << endl;
			system("pause");
			break;
		case 2:
			_pPlayer->Get_Item()->iManaPotion += 1;
			cout << "�������� ���ſϷ�!" << endl;
			cout << "���� �������Ǽ� : " << _pPlayer->Get_Item()->iManaPotion << " ��" << endl;
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

void CMapBuilder::Map_Dungeon(CPlayer* _pPlayer)
{
	int iInput(0);
	if (!m_pMonster)
		m_pMonster = new CMonster;
	while (true)
	{
		_pPlayer->Update();
		cout << "1. �ʱ�\t2. �߱�\t3. ���\t4. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pMonster->Initialize(iInput);
			m_pBattle->Battle_Map(_pPlayer, m_pMonster);
			break;
		case 2:
			m_pMonster->Initialize(iInput);
			m_pBattle->Battle_Map(_pPlayer, m_pMonster);
			break;
		case 3:
			m_pMonster->Initialize(iInput);
			m_pBattle->Battle_Map(_pPlayer, m_pMonster);
			break;
		case 4:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}
