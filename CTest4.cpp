#include "CTest4.h"

CTest4::CTest4()
{
	pTail = nullptr;
	pHead = nullptr;
	iLength = 0;
	tMylist = nullptr;
}

CTest4::~CTest4()
{
	cout << "�Ҹ��� ȣ��" << endl;
	Release();
}

void CTest4::Initialize()
{
	tMylist = new tagList;
	tMylist->iValue = 0;
	tMylist->Next_Index = nullptr;
	pHead = tMylist;
	pTail = tMylist;
}

void CTest4::Update()
{
	Initialize();
	int iInput(0), iValue(0);
	while (true)
	{
		system("cls");
		cout << "1. �߰�(��) 2. �߰�(��) 3. ����(��) 4. ����(��) 5. ����(Ư�� ��) 6. End" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			cout << "���� ��?" << endl;
			cin >> iValue;
			Push_front(iValue);
			cout << "�տ� " << iValue << " �߰��Ϸ�" << endl;
			break;
		case 2:
			cout << "���� ��?" << endl;
			cin >> iValue;
			Push_back(iValue);
			cout << "�ڿ� " << iValue << " �߰��Ϸ�" << endl;
			break;
		case 3:
			
			cout << "�� �� " << Pop_front() <<" �����Ϸ�" << endl;
			break;
		case 4:
			cout << "�� �� " << Pop_back() << " �����Ϸ�" << endl;
			break;
		case 5:
			cout << "���� ��?" << endl;
			cin >> iValue;
			Pop(iValue);
			cout <<  iValue << " �� �����Ϸ�" << endl;
			break;
		case 6:
			Erase();
			return;
			break;
		
		default:
			cout << "wrong" << endl;
			break;
		}
		Print();
		system("pause");
	}
}

void CTest4::Release()
{
	if (nullptr != tMylist)
	{
		SAFE_DELETE(tMylist);
	}
}


void CTest4::Push_front(int _iValue)
{
	tagList* pTemp = new tagList;
	pTemp->iValue = _iValue;
	pTemp->Next_Index = pHead;
	pHead = pTemp;
	pTail->Next_Index = pHead;
}

void CTest4::Push_back(int _iValue)
{
	tagList* pTemp = new tagList;
	pTemp->iValue = _iValue;
	pTemp->Next_Index = pHead;
	pTail->Next_Index = pTemp;
	pTail = pTemp;
}

void CTest4::Pop(int _iValue)
{
	tagList* pTemp = pHead;
	tagList* pSour = nullptr;
	while (_iValue != pTemp->iValue) // _iValue != iValue -> while
	{
		pSour = pTemp;
		pTemp = pTemp->Next_Index;
		if (pTemp == pHead)
		{
			cout << "There no include : " << _iValue << endl;
			return;
		}
	}
	//this will _iValue == iValue
	if (pTail == pTemp)
	{
		if (nullptr != pSour)
			pSour->Next_Index = pHead;
		pTail = pSour;
	}
	else if (pHead == pTemp)
	{
		pTail->Next_Index = pTemp->Next_Index;
		pHead = pTemp->Next_Index;
	}
	else
	{
		pSour->Next_Index = pTemp->Next_Index;
	}
	pTemp->iValue = 0;
	pTemp->Next_Index = nullptr;
	SAFE_DELETE(pTemp);
	cout << _iValue << " : Target Eliminated" << endl;
}

int CTest4::Pop_front()
{
	int iTemp(0);
	tagList* pTemp = pHead;
	pTail->Next_Index = pHead->Next_Index;
	pHead = pHead->Next_Index;
	iTemp = pTemp->iValue;
	pTemp->iValue = 0;
	pTemp->Next_Index = nullptr;
	SAFE_DELETE(pTemp);
	return iTemp;
}

int CTest4::Pop_back()
{
	int iTemp(0);
	tagList* pTemp = pHead;
	while (pTail != pTemp->Next_Index)
	{
		pTemp = pTemp->Next_Index;
	}
	pTail = pTemp;
	pTemp = pTail->Next_Index;
	iTemp = pTemp->iValue;
	pTemp->iValue = 0;
	pTemp->Next_Index = nullptr;
	pTail->Next_Index = pHead;
	SAFE_DELETE(pTemp);
	return iTemp;
}

void CTest4::Print()
{
	if (nullptr != pHead)
	{
		tagList* pTemp = pHead;
		while (pHead != pTemp->Next_Index)
		{
			cout << "[ " << pTemp->iValue << " ] ";
			pTemp = pTemp->Next_Index;
		}
		cout << "[ " << pTemp->iValue << " ] " << endl;
	}
}

void CTest4::Erase()
{
	tagList* pTemp = pHead;
	tagList* pSour = nullptr;
	cout << "���� ����" << endl;
	while (pTemp != pTail)
	{
		pTemp->iValue = 0;
		pSour = pTemp->Next_Index;
		//pTemp->Next_Index = nullptr;
		SAFE_DELETE(pTemp);
		pTemp = pSour;
	}
	pTemp->iValue = 0;
	tMylist = pTail;
}
