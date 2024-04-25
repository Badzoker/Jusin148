#include <iostream>

#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

using namespace std;

typedef struct tInfo
{
	char szName[32];
	int iHealth;
	int iAttack;

}INFO;

enum JOB
{
	WARRIOR = 1,
	WIZARD,
	THIEF,
	END
};

void HW1();
INFO Choose_Char(int _iInput);
void Print_Char(INFO* _player);
void HW1_Home(INFO* _player);
void HW1_Hunt(INFO* _player);
void HW1_Fight(INFO* _player, int* _pChoice);
INFO Create_Monster(int* _iChoice);
void Print_Monster(INFO* _monster);


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	HW1();
	return 0;
}

void HW1()
{
	int iInput(0);
	INFO* tPlayer = new INFO{}; // 동적할당 1번
	cout << "직업을 선택하시오.(1. 전사 , 2. 마법사 , 3. 도적) :" << endl;
	cin >> iInput;
	switch (iInput)
	{
	case WARRIOR :
		*tPlayer = Choose_Char(iInput);
		break;
	case WIZARD:
		*tPlayer = Choose_Char(iInput);
		break;
	case THIEF:
		*tPlayer = Choose_Char(iInput);
		break;
	
	default: //해야하긴함
		break;
	}
	HW1_Home(tPlayer);
	delete tPlayer; //heap 반환 1번
	tPlayer = nullptr;
	
}

INFO Choose_Char(int _iInput)
{
	INFO tTemp = {};
	switch (_iInput)
	{
	case 1:
		strcpy_s(tTemp.szName, 32, "전사");
		tTemp.iHealth = 100;
		tTemp.iAttack = 10;
		break;
	case 2:
		strcpy_s(tTemp.szName, 32, "마법사");
		tTemp.iHealth = 50;
		tTemp.iAttack = 20;
		break;
	case 3:
		strcpy_s(tTemp.szName, 32, "도적");
		tTemp.iHealth = 75;
		tTemp.iAttack = 15;
		break;
	default:
		break;
	}
	return tTemp;
}

void Print_Char(INFO* _player)
{
	system("cls");
	cout << "================\n직업 : " << _player->szName << "\n체력 : " << _player->iHealth << "\t  공격력 : " << _player->iAttack << endl;
}

void HW1_Home(INFO* _player)
{
	int iInput(0);
	while (true)
	{
		Print_Char(_player);
		cout << "1. 사냥터    2. 종료" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			HW1_Hunt(_player);
			break;
		case 2:
			return;
		default:
			break;
		}
	}
}

void HW1_Hunt(INFO* _player)
{
	int* pInput = new int(0); //동적할당 2번
	int iInput(0);
	while (true)
	{
		Print_Char(_player);
		cout << "1. 초급\t2. 중급\t3. 고급\t4. 전 단계" << endl;
		cin >> *pInput;
		if (*pInput == 4)
		{
			delete pInput;
			pInput = nullptr; //heap 반환 2번
			return;
		}
		else if (*pInput < 4)
		{
			HW1_Fight(_player, pInput);
		}
		else
		{
			cout << "잘못 입력했습니다." << endl;
		}
	}
}

void HW1_Fight(INFO* _player, int* _pChoice)
{
	int iInput(0);
	INFO tMonster = Create_Monster(_pChoice);
	while (true)
	{
		
		Print_Char(_player);
		Print_Monster(&tMonster);
		cout << "1. 공격    2. 도망" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			_player->iHealth -= tMonster.iAttack;
			tMonster.iHealth -= _player->iAttack;
			break;
		case 2:
			return;
		default:
			break;
		}
		if (0 >= _player->iHealth)
		{
			system("cls");
			cout << "================\n직업 : " << _player->szName << "\n체력 : " << 0 << "\t  공격력 : " << _player->iAttack << endl;
			_player->iHealth = 100;
			Print_Monster(&tMonster);
			cout << "죽음" << endl;
			system("pause");
			return;
		}
		else if (0 >= tMonster.iHealth)
		{
			system("cls");
			Print_Char(_player);
			cout << "\n+++++++++++++\n괴물 : " << tMonster.szName << "\n체력 : " << 0 << "\t  공격력 : " << tMonster.iAttack << endl;
			cout << "승리" << endl;
			system("pause");
			return;
		}
	}
}

INFO Create_Monster(int* _iChoice)
{
	INFO tMonster = {};
	int iTemp = *_iChoice;
	switch (*_iChoice)
	{
	case 1:
		strcpy_s(tMonster.szName, 32, "초급");
		tMonster.iHealth = iTemp * 30;
		tMonster.iAttack = iTemp * 3;
		break;
	case 2:
		strcpy_s(tMonster.szName, 32, "중급");
		tMonster.iHealth = iTemp * 30;
		tMonster.iAttack = iTemp * 3;
		break;
	case 3:
		strcpy_s(tMonster.szName, 32, "고급");
		tMonster.iHealth = iTemp * 30;
		tMonster.iAttack = iTemp * 3;
		break;
	default:
		break;
	}
	
	return tMonster;
}

void Print_Monster(INFO* _monster)
{
	cout << "\n+++++++++++++\n괴물 : " << _monster->szName << "\n체력 : " << _monster->iHealth << "\t  공격력 : " << _monster->iAttack << endl;
}