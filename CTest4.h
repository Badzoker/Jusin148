#pragma once
#include "mynamespace.h"
#include "TestStruct.h"
class CTest4 //Circular Linked list
{
public:
	CTest4();
	~CTest4();
	void Initialize();
	void Update();
	void Release();
	void Push_front(int _iValue);
	void Push_back(int _iValue);
	void Pop(int _iValue);
	int Pop_front();
	int Pop_back();
	void Print();
	void Erase();

private:
	int iLength;
	tagList* tMylist;
	tagList* pHead;
	tagList* pTail;
};

