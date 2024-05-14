#include "CTest3.h"

CTest3::CTest3()
{
	iLength = 0;
	tMylink = nullptr;
	pCur = nullptr;
}

CTest3::~CTest3()
{
	Release();
}

void CTest3::Initialize()
{
	tMylink = new tagLink;
	tMylink->iValue = 0;
	tMylink->pPrevious_Index = nullptr;
	tMylink->pNext_Index = nullptr;
	pCur = tMylink;
	iLength++;
}

//void CTest3::Update()
//{
//}

void CTest3::Release()
{
	if (nullptr != tMylink)
	{
		SAFE_DELETE(tMylink);
	}
}

void CTest3::Push_front(int _iValue)
{
	tagLink* pTemp = new tagLink;
	tagLink* pSour = pCur;
	pTemp->pPrevious_Index = nullptr;
	pTemp->iValue = _iValue;
	while (nullptr != pSour->pPrevious_Index) //ó������ ����� ����
	{
		pSour = pSour->pPrevious_Index;
	}
	pTemp->pNext_Index = pSour;
	pSour->pPrevious_Index = pTemp;
	iLength++;
}

void CTest3::Push_back(int _iValue)
{
	tagLink* pTemp = new tagLink;
	tagLink* pSour = pCur;
	pTemp->pNext_Index = nullptr;
	pTemp->iValue = _iValue;
	while (nullptr != pSour->pNext_Index)//���������� �̴� ����
	{
		pSour = pSour->pNext_Index;
	}
	pTemp->pPrevious_Index = pSour;
	pSour->pNext_Index = pTemp;
	iLength++;
}

void CTest3::Pop(int _iValue)
{
	tagLink* pTemp = nullptr;
	tagLink* pSour = pCur;
	tagLink* pDst = nullptr;
	while (nullptr != pSour->pPrevious_Index)//ó������ ����� ����
	{
		pSour = pSour->pPrevious_Index;
	}
	while (_iValue != pSour->iValue)//���������� �̴� ����
	{
		if (nullptr != pSour->pNext_Index)
		{
			pSour = pSour->pNext_Index;
		}
		else
		{
			cout << _iValue << " ���� ����Ʈ�� ����" << endl;
			return;
		}
	}
	cout << pSour->iValue << "�� ã��" << endl;
	if (nullptr != pSour->pNext_Index)
	{
		pTemp = pSour->pNext_Index;
	}
	if (nullptr != pSour->pPrevious_Index)
	{
		pDst = pSour->pPrevious_Index;
	}
	if (nullptr != pDst)
	{
		pTemp->pPrevious_Index = pDst;
		if (nullptr != pTemp)
		{
			pDst->pNext_Index = pTemp;
		}
	}
	
	SAFE_DELETE(pSour);
	cout << _iValue << " ���� ������" << endl;
	iLength--;
}

void CTest3::Pop_front()
{
	tagLink* pTemp = nullptr;
	tagLink* pSour = pCur;
	while (nullptr != pSour->pPrevious_Index)//ó������ ����� ����
	{
		pSour = pSour->pPrevious_Index;
	}
	pTemp = pSour->pNext_Index;
	pTemp->pPrevious_Index = nullptr;
	SAFE_DELETE(pSour);
	cout << "�� �� �� ������" << endl;
}

void CTest3::Pop_back()
{
	tagLink* pTemp = nullptr;
	tagLink* pSour = pCur;
	while (nullptr != pSour->pNext_Index)//���������� �̴� ����
	{
		pSour = pSour->pNext_Index;
	}
	pTemp = pSour->pPrevious_Index;
	pTemp->pNext_Index = nullptr;
	SAFE_DELETE(pSour);
	cout << "�� �� �� ������" << endl;
}

void CTest3::Print()
{
	tagLink* pSour = pCur;
	while (nullptr != pSour->pPrevious_Index)//ó������ ����� ����
	{
		pSour = pSour->pPrevious_Index;
	}
	
	while (nullptr != pSour->pNext_Index)//���������� �̴� ����
	{
		cout << "[ " << pSour->iValue << " ] ";
		pSour = pSour->pNext_Index;
	}
	cout << "[ " << pSour->iValue << " ] ";
}

void CTest3::Erase()
{
	tagLink* pTemp = nullptr;
	tagLink* pSour = pCur;
	while (nullptr != pSour->pPrevious_Index)//ó������ ����� ����
	{
		pSour = pSour->pPrevious_Index;
	}
	while (nullptr != pSour->pNext_Index)//���������� �̴� ����
	{
		pTemp = pSour;
		pSour = pSour->pNext_Index;
		SAFE_DELETE(pTemp);
	}
}
