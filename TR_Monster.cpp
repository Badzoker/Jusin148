#include "TR_Monster.h"
#include "mynamespace.h"

CMonster::CMonster()
{
	m_Info = nullptr;
	srand(unsigned(time(NULL)));
	iRandom_Armor = 0;
	m_pCToString = nullptr;
}

CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize(int _iChoose)
{
	if (!m_Info)
	{
		m_Info = new INFO;
	}
	m_Info->iAttack = 3 * _iChoose;
	m_Info->iCritical_Percent = 5 * _iChoose;
	m_Info->iMaxHp = 25 * _iChoose;
	m_Info->iCurrentHp = m_Info->iMaxHp;
	m_Info->iMaxMana = 10 * _iChoose;
	m_Info->iCurrentMana = m_Info->iMaxMana;
	m_Info->iExp = m_Info->iMaxHp;//��
	m_Info->iGold = 500 * _iChoose;//��
	iRandom_Armor = rand() % 4;
	switch (_iChoose)
	{
	case 1:
		strcpy_s(m_Info->szName, sizeof(m_Info->szName), "����");
		m_Info->eArmor_Type = ARMOR_LIGHT;
		m_Info->eAttack_Type = (ATTACK_TYPE)iRandom_Armor;
		break;
	case 2:
		strcpy_s(m_Info->szName, sizeof(m_Info->szName), "�β��β�");
		m_Info->eArmor_Type = ARMOR_MEDIUM;
		m_Info->eAttack_Type = (ATTACK_TYPE)iRandom_Armor;
		break;
	case 3:
		strcpy_s(m_Info->szName, sizeof(m_Info->szName), "����");
		m_Info->eArmor_Type = ARMOR_HEAVY;
		m_Info->eAttack_Type = (ATTACK_TYPE)iRandom_Armor;
		break;
	
	default:
		cout << "�߸� �Է��߽��ϴ�." << endl;
		break;
	}
}

void CMonster::Render()
{
	cout << "\n+++++++++++++\n���� : " << m_Info->szName << "\nü�� : " << m_Info->iCurrentHp << endl;
	cout << "���� : " << m_Info->iCurrentMana << "\t  ���ݷ� : " << m_Info->iAttack << "\t  ġ��Ÿ Ȯ�� : " << m_Info->iCritical_Percent << " %" << endl;
	m_pCToString->Attack_ToString(m_Info->eAttack_Type);
	cout << "����Ÿ�� : " << m_pCToString->Get_cToString() << endl;
	m_pCToString->Armor_ToString(m_Info->eArmor_Type);
	cout << "���Ÿ�� : " << m_pCToString->Get_cToString() << endl;
}

void CMonster::Release()
{
	cout << "���� �Ҹ��� ȣ��" << endl;
	Safe_Delete(m_Info);
}

