#include "CTest1.h"

CTest1::CTest1()
{
	iList_Length = 0;
	ppList = nullptr;
}

CTest1::~CTest1()
{
	Release();
}

void CTest1::Initialize(int _iLength)
{
	iList_Length = _iLength;
	if (!ppList)
	{
		ppList = new int[_iLength];
		
		for (int i = 0; i < _iLength; i++)
		{
			(ppList[i]) = 0;
		}
	}
}

void CTest1::Update()
{
}

void CTest1::Release()
{
	SAFE_DELETE_ARRAY(ppList);
}

void CTest1::Put(int _index, int _iNumber)
{
	if (_index > iList_Length)
	{
		int* ppTemp = new int[_index];
		for (int i = 0; i < iList_Length; i++)
		{
			ppTemp[i] = ppList[i];
		}
		SAFE_DELETE_ARRAY(ppList);
		ppList = ppTemp;
		ppList[_index - 1] = _iNumber;
		iList_Length = _index;
	}
	else
	{
		ppList[_index - 1] = _iNumber;
	}
}

void CTest1::Put_front(int _iNumber)
{
	int* ppTemp = new int [iList_Length + 1];
	for (int i = 1; i < iList_Length + 1; i++)
	{
		ppTemp[i] = ppList[i - 1];
	}
	SAFE_DELETE_ARRAY(ppList);
	ppList = ppTemp;
	ppList[0] = _iNumber;
	iList_Length++;
}

void CTest1::Put_back(int _iNumber)
{
	int* ppTemp = new int[iList_Length + 1];
	for (int i = 0; i < iList_Length; i++)
	{
		ppTemp[i] = ppList[i];
	}
	SAFE_DELETE_ARRAY(ppList);
	ppList = ppTemp;
	ppList[iList_Length] = _iNumber;
	iList_Length++;
}

void CTest1::Pop(int _iIndex)
{
	int* ppTemp = new int[iList_Length - 1];
	for (int i = 0; i < iList_Length; i++)
	{
		if ((_iIndex - 1) < i)
		{
			ppTemp[i - 1] = ppList[i];
		}
		else
		{
			ppTemp[i] = ppList[i];
		}
	}
	SAFE_DELETE_ARRAY(ppList);
	ppList = ppTemp;
	iList_Length--;
}

void CTest1::Erase()
{
	for (int i = 0; i < iList_Length; i++)
	{
		ppList[i] = 0;
	}
}

void CTest1::Print()
{
	for (int i = 0; i < iList_Length; i++)
	{
		cout << "[ " << ppList[i] << " ]" << "\t";
	}
	cout << endl << "================================================================" << endl;
}
