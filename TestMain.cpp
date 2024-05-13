#include "CTest1.h"
#include "CTest2.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CTest1 ct;
	CTest2 ct2;
	ct.Initialize(4);
	ct.Print();
	ct.Put(1, 7);
	ct.Put(2, 8);
	ct.Put(4, 5);
	ct.Print();
	ct.Put_back(1);
	ct.Print();
	ct.Put_front(88);
	ct.Print();
	ct.Pop(4);
	ct.Print();
	ct2.Initialize(5);
	ct2.Print();
	ct2.Put(1, 5);
	ct2.Put(2, 2);
	ct2.Put(3, 6);
	ct2.Put(4, 11);
	ct2.Put(5, 3);
	ct2.Print();
	ct2.Pop(4);
	ct2.Print();
	return 0;
}