#include "TR_MainGame.h"

CMainGame::CMainGame()
{
	m_pMonster = nullptr;
	m_pPlayer = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_pMonster = new CMonster;
	m_pPlayer = new CPlayer;
}

void CMainGame::Update()
{
	Menu();
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pMonster);
	SAFE_DELETE(m_pPlayer);
}

void CMainGame::Save()
{
	FILE* pFileJob = NULL;
	FILE* pFileItem = NULL;
	errno_t errWriteJob = 0;
	errno_t errWriteItem = 0;
	errWriteJob = fopen_s(&pFileJob, "./Data/Info/Job.txt", "wb");
	errWriteItem = fopen_s(&pFileItem, "./Data/Info/Item.txt", "wb");
	if (0 == errWriteJob && 0 == errWriteItem)
	{
		cout << "job저장됨" << endl;
		fwrite(m_pPlayer->Get_Info(), sizeof(INFO), 1, pFileJob);
		fwrite(m_pPlayer->Get_Item(), sizeof(ITEM), 1, pFileItem);
		fclose(pFileJob);
		fclose(pFileItem);
	}
	else
	{
		cout << "job게임저장에러" << endl;
	}
	system("pause");
}

void CMainGame::Menu()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		cout << "1. 게임시작\t2. 불러오기\t3. 종료" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			system("cls");
			cout << "직업을 선택하시오.(1. 전사 , 2. 마법사 , 3. 도적) :" << endl;
			cin >> iInput;
			m_pPlayer->Initialize(iInput);
			Home();
			break;
		case 2:
			m_pPlayer->Load();
			Home();
			break;
		case 3:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}

void CMainGame::Home()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pPlayer->Update();
		cout << "1. 사냥터    2. 상점    3. 상태창    4. 게임저장 후 종료    5. 메뉴" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Dungeon();
			break;
		case 2:
			Shop();
			break;
		case 3:
			m_pPlayer->Check_Equip();
			system("pause");
			break;
		case 4:
			Save();
			return;
		case 5:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}

void CMainGame::Shop()
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
			Shop_Equip();
			break;
		case 2:
			Shop_Consumable();
			break;
		case 3:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}

void CMainGame::Shop_Equip()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		m_pPlayer->Check_Equip();
		if (!strcmp(m_pPlayer->Get_Info()->szName, "전사"))
		{
			cout << "1. 장검\t2. 방패\t3. 돌아가기" << endl;
		}
		else if (!strcmp(m_pPlayer->Get_Info()->szName, "마법사"))
		{
			cout << "1. 지팡이\t2. 마법책(마나증가)\t3. 돌아가기" << endl;
		}
		else//(!strcmp(m_pPlayer->Get_Info()->szName, "도적"))
		{
			cout << "1. 뾰족한 단검\t2. 작은 단검\t3. 돌아가기" << endl;
		}
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (!m_pPlayer->Get_Item()->bMain_Item)
			{
				cout << "주장비 구매완료!" << endl;
				m_pPlayer->Get_Item()->bMain_Item = true;
				m_pPlayer->Get_Info()->iAttack += 10; //그냥 구현만 함
			}
			else
			{
				cout << "이미 착용중임" << endl;
			}
			system("pause");
			break;
		case 2:
			if (!m_pPlayer->Get_Item()->bSub_Item)
			{
				cout << "보조장비 구매완료!" << endl;
				m_pPlayer->Get_Item()->bSub_Item = true;
				m_pPlayer->Get_Info()->iMaxHp += 50;//그냥 구현만 함
				m_pPlayer->Get_Info()->iCurrentHp += 50;
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

void CMainGame::Shop_Consumable()
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
			m_pPlayer->Get_Item()->iPotion += 1;
			cout << "체력포션 구매완료!" << endl;
			cout << "현재 포션수 : " << m_pPlayer->Get_Item()->iPotion << " 개" << endl;
			system("pause");
			break;
		case 2:
			m_pPlayer->Get_Item()->iManaPotion += 1;
			cout << "마나포션 구매완료!" << endl;
			cout << "현재 마나포션수 : " << m_pPlayer->Get_Item()->iManaPotion << " 개" << endl;
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

void CMainGame::Dungeon()
{
	int iInput(0);
	while (true)
	{
		m_pPlayer->Update();
		cout << "1. 초급\t2. 중급\t3. 고급\t4. 돌아가기" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pMonster->Initialize(iInput);
			Fight();
			break;
		case 2:
			m_pMonster->Initialize(iInput);
			Fight();
			break;
		case 3:
			m_pMonster->Initialize(iInput);
			Fight();
			break;
		case 4:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}

void CMainGame::Fight()
{
	int iInput(0);
	while (true)
	{
		m_pPlayer->Update();
		cout << "===============  v    s  ===============" << endl;
		m_pMonster->Update();
		cout << "1. 공격    2. 스킬    3. 도구    4. 도망" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			m_pMonster->Damaged(m_pPlayer->Attack());
			if (0 >= m_pMonster->Get_Info()->iCurrentHp)
			{
				m_pPlayer->Take_Reward(m_pMonster->Reward());
				return;
			}
			m_pPlayer->Damaged(m_pMonster->Attack());
			if (0 >= m_pPlayer->Get_Info()->iCurrentHp)
			{
				m_pPlayer->Respawn();
				return;
			}
			system("pause");
			break;
		case 2:
			if (0 != m_pPlayer->Skill())
			{
				m_pMonster->Damaged(m_pPlayer->Skill());
				if (0 >= m_pMonster->Get_Info()->iCurrentHp)
				{
					m_pPlayer->Take_Reward(m_pMonster->Reward());
					return;
				}
				m_pPlayer->Damaged(m_pMonster->Attack());
				if (0 >= m_pPlayer->Get_Info()->iCurrentHp)
				{
					m_pPlayer->Respawn();
					return;
				}
				system("pause");
			}
			break;
		case 3:
			m_pPlayer->Using_Tools();
			break;
		case 4:
			return;
		default:
			break;
		}
	}
}
