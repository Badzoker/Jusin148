#include <iostream>

using namespace std;

typedef struct tPlayer
{
	const char* pJob;
	int iHealth;
	int iAttack;
}PLAYER, * PPLAYER;

//typedef struct tWarrior
//{
//	const char* pJob;
//	int iHealth;
//	int iAttack;
//}WARRIOR, * PWARRIOR;
//
//typedef struct tWizard
//{
//	const char* pJob;
//	int iHealth;
//	int iAttack;
//}WIZARD, * PWIZARD;
//
//typedef struct tThief
//{
//	const char* pJob;
//	int iHealth;
//	int iAttack;
//}THIEF, * PTHIEF;

typedef struct tMonster
{
	int iHealth;
	int iAttack;
}MON, *PMON;

enum THEEND
{
	LOSE,
	VICTORY
};

//���߿� Ŭ������ ����Լ��� �����ص� �ɵ�
void Text_Rpg();
void Menu_Start(int* _pChoice);
void Menu_Home(PLAYER _tPlayer[], int* _pChoice, PMON _pMon);
void Menu_Stage(PLAYER _tPlayer[], int* _pChoice, int* _pSelect, PMON _pMon);
void Menu_Fight(PLAYER _tPlayer[], int* _pChoice, int* _pSelect, PMON _pMon);
void Player_Stat(PLAYER _tPlayer[], int* _pChoice);
void Monster_Stat(PMON _pMon, int* _pSelect);
void Attack(PLAYER _tPlayer[], int* _pChoice, int* _pSelect, bool* _pCheck, PMON _pMon);


int main()
{
	Text_Rpg();
	
	return 0;
}

void Text_Rpg()
{
	int iChoice(0);
	int* pChoice = &iChoice;
	PLAYER tPlayer[3] = {};
	//PPLAYER gg[3]; -> �̰� �����ؼ� �ٲٱ�
	PPLAYER pWar = &tPlayer[0];
	PPLAYER pWiz = &tPlayer[1];
	PPLAYER pThi = &tPlayer[2];
	
	pWar->pJob = "����";
	pWiz->pJob = "������";
	pThi->pJob = "����";
	pWar->iHealth = 100;
	pWiz->iHealth = pWar->iHealth / 2;
	pThi->iHealth = pWar->iHealth / 4 * 3;
	pWar->iAttack = 10;
	pWiz->iAttack = pWar->iAttack * 2;
	pThi->iAttack = pWar->iAttack * 3 /2;
	MON tMon[3] = {};
	PMON pMon1 = &tMon[0];
	PMON pMon2 = &tMon[1];
	PMON pMon3 = &tMon[2];
	pMon1->iAttack = 3;
	pMon1->iHealth = 30;
	Menu_Start(pChoice);
	Menu_Home(tPlayer, pChoice, pMon1);
}
	

void Menu_Start(int* _pChoice)
{
	cout << "ĳ���͸� ���ÿ�\n1. ����  2. ������  3. ����\n" ;
	cin >> *_pChoice;
	*_pChoice -= 1;
}

void Menu_Home(PLAYER _tPlayer[], int* _pChoice, PMON _pMon)
{
	bool bCheck = true;
	int iSelect(0);
	int* pSelect = &iSelect;
	Player_Stat(_tPlayer, _pChoice);
	cout << "1. �����\t2. ����\n";
	cin >> iSelect;
	if (bCheck)
	{
		switch (iSelect)
		{
		case 1:
			iSelect = 0;
			Menu_Stage(_tPlayer, _pChoice, pSelect, _pMon);
			break;
		case 2:
			bCheck = false;
			break;
		default:
			iSelect = 0;
			Menu_Home(_tPlayer, _pChoice, _pMon);
			break;
		}
	}
	
	if (!bCheck)
		cout << "Text_rpg ��" << endl;
	
}

void Menu_Stage(PLAYER _tPlayer[], int* _pChoice, int* _pSelect, PMON _pMon)
{
	Player_Stat(_tPlayer, _pChoice);
	cout << "1. �ʱ�\t2. �߱�\t3. ���\t4. ����\n";
	cin >> *_pSelect;
	switch (*_pSelect)
	{
	case 1:
		Menu_Fight(_tPlayer, _pChoice, _pSelect, _pMon);
		break;
	case 2:
		Menu_Fight(_tPlayer, _pChoice, _pSelect, _pMon);
		break;
	case 3:
		Menu_Fight(_tPlayer, _pChoice, _pSelect, _pMon);
		break;
	case 4:
		Menu_Home(_tPlayer, _pChoice, _pMon);
		break;
	default:
		cout << "�ٽ� �����Ͻÿ�\n";
		*_pSelect = 0;
		Menu_Stage(_tPlayer, _pChoice, _pSelect, _pMon);
		break;
	}
}

void Menu_Fight(PLAYER _tPlayer[], int* _pChoice, int* _pSelect, PMON _pMon)
{
	
	bool bCheck = true;
	bool* pCheck = &bCheck;
	while (bCheck)
	{
		int iAction(0);
		Player_Stat(_tPlayer, _pChoice);
		Monster_Stat(_pMon, _pSelect);
		cout << "1. ����\t2. ����\t3. (��ų)\t4. (����)\n";
		cin >> iAction;
		switch (iAction)
		{
		case 1:
			Attack(_tPlayer, _pChoice, _pChoice, pCheck, _pMon);
			break;
		case 2:
			bCheck = false;
			*_pSelect = 0;

			break;
		default:
			cout << "�ٽ� �����Ͻÿ�\n";
			break;
		}
	}
	Menu_Stage(_tPlayer, _pChoice, _pSelect, _pMon);
}

void Player_Stat(PLAYER _tPlayer[], int* _pChoice)
{
	system("cls");
	cout << "���� : " << _tPlayer[*_pChoice].pJob << "\nü�� : " << _tPlayer[*_pChoice].iHealth << "\t���ݷ� : " << _tPlayer[*_pChoice].iAttack << endl;
}

void Monster_Stat(PMON _pMon, int* _pSelect)
{
	cout << "\n--���� ����â--\n����" << "\nü�� : " << _pMon->iHealth << "\t���ݷ� : " << _pMon->iAttack << endl;
}

void Attack(PLAYER _tPlayer[], int* _pChoice, int* _pSelect, bool* _pCheck, PMON _pMon)
{
	_tPlayer[*_pChoice].iHealth -= _pMon->iAttack;
	_pMon->iHealth -= _tPlayer[*_pChoice].iAttack;
	if (_tPlayer[*_pChoice].iHealth <= 0)
	{
		cout << "����!" << endl;
		Player_Stat(_tPlayer, _pChoice);
		Monster_Stat(_pMon, _pSelect);
		system("pause");
		_tPlayer[*_pChoice].iHealth = 100;
		*_pCheck = false;
	}
	else if (_pMon->iHealth <= 0)
	{
		cout << "�¸�!" << endl;
		Player_Stat(_tPlayer, _pChoice);
		Monster_Stat(_pMon, _pSelect);
		
		system("pause");
		_pMon->iHealth = 30;
		*_pCheck = false;
	}
}