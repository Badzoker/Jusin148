#include "TR_Battle.h"

CBattle::CBattle()
{
	m_pPlayer_GameManager = nullptr;
	m_pMonster_GameManager = nullptr;
	srand(unsigned(time(NULL)));
	iRandom = 0;
}

CBattle::~CBattle()
{
	cout << "child battle Eliminated" << endl;
	system("pause");
	//Release();
}

//void CBattle::Initialize()
//{
//
//}
// 
//void CBattle::Release()
//{
//}

void CBattle::Update()
{
	int iInput(0);
	while (true)
	{
		m_pPlayer_GameManager->Render();
		cout << "===============  v    s  ===============" << endl;
		m_pMonster_GameManager->Render();
		cout << "1. 공격    2. 스킬    3. 도구    4. 도망" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Battle_Normal();
			if (0 >= MONSTER_G->iCurrentHp)
			{
				m_pPlayer_GameManager->Take_Reward(m_pMonster_GameManager->Reward(), MONSTER_G->iGold);
				return;
			}
			else if (0 >= PLAYER_G->iCurrentHp)
			{
				m_pPlayer_GameManager->Respawn();
				return;
			}
			system("pause");
			break;
		case 2:
			Battle_Skill();
			if (0 >= MONSTER_G->iCurrentHp)
			{
				m_pPlayer_GameManager->Take_Reward(m_pMonster_GameManager->Reward(), MONSTER_G->iGold);
				return;
			}
			else if (0 >= PLAYER_G->iCurrentHp)
			{
				m_pPlayer_GameManager->Respawn();
				return;
			}
			system("pause");
			break;
		case 3:
			m_pPlayer_GameManager->Using_Tools();
			system("pause");
			break;
		case 4:
			return;
		default:
			break;
		}
	}
}

void CBattle::Battle_Normal()
{
	
	iRandom = (rand() % 100) + 1;
	if (0 < iRandom - (PLAYER_G->iCritical_Percent))
	{
		m_pMonster_GameManager->Damaged(m_pPlayer_GameManager, m_pPlayer_GameManager->Attack());//iRandom 이 20보다 클때 즉, (100 - 크리티컬 확률) 일때
	}
	else
	{
		cout << "------플레이어의 크리티컬공격!------" << endl;
		m_pMonster_GameManager->Damaged(m_pPlayer_GameManager, (m_pPlayer_GameManager->Attack()) * 2); // 크리티컬
	}
	if (0 >= MONSTER_G->iCurrentHp)
		return;
	iRandom = (rand() % 100) + 1;
	if (0 < iRandom - (MONSTER_G->iCritical_Percent))
	{
		m_pPlayer_GameManager->Damaged(m_pMonster_GameManager, m_pMonster_GameManager->Attack());//iRandom 이 20보다 클때 즉, (100 - 크리티컬 확률) 일때
	}
	else
	{
		cout << "++++++몬스터의 크리티컬공격!++++++" << endl;
		m_pPlayer_GameManager->Damaged(m_pMonster_GameManager, (m_pMonster_GameManager->Attack()) * 2); // 크리티컬
	}
	if (0 >= PLAYER_G->iCurrentHp)
		return;
}

void CBattle::Battle_Skill()
{
	iRandom = (rand() % 100) + 1;
	if (0 != PLAYER_G->iCurrentMana)
	{
		if (0 < iRandom - (PLAYER_G->iCritical_Percent))
		{
			m_pMonster_GameManager->Damaged(m_pPlayer_GameManager, m_pPlayer_GameManager->Skill());
		}
		else
		{
			m_pMonster_GameManager->Damaged(m_pPlayer_GameManager, (m_pPlayer_GameManager->Skill()) * 2);
		}
		if (0 >= MONSTER_G->iCurrentHp)
		{
			return;
		}
		if (0 < iRandom - (MONSTER_G->iCritical_Percent))
		{
			m_pPlayer_GameManager->Damaged(m_pMonster_GameManager, m_pMonster_GameManager->Attack());
		}
		else
		{
			m_pPlayer_GameManager->Damaged(m_pMonster_GameManager, (m_pMonster_GameManager->Attack())*2);
		}
		
		if (0 >= PLAYER_G->iCurrentHp)
		{
			return;
		}
	}
	else
	{
		cout << "mana less(Battle)" << endl;
	}
}

void CBattle::Battle_UsingTools()
{
	int iInput(0);
	cout << "\n=====TOOL=====\n" << "1. 체력포션(+15)\t\t2. 마나포션(+15)\t\t3. 돌아가기\n";
	while (true)
	{
		
		cout << "선택하시오." << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (1 <= PLAYER_G_ITEM->iPotion)
			{
				cout << "포션 사용!" << endl;
				PLAYER_G_ITEM->iPotion -= 1;
				PLAYER_G->iCurrentHp += 15;
				if (PLAYER_G->iMaxHp <= PLAYER_G->iCurrentHp)
				{
					PLAYER_G->iCurrentHp = PLAYER_G->iMaxHp;
				}
				system("pause");
				return;
			}
			cout << "포션 갯수 부족!" << endl;
			break;
		case 2:
			if (1 <= PLAYER_G_ITEM->iManaPotion)
			{
				cout << "마나포션 사용!" << endl;
				PLAYER_G_ITEM->iManaPotion -= 1;
				PLAYER_G->iCurrentMana += 15;
				if (PLAYER_G->iMaxMana <= PLAYER_G->iCurrentMana)
				{
					PLAYER_G->iCurrentMana = PLAYER_G->iMaxMana;
				}
				system("pause");
				return;
			}
			cout << "마나포션 갯수 부족!" << endl;
			break;
		case 3:
			return;
		default:
			cout << "잘못 입력했습니다." << endl;
			break;
		}
		system("pause");
	}
}
