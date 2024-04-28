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

typedef struct tInfo // �Ƹ� ������ �� ���� ��ȹ�ؾ��ҵ�
{
	char szName[32];
	int iHealth;
	int iMana;
	int iAttack;
	
}INFO;
typedef struct tItem
{
	bool bMain_Item;
	bool bSub_Item;
	int iPotion;
	int iManaPotion;
}ITEM;
enum JOB
{
	WARRIOR = 1,
	WIZARD,
	THIEF,
	END
};
enum EQUIP
{
	WEAPON = 1,
	SUBWEAPON,
	//END
};

#pragma region �Լ������

void TextRpg_Menu();
INFO* Choose_Char(int _iInput);
ITEM* Item_Start();
void Print_Char(INFO* _pPlayer);
void TextRpg_Home(INFO* _pPlayer);
void TextRpg_Hunt(INFO* _pPlayer, ITEM* _tItem);
void Check_Stat(ITEM* _tItem);
void TextRpg_Market(INFO* _pPlayer, ITEM* _tItem);
void TextRpg_Market_Equip(INFO* _pPlayer, ITEM* _tItem);
void TextRpg_Market_Consumable(INFO* _pPlayer, ITEM* _tItem);
void TextRpg_Fight(INFO* _pPlayer, ITEM* _tItem, INFO* _pMonster);
void Create_Object(INFO** ppInfo, const char* _pName, int _iHealth,int _iMana, int _iAttack);
void Print_Monster(INFO* _monster);
void TextRpg_Skill(INFO* _pPlayer, ITEM* _tItem, INFO* _pMonster);
void TextRpg_Tool(INFO* _pPlayer, ITEM* _tItem);
void Print_Item(ITEM* _tItem);
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
	case WARRIOR:
		tPlayer = Choose_Char(iInput);
		break;
	case WIZARD:
		tPlayer = Choose_Char(iInput);
		break;
	case THIEF:
		tPlayer = Choose_Char(iInput);
		break;

	default:
		cout << "�߸� �Է��߽��ϴ�." << endl;
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
		Create_Object(&tTemp, "����", 100, 20, 10);
		break;
	case 2:
		Create_Object(&tTemp, "������", 50, 100,20);
		break;
	case 3:
		Create_Object(&tTemp, "����", 75, 50,15);
		break;
	}
	return tTemp;
}
void Print_Char(INFO* _pPlayer)
{
	system("cls");
	cout << "================\n���� : " << _pPlayer->szName << "\nü�� : " << _pPlayer->iHealth << "\n���� : " << _pPlayer->iMana << "\t  ���ݷ� : " << _pPlayer->iAttack << endl;
}
void TextRpg_Home(INFO* _pPlayer)
{
	int iInput(0);
	ITEM* tItem = nullptr; // �����Ҵ� 2��
	tItem = Item_Start();
	while (true)
	{
		Print_Char(_pPlayer);
		cout << "1. �����    2. ����    3. ����â    4. ��������" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			TextRpg_Hunt(_pPlayer, tItem);
			break;
		case 2:
			TextRpg_Market(_pPlayer, tItem);
			break;
		case 3:
			Check_Stat(tItem);
			break;
		case 4:
			if (tItem != nullptr) //heap ��ȯ 2��
			{
				delete tItem;
				tItem = nullptr;
			}
			return;
		default:
			cout << "�߸� �Է��߽��ϴ�." << endl;
			break;
		}
	}
}
ITEM* Item_Start()
{
	ITEM* tTemp = new ITEM;
	tTemp->bMain_Item = false;
	tTemp->bSub_Item = false;
	tTemp->iPotion = 0;
	tTemp->iManaPotion = 0;
	return tTemp;
}
void Check_Stat(ITEM* _tItem)
{
	char cTemp[32] = {};
	if (_tItem->bMain_Item)
		strcpy_s(cTemp, sizeof(cTemp), "������");
	else
		strcpy_s(cTemp, sizeof(cTemp), "����");
	cout << "����� : " << cTemp << endl;

	if (_tItem->bSub_Item)
		strcpy_s(cTemp, sizeof(cTemp), "������");
	else
		strcpy_s(cTemp, sizeof(cTemp), "����");
	cout << "������� : " << cTemp << endl;

	cout << "ü������ : " << _tItem->iPotion << " ��" << endl;
	cout << "�������� : " << _tItem->iManaPotion << " ��" << endl;
}
void TextRpg_Hunt(INFO* _pPlayer, ITEM* _tItem)
{
	int iInput(0);
	INFO* tMonster = nullptr;
	while (true)
	{
		Print_Char(_pPlayer);
		cout << "1. �ʱ�\t2. �߱�\t3. ���\t4. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Create_Object(&tMonster, "�ʱ�", 30 * iInput, 10 * iInput,3 * iInput);
			TextRpg_Fight(_pPlayer, _tItem, tMonster);
			break;
		case 2:
			Create_Object(&tMonster, "�߱�", 30 * iInput, 10 * iInput, 3 * iInput);
			TextRpg_Fight(_pPlayer, _tItem, tMonster);
			break;
		case 3:
			Create_Object(&tMonster, "���", 30 * iInput, 10 * iInput, 3 * iInput);
			TextRpg_Fight(_pPlayer, _tItem, tMonster);
			break;
		case 4:
			//if (tMonster != nullptr) // ���� 1. ���µ� ������� �ؼ� �׷��ǰ�?
			//{
			//	delete tMonster;
			//	tMonster = nullptr;
			//}
			return;
		default:
			cout << "�߸� �Է��߽��ϴ�." << endl;
			break;
		}
	}
}
void TextRpg_Market(INFO* _pPlayer, ITEM* _tItem)
{
	int iInput(0);
	while (true)
	{
		Print_Char(_pPlayer);
		Print_Item(_tItem);
		cout << "1. ���\t2. ����\t3. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			TextRpg_Market_Equip(_pPlayer, _tItem);
			break;
		case 2:
			TextRpg_Market_Consumable(_pPlayer, _tItem);
			break;
		case 3:
			return;
		default:
			cout << "�߸� �Է��߽��ϴ�." << endl;
			break;
		}
	}
}
void TextRpg_Market_Equip(INFO* _pPlayer, ITEM* _tItem)
{
	int iInput(0);
	while (true)
	{
		Print_Char(_pPlayer);
		Print_Item(_tItem);
		if (!strcmp(_pPlayer->szName, "����"))
		{
			cout << "1. ���\t2. ����\t3. ���ư���" << endl;
		}
		else if (!strcmp(_pPlayer->szName, "������"))
		{
			cout << "1. ������\t2. ����å(��������)\t3. ���ư���" << endl;
		}
		else//(!strcmp(_pPlayer->szName, "����"))
		{
			cout << "1. ������ �ܰ�\t2. ���� �ܰ�\t3. ���ư���" << endl;
		}
		
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (!_tItem->bMain_Item)
			{
				cout << "����� ���ſϷ�!" << endl;
				_tItem->bMain_Item = true;
				_pPlayer->iAttack += 10; //�׳� ������ ��
			}
			else
			{
				cout << "�̹� ��������" << endl;
			}
			system("pause");
			break;
		case 2:
			if (!_tItem->bSub_Item)
			{
				cout << "������� ���ſϷ�!" << endl;
				_tItem->bSub_Item = true;
				_pPlayer->iHealth += 50;//�׳� ������ ��
			}
			else
			{
				cout << "�̹� ��������" << endl;
			}
			system("pause");
			break;
		case 3:
			return;
		default:
			cout << "�߸� �Է��߽��ϴ�." << endl;
			break;
		}
	}
}
void TextRpg_Market_Consumable(INFO* _pPlayer, ITEM* _tItem)
{
	int iInput(0);
	while (true)
	{
		Print_Char(_pPlayer);
		Print_Item(_tItem);
		cout << "1. ü������\t2. ��������\t3. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			_tItem->iPotion += 1;
			cout << "ü������ ���ſϷ�!" << endl;
			cout << "���� ���Ǽ� : " << _tItem->iPotion << " ��" << endl;
			system("pause");
			break;
		case 2:
			_tItem->iManaPotion += 1;
			cout << "�������� ���ſϷ�!" << endl;
			cout << "���� �������Ǽ� : " << _tItem->iManaPotion << " ��" << endl;
			system("pause");
			break;
		case 3:
			return;
		default:
			cout << "�߸� �Է��߽��ϴ�." << endl;
			break;
		}
	}
}
void TextRpg_Fight(INFO* _pPlayer, ITEM* _tItem, INFO* _pMonster)
{
	int iInput(0);
	while (true)
	{
		Print_Char(_pPlayer);
		Print_Monster(_pMonster);
		cout << "1. ����    2. ��ų    3. ����    4. ����" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			_pPlayer->iHealth -= _pMonster->iAttack;
			_pMonster->iHealth -= _pPlayer->iAttack;
			break;
		case 2:
			TextRpg_Skill(_pPlayer, _tItem, _pMonster);
			break;
		case 3:
			TextRpg_Tool(_pPlayer, _tItem);
			break;
		case 4:
			delete _pMonster;
			_pMonster = nullptr;
			return;
		default:
			break;
		}
		if (0 >= _pPlayer->iHealth)
		{
			system("cls");
			cout << "================\n���� : " << _pPlayer->szName << "\nü�� : " << 0 << "\t  ���ݷ� : " << _pPlayer->iAttack << endl;
			_pPlayer->iHealth = 100;
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
			Print_Char(_pPlayer);
			cout << "\n+++++++++++++\n���� : " << _pMonster->szName << "\nü�� : " << 0 << "\t  ���ݷ� : " << _pMonster->iAttack << endl;
			cout << "�¸�" << endl;
			system("pause");
			delete _pMonster;
			_pMonster = nullptr;
			return;
		}
	}
}
void Create_Object(INFO** ppInfo, const char* _pName, int _iHealth, int _iMana, int _iAttack)
{
	*ppInfo = new INFO;
	strcpy_s((*ppInfo)->szName, sizeof(INFO), _pName);
	(*ppInfo)->iHealth = _iHealth;
	(*ppInfo)->iMana = _iMana;
	(*ppInfo)->iAttack = _iAttack;
}
void Print_Monster(INFO* _pMonster)
{
	cout << "\n+++++++++++++\n���� : " << _pMonster->szName << "\nü�� : " << _pMonster->iHealth << "\n���� : " << _pMonster->iMana << "\t  ���ݷ� : " << _pMonster->iAttack << endl;
}
void Print_Item(ITEM* _tItem)
{
	char cTemp[32] = {};
	if (_tItem->bMain_Item)
		strcpy_s(cTemp, sizeof(cTemp), "������");
	else
		strcpy_s(cTemp, sizeof(cTemp), "����");
	cout << "����� : " << cTemp << endl;

	if (_tItem->bSub_Item)
		strcpy_s(cTemp, sizeof(cTemp), "������");
	else
		strcpy_s(cTemp, sizeof(cTemp), "����");
	cout << "������� : " << cTemp << endl;

	cout << "ü������ : " << _tItem->iPotion << " ��" << endl;
	cout << "�������� : " << _tItem->iManaPotion << " ��" << endl;
}
void TextRpg_Skill(INFO* _pPlayer, ITEM* _tItem, INFO* _pMonster)
{
	int iInput(0);
	cout << "\n=====SKILL=====\n" << "1. �⺻ ��ų(mana -5)\t\t2. ���� ��ų(mana -20)\t\t3. ���ư���\n";
	while (true)
	{
		cout << "�����Ͻÿ�." << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (5 <= _pPlayer->iMana)
			{
				cout << "�⺻ ��ų ���!" << endl;
				_pPlayer->iMana -= 5;
				_pPlayer->iHealth -= _pMonster->iAttack;
				_pMonster->iHealth -= (_pPlayer->iAttack + 5);
				system("pause");
				return;
			}
			cout << "���� ����!" << endl;
			break;
		case 2:
			if (20 <= _pPlayer->iMana)
			{
				cout << "�⺻ ��ų ���!" << endl;
				_pPlayer->iMana -= 20;
				_pPlayer->iHealth -= _pMonster->iAttack;
				_pMonster->iHealth -= (_pPlayer->iAttack + 20);
				system("pause");
				return;
			}
			cout << "���� ����!" << endl;
			break;
		case 3:
			return;
		default:
			cout << "�߸� �Է��߽��ϴ�." << endl;
			break;
		}
		system("pause");
	}
	
}
void TextRpg_Tool(INFO* _pPlayer, ITEM* _tItem)
{
	int iInput(0);
	cout << "\n=====TOOL=====\n" << "1. ü������(+15)\t\t2. ��������(+15)\t\t3. ���ư���\n";
	while (true)
	{
		cout << "�����Ͻÿ�." << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (1 <= _tItem->iPotion)
			{
				cout << "���� ���!" << endl;
				_tItem->iPotion -= 1;
				_pPlayer->iHealth += 15;
				if (!strcmp(_pPlayer->szName, "����")) // �̰� �����ϴ� �� ���� ���� �� �� �ֵ��� �����غ���
				{
					if (_tItem->bSub_Item)
					{
						if (150 < _pPlayer->iHealth)
						{
							_pPlayer->iHealth = 150;
						}
					}
					else
					{
						if (100 < _pPlayer->iHealth)
						{
							_pPlayer->iHealth = 100;
						}
					}
				}
				else if (!strcmp(_pPlayer->szName, "������"))
				{
					if (_tItem->bSub_Item)
					{
						if (100 < _pPlayer->iHealth)
						{
							_pPlayer->iHealth = 100;
						}
					}
					else
					{
						if (50 < _pPlayer->iHealth)
						{
							_pPlayer->iHealth = 50;
						}
					}
				}
				else//(!strcmp(_pPlayer->szName, "����"))
				{
					if (_tItem->bSub_Item)
					{
						if (125 < _pPlayer->iHealth)
						{
							_pPlayer->iHealth = 125;
						}
					}
					else
					{
						if (75 < _pPlayer->iHealth)
						{
							_pPlayer->iHealth = 75;
						}
					}
					
				}
				system("pause");
				return;
			}
			cout << "���� ���� ����!" << endl;
			break;
		case 2:
			if (1 <= _tItem->iManaPotion)
			{
				cout << "�������� ���!" << endl;
				_tItem->iManaPotion -= 1;
				_pPlayer->iMana += 15;
				if (!strcmp(_pPlayer->szName, "����")) // �̰� �����ϴ� �� ���� ���� �� �� �ֵ��� �����غ���
				{
					if (20 < _pPlayer->iMana)
					{
						_pPlayer->iMana = 20;
					}
				}
				else if (!strcmp(_pPlayer->szName, "������"))
				{
					if (100 < _pPlayer->iMana)
					{
						_pPlayer->iMana = 100;
					}
				}
				else//(!strcmp(_pPlayer->szName, "����"))
				{
					if (50 < _pPlayer->iMana)
					{
						_pPlayer->iMana = 50;
					}
				}
				system("pause");
				return;
			}
			cout << "�������� ���� ����!" << endl;
			break;
		case 3:
			return;
		default:
			cout << "�߸� �Է��߽��ϴ�." << endl;
			break;
		}
		system("pause");
	}
}

#pragma endregion