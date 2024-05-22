#pragma once
#include <iostream>
#include <stdio.h>
#include "CToString.h"
#include "TR_Enum.h"

using namespace std;

#define SAFE_DELETE(p) if(p != nullptr){delete p;p = nullptr;}
#define SAFE_DELETE_ARRAY(p) if(p != nullptr){delete[] p;p = nullptr;}
#define PLAYER m_pPlayer->Get_Info()
#define PLAYER_ITEM m_pPlayer->Get_Item()
#define MONSTER m_pMonster->Get_Info()
#define DC_OBJ(p,o) dynamic_cast<p*>(o)
#define DC_PLAYER dynamic_cast<CPlayer*>(m_pPlayer)
#define DC_MONSTER dynamic_cast<CMonster*>(m_pMonster)
#define SC_PLAYER static_cast<CPlayer*>(m_pPlayer)
#define SC_MONSTER static_cast<CMonster*>(m_pMonster)
//#define PLAYER_G m_pPlayer_GameManager->Get_Info()
//#define PLAYER_G_ITEM m_pPlayer_GameManager->Get_Item()
//#define MONSTER_G m_pMonster_GameManager->Get_Info()
//#define DC_PLAYER_G_ITEM dynamic_cast<CPlayer*>(m_pPlayer_GameManager)->Get_Item()

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