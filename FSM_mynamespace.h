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

//_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

template<typename T>
void Safe_Delete(T & _p)
{
	if (_p)
	{
		delete _p;
		_p = nullptr;
	}
}

template<typename T>
void Safe_Delete_Array(T& _p)
{
	if (_p)
	{
		delete[] _p;
		_p = nullptr;
	}
}

enum STATE
{
	STATE_IDLE,
	STATE_ATTACK,
	STATE_DEAD,
	STATE_END
};