#pragma once
#include <iostream>
#include <stdio.h>
#include "CToString.h"
#include "TR_Enum.h"
#include "TR_Struct.h"
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//#define SAFE_DELETE(p) if(p != nullptr){delete p;p = nullptr;}
//#define SAFE_DELETE_ARRAY(p) if(p != nullptr){delete[] p;p = nullptr;}
#define PLAYER m_pPlayer->Get_Info()
#define PLAYER_ITEM m_pPlayer->Get_Item()
#define MONSTER m_pMonster->Get_Info()
#define DC_OBJ(p,o) dynamic_cast<p*>(o)
#define DC_PLAYER dynamic_cast<CPlayer*>(m_pPlayer)
#define DC_MONSTER dynamic_cast<CMonster*>(m_pMonster)
#define SC_PLAYER static_cast<CPlayer*>(m_pPlayer)
#define SC_MONSTER static_cast<CMonster*>(m_pMonster)


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
	if (_p != nullptr)
	{
		delete _p;
		_p = nullptr;
	}
}

template<typename T>
void Safe_Delete_Array(T & _p)
{
	if (_p != nullptr)
	{
		delete[] _p;
		_p = nullptr;
	}
}