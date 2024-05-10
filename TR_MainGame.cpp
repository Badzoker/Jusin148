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
	m_pMapBuilder = new CMapBuilder;
	//m_pMapBuilder->Initialize();
}

void CMainGame::Update()
{
	Menu();
}

void CMainGame::Release()
{
	//SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pMapBuilder);
}

void CMainGame::Menu()
{
	int iInput(0);
	while (true)
	{
		system("cls");
		cout << "1. ���ӽ���\t2. �ҷ�����\t3. ����" << endl;
		cin >> iInput;
		if (!m_pPlayer)
		{
			m_pPlayer = new CPlayer;
			m_pMapBuilder->Set_Player(m_pPlayer);
		}
		switch (iInput)
		{
		case 1:
			system("cls");
			cout << "������ �����Ͻÿ�.(1. ���� , 2. ������ , 3. ����) :" << endl;
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

