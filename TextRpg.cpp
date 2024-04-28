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

typedef struct tInfo // 아마 소지금 및 보상도 계획해야할듯
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

#pragma region 함수선언부

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

#pragma region 함수정의부

void TextRpg_Menu()
{
	int iInput(0);
	INFO* tPlayer = nullptr;

	cout << "직업을 선택하시오.(1. 전사 , 2. 마법사 , 3. 도적) :" << endl;
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
		cout << "잘못 입력했습니다." << endl;
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
		Create_Object(&tTemp, "전사", 100, 20, 10);
		break;
	case 2:
		Create_Object(&tTemp, "마법사", 50, 100,20);
		break;
	case 3:
		Create_Object(&tTemp, "도적", 75, 50,15);
		break;
	}
	return tTemp;
}

void Print_Char(INFO* _pPlayer)
{
	system("cls");
	cout << "================\n직업 : " << _pPlayer->szName << "\n체력 : " << _pPlayer->iHealth << "\n마나 : " << _pPlayer->iMana << "\t  공격력 : " << _pPlayer->iAttack << endl;
}

void TextRpg_Home(INFO* _pPlayer)
{
	int iInput(0);
	ITEM* tItem = nullptr;
	tItem = Item_Start();
	while (true)
	{
		Print_Char(_pPlayer);
		cout << "1. 사냥터    2. 상점    3. 상태창    4. 게임종료" << endl;
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
			if (tItem != nullptr)
			{
				delete tItem;
				tItem = nullptr;
			}
			return;
		default:
			cout << "잘못 입력했습니다." << endl;
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
		strcpy_s(cTemp, sizeof(cTemp), "착용중");
	else
		strcpy_s(cTemp, sizeof(cTemp), "없음");
	cout << "주장비 : " << cTemp << endl;

	if (_tItem->bSub_Item)
		strcpy_s(cTemp, sizeof(cTemp), "착용중");
	else
		strcpy_s(cTemp, sizeof(cTemp), "없음");
	cout << "보조장비 : " << cTemp << endl;

	cout << "체력포션 : " << _tItem->iPotion << " 개" << endl;
	cout << "마나포션 : " << _tItem->iManaPotion << " 개" << endl;
}
void TextRpg_Hunt(INFO* _pPlayer, ITEM* _tItem)
{
	int iInput(0);
	INFO* tMonster = nullptr;
	while (true)
	{
		Print_Char(_pPlayer);
		cout << "1. 초급\t2. 중급\t3. 고급\t4. 돌아가기" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Create_Object(&tMonster, "초급", 30 * iInput, 10 * iInput,3 * iInput);
			TextRpg_Fight(_pPlayer, _tItem, tMonster);
			break;
		case 2:
			Create_Object(&tMonster, "중급", 30 * iInput, 10 * iInput, 3 * iInput);
			TextRpg_Fight(_pPlayer, _tItem, tMonster);
			break;
		case 3:
			Create_Object(&tMonster, "고급", 30 * iInput, 10 * iInput, 3 * iInput);
			TextRpg_Fight(_pPlayer, _tItem, tMonster);
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

void TextRpg_Market(INFO* _pPlayer, ITEM* _tItem)
{
	int iInput(0);
	while (true)
	{
		Print_Char(_pPlayer);
		Print_Item(_tItem);
		cout << "1. 장비\t2. 도구\t3. 돌아가기" << endl;
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
			cout << "잘못 입력했습니다." << endl;
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
		if (!strcmp(_pPlayer->szName, "전사"))
		{
			cout << "1. 장검\t2. 방패\t3. 돌아가기" << endl;
		}
		else if (!strcmp(_pPlayer->szName, "마법사"))
		{
			cout << "1. 지팡이\t2. 마법책(마나증가)\t3. 돌아가기" << endl;
		}
		else//(!strcmp(_pPlayer->szName, "도적"))
		{
			cout << "1. 뾰족한 단검\t2. 작은 단검\t3. 돌아가기" << endl;
		}
		
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (!_tItem->bMain_Item)
			{
				cout << "주장비 구매완료!" << endl;
				_tItem->bMain_Item = true;
				_pPlayer->iAttack += 10; //그냥 구현만 함
			}
			else
			{
				cout << "이미 착용중임" << endl;
			}
			system("pause");
			break;
		case 2:
			if (!_tItem->bSub_Item)
			{
				cout << "보조장비 구매완료!" << endl;
				_tItem->bSub_Item = true;
				_pPlayer->iHealth += 50;//그냥 구현만 함
			}
			else
			{
				cout << "이미 착용중임" << endl;
			}
			system("pause");
			break;
		case 3:
			return;
		default:
			cout << "잘못 입력했습니다." << endl;
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
		cout << "1. 체력포션\t2. 마나포션\t3. 돌아가기" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			_tItem->iPotion += 1;
			cout << "체력포션 구매완료!" << endl;
			cout << "현재 포션수 : " << _tItem->iPotion << " 개" << endl;
			system("pause");
			break;
		case 2:
			_tItem->iManaPotion += 1;
			cout << "마나포션 구매완료!" << endl;
			cout << "현재 마나포션수 : " << _tItem->iManaPotion << " 개" << endl;
			system("pause");
			break;
		case 3:
			return;
		default:
			cout << "잘못 입력했습니다." << endl;
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
		cout << "1. 공격    2. 스킬    3. 도구    4. 도망" << endl;
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
			cout << "================\n직업 : " << _pPlayer->szName << "\n체력 : " << 0 << "\t  공격력 : " << _pPlayer->iAttack << endl;
			_pPlayer->iHealth = 100;
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
			Print_Char(_pPlayer);
			cout << "\n+++++++++++++\n괴물 : " << _pMonster->szName << "\n체력 : " << 0 << "\t  공격력 : " << _pMonster->iAttack << endl;
			cout << "승리" << endl;
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
	cout << "\n+++++++++++++\n괴물 : " << _pMonster->szName << "\n체력 : " << _pMonster->iHealth << "\n마나 : " << _pMonster->iMana << "\t  공격력 : " << _pMonster->iAttack << endl;
}
void Print_Item(ITEM* _tItem)
{
	char cTemp[32] = {};
	if (_tItem->bMain_Item)
		strcpy_s(cTemp, sizeof(cTemp), "착용중");
	else
		strcpy_s(cTemp, sizeof(cTemp), "없음");
	cout << "주장비 : " << cTemp << endl;

	if (_tItem->bSub_Item)
		strcpy_s(cTemp, sizeof(cTemp), "착용중");
	else
		strcpy_s(cTemp, sizeof(cTemp), "없음");
	cout << "보조장비 : " << cTemp << endl;

	cout << "체력포션 : " << _tItem->iPotion << " 개" << endl;
	cout << "마나포션 : " << _tItem->iManaPotion << " 개" << endl;
}

void TextRpg_Skill(INFO* _pPlayer, ITEM* _tItem, INFO* _pMonster)
{
	int iInput(0);
	cout << "\n=====SKILL=====\n" << "1. 기본 스킬(mana -5)\t\t2. 강한 스킬(mana -20)\t\t3. 돌아가기\n";
	while (true)
	{
		cout << "선택하시오." << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (5 <= _pPlayer->iMana)
			{
				cout << "기본 스킬 사용!" << endl;
				_pPlayer->iMana -= 5;
				_pPlayer->iHealth -= _pMonster->iAttack;
				_pMonster->iHealth -= (_pPlayer->iAttack + 5);
				system("pause");
				return;
			}
			cout << "마나 부족!" << endl;
			break;
		case 2:
			if (20 <= _pPlayer->iMana)
			{
				cout << "기본 스킬 사용!" << endl;
				_pPlayer->iMana -= 20;
				_pPlayer->iHealth -= _pMonster->iAttack;
				_pMonster->iHealth -= (_pPlayer->iAttack + 20);
				system("pause");
				return;
			}
			cout << "마나 부족!" << endl;
			break;
		case 3:
			return;
		default:
			cout << "잘못 입력했습니다." << endl;
			break;
		}
		system("pause");
	}
	
}
void TextRpg_Tool(INFO* _pPlayer, ITEM* _tItem)
{
	int iInput(0);
	cout << "\n=====TOOL=====\n" << "1. 체력포션(+15)\t\t2. 마나포션(+15)\t\t3. 돌아가기\n";
	while (true)
	{
		cout << "선택하시오." << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			if (1 <= _tItem->iPotion)
			{
				cout << "포션 사용!" << endl;
				_tItem->iPotion -= 1;
				_pPlayer->iHealth += 15;
				if (!strcmp(_pPlayer->szName, "전사")) // 이거 구분하는 법 좀더 쉽게 할 수 있도록 생각해보기
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
				else if (!strcmp(_pPlayer->szName, "마법사"))
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
				else//(!strcmp(_pPlayer->szName, "도적"))
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
			cout << "포션 갯수 부족!" << endl;
			break;
		case 2:
			if (1 <= _tItem->iManaPotion)
			{
				cout << "마나포션 사용!" << endl;
				_tItem->iManaPotion -= 1;
				_pPlayer->iMana += 15;
				if (!strcmp(_pPlayer->szName, "전사")) // 이거 구분하는 법 좀더 쉽게 할 수 있도록 생각해보기
				{
					if (20 < _pPlayer->iMana)
					{
						_pPlayer->iMana = 20;
					}
				}
				else if (!strcmp(_pPlayer->szName, "마법사"))
				{
					if (100 < _pPlayer->iMana)
					{
						_pPlayer->iMana = 100;
					}
				}
				else//(!strcmp(_pPlayer->szName, "도적"))
				{
					if (50 < _pPlayer->iMana)
					{
						_pPlayer->iMana = 50;
					}
				}
				system("pause");
				return;
			}
			cout << "마나포션 갯수 부족!" << endl;
			break;
		case 3:
			return;
		default:
			cout << "잘못 입력했습니다." << endl;
			break;
		}
		system("pause");
	}
}

#pragma endregion