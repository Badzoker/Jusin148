#include "TR_Player.h"

CPlayer::CPlayer()
{
	m_Info = nullptr;
	m_pItem = nullptr;
	m_pCToString = nullptr;
	cout << "Player Create" << endl;
}

CPlayer::~CPlayer()
{
	Release();
}

//void CPlayer::Damaged(int _iDamage, ATTACK_TYPE _eAttacked_Type, ARMOR_TYPE _eMyArmor_Type)
//{
//	int iDamage_Final = _iDamage;
//	switch (_eAttacked_Type)
//	{
//	case ATTACK_NORMAL:
//		if (ARMOR_MEDIUM == _eMyArmor_Type)
//			iDamage_Final = _iDamage * 2;
//		else if (ARMOR_LIGHT == _eMyArmor_Type)
//			iDamage_Final = (int)(_iDamage / 2);
//		break;
//	case ATTACK_MAGIC:
//		if (ARMOR_HEAVY == _eMyArmor_Type)
//			iDamage_Final = _iDamage * 2;
//		else if (ARMOR_MEDIUM == _eMyArmor_Type)
//			iDamage_Final = (int)(_iDamage / 2);
//		break;
//	case ATTACK_LIGHT:
//		if (ARMOR_LIGHT == _eMyArmor_Type)
//			iDamage_Final = _iDamage * 2;
//		else if (ARMOR_HEAVY == _eMyArmor_Type)
//			iDamage_Final = (int)(_iDamage / 2);
//		break;
//	case ATTACK_CHAOS:
//		iDamage_Final = (int)((float)_iDamage * 1.2f);
//		break;
//	case ATTACK_TYPE_END:
//		break;
//	default:
//		break;
//	}
//	m_Info->iCurrentHp -= iDamage_Final;
//	cout << m_Info->szName <<" �� " << iDamage_Final << " ��ŭ ���ظ� �Ծ���!" << endl;
//
//	if (0 >= m_Info->iCurrentHp)
//	{
//		cout << "�÷��̾ �׾���!" << endl;
//	}
//	
//}

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
	m_pItem = new ITEM;
	FILE* pFileJob = NULL;
	FILE* pFileItem = NULL;
	errno_t errReadJob = 0;
	errno_t errReadItem = 0;
	errReadJob = fopen_s(&pFileJob, "./Data/Info/Job.txt", "rb");
	errReadItem = fopen_s(&pFileItem, "./Data/Info/Item.txt", "rb");
	if (0 == errReadJob && 0 == errReadItem)
	{
		fread(m_Info, sizeof(INFO), 1, pFileJob);
		fread(m_pItem, sizeof(ITEM), 1, pFileItem);
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
		fwrite(m_pItem, sizeof(ITEM), 1, pFileItem);
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
	char cTemp[32] = {};
	if (m_pItem->bMain_Item)
		strcpy_s(cTemp, sizeof(cTemp), "������");
	else
		strcpy_s(cTemp, sizeof(cTemp), "����");
	cout << "����� : " << cTemp << endl;

	if (m_pItem->bSub_Item)
		strcpy_s(cTemp, sizeof(cTemp), "������");
	else
		strcpy_s(cTemp, sizeof(cTemp), "����");
	cout << "������� : " << cTemp << endl;

	cout << "ü������ : " << m_pItem->iPotion << " ��" << endl;
	cout << "�������� : " << m_pItem->iManaPotion << " ��" << endl;
	cout << "���� ��� : " << m_Info->iGold << " G" << endl;
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
				return m_Info->iAttack + 5;
			}
			cout << "���� ����!" << endl;
			break;
		case 2:
			if (20 <= m_Info->iCurrentMana)
			{
				cout << "�⺻ ��ų ���!" << endl;
				m_Info->iCurrentMana -= 20;
				return m_Info->iAttack + 20;
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
			if (1 <= m_pItem->iPotion)
			{
				cout << "���� ���!" << endl;
				m_pItem->iPotion -= 1;
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
			if (1 <= m_pItem->iManaPotion)
			{
				cout << "�������� ���!" << endl;
				m_pItem->iManaPotion -= 1;
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

void CPlayer::Initialize(int _iChoose)
{
	if (!m_Info)
		m_Info = new INFO;
	if (!m_pItem)
		m_pItem = new ITEM;
	memset(m_Info, 0, sizeof(INFO));
	memset(m_pItem, 0, sizeof(ITEM));
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
		strcpy_s(m_Info->szName, sizeof(m_Info->szName), "����");
		break;
	case 2:
		m_Info->iAttack = 20;
		m_Info->iMaxHp = 50;
		m_Info->iMaxMana = 50;
		m_Info->iCritical_Percent = 20;
		m_Info->eAttack_Type = ATTACK_MAGIC;
		m_Info->eArmor_Type = ARMOR_LIGHT;
		strcpy_s(m_Info->szName, sizeof(m_Info->szName), "������");
		break;
	case 3:
		m_Info->iAttack = 15;
		m_Info->iMaxHp = 75;
		m_Info->iMaxMana = 35;
		m_Info->iCritical_Percent = 30;
		m_Info->eAttack_Type = ATTACK_LIGHT;
		m_Info->eArmor_Type = ARMOR_MEDIUM;
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
	/*if (!m_pCToString)
	{
		m_pCToString = new CToString;
	}
	m_pCToString->Enum_ToString((ATTACK_TYPE)m_Info->eAttack_Type);*/
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
	
}

void CPlayer::Release()
{
	cout << "�÷��̾� �Ҹ��� ȣ��" << endl;
	SAFE_DELETE(m_Info);
	SAFE_DELETE(m_pItem);
}