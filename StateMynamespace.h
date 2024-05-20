#pragma once
#pragma once
#include <iostream>

using namespace std;

#define SAFE_DELETE(p) if(p != nullptr){delete p;p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p != nullptr){delete[] p;p = nullptr;}


#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

enum STATE
{
	STATE_IDLE,
	STATE_RUN,
	STATE_ATTACK,
	STATE_DEAD,
	STATE_END
};