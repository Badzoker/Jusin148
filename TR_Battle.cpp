#include "TR_Battle.h"

CBattle::CBattle()
{
	m_pPlayer = nullptr;
	m_pMonster = nullptr;
	srand(unsigned(time(NULL)));
	iRandom = 0;
}

CBattle::~CBattle()
{
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
		m_pPlayer->Render();
		cout << "===============  v    s  ===============" << endl;
		m_pMonster->Render();
		cout << "1. 공격    2. 스킬    3. 도구    4. 도망" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Battle_Normal();
			if (0 >= MONSTER->iCurrentHp)
			{
				SC_PLAYER->Take_Reward(SC_MONSTER->Reward(), MONSTER->iGold);
				//dynamic_cast<CPlayer*>(m_pPlayer_GameManager)->Take_Reward(dynamic_cast<CMonster*>(m_pMonster_GameManager)->Reward(), MONSTER_G->iGold);
				//m_pPlayer_GameManager->Take_Reward(m_pMonster_GameManager->Reward(), MONSTER_G->iGold);
				return;
			}
			else if (0 >= PLAYER->iCurrentHp)
			{
				SC_PLAYER->Respawn();
				//dynamic_cast<CPlayer*>(m_pPlayer_GameManager)->Respawn();
				//m_pPlayer_GameManager->Respawn();
				return;
			}
			system("pause");
			break;
		case 2:
			Battle_Skill();
			if (0 >= MONSTER->iCurrentHp)
			{
				SC_PLAYER->Take_Reward(SC_MONSTER->Reward(), MONSTER->iGold);
				//dynamic_cast<CPlayer*>(m_pPlayer_GameManager)->Take_Reward(dynamic_cast<CMonster*>(m_pMonster_GameManager)->Reward(), MONSTER_G->iGold);
				//m_pPlayer_GameManager->Take_Reward(m_pMonster_GameManager->Reward(), MONSTER_G->iGold);
				return;
			}
			else if (0 >= PLAYER->iCurrentHp)
			{
				SC_PLAYER->Respawn();
				//dynamic_cast<CPlayer*>(m_pPlayer_GameManager)->Respawn();
				//m_pPlayer_GameManager->Respawn();
				return;
			}
			system("pause");
			break;
		case 3:
			SC_PLAYER->Using_Tools();
			//dynamic_cast<CPlayer*>(m_pPlayer_GameManager)->Using_Tools();
			//m_pPlayer_GameManager->Using_Tools();
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
	if (0 < iRandom - (PLAYER->iCritical_Percent))
	{
		m_pMonster->Damaged(m_pPlayer, m_pPlayer->Attack());//iRandom 이 20보다 클때 즉, (100 - 크리티컬 확률) 일때
	}
	else
	{
		cout << "------플레이어의 크리티컬공격!------" << endl;
		m_pMonster->Damaged(m_pPlayer, (m_pPlayer->Attack()) * 2); // 크리티컬
	}
	if (0 >= MONSTER->iCurrentHp)
		return;
	iRandom = (rand() % 100) + 1;
	if (0 < iRandom - (MONSTER->iCritical_Percent))
	{
		m_pPlayer->Damaged(m_pMonster, m_pMonster->Attack());//iRandom 이 20보다 클때 즉, (100 - 크리티컬 확률) 일때
	}
	else
	{
		cout << "++++++몬스터의 크리티컬공격!++++++" << endl;
		m_pPlayer->Damaged(m_pMonster, (m_pMonster->Attack()) * 2); // 크리티컬
	}
	if (0 >= PLAYER->iCurrentHp)
		return;
}

void CBattle::Battle_Skill()
{
	iRandom = (rand() % 100) + 1;
	if (0 != PLAYER->iCurrentMana)
	{
		if (0 < iRandom - (PLAYER->iCritical_Percent))
		{
			m_pMonster->Damaged(m_pPlayer, SC_PLAYER->Skill());
			//m_pMonster_GameManager->Damaged(m_pPlayer_GameManager, dynamic_cast<CPlayer*>(m_pPlayer_GameManager)->Skill());
			//m_pMonster_GameManager->Damaged(m_pPlayer_GameManager, m_pPlayer_GameManager->Skill());
		}
		else
		{
			m_pMonster->Damaged(m_pPlayer, (SC_PLAYER->Skill()) * 2);
			//m_pMonster_GameManager->Damaged(m_pPlayer_GameManager, (dynamic_cast<CPlayer*>(m_pPlayer_GameManager)->Skill()) * 2);
			//m_pMonster_GameManager->Damaged(m_pPlayer_GameManager, (m_pPlayer_GameManager->Skill()) * 2);
		}
		if (0 >= MONSTER->iCurrentHp)
		{
			return;
		}
		if (0 < iRandom - (MONSTER->iCritical_Percent))
		{
			m_pPlayer->Damaged(m_pMonster, m_pMonster->Attack());
		}
		else
		{
			m_pPlayer->Damaged(m_pMonster, (m_pMonster->Attack())*2);
		}
		
		if (0 >= PLAYER->iCurrentHp)
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
			if (1 <= SC_PLAYER->Get_Item()->iPotion)
			{
				cout << "포션 사용!" << endl;
				SC_PLAYER->Get_Item()->iPotion -= 1;
				PLAYER->iCurrentHp += 15;
				if (PLAYER->iMaxHp <= PLAYER->iCurrentHp)
				{
					PLAYER->iCurrentHp = PLAYER->iMaxHp;
				}
				system("pause");
				return;
			}
			cout << "포션 갯수 부족!" << endl;
			break;
		case 2:
			if (1 <= SC_PLAYER->Get_Item()->iManaPotion)
			{
				cout << "마나포션 사용!" << endl;
				SC_PLAYER->Get_Item()->iManaPotion -= 1;
				PLAYER->iCurrentMana += 15;
				if (PLAYER->iMaxMana <= PLAYER->iCurrentMana)
				{
					PLAYER->iCurrentMana = PLAYER->iMaxMana;
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
