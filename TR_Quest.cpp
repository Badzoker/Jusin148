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
			cout << "레벨업 퀘스트 완료!" << endl;
			isBegin_Level = false;
		}
		else
		{
			cout << "레벨업 퀘스트 진행중" << endl;
		}
	}
	if (isBegin_Hunt)
	{
		if (0 == iCount_Hunting)
		{
			cout << "사냥 퀘스트 완료!" << endl;
			isBegin_Hunt = false;
		}
		else
		{
			cout << "사냥 퀘스트 진행중" << endl;
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
		cout << "자네는 아직 약해보이는군! 좀 더 힘내서 레벨업을 하면 기분이 좋을걸세!" << endl;
		iLevel_Current = PLAYER->iLevel;
	}
	
}

void CQuest::Quest_Hunt()
{
	if (!isBegin_Hunt)
	{
		isBegin_Hunt = true;
		cout << "자네는 사냥 경험이 없어 보이는군! 좀 더 힘내서 사냥을 하면 기분이 좋을걸세!" << endl;
		iCount_Hunting = 3;
	}
}
