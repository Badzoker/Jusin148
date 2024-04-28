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

#pragma region 함수선언부

void TextRpg_Menu();
INFO* Choose_Char(int _iInput);
void Print_Char(INFO* _player);
void TextRpg_Home(INFO* _player);
void TextRpg_Hunt(INFO* _player);
void TextRpg_Fight(INFO* _player, INFO* _pMonster);
void Create_Object(INFO** ppInfo, const char* _pName, int _iHealth, int _iAttack);
void Print_Monster(INFO* _monster);

#pragma endregion

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	TextRpg_Menu();
	return 0;
}

#pragma region 함수정의부

void TextRpg_Menu()
{
	int iInput(0);
	INFO* tPlayer = nullptr; 
	cout << "직업을 선택하시오.(1. 전사 , 2. 마법사 , 3. 도적) :" << endl;
	cin >> iInput;
	switch (iInput)
	{
	case WARRIOR :
		tPlayer = Choose_Char(iInput);
		break;
	case WIZARD:
		tPlayer = Choose_Char(iInput);
		break;
	case THIEF:
		tPlayer = Choose_Char(iInput);
		break;
	
	default: //해야하긴함
		break;
	}
	TextRpg_Home(tPlayer);
	if (tPlayer != nullptr)
	{
		delete tPlayer; //heap 반환 1번
		tPlayer = nullptr;
	}
	
}

INFO* Choose_Char(int _iInput)
{
	INFO* tTemp = nullptr;
	switch (_iInput)
	{
	case 1:
		tTemp = new INFO;
		strcpy_s(tTemp->szName, 32, "전사");
		tTemp->iHealth = 100;
		tTemp->iAttack = 10;
		break;
	case 2:
		Create_Object(&tTemp, "마법사", 50, 20);
		break;
	case 3:
		Create_Object(&tTemp, "도적", 75, 15);
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

void TextRpg_Home(INFO* _player)
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
			TextRpg_Hunt(_player);
			break;
		case 2:
			return;
		default:
			break;
		}
	}
}

void TextRpg_Hunt(INFO* _player)
{
	int iInput(0);
	INFO* tMonster = nullptr;
	while (true)
	{
		Print_Char(_player);
		cout << "1. 초급\t2. 중급\t3. 고급\t4. 전 단계" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Create_Object(&tMonster, "초급", 30 * iInput, 3 * iInput);
			TextRpg_Fight(_player, tMonster);
			break;
		case 2:
			Create_Object(&tMonster, "중급", 30 * iInput, 3 * iInput);
			TextRpg_Fight(_player, tMonster);
				break;
		case 3:
			Create_Object(&tMonster, "고급", 30 * iInput, 3 * iInput);
			TextRpg_Fight(_player, tMonster);
				break;
		case 4:
			/*if (tMonster != nullptr) // 질문 1. 없는데 지우려고 해서 그런건가?
			{
				delete tMonster;
				tMonster = nullptr;
			}*/
			return;
		default:
			cout << "잘못 입력했습니다." << endl;
			break;
		}
	}
}

void TextRpg_Fight(INFO* _player, INFO* _pMonster)
{
	int iInput(0);
	while (true)
	{
		
		Print_Char(_player);
		Print_Monster(_pMonster);
		cout << "1. 공격    2. 도망" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			_player->iHealth -= _pMonster->iAttack;
			_pMonster->iHealth -= _player->iAttack;
			break;
		case 2:
			delete _pMonster;
			_pMonster = nullptr;
			return;
		default:
			break;
		}
		if (0 >= _player->iHealth)
		{
			system("cls");
			cout << "================\n직업 : " << _player->szName << "\n체력 : " << 0 << "\t  공격력 : " << _player->iAttack << endl;
			_player->iHealth = 100;
			Print_Monster(_pMonster);
			cout << "죽음" << endl;
			system("pause");
			delete _pMonster;
			_pMonster = nullptr;
			return;
		}
		else if (0 >= _pMonster->iHealth)
		{
			system("cls");
			Print_Char(_player);
			cout << "\n+++++++++++++\n괴물 : " << _pMonster->szName << "\n체력 : " << 0 << "\t  공격력 : " << _pMonster->iAttack << endl;
			cout << "승리" << endl;
			system("pause");
			delete _pMonster;
			_pMonster = nullptr;
			return;
		}
	}
}

void Create_Object(INFO** ppInfo, const char* _pName, int _iHealth, int _iAttack)
{
	*ppInfo = new INFO;
	strcpy_s((*ppInfo)->szName, sizeof(INFO), _pName);
	(*ppInfo)->iHealth = _iHealth;
	(*ppInfo)->iAttack = _iAttack;
}

void Print_Monster(INFO* _monster)
{
	cout << "\n+++++++++++++\n괴물 : " << _monster->szName << "\n체력 : " << _monster->iHealth << "\t  공격력 : " << _monster->iAttack << endl;
}

#pragma endregion