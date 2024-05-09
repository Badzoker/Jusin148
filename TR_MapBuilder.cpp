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
		cout << "1. 사냥터    2. 상점    3. 상태창    4. 게임저장 후 종료    5. 메뉴" << endl;
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
		cout << "1. 장비\t2. 도구\t3. 돌아가기" << endl;
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
		if (!strcmp(_pPlayer->Get_Info()->szName, "전사"))
		{
			cout << "1. 장검\t2. 방패\t3. 돌아가기" << endl;
		}
		else if (!strcmp(_pPlayer->Get_Info()->szName, "마법사"))
		{
			cout << "1. 지팡이\t2. 마법책(마나증가)\t3. 돌아가기" << endl;
		}
		else//(!strcmp(_pPlayer->Get_Info()->szName, "도적"))
		{
			cout << "1. 뾰족한 단검\t2. 작은 단검\t3. 돌아가기" << endl;
		}
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (!_pPlayer->Get_Item()->bMain_Item)
			{
				cout << "주장비 구매완료!" << endl;
				_pPlayer->Get_Item()->bMain_Item = true;
				_pPlayer->Get_Info()->iAttack += 10; //그냥 구현만 함
			}
			else
			{
				cout << "이미 착용중임" << endl;
			}
			system("pause");
			break;
		case 2:
			if (!_pPlayer->Get_Item()->bSub_Item)
			{
				cout << "보조장비 구매완료!" << endl;
				_pPlayer->Get_Item()->bSub_Item = true;
				_pPlayer->Get_Info()->iMaxHp += 50;//그냥 구현만 함
				_pPlayer->Get_Info()->iCurrentHp += 50;
			}
			else
			{
				cout << "이미 착용중임" << endl;
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
		cout << "1. 체력포션\t2. 마나포션\t3. 돌아가기" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			_pPlayer->Get_Item()->iPotion += 1;
			cout << "체력포션 구매완료!" << endl;
			cout << "현재 포션수 : " << _pPlayer->Get_Item()->iPotion << " 개" << endl;
			system("pause");
			break;
		case 2:
			_pPlayer->Get_Item()->iManaPotion += 1;
			cout << "마나포션 구매완료!" << endl;
			cout << "현재 마나포션수 : " << _pPlayer->Get_Item()->iManaPotion << " 개" << endl;
			system("pause");
			break;
		case 3:
			return;
		default:
			cout << "잘못 입력했습니다." << endl;
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
		cout << "1. 초급\t2. 중급\t3. 고급\t4. 돌아가기" << endl;
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
