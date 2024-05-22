#include "FSM_mynamespace.h"
#include "FSM_Machine.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	FSM_Machine game;
	game.Initialize();
	return 0;
}