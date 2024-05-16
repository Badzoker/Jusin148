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
	SAFE_DELETE(m_pMonster);
	SAFE_DELETE(m_pBattle);
	SAFE_DELETE(m_pCToString);
	SAFE_DELETE(m_pPlayer);
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
		if (!strcmp(PLAYER->szName, "전사"))
		{
			cout << "1. 장검(1000G)\t2. 방패(1500G)\t3. 돌아가기" << endl;
		}
		else if (!strcmp(PLAYER->szName, "마법사"))
		{
			cout << "1. 지팡이(1000G)\t2. 마법책(1500G)\t3. 돌아가기" << endl;
		}
		else//(!strcmp(PLAYER_G->szName, "도적"))
		{
			cout << "1. 뾰족한 단검(1000G)\t2. 날쌘 장갑(1500G)\t3. 돌아가기" << endl;
		}
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (!(PLAYER_ITEM->bMain_Item))
			{
				
				if (WEAPON <= PLAYER->iGold)
				{
					PLAYER->iGold -= 1000;
					cout << "주장비 구매완료!" << endl;
					PLAYER_ITEM->bMain_Item = true;
					if (!strcmp(PLAYER->szName, "전사"))
					{
						PLAYER->iAttack += 15; //전사는 공격력 +++
					}
					else if (!strcmp(PLAYER->szName, "마법사"))
					{
						PLAYER->iAttack += 10; //마법사는 공격력++ 
						PLAYER->iCritical_Percent += 5; //치명타+
					}
					else//(!strcmp(PLAYER_G->szName, "도적"))
					{
						PLAYER->iAttack += 5; //도적은 공격력+
						PLAYER->iCritical_Percent += 10; //치명타++
					}
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
			if (!(PLAYER_ITEM->bSub_Item))
			{
				if (SUB_WEAPON <= PLAYER->iGold)
				{
					PLAYER->iGold -= 1500;
					cout << "보조장비 구매완료!" << endl;
					PLAYER_ITEM->bSub_Item = true;
					if (!strcmp(PLAYER->szName, "전사"))
					{
						PLAYER->iMaxHp += 50; // 전사는 체력+
						PLAYER->iCurrentHp += 50;
					}
					else if (!strcmp(PLAYER->szName, "마법사"))
					{
						PLAYER->iMaxMana += 50; // 마법사는 마나+
						PLAYER->iCurrentMana += 50;
					}
					else//(!strcmp(PLAYER_G->szName, "도적"))
					{
						PLAYER->iCritical_Percent += 10; //도적은 치명타+
					}
					
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
			if (HEAL_POTION <= PLAYER->iGold)
			{
				PLAYER->iGold -= 100;
				PLAYER_ITEM->iPotion += 1;
				cout << "체력포션 구매완료!" << endl;
				cout << "현재 포션수 : " << PLAYER_ITEM->iPotion << " 개" << endl;
			}
			else
			{
				cout << "골드가 부족함" << endl;
			}
			
			system("pause");
			break;
		case 2:
			if (MANA_POTION <= PLAYER->iGold)
			{
				PLAYER->iGold -= 150;
				PLAYER_ITEM->iManaPotion += 1;
				cout << "마나포션 구매완료!" << endl;
				cout << "현재 마나포션수 : " << PLAYER_ITEM->iManaPotion << " 개" << endl;
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
		cout << "1. 초급\t2. 중급\t3. 고급\t4. 돌아가기" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pMonster->Initialize(iInput);
			m_pBattle->Update();
			break;
		case 2:
			m_pMonster->Initialize(iInput);
			m_pBattle->Update();
			break;
		case 3:
			m_pMonster->Initialize(iInput);
			m_pBattle->Update();
			break;
		case 4:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}
