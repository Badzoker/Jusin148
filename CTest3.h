#pragma once
#include "TestStruct.h"
#include "mynamespace.h"

class CTest3
{
public:
	CTest3();
	~CTest3();
	void Initialize();
	//void Update();
	void Release();
	void Push_front(int _iValue);
	void Push_back(int _iValue);
	void Pop(int _iValue);
	void Pop_front();
	void Pop_back();
	void Print();
	void Erase();

private:
	int iLength;
	tagLink* tMylink;
	tagLink* pCur;
};