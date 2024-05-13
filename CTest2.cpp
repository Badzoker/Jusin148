#include "CTest2.h"

CTest2::CTest2()
{
	tMylist = nullptr;
	iLength = 0;
}

CTest2::~CTest2()
{
	Release();
}

void CTest2::Initialize(int _iLength)
{
	tMylist = new MYLIST;
	tMylist->pPrevious_Index = nullptr;
	tMylist->pNext_Index = nullptr;
	tMylist->iValue = 0;

}

void CTest2::Update()
{
}

void CTest2::Release()
{
	if (nullptr != tMylist->pPrevious_Index)
	{
		SAFE_DELETE(tMylist);
	}
}

void CTest2::Pop(int _iIndex)
{
}

void CTest2::Put(int _iIndex, int _iValue)
{
}

void CTest2::Put_front(int _iValue)
{
}

void CTest2::Put_back(int _iValue)
{
	
}

void CTest2::Pop_front(int _iValue)
{
}

void CTest2::Pop_back(int _iValue)
{
}

void CTest2::Erase()
{
}

void CTest2::Print()
{
	cout << endl << endl;
}
