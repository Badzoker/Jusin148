#include "TR_Player.h"

CPlayer::CPlayer()
{
	m_pInfo = nullptr;
	m_pItem = nullptr;
	m_pCToString = nullptr;
}

CPlayer::~CPlayer()
{
	Release();
}

void CPlayer::Damaged(int _iDamage, ATTACK_TYPE _eAttacked_Type, ARMOR_TYPE _eMyArmor_Type)
{
	int iDamage_Final = _iDamage;
	switch (_eAttacked_Type)
	{
	case ATTACK_NORMAL:
		if (ARMOR_MEDIUM == _eMyArmor_Type)
			iDamage_Final = _iDamage * 2;
		else if (ARMOR_LIGHT == _eMyArmor_Type)
			iDamage_Final = (int)(_iDamage / 2);
		break;
	case ATTACK_MAGIC:
		if (ARMOR_HEAVY == _eMyArmor_Type)
			iDamage_Final = _iDamage * 2;
		else if (ARMOR_MEDIUM == _eMyArmor_Type)
			iDamage_Final = (int)(_iDamage / 2);
		break;
	case ATTACK_LIGHT:
		if (ARMOR_LIGHT == _eMyArmor_Type)
			iDamage_Final = _iDamage * 2;
		else if (ARMOR_HEAVY == _eMyArmor_Type)
			iDamage_Final = (int)(_iDamage / 2);
		break;
	case ATTACK_CHAOS:
		iDamage_Final = (int)((float)_iDamage * 1.2f);
		break;
	case ATTACK_TYPE_END:
		break;
	default:
		break;
	}
	m_pInfo->iCurrentHp -= iDamage_Final;
	cout << m_pInfo->szName <<" �� " << iDamage_Final << " ��ŭ ���ظ� �Ծ���!" << endl;

	if (0 >= m_pInfo->iCurrentHp)
	{
		cout << "�÷��̾ �׾���!" << endl;
	}
	
}

void CPlayer::Level_Up()
{
	m_pInfo->iMaxExp += 50;
	m_pInfo->iExp = 0;
	m_pInfo->iLevel += 1;
	m_pInfo->iAttack += 10;
	m_pInfo->iMaxHp += 10;
	m_pInfo->iMaxMana += 10;
	m_pInfo->iCurrentHp = m_pInfo->iMaxHp;
	m_pInfo->iCurrentMana = m_pInfo->iMaxMana;
	cout << "Level up!" << endl;
}

void CPlayer::Load()
{
	m_pInfo = new INFO;
	m_pItem = new ITEM;
	FILE* pFileJob = NULL;
	FILE* pFileItem = NULL;
	errno_t errReadJob = 0;
	errno_t errReadItem = 0;
	errReadJob = fopen_s(&pFileJob, "./Data/Info/Job.txt", "rb");
	errReadItem = fopen_s(&pFileItem, "./Data/Info/Item.txt", "rb");
	if (0 == errReadJob && 0 == errReadItem)
	{
		fread(m_pInfo, sizeof(INFO), 1, pFileJob);
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
		fwrite(m_pInfo, sizeof(INFO), 1, pFileJob);
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
	cout << "���� ��� : " << m_pItem->iGold << " G" << endl;
}

void CPlayer::Respawn()
{
	cout << "��Ȱ! ü�°� ������ ���� ä������!" << endl;
	m_pInfo->iCurrentHp = m_pInfo->iMaxHp;
	m_pInfo->iCurrentMana = m_pInfo->iMaxMana;
	system("pause");
}

void CPlayer::Take_Reward(int _iReward, int _iGold)
{
	m_pInfo->iExp += _iReward;
	if (m_pInfo->iMaxExp <= m_pInfo->iExp)
	{
		Level_Up();
	}
	system("pause");
	m_pItem->iGold += _iGold;
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
			if (5 <= m_pInfo->iCurrentMana)
			{
				cout << "�⺻ ��ų ���!" << endl;
				m_pInfo->iCurrentMana -= 5;
				return m_pInfo->iAttack + 5;
			}
			cout << "���� ����!" << endl;
			break;
		case 2:
			if (20 <= m_pInfo->iCurrentMana)
			{
				cout << "�⺻ ��ų ���!" << endl;
				m_pInfo->iCurrentMana -= 20;
				return m_pInfo->iAttack + 20;
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
				m_pInfo->iCurrentHp += 15;
				if (m_pInfo->iMaxHp <= m_pInfo->iCurrentHp)
				{
					m_pInfo->iCurrentHp = m_pInfo->iMaxHp;
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
				m_pInfo->iCurrentMana += 15;
				if (m_pInfo->iMaxMana <= m_pInfo->iCurrentMana)
				{
					m_pInfo->iCurrentMana = m_pInfo->iMaxMana;
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

INFO* CPlayer::Get_Info()
{
	return m_pInfo;
}

ITEM* CPlayer::Get_Item()
{
	return m_pItem;
}

void CPlayer::Initialize(int _iChoose)
{
	if (!m_pInfo)
		m_pInfo = new INFO;
	if (!m_pItem)
		m_pItem = new ITEM;
	memset(m_pInfo, 0, sizeof(INFO));
	memset(m_pItem, 0, sizeof(ITEM));
	m_pInfo->iLevel = 1;
	m_pInfo->iMaxExp = 100;
	switch (_iChoose)
	{
	case 1:
		m_pInfo->iAttack = 10;
		m_pInfo->iMaxHp = 100;
		m_pInfo->iMaxMana = 20;
		m_pInfo->iCritical_Percent = 20;
		m_pInfo->eAttack_Type = ATTACK_NORMAL;
		m_pInfo->eArmor_Type = ARMOR_HEAVY;
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "����");
		break;
	case 2:
		m_pInfo->iAttack = 20;
		m_pInfo->iMaxHp = 50;
		m_pInfo->iMaxMana = 50;
		m_pInfo->iCritical_Percent = 20;
		m_pInfo->eAttack_Type = ATTACK_MAGIC;
		m_pInfo->eArmor_Type = ARMOR_LIGHT;
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "������");
		break;
	case 3:
		m_pInfo->iAttack = 15;
		m_pInfo->iMaxHp = 75;
		m_pInfo->iMaxMana = 35;
		m_pInfo->iCritical_Percent = 30;
		m_pInfo->eAttack_Type = ATTACK_LIGHT;
		m_pInfo->eArmor_Type = ARMOR_MEDIUM;
		strcpy_s(m_pInfo->szName, sizeof(m_pInfo->szName), "����");
		break;
	default:
		break;
	}
	m_pInfo->iCurrentHp = m_pInfo->iMaxHp;
	m_pInfo->iCurrentMana = m_pInfo->iMaxMana;
}

void CPlayer::Render()
{
	/*if (!m_pCToString)
	{
		m_pCToString = new CToString;
	}*/
	//m_pCToString->Enum_ToString((ATTACK_TYPE)m_pInfo->eAttack_Type);
	system("cls");
	cout << "================\n���� : " << m_pInfo->szName << endl;
	cout << "ü�� : " << m_pInfo->iCurrentHp << " / " << m_pInfo->iMaxHp << endl;
	cout << "���� : " << m_pInfo->iCurrentMana << " / " << m_pInfo->iMaxMana << endl;
	cout << "���ݷ� : " << m_pInfo->iAttack << "\t  ġ��Ÿ Ȯ�� : " << m_pInfo->iCritical_Percent << " %" << endl;
	m_pCToString->Attack_ToString(m_pInfo->eAttack_Type);
	cout << "����Ÿ�� : " << m_pCToString->Get_cToString() << endl;
	m_pCToString->Armor_ToString(m_pInfo->eArmor_Type);
	cout << "���Ÿ�� : " << m_pCToString->Get_cToString() << endl;
	cout << "����ġ : " << m_pInfo->iExp << " / " << m_pInfo->iMaxExp << endl;
	cout << "���� : " << m_pInfo->iLevel << endl;
	
}

void CPlayer::Release()
{
	cout << "�÷��̾� �Ҹ��� ȣ��" << endl;
	SAFE_DELETE(m_pInfo);
	SAFE_DELETE(m_pItem);
	//SAFE_DELETE(m_pCToString);
}