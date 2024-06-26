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

void CMapBuilder::Release()
{
	Safe_Delete(m_pMonster);
	Safe_Delete(m_pBattle);
	Safe_Delete(m_pCToString);
	Safe_Delete(m_pPlayer);
	cout << "mapbuilder eliminated" << endl; 
	system("pause");
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
			SC_PLAYER->Check_Equip();
			system("pause");
			break;
		case 4:
			SC_PLAYER->Save();
			Safe_Delete(m_pPlayer);
			return;
		case 5:
			Safe_Delete(m_pPlayer);
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
		SC_PLAYER->Render();
		cout << "1. 장비\t2. 도구\t3. 돌아가기   4.관리자   5. 인벤토리" << endl;
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
		case 5:
			Map_Shop_Inventory();
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
		SC_PLAYER->Render();
		if (!strcmp(PLAYER->szName, "전사"))
		{
			cout << "1. 장검(1000G)\t2. 방패(1500G)\t3. 돌아가기" << endl;
		}
		else if (!strcmp(PLAYER->szName, "마법사"))
		{
			cout << "1. 지팡이(1000G)\t2. 마법책(1500G)\t3. 돌아가기" << endl;
		}
		else//(!strcmp(PLAYER->szName, "도적"))
		{
			cout << "1. 뾰족한 단검(1000G)\t2. 날쌘 장갑(1500G)\t3. 돌아가기" << endl;
		}
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (!(SC_PLAYER->Get_Item()->bMain_Item))
			{
				
				if (WEAPON <= PLAYER->iGold)
				{
					PLAYER->iGold -= 1000;
					cout << "주장비 구매완료!" << endl;
					SC_PLAYER->Get_Item()->bMain_Item = true;
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
			if (!(SC_PLAYER->Get_Item()->bSub_Item))
			{
				if (SUB_WEAPON <= PLAYER->iGold)
				{
					PLAYER->iGold -= 1500;
					cout << "보조장비 구매완료!" << endl;
					SC_PLAYER->Get_Item()->bSub_Item = true;
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
		SC_PLAYER->Render();
		cout << "1. 체력포션\t2. 마나포션\t3. 돌아가기" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (HEAL_POTION <= PLAYER->iGold)
			{
				PLAYER->iGold -= 100;
				SC_PLAYER->Get_Item()->iPotion += 1;
				cout << "체력포션 구매완료!" << endl;
				cout << "현재 포션수 : " << SC_PLAYER->Get_Item()->iPotion << " 개" << endl;
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
				SC_PLAYER->Get_Item()->iManaPotion += 1;
				cout << "마나포션 구매완료!" << endl;
				cout << "현재 마나포션수 : " << SC_PLAYER->Get_Item()->iManaPotion << " 개" << endl;
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

void CMapBuilder::Map_Shop_Inventory()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		SC_PLAYER->Render();
		cout << "1. 주장비  2. 보조장비  3. 돌아가기  4. 체력포션  5. 마나포션  6. 출력  7. 판매" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			DC_PLAYER->Get_Inven()->Create_Main(PLAYER->eJob);
			break;
		case 2:
			DC_PLAYER->Get_Inven()->Create_Sub(PLAYER->eJob);
			break;
		case 3:
			return;
		case 4:
			DC_PLAYER->Get_Inven()->Create_Potion();
			break;
		case 5:
			DC_PLAYER->Get_Inven()->Create_ManaPotion();
			break;
		case 6:
			DC_PLAYER->Get_Inven()->Render();
			break;
		case 7:
			DC_PLAYER->Get_Inven()->Sell_Item();
			break;
		default:
			cout << "wrong" << endl;
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
				Safe_Delete_Array(m_pShop);
				m_pShop = tTemp;
			}
			cout << "주장비 입니까?  1. Y  2. N" << endl;
			cin >> iInput;
			if (1 == iInput)
				m_pShop[m_pShop->iCount].bIs_Main = true;
			else
				m_pShop[m_pShop->iCount].bIs_Main = false;
			
			
			cout << "아이템 이름이 뭡니까? :" << endl;
			cin.ignore(); //버퍼에 남아있는 \n 한칸 지워주는 역할
			gets_s(m_pShop[m_pShop->iCount].szName, sizeof(m_pShop[m_pShop->iCount].szName));
			cout << "이름 입력완료" << endl;
			cout << "가격은 얼맙니까? :" << endl;
			cin >> iInput;
			m_pShop[m_pShop->iCount].iGold = iInput;
			cout << "등록된 물품은\n주장비? : " << m_pShop[m_pShop->iCount].bIs_Main << "\n이름 : " << m_pShop[m_pShop->iCount].szName << "\n가격 : " << m_pShop[m_pShop->iCount].iGold << endl;
			m_pShop->iCount += 1;
			cout << "등록된 물품은 총 " << m_pShop->iCount << "개 입니다." << endl;
			system("pause");
			break;
		case 2:
			Safe_Delete_Array(m_pShop);
			return;
		case 3:
			for (int i = 0; i < m_pShop->iCount; i++)
			{
				cout << "등록된 물품은\n주장비? : " << m_pShop[i].bIs_Main << "\n이름 : " << m_pShop[i].szName << "\n가격 : " << m_pShop[i].iGold << endl << endl;
			}
			cout << "등록된 물품은 총 " << m_pShop->iCount << "개 입니다." << endl;
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
		cout << "상점 갯수 불러오기 성공" << endl;
		system("pause");
		if (0 == errReadItem)
		{
			m_pShop = new SHOP[pTemp->iCount];
			fread(m_pShop, sizeof(SHOP), pTemp->iCount, pFileShop);
			fclose(pFileShop);
			cout << "상점 불러오기 성공" << endl;
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
		Safe_Delete(pTemp);
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
			Safe_Delete(m_pMonster);
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}
