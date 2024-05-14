#pragma once
#include "mynamespace.h"
#include "TestStruct.h"
class CTest2
{
public:
	CTest2();
	~CTest2();
	void Initialize();
	void Update();
	void Release();
	void Pop(int _iIndex);
	void Put(int _iIndex, int _iValue);
	void Put_front(int _iValue);
	void Put_back(int _iValue);
	void Pop_front(int _iValue);
	void Pop_back(int _iValue);
	void Erase();
	void Print();
private:
	tagList* tMylist;
	//MYPOINTER* pCurrent;
	int iLength;
	tagList* pCur;
};