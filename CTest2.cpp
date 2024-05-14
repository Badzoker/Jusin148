#include "CTest2.h"

CTest2::CTest2()
{
	tMylist = nullptr;
	iLength = 0;
	pCur = nullptr;
}

CTest2::~CTest2()
{
}

void CTest2::Initialize()
{
	tMylist = new tagList;
	tMylist->iValue = 0;
	tMylist->Next_Index = nullptr;
	pCur = tMylist;
	iLength++;
}

void CTest2::Update()
{
}

void CTest2::Release()
{
}

void CTest2::Pop(int _iIndex)
{
}

void CTest2::Put(int _iIndex, int _iValue)
{
}

void CTest2::Put_front(int _iValue)
{
	tagList* pTemp = new tagList;
	pTemp->iValue = _iValue;
	pTemp->Next_Index = pCur;
	pCur = pTemp;
	iLength++;
}

void CTest2::Put_back(int _iValue)
{
	tagList* pTemp = nullptr;
	tagList* pSour = nullptr;
	pSour = pCur;
	while (nullptr != pSour->Next_Index)
	{
		pTemp = pSour->Next_Index;
		pSour = pTemp;
	}
	pTemp = nullptr;
	pTemp = new tagList;
	pTemp->iValue = _iValue;
	pTemp->Next_Index = nullptr;
	pSour->Next_Index = pTemp;
	iLength++;
}

void CTest2::Pop_front(int _iValue)
{
}

void CTest2::Pop_back(int _iValue)
{
}

void CTest2::Erase()
{
	while (0 < iLength)
	{
		tagList* pSour = pCur->Next_Index;
		for (int i = 0; i < iLength - 1; i++)
		{
			tagList* pTemp = pSour;
			pSour = pTemp->Next_Index;
		}
		SAFE_DELETE(pSour);
		iLength--;
	}
	SAFE_DELETE(pCur);
	/*while (nullptr != pSour->Next_Index)
	{
		tagList* pTemp = pSour->Next_Index;
		pSour = pTemp;
	}*/
}

void CTest2::Print()
{
	tagList* pTemp = pCur->Next_Index;
	tagList* pSour = pCur;
	while (nullptr != pSour->Next_Index)
	{
		cout << "[ " << pSour->iValue << " ]  ";
		pSour = pTemp;
		pTemp = pSour->Next_Index;
	}
	cout << "[ " << pSour->iValue << " ]  ";

}
