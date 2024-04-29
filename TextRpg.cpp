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
	LOAD,
	END
};
enum EQUIP
{
	WEAPON = 1,
	SUBWEAPON,
	//END//HAHA
};

#pragma region �Լ������


void TextRpg_Menu();
INFO* Choose_Char(int _iInput);
ITEM* Item_Start();

void Print_Char(INFO* _pPlayer);
void TextRpg_Home(INFO* _pPlayer, ITEM* _pItem);
void TextRpg_Hunt(INFO* _pPlayer, ITEM* _pItem);
void Check_Stat(ITEM* _pItem);
void TextRpg_Market(INFO* _pPlayer, ITEM* _pItem);
void TextRpg_Market_Equip(INFO* _pPlayer, ITEM* _pItem);
void TextRpg_Market_Consumable(INFO* _pPlayer, ITEM* _pItem);
void TextRpg_Fight(INFO* _pPlayer, ITEM* _pItem, INFO* _pMonster);
INFO* Create_Object(const char* _pName, int _iHealth, int _iMana, int _iAttack);
void Print_Monster(INFO* _monster);
void TextRpg_Skill(INFO* _pPlayer, ITEM* _pItem, INFO* _pMonster);
void TextRpg_Tool(INFO* _pPlayer, ITEM* _pItem);
void Print_Item(ITEM* _pItem);
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
	ITEM* tItem = nullptr; // �����Ҵ� 2��
	FILE* pFileJob = NULL;
	FILE* pFileItem = NULL;
	errno_t errReadJob = fopen_s(&pFileJob, "Data/Job.txt", "rb");
	errno_t errReadItem = fopen_s(&pFileItem, "Data/Item.txt", "rb");
	cout << "������ �����Ͻÿ�.(1. ���� , 2. ������ , 3. ���� , 4. �ҷ�����) :" << endl;
	cin >> iInput;
	switch (iInput)
	{
	case WARRIOR:
		tPlayer = Choose_Char(iInput);
		//tItem = Item_Start();

		break;
	case WIZARD:
		tPlayer = Choose_Char(iInput);
		tItem = Item_Start();

		break;
	case THIEF:
		tPlayer = Choose_Char(iInput);
		tItem = Item_Start();

		break;
	case LOAD: 
		if (0 == errReadJob && 0 == errReadItem)
		{
			tPlayer = new INFO;
			tItem = new ITEM;
			fread(tPlayer, sizeof(INFO), 1, pFileJob);
			fclose(pFileJob);
			fread(tItem, sizeof(ITEM), 1, pFileItem);
			/*while (0 == feof(pFile))
			{

			}*/
			
			fclose(pFileItem);
		}
		else
		{
			cout << "�ҷ����� ����" << endl;
		}
		system("pause");
		break;
	default:
		cout << "�߸� �Է��߽��ϴ�." << endl;
		break;
	}
	TextRpg_Home(tPlayer, tItem);
	if (tPlayer != nullptr)
	{
		delete tPlayer; //heap ��ȯ 1��
		tPlayer = nullptr;
	}
	if (tItem != nullptr) //heap ��ȯ 2��
	{
		delete tItem;
		tItem = nullptr;
	}
}
INFO* Choose_Char(int _iInput)
{
	INFO* tTemp = nullptr;
	switch (_iInput)
	{
	case 1:
		tTemp = Create_Object("����", 100, 20, 10);
		break;
	case 2:
		tTemp = Create_Object("������", 50, 100,20);
		break;
	case 3:
		tTemp = Create_Object("����", 75, 50,15);
		break;
	}
	return tTemp;
}
void Print_Char(INFO* _pPlayer)
{
	system("cls");
	cout << "================\n���� : " << _pPlayer->szName << "\nü�� : " << _pPlayer->iHealth << "\n���� : " << _pPlayer->iMana << "\t  ���ݷ� : " << _pPlayer->iAttack << endl;
}

void TextRpg_Home(INFO* _pPlayer, ITEM* _pItem)
{
	int iInput(0), iTemp(0);
	
	FILE* pFileJob = NULL;
	FILE* pFileItem = NULL;
	
	errno_t errWriteJob = fopen_s(&pFileJob, "Data/Job.txt", "wb");
	errno_t errWriteItem = fopen_s(&pFileItem, "Data/Item.txt", "wb");
	char cTemp[32] = {};

	while (true)
	{
		Print_Char(_pPlayer);
		cout << "1. �����    2. ����    3. ����â    4. ��������    5. ����" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			TextRpg_Hunt(_pPlayer, _pItem);
			break;
		case 2:
			TextRpg_Market(_pPlayer, _pItem);
			break;
		case 3:
			Check_Stat(_pItem);
			break;
		case 4:
			if (0 == errWriteJob && 0 == errWriteItem)
			{
				cout << "�����" << endl;

				fwrite(_pPlayer, sizeof(INFO), 1, pFileJob);
				fclose(pFileJob);
				fwrite(_pItem, sizeof(ITEM), 1, pFileItem);
				fclose(pFileItem);
			}
			else
			{
				cout << "�������忡��" << endl;
			}
			system("pause");
			break;
		case 5:
			
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
void Check_Stat(ITEM* _pItem)
{
	char cTemp[32] = {};
	if (_pItem->bMain_Item)
		strcpy_s(cTemp, sizeof(cTemp), "������");
	else
		strcpy_s(cTemp, sizeof(cTemp), "����");
	cout << "����� : " << cTemp << endl;

	if (_pItem->bSub_Item)
		strcpy_s(cTemp, sizeof(cTemp), "������");
	else
		strcpy_s(cTemp, sizeof(cTemp), "����");
	cout << "������� : " << cTemp << endl;

	cout << "ü������ : " << _pItem->iPotion << " ��" << endl;
	cout << "�������� : " << _pItem->iManaPotion << " ��" << endl;
}
void TextRpg_Hunt(INFO* _pPlayer, ITEM* _pItem)
{
	int iInput(0);
	INFO* tMonster = new INFO;

	while (true)
	{
		Print_Char(_pPlayer);
		cout << "1. �ʱ�\t2. �߱�\t3. ���\t4. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			tMonster = Create_Object("�ʱ�", 30 * iInput, 10 * iInput,3 * iInput);
			TextRpg_Fight(_pPlayer, _pItem, tMonster);
			break;
		case 2:
			tMonster = Create_Object("�߱�", 30 * iInput, 10 * iInput, 3 * iInput);
			TextRpg_Fight(_pPlayer, _pItem, tMonster);
			break;
		case 3:
			tMonster = Create_Object("���", 30 * iInput, 10 * iInput, 3 * iInput);
			TextRpg_Fight(_pPlayer, _pItem, tMonster);
			break;
		case 4:
			if (tMonster != nullptr) // ���� 1. ���µ� ������� �ؼ� �׷��ǰ�?
			{
				cout << tMonster << endl;
				system("pause");
				/*delete tMonster;
				tMonster = nullptr;*/
			}
			return;
		default:
			cout << "�߸� �Է��߽��ϴ�." << endl;
			break;
		}
	}
}
void TextRpg_Market(INFO* _pPlayer, ITEM* _pItem)
{
	int iInput(0);
	while (true)
	{
		Print_Char(_pPlayer);
		Print_Item(_pItem);
		cout << "1. ���\t2. ����\t3. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			TextRpg_Market_Equip(_pPlayer, _pItem);
			break;
		case 2:
			TextRpg_Market_Consumable(_pPlayer, _pItem);
			break;
		case 3:
			return;
		default:
			cout << "�߸� �Է��߽��ϴ�." << endl;
			break;
		}
	}
}
void TextRpg_Market_Equip(INFO* _pPlayer, ITEM* _pItem)
{
	int iInput(0);
	while (true)
	{
		Print_Char(_pPlayer);
		Print_Item(_pItem);
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
			if (!_pItem->bMain_Item)
			{
				cout << "����� ���ſϷ�!" << endl;
				_pItem->bMain_Item = true;
				_pPlayer->iAttack += 10; //�׳� ������ ��
			}
			else
			{
				cout << "�̹� ��������" << endl;
			}
			system("pause");
			break;
		case 2:
			if (!_pItem->bSub_Item)
			{
				cout << "������� ���ſϷ�!" << endl;
				_pItem->bSub_Item = true;
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
void TextRpg_Market_Consumable(INFO* _pPlayer, ITEM* _pItem)
{
	int iInput(0);
	while (true)
	{
		Print_Char(_pPlayer);
		Print_Item(_pItem);
		cout << "1. ü������\t2. ��������\t3. ���ư���" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			_pItem->iPotion += 1;
			cout << "ü������ ���ſϷ�!" << endl;
			cout << "���� ���Ǽ� : " << _pItem->iPotion << " ��" << endl;
			system("pause");
			break;
		case 2:
			_pItem->iManaPotion += 1;
			cout << "�������� ���ſϷ�!" << endl;
			cout << "���� �������Ǽ� : " << _pItem->iManaPotion << " ��" << endl;
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
void TextRpg_Fight(INFO* _pPlayer, ITEM* _pItem, INFO* _pMonster)
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
			TextRpg_Skill(_pPlayer, _pItem, _pMonster);
			break;
		case 3:
			TextRpg_Tool(_pPlayer, _pItem);
			break;
		case 4:
			delete _pMonster;
			_pMonster = nullptr;
			cout << _pMonster << endl;
			system("pause");
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
			cout << _pMonster << endl;
			system("pause");
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
			cout << _pMonster << endl;
			system("pause");
			return;
		}
	}
}
INFO* Create_Object(const char* _pName, int _iHealth, int _iMana, int _iAttack)
{
	INFO* pTemp = new INFO;
	strcpy_s(pTemp->szName, sizeof(INFO), _pName);
	pTemp->iHealth = _iHealth;
	pTemp->iMana = _iMana;
	pTemp->iAttack = _iAttack;
	return pTemp;
}
void Print_Monster(INFO* _pMonster)
{
	cout << "\n+++++++++++++\n���� : " << _pMonster->szName << "\nü�� : " << _pMonster->iHealth << "\n���� : " << _pMonster->iMana << "\t  ���ݷ� : " << _pMonster->iAttack << endl;
}
void Print_Item(ITEM* _pItem)
{
	char cTemp[32] = {};
	if (_pItem->bMain_Item)
		strcpy_s(cTemp, sizeof(cTemp), "������");
	else
		strcpy_s(cTemp, sizeof(cTemp), "����");
	cout << "����� : " << cTemp << endl;

	if (_pItem->bSub_Item)
		strcpy_s(cTemp, sizeof(cTemp), "������");
	else
		strcpy_s(cTemp, sizeof(cTemp), "����");
	cout << "������� : " << cTemp << endl;

	cout << "ü������ : " << _pItem->iPotion << " ��" << endl;
	cout << "�������� : " << _pItem->iManaPotion << " ��" << endl;
}
void TextRpg_Skill(INFO* _pPlayer, ITEM* _pItem, INFO* _pMonster)
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
void TextRpg_Tool(INFO* _pPlayer, ITEM* _pItem)
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
			if (1 <= _pItem->iPotion)
			{
				cout << "���� ���!" << endl;
				_pItem->iPotion -= 1;
				_pPlayer->iHealth += 15;
				if (!strcmp(_pPlayer->szName, "����")) // �̰� �����ϴ� �� ���� ���� �� �� �ֵ��� �����غ���
				{
					if (_pItem->bSub_Item)
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
					if (_pItem->bSub_Item)
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
					if (_pItem->bSub_Item)
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
			if (1 <= _pItem->iManaPotion)
			{
				cout << "�������� ���!" << endl;
				_pItem->iManaPotion -= 1;
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