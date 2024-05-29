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
		cout << "�ҷ����� ����" << endl;
		system("pause");
	}
	cout << "�ҷ����� ����" << endl;

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
		cout << "�����" << endl;
		fwrite(m_Info, sizeof(INFO), 1, pFileJob);
		fwrite(m_Item, sizeof(ITEM), 1, pFileItem);
		fclose(pFileJob);
		fclose(pFileItem);
	}
	else
	{
		cout << "�������忡��" << endl;
	}
	system("pause");
}

void CPlayer::Check_Equip()
{
	while (true)
	{
		system("cls");
		//�����
		Render();
		cout << "����� : ";
		if (!strcmp(m_Info->szName, "����"))
		{
			cout << "��� ";
		}
		else if (!strcmp(m_Info->szName, "������"))
		{
			cout << "������ ";
		}
		else//(!strcmp(PLAYER->szName, "����"))
		{
			cout << "������ �ܰ� ";
		}
		if (m_Item->bMain_Item)
		{
			cout << "������" << endl;
		}
		else
		{
			cout << "����" << endl;
		}
		//�������
		cout << "������� : ";
		if (!strcmp(m_Info->szName, "����"))
		{
			cout << "���� ";
		}
		else if (!strcmp(m_Info->szName, "������"))
		{
			cout << "����å ";
		}
		else//(!strcmp(PLAYER->szName, "����"))
		{
			cout << "���� �尩 ";
		}
		if (m_Item->bSub_Item)
		{
			cout << "������" << endl;
		}
		else
		{
			cout << "����" << endl;
		}
		cout << "1. �����   2. �������   3. �ڷ�" << endl;
		int iInput(0);
		cin >> iInput;
		switch (iInput)
		{
		case 1: 
			cout << "1. ���� / ����   2. �ڷ�" << endl;
			cin >> iInput;
			if (m_Item->bMain_Item && 1 == iInput)
			{
				m_Item->bMain_Item_Equiped = !m_Item->bMain_Item_Equiped;
			}
			else
			{
				cout << "����� ����" << endl;
			}
			if (m_Item->bMain_Item_Equiped)
			{
				if (!strcmp(m_Info->szName, "����"))
				{
					m_Info->iAttack += 15; //����� ���ݷ� +++
				}
				else if (!strcmp(m_Info->szName, "������"))
				{
					m_Info->iAttack += 10; //������� ���ݷ�++ 
					m_Info->iCritical_Percent += 5; //ġ��Ÿ+
				}
				else//(!strcmp(PLAYER_G->szName, "����"))
				{
					m_Info->iAttack += 5; //������ ���ݷ�+
					m_Info->iCritical_Percent += 10; //ġ��Ÿ++
				}
			}
			break;
		case 2:
			cout << "1. ���� / ����   2. �ڷ�" << endl;
			cin >> iInput;
			if (m_Item->bSub_Item && 1 == iInput)
			{
				m_Item->bSub_Item_Equiped = !m_Item->bSub_Item_Equiped;
			}
			else
			{
				cout << "������� ����" << endl;
			}
			if (m_Item->bSub_Item_Equiped)
			{
				if (!strcmp(m_Info->szName, "����"))
				{
					m_Info->iMaxHp += 50; // ����� ü��+
					m_Info->iCurrentHp += 50;
				}
				else if (!strcmp(m_Info->szName, "������"))
				{
					m_Info->iMaxMana += 50; // ������� ����+
					m_Info->iCurrentMana += 50;
				}
				else//(!strcmp(PLAYER_G->szName, "����"))
				{
					m_Info->iCritical_Percent += 10; //������ ġ��Ÿ+
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
	cout << "��Ȱ! ü�°� ������ ���� ä������!" << endl;
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
	cout << "\n=====SKILL=====\n" << "1. �⺻ ��ų(mana -5)\t\t2. ���� ��ų(mana -20)\t\t3. ���ư���\n";
	while (true)
	{
		cout << "�����Ͻÿ�." << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (5 <= m_Info->iCurrentMana)
			{
				cout << "�⺻ ��ų ���!" << endl;
				m_Info->iCurrentMana -= 5;
				return (m_Info->iAttack + 5);
			}
			cout << "���� ����!" << endl;
			break;
		case 2:
			if (20 <= m_Info->iCurrentMana)
			{
				cout << "�⺻ ��ų ���!" << endl;
				m_Info->iCurrentMana -= 20;
				return (m_Info->iAttack + 20);
			}
			cout << "���� ����!" << endl;
			break;
		case 3:
			return 0;
		default:
			cout << "�߸� �Է��߽��ϴ�." << endl;
			break;
		}
	}
}

void CPlayer::Using_Tools()
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
			if (1 <= m_Item->iPotion)
			{
				cout << "���� ���!" << endl;
				m_Item->iPotion -= 1;
				m_Info->iCurrentHp += 15;
				if (m_Info->iMaxHp <= m_Info->iCurrentHp)
				{
					m_Info->iCurrentHp = m_Info->iMaxHp;
				}
				system("pause");
				return;
			}
			cout << "���� ���� ����!" << endl;
			break;
		case 2:
			if (1 <= m_Item->iManaPotion)
			{
				cout << "�������� ���!" << endl;
				m_Item->iManaPotion -= 1;
				m_Info->iCurrentMana += 15;
				if (m_Info->iMaxMana <= m_Info->iCurrentMana)
				{
					m_Info->iCurrentMana = m_Info->iMaxMana;
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
		strcpy_s(m_Info->szName, sizeof(m_Info->szName), "����");
		break;
	case 2:
		m_Info->iAttack = 20;
		m_Info->iMaxHp = 50;
		m_Info->iMaxMana = 50;
		m_Info->iCritical_Percent = 20;
		m_Info->eAttack_Type = ATTACK_MAGIC;
		m_Info->eArmor_Type = ARMOR_LIGHT;
		m_Info->eJob = WIZARD;
		strcpy_s(m_Info->szName, sizeof(m_Info->szName), "������");
		break;
	case 3:
		m_Info->iAttack = 15;
		m_Info->iMaxHp = 75;
		m_Info->iMaxMana = 35;
		m_Info->iCritical_Percent = 30;
		m_Info->eAttack_Type = ATTACK_LIGHT;
		m_Info->eArmor_Type = ARMOR_MEDIUM;
		m_Info->eJob = THIEF;
		strcpy_s(m_Info->szName, sizeof(m_Info->szName), "����");
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
	cout << "================\n���� : " << m_Info->szName << endl;
	cout << "ü�� : " << m_Info->iCurrentHp << " / " << m_Info->iMaxHp << endl;
	cout << "���� : " << m_Info->iCurrentMana << " / " << m_Info->iMaxMana << endl;
	cout << "���ݷ� : " << m_Info->iAttack << "\t  ġ��Ÿ Ȯ�� : " << m_Info->iCritical_Percent << " %" << endl;
	m_pCToString->Attack_ToString(m_Info->eAttack_Type);
	cout << "����Ÿ�� : " << m_pCToString->Get_cToString() << endl;
	m_pCToString->Armor_ToString(m_Info->eArmor_Type);
	cout << "���Ÿ�� : " << m_pCToString->Get_cToString() << endl;
	cout << "����ġ : " << m_Info->iExp << " / " << m_Info->iMaxExp << endl;
	cout << "���� : " << m_Info->iLevel << endl;
	cout << "---������---" << endl;
	char cTemp[32] = {};
	if (m_Item->bMain_Item_Equiped)
		strcpy_s(cTemp, sizeof(cTemp), "������");
	else
		strcpy_s(cTemp, sizeof(cTemp), "����");
	cout << "����� : " << cTemp << endl;

	if (m_Item->bSub_Item_Equiped)
		strcpy_s(cTemp, sizeof(cTemp), "������");
	else
		strcpy_s(cTemp, sizeof(cTemp), "����");
	cout << "������� : " << cTemp << endl;

	cout << "ü������ : " << m_Item->iPotion << " ��" << endl;
	cout << "�������� : " << m_Item->iManaPotion << " ��" << endl;
	cout << "���� ��� : " << m_Info->iGold << " G" << endl;
}

void CPlayer::Release()
{
	cout << "�÷��̾� �Ҹ��� ȣ��" << endl;
	Safe_Delete(m_Info);
	Safe_Delete(m_Item);
}