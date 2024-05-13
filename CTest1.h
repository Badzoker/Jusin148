#pragma once
#include "mynamespace.h"

class CTest1
{
	
public:
	CTest1();
	~CTest1();
	void Initialize(int _iLength);
	void Update();
	void Release();
	void Put(int _index, int _iNumber);
	void Put_front(int _iNumber);
	void Put_back(int _iNumber);
	void Pop(int _iIndex);
	void Erase();
	void Print();
private:
	int iList_Length;
	int* ppList;
};

