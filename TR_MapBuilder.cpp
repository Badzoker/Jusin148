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
	cout << "mapbuilder eliminated" << endl; //안불림..
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
		m_pPlayer_GameManager->Check_Equip();
		if (!strcmp(PLAYER_G->szName, "전사"))
		{
			cout << "1. 장검(1000G)\t2. 방패(1500G)\t3. 돌아가기" << endl;
		}
		else if (!strcmp(PLAYER_G->szName, "마법사"))
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
			if (!(PLAYER_G_ITEM->bMain_Item))
			{
				
				if (WEAPON <= PLAYER_G->iGold)
				{
					PLAYER_G->iGold -= 1000;
					cout << "주장비 구매완료!" << endl;
					PLAYER_G_ITEM->bMain_Item = true;
					if (!strcmp(PLAYER_G->szName, "전사"))
					{
						PLAYER_G->iAttack += 15; //전사는 공격력 +++
					}
					else if (!strcmp(PLAYER_G->szName, "마법사"))
					{
						PLAYER_G->iAttack += 10; //마법사는 공격력++ 
						PLAYER_G->iCritical_Percent += 5; //치명타+
					}
					else//(!strcmp(PLAYER_G->szName, "도적"))
					{
						PLAYER_G->iAttack += 5; //도적은 공격력+
						PLAYER_G->iCritical_Percent += 10; //치명타++
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
			if (!(PLAYER_G_ITEM->bSub_Item))
			{
				if (SUB_WEAPON <= PLAYER_G->iGold)
				{
					PLAYER_G->iGold -= 1500;
					cout << "보조장비 구매완료!" << endl;
					PLAYER_G_ITEM->bSub_Item = true;
					if (!strcmp(PLAYER_G->szName, "전사"))
					{
						PLAYER_G->iMaxHp += 50; // 전사는 체력+
						PLAYER_G->iCurrentHp += 50;
					}
					else if (!strcmp(PLAYER_G->szName, "마법사"))
					{
						PLAYER_G->iMaxMana += 50; // 마법사는 마나+
						PLAYER_G->iCurrentMana += 50;
					}
					else//(!strcmp(PLAYER_G->szName, "도적"))
					{
						PLAYER_G->iCritical_Percent += 10; //도적은 치명타+
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
		m_pPlayer_GameManager->Check_Equip();
		cout << "1. 체력포션\t2. 마나포션\t3. 돌아가기" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (HEAL_POTION <= PLAYER_G->iGold)
			{
				PLAYER_G->iGold -= 100;
				PLAYER_G_ITEM->iPotion += 1;
				cout << "체력포션 구매완료!" << endl;
				cout << "현재 포션수 : " << PLAYER_G_ITEM->iPotion << " 개" << endl;
			}
			else
			{
				cout << "골드가 부족함" << endl;
			}
			
			system("pause");
			break;
		case 2:
			if (MANA_POTION <= PLAYER_G->iGold)
			{
				PLAYER_G->iGold -= 150;
				PLAYER_G_ITEM->iManaPotion += 1;
				cout << "마나포션 구매완료!" << endl;
				cout << "현재 마나포션수 : " << PLAYER_G_ITEM->iManaPotion << " 개" << endl;
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
		cout << "1. 초급\t2. 중급\t3. 고급\t4. 돌아가기" << endl;
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
