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
	Release();
}

void CBattle::Initialize()
{

}

void CBattle::Update()
{
	int iInput(0);
	while (true)
	{
		m_pPlayer->Render();
		cout << "===============  v    s  ===============" << endl;
		m_pMonster->Render();
		cout << "1. ����    2. ��ų    3. ����    4. ����" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Battle_Normal();
			if (0 >= MONSTER->iCurrentHp)
			{
				m_pPlayer->Take_Reward(m_pMonster->Reward(), MONSTER->iGold);
				return;
			}
			else if (0 >= PLAYER->iCurrentHp)
			{
				m_pPlayer->Respawn();
				return;
			}
			system("pause");
			break;
		case 2:
			Battle_Skill();
			if (0 >= MONSTER->iCurrentHp)
			{
				m_pPlayer->Take_Reward(m_pMonster->Reward(), MONSTER->iGold);
				return;
			}
			else if (0 >= PLAYER->iCurrentHp)
			{
				m_pPlayer->Respawn();
				return;
			}
			system("pause");
			break;
		case 3:
			m_pPlayer->Using_Tools();
			system("pause");
			break;
		case 4:
			return;
		default:
			break;
		}
	}
}

void CBattle::Release()
{
}

void CBattle::Battle_Normal()
{
	
	iRandom = (rand() % 100) + 1;
	if (0 < iRandom - (PLAYER->iCritical_Percent))
	{
		m_pMonster->Damaged(m_pPlayer, m_pPlayer->Attack());//iRandom �� 20���� Ŭ�� ��, (100 - ũ��Ƽ�� Ȯ��) �϶�
	}
	else
	{
		cout << "------�÷��̾��� ũ��Ƽ�ð���!------" << endl;
		m_pMonster->Damaged(m_pPlayer, m_pPlayer->Attack()); // ũ��Ƽ��
	}
	if (0 >= MONSTER->iCurrentHp)
		return;
	iRandom = (rand() % 100) + 1;
	if (0 < iRandom - (MONSTER->iCritical_Percent))
	{
		m_pPlayer->Damaged(m_pMonster, m_pMonster->Attack());//iRandom �� 20���� Ŭ�� ��, (100 - ũ��Ƽ�� Ȯ��) �϶�
	}
	else
	{
		cout << "++++++������ ũ��Ƽ�ð���!++++++" << endl;
		m_pPlayer->Damaged(m_pMonster, m_pMonster->Attack()); // ũ��Ƽ��
	}
	if (0 >= PLAYER->iCurrentHp)
		return;
}

void CBattle::Battle_Skill()
{
	
	if (0 != PLAYER->iCurrentMana)
	{
		m_pMonster->Damaged(m_pPlayer, m_pPlayer->Skill());
		if (0 >= MONSTER->iCurrentHp)
		{
			m_pPlayer->Take_Reward(m_pMonster->Reward(), MONSTER->iGold);
			return;
		}
		m_pPlayer->Damaged(m_pMonster, m_pMonster->Attack());
		if (0 >= PLAYER->iCurrentHp)
		{
			m_pPlayer->Respawn();
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
			if (1 <= m_pPlayer->Get_Item()->iPotion)
			{
				cout << "���� ���!" << endl;
				m_pPlayer->Get_Item()->iPotion -= 1;
				PLAYER->iCurrentHp += 15;
				if (PLAYER->iMaxHp <= PLAYER->iCurrentHp)
				{
					PLAYER->iCurrentHp = PLAYER->iMaxHp;
				}
				system("pause");
				return;
			}
			cout << "���� ���� ����!" << endl;
			break;
		case 2:
			if (1 <= m_pPlayer->Get_Item()->iManaPotion)
			{
				cout << "�������� ���!" << endl;
				m_pPlayer->Get_Item()->iManaPotion -= 1;
				PLAYER->iCurrentMana += 15;
				if (PLAYER->iMaxMana <= PLAYER->iCurrentMana)
				{
					PLAYER->iCurrentMana = PLAYER->iMaxMana;
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

void CBattle::Set_Player(CPlayer* _pPlayer)
{
	m_pPlayer = _pPlayer;
}

void CBattle::Set_Monster(CMonster* _pMonster)
{
	m_pMonster = _pMonster;
}
