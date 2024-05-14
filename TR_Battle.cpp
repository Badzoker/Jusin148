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
		cout << "1. 공격    2. 스킬    3. 도구    4. 도망" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Battle_Normal();
			if (0 >= m_pMonster->Get_Info()->iCurrentHp)
			{
				m_pPlayer->Take_Reward(m_pMonster->Reward(), m_pMonster->Get_Info()->iGold);
				return;
			}
			else if (0 >= m_pPlayer->Get_Info()->iCurrentHp)
			{
				m_pPlayer->Respawn();
				return;
			}
			system("pause");
			break;
		case 2:
			Battle_Skill();
			if (0 >= m_pMonster->Get_Info()->iCurrentHp)
			{
				m_pPlayer->Take_Reward(m_pMonster->Reward(), m_pMonster->Get_Info()->iGold);
				return;
			}
			else if (0 >= m_pPlayer->Get_Info()->iCurrentHp)
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
	if (0 < iRandom - (m_pPlayer->Get_Info()->iCritical_Percent))
	{
		m_pMonster->Damaged(m_pPlayer->Get_Info()->iAttack, m_pPlayer->Get_Info()->eAttack_Type, m_pMonster->Get_Info()->eArmor_Type, m_pMonster->Get_Info());//iRandom 이 20보다 클때 즉, (100 - 크리티컬 확률) 일때
	}
	else
	{
		cout << "------플레이어의 크리티컬공격!------" << endl;
		m_pMonster->Damaged((m_pPlayer->Attack(m_pPlayer->Get_Info()->iAttack)) * 2, m_pPlayer->Get_Info()->eAttack_Type, m_pMonster->Get_Info()->eArmor_Type, m_pMonster->Get_Info()); // 크리티컬
	}
	if (0 >= m_pMonster->Get_Info()->iCurrentHp)
		return;
	iRandom = (rand() % 100) + 1;
	if (0 < iRandom - (m_pMonster->Get_Info()->iCritical_Percent))
	{
		m_pPlayer->Damaged(m_pMonster->Attack(m_pMonster->Get_Info()->iAttack), m_pMonster->Get_Info()->eAttack_Type, m_pPlayer->Get_Info()->eArmor_Type, m_pPlayer->Get_Info());;//iRandom 이 20보다 클때 즉, (100 - 크리티컬 확률) 일때
	}
	else
	{
		cout << "++++++몬스터의 크리티컬공격!++++++" << endl;
		m_pPlayer->Damaged((m_pMonster->Attack(m_pMonster->Get_Info()->iAttack)) * 2, m_pMonster->Get_Info()->eAttack_Type, m_pPlayer->Get_Info()->eArmor_Type, m_pPlayer->Get_Info()); // 크리티컬
	}
	if (0 >= m_pPlayer->Get_Info()->iCurrentHp)
		return;
}

void CBattle::Battle_Skill()
{
	
	if (0 != m_pPlayer->Skill())
	{
		m_pMonster->Damaged(m_pPlayer->Skill(), m_pPlayer->Get_Info()->eAttack_Type, m_pMonster->Get_Info()->eArmor_Type, m_pMonster->Get_Info());
		if (0 >= m_pMonster->Get_Info()->iCurrentHp)
		{
			m_pPlayer->Take_Reward(m_pMonster->Reward(), m_pMonster->Get_Info()->iGold);
			return;
		}
		m_pPlayer->Damaged(m_pMonster->Attack(m_pMonster->Get_Info()->iAttack), m_pMonster->Get_Info()->eAttack_Type, m_pPlayer->Get_Info()->eArmor_Type, m_pPlayer->Get_Info());
		if (0 >= m_pPlayer->Get_Info()->iCurrentHp)
		{
			m_pPlayer->Respawn();
			return;
		}
		system("pause");
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
			if (1 <= m_pPlayer->Get_Item()->iPotion)
			{
				cout << "포션 사용!" << endl;
				m_pPlayer->Get_Item()->iPotion -= 1;
				m_pPlayer->Get_Info()->iCurrentHp += 15;
				if (m_pPlayer->Get_Info()->iMaxHp <= m_pPlayer->Get_Info()->iCurrentHp)
				{
					m_pPlayer->Get_Info()->iCurrentHp = m_pPlayer->Get_Info()->iMaxHp;
				}
				system("pause");
				return;
			}
			cout << "포션 갯수 부족!" << endl;
			break;
		case 2:
			if (1 <= m_pPlayer->Get_Item()->iManaPotion)
			{
				cout << "마나포션 사용!" << endl;
				m_pPlayer->Get_Item()->iManaPotion -= 1;
				m_pPlayer->Get_Info()->iCurrentMana += 15;
				if (m_pPlayer->Get_Info()->iMaxMana <= m_pPlayer->Get_Info()->iCurrentMana)
				{
					m_pPlayer->Get_Info()->iCurrentMana = m_pPlayer->Get_Info()->iMaxMana;
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

void CBattle::Set_Player(CPlayer* _pPlayer)
{
	m_pPlayer = _pPlayer;
}

void CBattle::Set_Monster(CMonster* _pMonster)
{
	m_pMonster = _pMonster;
}
