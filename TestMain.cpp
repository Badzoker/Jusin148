#include "CTest1.h"
#include "CTest2.h"
//#include "MyTest.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CTest2 ct2;
	ct2.Initialize();
	ct2.Put_front(3);
	ct2.Put_back(2);
	ct2.Put_back(4);
	ct2.Print();
	ct2.Erase();
	return 0;
}