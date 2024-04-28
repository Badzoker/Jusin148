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

#pragma region �Լ������

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

#pragma region �Լ����Ǻ�

void TextRpg_Menu()
{
	int iInput(0);
	INFO* tPlayer = nullptr; 
	cout << "������ �����Ͻÿ�.(1. ���� , 2. ������ , 3. ����) :" << endl;
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
	
	default: //�ؾ��ϱ���
		break;
	}
	TextRpg_Home(tPlayer);
	if (tPlayer != nullptr)
	{
		delete tPlayer; //heap ��ȯ 1��
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
		strcpy_s(tTemp->szName, 32, "����");
		tTemp->iHealth = 100;
		tTemp->iAttack = 10;
		break;
	case 2:
		Create_Object(&tTemp, "������", 50, 20);
		break;
	case 3:
		Create_Object(&tTemp, "����", 75, 15);
		break;
	default:
		break;
	}
	return tTemp;
}

void Print_Char(INFO* _player)
{
	system("cls");
	cout << "================\n���� : " << _player->szName << "\nü�� : " << _player->iHealth << "\t  ���ݷ� : " << _player->iAttack << endl;
}

void TextRpg_Home(INFO* _player)
{
	int iInput(0);
	while (true)
	{
		Print_Char(_player);
		cout << "1. �����    2. ����" << endl;
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
		cout << "1. �ʱ�\t2. �߱�\t3. ���\t4. �� �ܰ�" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Create_Object(&tMonster, "�ʱ�", 30 * iInput, 3 * iInput);
			TextRpg_Fight(_player, tMonster);
			break;
		case 2:
			Create_Object(&tMonster, "�߱�", 30 * iInput, 3 * iInput);
			TextRpg_Fight(_player, tMonster);
				break;
		case 3:
			Create_Object(&tMonster, "���", 30 * iInput, 3 * iInput);
			TextRpg_Fight(_player, tMonster);
				break;
		case 4:
			/*if (tMonster != nullptr) // ���� 1. ���µ� ������� �ؼ� �׷��ǰ�?
			{
				delete tMonster;
				tMonster = nullptr;
			}*/
			return;
		default:
			cout << "�߸� �Է��߽��ϴ�." << endl;
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
		cout << "1. ����    2. ����" << endl;
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
			cout << "================\n���� : " << _player->szName << "\nü�� : " << 0 << "\t  ���ݷ� : " << _player->iAttack << endl;
			_player->iHealth = 100;
			Print_Monster(_pMonster);
			cout << "����" << endl;
			system("pause");
			delete _pMonster;
			_pMonster = nullptr;
			return;
		}
		else if (0 >= _pMonster->iHealth)
		{
			system("cls");
			Print_Char(_player);
			cout << "\n+++++++++++++\n���� : " << _pMonster->szName << "\nü�� : " << 0 << "\t  ���ݷ� : " << _pMonster->iAttack << endl;
			cout << "�¸�" << endl;
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
	cout << "\n+++++++++++++\n���� : " << _monster->szName << "\nü�� : " << _monster->iHealth << "\t  ���ݷ� : " << _monster->iAttack << endl;
}

#pragma endregion