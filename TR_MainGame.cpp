#include "TR_MainGame.h"

CMainGame::CMainGame()
{
	m_pPlayer = nullptr;
	m_pMapBuilder = nullptr;
	//m_pCToString = nullptr;
}

CMainGame::~CMainGame()
{
	Release();
	cout << "main game eliminated" << endl;
}

void CMainGame::Initialize()
{
	m_pMapBuilder = new CMapBuilder; //여기서 할당하고 여기서 해제
	//m_pCToString = new CToString;
}

void CMainGame::Update()
{
	Menu();
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pMapBuilder);
}

void CMainGame::Menu()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		cout << "1. 게임시작\t2. 불러오기\t3. 종료" << endl;
		cin >> iInput;
		if (!m_pPlayer)
		{
			m_pPlayer = new CPlayer;
			//m_pPlayer->Set_CToString(m_pCToString);
			m_pMapBuilder->Set_Player(m_pPlayer);
			//m_pMapBuilder->Set_CToString(m_pCToString);
		}
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
