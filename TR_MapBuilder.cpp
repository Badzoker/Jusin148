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
		cout << "1. 장비\t2. 도구\t3. 돌아가기     4.관리자" << endl;
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
		cout << "1. 아이템 추가   2. 이전   3. 출력   4. 저장" << endl;
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
			cout << "주장비 입니까?  1. Y  2. N" << endl;
			cin >> iInput;
			if (1 == iInput)
				m_pShop[m_pShop->iCount].bIs_Main = true;
			else
				m_pShop[m_pShop->iCount].bIs_Main = false;

			cout << "아이템 이름이 뭡니까? :" << endl;
			cin >> szTemp;
			strcpy_s(m_pShop[m_pShop->iCount].szName, sizeof(szTemp), szTemp);
			cout << "가격은 얼맙니까? :" << endl;
			cin >> iInput;
			m_pShop[m_pShop->iCount].iGold = iInput;
			cout << "등록된 물품은\n주장비? : " << m_pShop[m_pShop->iCount].bIs_Main << "\n이름 : " << m_pShop[m_pShop->iCount].szName << "\n가격 : " << m_pShop[m_pShop->iCount].iGold << endl;
			m_pShop->iCount += 1;
			cout << "등록된 물품은 총 " << m_pShop->iCount << "개 입니다." << endl;
			break;
		case 2:
			SAFE_DELETE_ARRAY(m_pShop);
			return;
		case 3:
			for (int i = 0; i < m_pShop->iCount; i++)
			{
				cout << "등록된 물품은\n주장비? : " << m_pShop[i].bIs_Main << "\n이름 : " << m_pShop[i].szName << "\n가격 : " << m_pShop[i].iGold << endl << endl;
			}
			cout << "등록된 물품은 총 " << m_pShop->iCount << "개 입니다." << endl;
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
		cout << "상점 저장 성공" << endl;
		system("pause");
	}
	else
	{
		cout << "상점 저장 실패" << endl;
		system("pause");
	}
}

void CMapBuilder::Map_Shop_Load()
{
	SHOP* pTemp = new SHOP;
	FILE* pFileShop = NULL;
	errno_t errReadItem = 0;
	errReadItem = fopen_s(&pFileShop, "./Data/Info/Shop.txt", "rb");
	if (0 == errReadItem)
	{
		fread(pTemp, sizeof(SHOP), 1, pFileShop);
		fclose(pFileShop);
		cout << "상점 갯수 불러오기 성공" << endl;
		system("pause");
		if (0 == errReadItem)
		{
			m_pShop = new SHOP[pTemp->iCount];
			fread(m_pShop, sizeof(SHOP), pTemp->iCount, pFileShop);
			fclose(pFileShop);
			cout << "상점 불러오기 성공" << endl;
			SAFE_DELETE(pTemp);
			system("pause");
		}
		else
		{
			cout << "상점 불러오기 실패" << endl;
			system("pause");
		}
	}
	else
	{
		cout << "상점 갯수 불러오기 실패" << endl;
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
