#include "TR_MapBuilder.h"

CMapBuilder::CMapBuilder()
{
	m_pPlayer = nullptr;
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

void CMapBuilder::Map_Home()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pPlayer->Render();
		cout << "1. 사냥터    2. 상점    3. 상태창    4. 게임저장 후 종료    5. 메뉴" << endl;
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
		cout << "1. 장비\t2. 도구\t3. 돌아가기" << endl;
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
		if (!strcmp(m_pPlayer->Get_Info()->szName, "전사"))
		{
			cout << "1. 장검(1000G)\t2. 방패(1500G)\t3. 돌아가기" << endl;
		}
		else if (!strcmp(m_pPlayer->Get_Info()->szName, "마법사"))
		{
			cout << "1. 지팡이(1000G)\t2. 마법책(1500G)\t3. 돌아가기" << endl;
		}
		else//(!strcmp(m_pPlayer->Get_Info()->szName, "도적"))
		{
			cout << "1. 뾰족한 단검(1000G)\t2. 날쌘 장갑(1500G)\t3. 돌아가기" << endl;
		}
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (!(m_pPlayer->Get_Item()->bMain_Item))
			{
				if (1000 <= m_pPlayer->Get_Item()->iGold)
				{
					m_pPlayer->Get_Item()->iGold -= 1000;
					cout << "주장비 구매완료!" << endl;
					m_pPlayer->Get_Item()->bMain_Item = true;
					m_pPlayer->Get_Info()->iAttack += 10; //그냥 구현만 함
				}
				else
				{
					cout << "골드가 부족함!" << endl;
				}
			}
			else
			{
				cout << "이미 착용중임" << endl;
			}
			system("pause");
			break;
		case 2:
			if (!(m_pPlayer->Get_Item()->bSub_Item))
			{
				if (1500 <= m_pPlayer->Get_Item()->iGold)
				{
					m_pPlayer->Get_Item()->iGold -= 1500;
					cout << "보조장비 구매완료!" << endl;
					m_pPlayer->Get_Item()->bSub_Item = true;
					m_pPlayer->Get_Info()->iMaxHp += 50;//그냥 구현만 함
					m_pPlayer->Get_Info()->iCurrentHp += 50;
				}
				else
				{
					cout << "골드가 부족함" << endl;
				}
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

void CMapBuilder::Map_Shop_Consumable()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pPlayer->Check_Equip();
		cout << "1. 체력포션\t2. 마나포션\t3. 돌아가기" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (100 <= m_pPlayer->Get_Item()->iGold)
			{
				m_pPlayer->Get_Item()->iGold -= 100;
				m_pPlayer->Get_Item()->iPotion += 1;
				cout << "체력포션 구매완료!" << endl;
				cout << "현재 포션수 : " << m_pPlayer->Get_Item()->iPotion << " 개" << endl;
			}
			else
			{
				cout << "골드가 부족함" << endl;
			}
			
			system("pause");
			break;
		case 2:
			if (150 <= m_pPlayer->Get_Item()->iGold)
			{
				m_pPlayer->Get_Item()->iGold -= 150;
				m_pPlayer->Get_Item()->iManaPotion += 1;
				cout << "마나포션 구매완료!" << endl;
				cout << "현재 마나포션수 : " << m_pPlayer->Get_Item()->iManaPotion << " 개" << endl;
			}
			else
			{
				cout << "골드가 부족함" << endl;
			}
			
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

void CMapBuilder::Map_Dungeon()
{
	int iInput(0);
	if (!m_pMonster)
	{
		m_pMonster = new CMonster;
		m_pBattle->Set_Player(m_pPlayer);
		m_pBattle->Set_Monster(m_pMonster);
	}
	while (true)
	{
		m_pPlayer->Render();
		cout << "1. 초급\t2. 중급\t3. 고급\t4. 돌아가기" << endl;
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
