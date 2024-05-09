#pragma once
#include "TR_Battle.h"
#include "TR_MapBuilder.h"
class CMainGame
{
private:
	CPlayer* m_pPlayer;
	CMapBuilder* m_pMapBuilder;
public:
	CMainGame();
	~CMainGame();
	void Initialize();
	void Update();
	void Release();
	void Menu();
};