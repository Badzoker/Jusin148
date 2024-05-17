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
		cout << "1. ����    2. ��ų    3. ����    4. ����" << endl;
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
		m_pMonster_GameManager->Damaged(m_pPlayer_GameManager, m_pPlayer_GameManager->Attack());//iRandom �� 20���� Ŭ�� ��, (100 - ũ��Ƽ�� Ȯ��) �϶�
	}
	else
	{
		cout << "------�÷��̾��� ũ��Ƽ�ð���!------" << endl;
		m_pMonster_GameManager->Damaged(m_pPlayer_GameManager, (m_pPlayer_GameManager->Attack()) * 2); // ũ��Ƽ��
	}
	if (0 >= MONSTER_G->iCurrentHp)
		return;
	iRandom = (rand() % 100) + 1;
	if (0 < iRandom - (MONSTER_G->iCritical_Percent))
	{
		m_pPlayer_GameManager->Damaged(m_pMonster_GameManager, m_pMonster_GameManager->Attack());//iRandom �� 20���� Ŭ�� ��, (100 - ũ��Ƽ�� Ȯ��) �϶�
	}
	else
	{
		cout << "++++++������ ũ��Ƽ�ð���!++++++" << endl;
		m_pPlayer_GameManager->Damaged(m_pMonster_GameManager, (m_pMonster_GameManager->Attack()) * 2); // ũ��Ƽ��
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
	cout << "\n=====TOOL=====\n" << "1. ü������(+15)\t\t2. ��������(+15)\t\t3. ���ư���\n";
	while (true)
	{
		
		cout << "�����Ͻÿ�." << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (1 <= PLAYER_G_ITEM->iPotion)
			{
				cout << "���� ���!" << endl;
				PLAYER_G_ITEM->iPotion -= 1;
				PLAYER_G->iCurrentHp += 15;
				if (PLAYER_G->iMaxHp <= PLAYER_G->iCurrentHp)
				{
					PLAYER_G->iCurrentHp = PLAYER_G->iMaxHp;
				}
				system("pause");
				return;
			}
			cout << "���� ���� ����!" << endl;
			break;
		case 2:
			if (1 <= PLAYER_G_ITEM->iManaPotion)
			{
				cout << "�������� ���!" << endl;
				PLAYER_G_ITEM->iManaPotion -= 1;
				PLAYER_G->iCurrentMana += 15;
				if (PLAYER_G->iMaxMana <= PLAYER_G->iCurrentMana)
				{
					PLAYER_G->iCurrentMana = PLAYER_G->iMaxMana;
				}
				system("pause");
				return;
			}
			cout << "�������� ���� ����!" << endl;
			break;
		case 3:
			return;
		default:
			cout << "�߸� �Է��߽��ϴ�." << endl;
			break;
		}
		system("pause");
	}
}
