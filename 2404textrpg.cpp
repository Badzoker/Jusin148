#include <iostream>

using namespace std;

const int iCount_Character = 3;
//const int iCount_Monster = 3;

typedef struct tPlayer
{
	const char* pJob;
	int iHealth;
	int iAttack;

}PLAYER, * PPLAYER;


typedef struct tMonster
{
	int iHealth;
	int iAttack;

}MON, * PMON;


enum HP
{
	WARRIOR = 100,
	WIZARD = 50,
	THIEF = 75
};

//나중에 클래스던 멤버함수로 구현해도 될듯
void Text_Rpg();
void Menu_Start(int* _pChoice);
void Menu_Home(PPLAYER _pPlayer[], int* _pChoice, PMON _pMon[]);
void Menu_Stage(PPLAYER _pPlayer[], int* _pChoice, int* _pSelect, PMON _pMon[]);
void Menu_Fight(PPLAYER _pPlayer[], int* _pChoice, int* _pSelect, PMON _pMon[]);
void Player_Stat(PPLAYER _pPlayer[], int* _pChoice);
void Monster_Stat(PMON _pMon[], int* _pSelect);
void Attack(PPLAYER _pPlayer[], int* _pChoice, int* _pSelect, bool* _pCheck, PMON _pMon[]);


int main()
{
	Text_Rpg();

	return 0;
}

void Text_Rpg()
{
	int iChoice(0);
	int* pChoice = &iChoice;
	PLAYER tPlayer[iCount_Character] = {"전사", 100, 10, "마법사", 50, 20, "도적", 75, 15};
	PPLAYER pPlayer[iCount_Character] = {};
	MON tMon[iCount_Character] = {};
	PMON pMon[iCount_Character] = {};
	for (int i = 0; i < iCount_Character; i++)
	{
		pPlayer[i] = &tPlayer[i];
		pMon[i] = &tMon[i];
		pMon[i]->iHealth = (i + 1) * 30;
		pMon[i]->iAttack = (i + 1) * 3;
	}
	/*pPlayer[0]->pJob = "전사";
	pPlayer[1]->pJob = "마법사";
	pPlayer[2]->pJob = "도적";
	pPlayer[0]->iHealth = 100;
	pPlayer[1]->iHealth = 50;
	pPlayer[2]->iHealth = 75;
	pPlayer[0]->iAttack = 10;
	pPlayer[1]->iAttack = 20;
	pPlayer[2]->iAttack = 15;*/
	
	Menu_Start(pChoice);
	Menu_Home(pPlayer, pChoice, pMon);
}


void Menu_Start(int* _pChoice)
{
	cout << "캐릭터를 고르시오\n1. 전사  2. 마법사  3. 도적\n";
	cin >> *_pChoice;
	*_pChoice -= 1;
}

void Menu_Home(PPLAYER _pPlayer[], int* _pChoice, PMON _pMon[])
{
	bool bCheck = true;
	int iSelect(0);
	int* pSelect = &iSelect;
	Player_Stat(_pPlayer, _pChoice);
	cout << "1. 사냥터\t2. 종료\n";
	cin >> iSelect;
	if (bCheck)
	{
		switch (iSelect)
		{
		case 1:
			iSelect = 0;
			Menu_Stage(_pPlayer, _pChoice, pSelect, _pMon);
			break;
		case 2:
			bCheck = false;
			break;
		default:
			iSelect = 0;
			Menu_Home(_pPlayer, _pChoice, _pMon);
			break;
		}
	}
	if (!bCheck)
		cout << "Text_rpg 끝" << endl;
}

void Menu_Stage(PPLAYER _pPlayer[], int* _pChoice, int* _pSelect, PMON _pMon[])
{
	Player_Stat(_pPlayer, _pChoice);
	cout << "1. 초급\t2. 중급\t3. 고급\t4. 이전\n";
	cin >> *_pSelect;
	switch (*_pSelect)
	{
	case 1:
		Menu_Fight(_pPlayer, _pChoice, _pSelect, _pMon);
		break;
	case 2:
		Menu_Fight(_pPlayer, _pChoice, _pSelect, _pMon);
		break;
	case 3:
		Menu_Fight(_pPlayer, _pChoice, _pSelect, _pMon);
		break;
	case 4:
		Menu_Home(_pPlayer, _pChoice, _pMon);
		break;
	default:
		cout << "다시 선택하시오\n";
		*_pSelect = 0;
		Menu_Stage(_pPlayer, _pChoice, _pSelect, _pMon);
		break;
	}
}

void Menu_Fight(PPLAYER _pPlayer[], int* _pChoice, int* _pSelect, PMON _pMon[])
{
	*_pSelect -= 1;
	bool bCheck = true;
	bool* pCheck = &bCheck;
	for (int i = 0; i < iCount_Character; i++) //몬스터 체력 초기화
	{
		_pMon[i]->iHealth = (i + 1) * 30;
	}
	while (bCheck)
	{
		int iAction(0);
		Player_Stat(_pPlayer, _pChoice);
		Monster_Stat(_pMon, _pSelect);
		cout << "1. 공격\t2. 도망\t3. (스킬)\t4. (도구)\n";
		cin >> iAction;
		switch (iAction)
		{
		case 1:
			Attack(_pPlayer, _pChoice, _pSelect, pCheck, _pMon);
			break;
		case 2:
			bCheck = false;
			for (int i = 0; i < iCount_Character; i++)
			{
				_pMon[i]->iHealth = (i + 1) * 30;
			}
			*_pSelect = 0;
			break;
		default:
			cout << "다시 선택하시오\n";
			break;
		}
	}
	Menu_Stage(_pPlayer, _pChoice, _pSelect, _pMon);
}

void Player_Stat(PPLAYER _pPlayer[], int* _pChoice)
{
	system("cls");
	if (_pPlayer[*_pChoice]->iHealth < 0)
	{
		_pPlayer[*_pChoice]->iHealth = 0;
	}
	cout << "직업 : " << _pPlayer[*_pChoice]->pJob << "\n체력 : " << _pPlayer[*_pChoice]->iHealth << "\t공격력 : " << _pPlayer[*_pChoice]->iAttack << endl;
}

void Monster_Stat(PMON _pMon[], int* _pSelect)
{
	cout << "\n--몬스터 상태창--\n굼바" << "\n체력 : " << _pMon[*_pSelect]->iHealth << "\t공격력 : " << _pMon[*_pSelect]->iAttack << endl;
}

void Attack(PPLAYER _pPlayer[], int* _pChoice, int* _pSelect, bool* _pCheck, PMON _pMon[])
{
	_pPlayer[*_pChoice]->iHealth -= _pMon[*_pSelect]->iAttack;
	_pMon[*_pSelect]->iHealth -= _pPlayer[*_pChoice]->iAttack;
	if (_pPlayer[*_pChoice]->iHealth <= 0)
	{
		Player_Stat(_pPlayer, _pChoice);
		Monster_Stat(_pMon, _pSelect);
		cout << "죽음!" << endl;
		system("pause");
		switch (*_pChoice)
		{
		case 0:
			_pPlayer[*_pChoice]->iHealth = HP(WARRIOR);
			break;
		case 1:
			_pPlayer[*_pChoice]->iHealth = HP(WIZARD);
			break;
		case 2:
			_pPlayer[*_pChoice]->iHealth = HP(THIEF);
			break;
		default:
			break;
		}
		*_pCheck = false;
	}
	else if (_pMon[*_pSelect]->iHealth <= 0)
	{
		Player_Stat(_pPlayer, _pChoice);
		Monster_Stat(_pMon, _pSelect);
		cout << "승리!" << endl;
		system("pause");
		_pMon[*_pSelect]->iHealth = 30 * (*_pSelect + 1);
		*_pCheck = false;
	}
}