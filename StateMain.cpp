#include "StateMynamespace.h"
#include "State_Player.h"
#include "CFSM.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//State_Player* player = new State_Player;
	//player->Initialize();
	//SAFE_DELETE(player);
	CFSM* game = new CFSM;
	game->Initialize();
	SAFE_DELETE(game);
	return 0;
}