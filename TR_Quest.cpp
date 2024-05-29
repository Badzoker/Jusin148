#include "TR_Quest.h"

CQuest::CQuest()
{
	m_pPlayer = nullptr;
	isBegin_Hunt = false;
	isBegin_Level = false;
	iCount_Hunting = 0;
	iLevel_Current = 0;
}

CQuest::~CQuest()
{
	Release();
}

void CQuest::Initialize()
{

}

void CQuest::Render()
{
	if (isBegin_Level)
	{
		if (PLAYER->iLevel > iLevel_Current)
		{
			cout << "������ ����Ʈ �Ϸ�!" << endl;
			isBegin_Level = false;
		}
		else
		{
			cout << "������ ����Ʈ ������" << endl;
		}
	}
	if (isBegin_Hunt)
	{
		if (0 == iCount_Hunting)
		{
			cout << "��� ����Ʈ �Ϸ�!" << endl;
			isBegin_Hunt = false;
		}
		else
		{
			cout << "��� ����Ʈ ������" << endl;
		}
	}
}

void CQuest::Release()
{
	Safe_Delete(m_pPlayer);
}

void CQuest::Quest_Level()
{
	if (!isBegin_Level)
	{
		isBegin_Level = true;
		cout << "�ڳ״� ���� ���غ��̴±�! �� �� ������ �������� �ϸ� ����� �����ɼ�!" << endl;
		iLevel_Current = PLAYER->iLevel;
	}
	
}

void CQuest::Quest_Hunt()
{
	if (!isBegin_Hunt)
	{
		isBegin_Hunt = true;
		cout << "�ڳ״� ��� ������ ���� ���̴±�! �� �� ������ ����� �ϸ� ����� �����ɼ�!" << endl;
		iCount_Hunting = 3;
	}
}
