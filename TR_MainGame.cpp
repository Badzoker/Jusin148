#include "TR_MainGame.h"

CMainGame::CMainGame()
{
	m_pPlayer = nullptr;
	m_pMapBuilder = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
}

void CMainGame::Initialize()
{
	m_pPlayer = new CPlayer;
	m_pMapBuilder = new CMapBuilder;
	m_pMapBuilder->Initialize();
}

void CMainGame::Update()
{
	Menu();
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pMapBuilder);
}

void CMainGame::Menu()
{
	m_pMapBuilder->Set_Player(m_pPlayer);
	int iInput(0);
	while (true)
	{
		system("cls");
		cout << "1. 게임시작\t2. 불러오기\t3. 종료" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			system("cls");
			cout << "직업을 선택하시오.(1. 전사 , 2. 마법사 , 3. 도적) :" << endl;
			cin >> iInput;
			m_pPlayer->Initialize(iInput);
			m_pMapBuilder->Map_Home();
			break;
		case 2:
			m_pPlayer->Load();
			m_pMapBuilder->Map_Home();
			break;
		case 3:
			return;
		default:
			cout << "wrong" << endl;
			break;
		}
	}
}

