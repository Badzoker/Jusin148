#include "TR_Player.h"

CPlayer::CPlayer()
{
	m_Info = nullptr;
	m_Item = nullptr;
	m_pCToString = nullptr;
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Level_Up()
{
	m_Info->iMaxExp += 50;
	m_Info->iExp = 0;
	m_Info->iLevel += 1;
	m_Info->iAttack += 10;
	m_Info->iMaxHp += 10;
	m_Info->iMaxMana += 10;
	m_Info->iCurrentHp = m_Info->iMaxHp;
	m_Info->iCurrentMana = m_Info->iMaxMana;
	cout << "Level up!" << endl;
}

void CPlayer::Load()
{
	m_Info = new INFO;
	m_Item = new ITEM;
	FILE* pFileJob = NULL;
	FILE* pFileItem = NULL;
	errno_t errReadJob = 0;
	errno_t errReadItem = 0;
	errReadJob = fopen_s(&pFileJob, "./Data/Info/Job.txt", "rb");
	errReadItem = fopen_s(&pFileItem, "./Data/Info/Item.txt", "rb");
	if (0 == errReadJob && 0 == errReadItem)
	{
		fread(m_Info, sizeof(INFO), 1, pFileJob);
		fread(m_Item, sizeof(ITEM), 1, pFileItem);
		fclose(pFileJob);
		fclose(pFileItem);
	}
	else
	{
		cout << "불러오기 실패" << endl;
		system("pause");
	}
	cout << "불러오기 성공" << endl;

}

void CPlayer::Save()
{
	FILE* pFileJob = NULL;
	FILE* pFileItem = NULL;
	errno_t errWriteJob = 0;
	errno_t errWriteItem = 0;
	errWriteJob = fopen_s(&pFileJob, "./Data/Info/Job.txt", "wb");
	errWriteItem = fopen_s(&pFileItem, "./Data/Info/Item.txt", "wb");
	if (0 == errWriteJob && 0 == errWriteItem)
	{
		cout << "저장됨" << endl;
		fwrite(m_Info, sizeof(INFO), 1, pFileJob);
		fwrite(m_Item, sizeof(ITEM), 1, pFileItem);
		fclose(pFileJob);
		fclose(pFileItem);
	}
	else
	{
		cout << "게임저장에러" << endl;
	}
	system("pause");
}

void CPlayer::Check_Equip()
{
	while (true)
	{
		system("cls");
		//주장비
		Render();
		cout << "주장비 : ";
		if (!strcmp(m_Info->szName, "전사"))
		{
			cout << "장검 ";
		}
		else if (!strcmp(m_Info->szName, "마법사"))
		{
			cout << "지팡이 ";
		}
		else//(!strcmp(PLAYER->szName, "도적"))
		{
			cout << "뾰족한 단검 ";
		}
		if (m_Item->bMain_Item)
		{
			cout << "보유중" << endl;
		}
		else
		{
			cout << "없음" << endl;
		}
		//보조장비
		cout << "보조장비 : ";
		if (!strcmp(m_Info->szName, "전사"))
		{
			cout << "방패 ";
		}
		else if (!strcmp(m_Info->szName, "마법사"))
		{
			cout << "마법책 ";
		}
		else//(!strcmp(PLAYER->szName, "도적"))
		{
			cout << "날쌘 장갑 ";
		}
		if (m_Item->bSub_Item)
		{
			cout << "보유중" << endl;
		}
		else
		{
			cout << "없음" << endl;
		}
		cout << "1. 주장비   2. 보조장비   3. 뒤로" << endl;
		int iInput(0);
		cin >> iInput;
		switch (iInput)
		{
		case 1: 
			cout << "1. 착용 / 해제   2. 뒤로" << endl;
			cin >> iInput;
			if (m_Item->bMain_Item && 1 == iInput)
			{
				m_Item->bMain_Item_Equiped = !m_Item->bMain_Item_Equiped;
			}
			else
			{
				cout << "주장비 없음" << endl;
			}
			if (m_Item->bMain_Item_Equiped)
			{
				if (!strcmp(m_Info->szName, "전사"))
				{
					m_Info->iAttack += 15; //전사는 공격력 +++
				}
				else if (!strcmp(m_Info->szName, "마법사"))
				{
					m_Info->iAttack += 10; //마법사는 공격력++ 
					m_Info->iCritical_Percent += 5; //치명타+
				}
				else//(!strcmp(PLAYER_G->szName, "도적"))
				{
					m_Info->iAttack += 5; //도적은 공격력+
					m_Info->iCritical_Percent += 10; //치명타++
				}
			}
			break;
		case 2:
			cout << "1. 착용 / 해제   2. 뒤로" << endl;
			cin >> iInput;
			if (m_Item->bSub_Item && 1 == iInput)
			{
				m_Item->bSub_Item_Equiped = !m_Item->bSub_Item_Equiped;
			}
			else
			{
				cout << "보조장비 없음" << endl;
			}
			if (m_Item->bSub_Item_Equiped)
			{
				if (!strcmp(m_Info->szName, "전사"))
				{
					m_Info->iMaxHp += 50; // 전사는 체력+
					m_Info->iCurrentHp += 50;
				}
				else if (!strcmp(m_Info->szName, "마법사"))
				{
					m_Info->iMaxMana += 50; // 마법사는 마나+
					m_Info->iCurrentMana += 50;
				}
				else//(!strcmp(PLAYER_G->szName, "도적"))
				{
					m_Info->iCritical_Percent += 10; //도적은 치명타+
				}
			}
			break;
		case 3:
			return;
		default:
			break;
		}
	}
	
}

void CPlayer::Render_Equip()
{
	
}

void CPlayer::Respawn()
{
	cout << "부활! 체력과 마나가 가득 채워졌다!" << endl;
	m_Info->iCurrentHp = m_Info->iMaxHp;
	m_Info->iCurrentMana = m_Info->iMaxMana;
	system("pause");
}

void CPlayer::Take_Reward(int _iReward, int _iGold)
{
	m_Info->iExp += _iReward;
	if (m_Info->iMaxExp <= m_Info->iExp)
	{
		Level_Up();
	}
	system("pause");
	m_Info->iGold += _iGold;
}

int CPlayer::Skill()
{
	int iInput(0);
	cout << "\n=====SKILL=====\n" << "1. 기본 스킬(mana -5)\t\t2. 강한 스킬(mana -20)\t\t3. 돌아가기\n";
	while (true)
	{
		cout << "선택하시오." << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (5 <= m_Info->iCurrentMana)
			{
				cout << "기본 스킬 사용!" << endl;
				m_Info->iCurrentMana -= 5;
				return (m_Info->iAttack + 5);
			}
			cout << "마나 부족!" << endl;
			break;
		case 2:
			if (20 <= m_Info->iCurrentMana)
			{
				cout << "기본 스킬 사용!" << endl;
				m_Info->iCurrentMana -= 20;
				return (m_Info->iAttack + 20);
			}
			cout << "마나 부족!" << endl;
			break;
		case 3:
			return 0;
		default:
			cout << "잘못 입력했습니다." << endl;
			break;
		}
	}
}

void CPlayer::Using_Tools()
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
			if (1 <= m_Item->iPotion)
			{
				cout << "포션 사용!" << endl;
				m_Item->iPotion -= 1;
				m_Info->iCurrentHp += 15;
				if (m_Info->iMaxHp <= m_Info->iCurrentHp)
				{
					m_Info->iCurrentHp = m_Info->iMaxHp;
				}
				system("pause");
				return;
			}
			cout << "포션 갯수 부족!" << endl;
			break;
		case 2:
			if (1 <= m_Item->iManaPotion)
			{
				cout << "마나포션 사용!" << endl;
				m_Item->iManaPotion -= 1;
				m_Info->iCurrentMana += 15;
				if (m_Info->iMaxMana <= m_Info->iCurrentMana)
				{
					m_Info->iCurrentMana = m_Info->iMaxMana;
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

void CPlayer::Inventory()
{
	m_pInven->Render();
}

void CPlayer::Initialize(int _iChoose)
{
	if (!m_Info)
		m_Info = new INFO;
	if (!m_Item)
		m_Item = new ITEM;
	memset(m_Info, 0, sizeof(INFO));
	memset(m_Item, 0, sizeof(ITEM));
	m_Info->iLevel = 1;
	m_Info->iMaxExp = 100;
	switch (_iChoose)
	{
	case 1:
		m_Info->iAttack = 10;
		m_Info->iMaxHp = 100;
		m_Info->iMaxMana = 20;
		m_Info->iCritical_Percent = 20;
		m_Info->eAttack_Type = ATTACK_NORMAL;
		m_Info->eArmor_Type = ARMOR_HEAVY;
		m_Info->eJob = WARRIOR;
		strcpy_s(m_Info->szName, sizeof(m_Info->szName), "전사");
		break;
	case 2:
		m_Info->iAttack = 20;
		m_Info->iMaxHp = 50;
		m_Info->iMaxMana = 50;
		m_Info->iCritical_Percent = 20;
		m_Info->eAttack_Type = ATTACK_MAGIC;
		m_Info->eArmor_Type = ARMOR_LIGHT;
		m_Info->eJob = WIZARD;
		strcpy_s(m_Info->szName, sizeof(m_Info->szName), "마법사");
		break;
	case 3:
		m_Info->iAttack = 15;
		m_Info->iMaxHp = 75;
		m_Info->iMaxMana = 35;
		m_Info->iCritical_Percent = 30;
		m_Info->eAttack_Type = ATTACK_LIGHT;
		m_Info->eArmor_Type = ARMOR_MEDIUM;
		m_Info->eJob = THIEF;
		strcpy_s(m_Info->szName, sizeof(m_Info->szName), "도적");
		break;
	default:
		break;
	}
	m_Info->iCurrentHp = m_Info->iMaxHp;
	m_Info->iCurrentMana = m_Info->iMaxMana;
}

void CPlayer::Render()
{
	system("cls");
	cout << "================\n직업 : " << m_Info->szName << endl;
	cout << "체력 : " << m_Info->iCurrentHp << " / " << m_Info->iMaxHp << endl;
	cout << "마나 : " << m_Info->iCurrentMana << " / " << m_Info->iMaxMana << endl;
	cout << "공격력 : " << m_Info->iAttack << "\t  치명타 확률 : " << m_Info->iCritical_Percent << " %" << endl;
	m_pCToString->Attack_ToString(m_Info->eAttack_Type);
	cout << "공격타입 : " << m_pCToString->Get_cToString() << endl;
	m_pCToString->Armor_ToString(m_Info->eArmor_Type);
	cout << "방어타입 : " << m_pCToString->Get_cToString() << endl;
	cout << "경험치 : " << m_Info->iExp << " / " << m_Info->iMaxExp << endl;
	cout << "레벨 : " << m_Info->iLevel << endl;
	cout << "---아이템---" << endl;
	char cTemp[32] = {};
	if (m_Item->bMain_Item_Equiped)
		strcpy_s(cTemp, sizeof(cTemp), "착용중");
	else
		strcpy_s(cTemp, sizeof(cTemp), "없음");
	cout << "주장비 : " << cTemp << endl;

	if (m_Item->bSub_Item_Equiped)
		strcpy_s(cTemp, sizeof(cTemp), "착용중");
	else
		strcpy_s(cTemp, sizeof(cTemp), "없음");
	cout << "보조장비 : " << cTemp << endl;

	cout << "체력포션 : " << m_Item->iPotion << " 개" << endl;
	cout << "마나포션 : " << m_Item->iManaPotion << " 개" << endl;
	cout << "소지 골드 : " << m_Info->iGold << " G" << endl;
}

void CPlayer::Release()
{
	cout << "플레이어 소멸자 호출" << endl;
	Safe_Delete(m_Info);
	Safe_Delete(m_Item);
}