#include "CTest1.h"
#include "CTest2.h"
#include "CTest3.h"
//#include "MyTest.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	/*CTest2 ct2;
	ct2.Initialize();
	ct2.Put_front(3);
	ct2.Put_back(2);
	ct2.Put_back(4);
	ct2.Print();
	ct2.Erase();*/
	CTest3 ct;
	ct.Initialize();
	ct.Push_front(3);
	ct.Push_front(2);
	ct.Push_back(55);
	ct.Push_front(12);
	ct.Print();
	ct.Pop(2);
	ct.Pop_back();
	ct.Print();
	ct.Erase();
	return 0;
}