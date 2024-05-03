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
	int iCurrentHp;
	int iMaxHp;
	int iCurrentMana;
	int iMaxMana;
	int iAttack;
	int iLevel;
	int iExp;
	int iMaxExp;
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

#pragma region 함수선언부

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
INFO* Create_Object(const char* _pName, int _iCurrentHp, int _iCurrentMana, int _iAttack);
void Print_Monster(INFO* _monster);
void TextRpg_Skill(INFO* _pPlayer, ITEM* _pItem, INFO* _pMonster);
void TextRpg_Tool(INFO* _pPlayer, ITEM* _pItem);
void Print_Item(ITEM* _pItem);
void LevelUp(INFO* _pPlayer);

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
	ITEM* tItem = nullptr; // 동적할당 2번
	FILE* pFileJob = NULL;
	FILE* pFileItem = NULL;
	errno_t errReadJob = 0;
	errno_t errReadItem = 0;
	cout << "직업을 선택하시오.(1. 전사 , 2. 마법사 , 3. 도적 , 4. 불러오기) :" << endl;
	cin >> iInput;
	switch (iInput)
	{
	case WARRIOR:
		tPlayer = Choose_Char(iInput);
		tItem = Item_Start();
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
		errReadJob = fopen_s(&pFileJob, "./Data/Info/Job.txt", "rb");
		errReadItem = fopen_s(&pFileItem, "./Data/Info/Item.txt", "rb");
		if (0 == errReadJob && 0 == errReadItem)
		{
			tPlayer = new INFO;
			tItem = new ITEM;
			fread(tPlayer, sizeof(INFO), 1, pFileJob);
			fread(tItem, sizeof(ITEM), 1, pFileItem);
			fclose(pFileJob);
			fclose(pFileItem);
		}
		else
		{
			cout << "불러오기 에러" << endl;
		}
		system("pause");
		break;
	default:
		cout << "잘못 입력했습니다." << endl;
		break;
	}
	TextRpg_Home(tPlayer, tItem);
	if (tPlayer != nullptr)
	{
		delete tPlayer; //heap 반환 1번
		tPlayer = nullptr;
	}
	if (tItem != nullptr) //heap 반환 2번
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
		tTemp = Create_Object("전사", 100, 20, 10);
		
		break;
	case 2:
		tTemp = Create_Object("마법사", 50, 100, 20);
		break;
	case 3:
		tTemp = Create_Object("도적", 75, 50, 15);
		break;
	}
	return tTemp;
}
void Print_Char(INFO* _pPlayer)
{
	system("cls");
	cout << "================\n직업 : " << _pPlayer->szName << endl;
	cout << "체력 : " << _pPlayer->iCurrentHp << " / " << _pPlayer->iMaxHp << endl;
	cout << "마나 : " << _pPlayer->iCurrentMana << " / " << _pPlayer->iMaxMana << "\t  공격력 : " << _pPlayer->iAttack << endl;
	cout << "경험치 : " << _pPlayer->iExp << " / " << _pPlayer->iMaxExp << endl;
	cout << "레벨 : " << _pPlayer->iLevel << endl;
}

void TextRpg_Home(INFO* _pPlayer, ITEM* _pItem)
{
	int iInput(0), iTemp(0);
	
	FILE* pFileJob = NULL;
	FILE* pFileItem = NULL;
	errno_t errWriteJob = 0;
	errno_t errWriteItem = 0; 
	char cTemp[32] = {};
	while (true)
	{
		Print_Char(_pPlayer);
		cout << "1. 사냥터    2. 상점    3. 상태창    4. 게임저장 후 종료    5. 종료" << endl;
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
			errWriteJob = fopen_s(&pFileJob, "./Data/Info/Job.txt", "wb");
			errWriteItem = fopen_s(&pFileItem, "./Data/Info/Item.txt", "wb");
			if (0 == errWriteJob && 0 == errWriteItem)
			{
				cout << "job저장됨" << endl;
				fwrite(_pPlayer, sizeof(INFO), 1, pFileJob);
				fwrite(_pItem, sizeof(ITEM), 1, pFileItem);
				fclose(pFileJob);
				fclose(pFileItem);
			}
			else
			{
				cout << "job게임저장에러" << endl;
			}
			cout << "게임저장후 종료" << endl;
			system("pause");
			return;
		case 5:
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
void Check_Stat(ITEM* _pItem)
{
	char cTemp[32] = {};
	if (_pItem->bMain_Item)
		strcpy_s(cTemp, sizeof(cTemp), "착용중");
	else
		strcpy_s(cTemp, sizeof(cTemp), "없음");
	cout << "주장비 : " << cTemp << endl;

	if (_pItem->bSub_Item)
		strcpy_s(cTemp, sizeof(cTemp), "착용중");
	else
		strcpy_s(cTemp, sizeof(cTemp), "없음");
	cout << "보조장비 : " << cTemp << endl;

	cout << "체력포션 : " << _pItem->iPotion << " 개" << endl;
	cout << "마나포션 : " << _pItem->iManaPotion << " 개" << endl;
}
void TextRpg_Hunt(INFO* _pPlayer, ITEM* _pItem)
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
			tMonster = Create_Object("초급", 30 * iInput, 10 * iInput,3 * iInput);
			tMonster->iExp = tMonster->iMaxHp;
			TextRpg_Fight(_pPlayer, _pItem, tMonster);
			break;
		case 2:
			tMonster = Create_Object("중급", 30 * iInput, 10 * iInput, 3 * iInput);
			tMonster->iExp = tMonster->iMaxHp;
			TextRpg_Fight(_pPlayer, _pItem, tMonster);
			break;
		case 3:
			tMonster = Create_Object("고급", 30 * iInput, 10 * iInput, 3 * iInput);
			tMonster->iExp = tMonster->iMaxHp;
			TextRpg_Fight(_pPlayer, _pItem, tMonster);
			break;
		case 4:
			if (tMonster != nullptr) // 질문 1. 없는데 지우려고 해서 그런건가?
			{
				cout << tMonster << endl;
				system("pause");
				/*delete tMonster;
				tMonster = nullptr;*/
			}
			return;
		default:
			cout << "잘못 입력했습니다." << endl;
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
		cout << "1. 장비\t2. 도구\t3. 돌아가기" << endl;
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
			cout << "잘못 입력했습니다." << endl;
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
			if (!_pItem->bMain_Item)
			{
				cout << "주장비 구매완료!" << endl;
				_pItem->bMain_Item = true;
				_pPlayer->iAttack += 10; //그냥 구현만 함
			}
			else
			{
				cout << "이미 착용중임" << endl;
			}
			system("pause");
			break;
		case 2:
			if (!_pItem->bSub_Item)
			{
				cout << "보조장비 구매완료!" << endl;
				_pItem->bSub_Item = true;
				_pPlayer->iMaxHp += 50;//그냥 구현만 함
				_pPlayer->iCurrentHp += 50;
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
void TextRpg_Market_Consumable(INFO* _pPlayer, ITEM* _pItem)
{
	int iInput(0);
	while (true)
	{
		Print_Char(_pPlayer);
		Print_Item(_pItem);
		cout << "1. 체력포션\t2. 마나포션\t3. 돌아가기" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			_pItem->iPotion += 1;
			cout << "체력포션 구매완료!" << endl;
			cout << "현재 포션수 : " << _pItem->iPotion << " 개" << endl;
			system("pause");
			break;
		case 2:
			_pItem->iManaPotion += 1;
			cout << "마나포션 구매완료!" << endl;
			cout << "현재 마나포션수 : " << _pItem->iManaPotion << " 개" << endl;
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
void TextRpg_Fight(INFO* _pPlayer, ITEM* _pItem, INFO* _pMonster)
{
	int iInput(0), iTemp(0);
	while (true)
	{
		Print_Char(_pPlayer);
		Print_Monster(_pMonster);
		cout << "1. 공격    2. 스킬    3. 도구    4. 도망" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			_pPlayer->iCurrentHp -= _pMonster->iAttack;
			_pMonster->iCurrentHp -= _pPlayer->iAttack;
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
		if (0 >= _pPlayer->iCurrentHp)
		{
			system("cls");
			cout << "================\n직업 : " << _pPlayer->szName << "\n체력 : " << 0 << "\t  공격력 : " << _pPlayer->iAttack << endl;
			_pPlayer->iCurrentHp = _pPlayer->iMaxHp;
			
			Print_Monster(_pMonster);
			cout << "죽음" << endl;
			system("pause");
			delete _pMonster;
			_pMonster = nullptr;
			cout << _pMonster << endl;
			system("pause");
			return;
		}
		else if (0 >= _pMonster->iCurrentHp)
		{
			system("cls");
			Print_Char(_pPlayer);
			cout << "\n+++++++++++++\n괴물 : " << _pMonster->szName << "\n체력 : " << 0 << "\t  공격력 : " << _pMonster->iAttack << endl;
			_pPlayer->iExp += _pMonster->iExp;
			cout << "승리" << endl;
			if (_pPlayer->iExp >= _pPlayer->iMaxExp)
			{
				iTemp = (_pPlayer->iExp) - (_pPlayer->iMaxExp);
				LevelUp(_pPlayer);
				_pPlayer->iExp = iTemp;
			}
			system("pause");
			delete _pMonster;
			_pMonster = nullptr;
			cout << _pMonster << endl;
			system("pause");
			return;
		}
	}
}
INFO* Create_Object(const char* _pName, int _iMaxHp, int _iMaxMana, int _iAttack)
{
	INFO* pTemp = new INFO;
	strcpy_s(pTemp->szName, sizeof(INFO), _pName);
	pTemp->iMaxHp = _iMaxHp;
	pTemp->iCurrentHp = pTemp->iMaxHp;
	pTemp->iMaxMana = _iMaxMana;
	pTemp->iCurrentMana = _iMaxMana;
	pTemp->iAttack = _iAttack;
	pTemp->iLevel = 1;
	pTemp->iMaxExp = 100;
	pTemp->iExp = 0;
	return pTemp;
}
void Print_Monster(INFO* _pMonster)
{
	cout << "\n+++++++++++++\n괴물 : " << _pMonster->szName << "\n체력 : " << _pMonster->iCurrentHp << "\n마나 : " << _pMonster->iCurrentMana << "\t  공격력 : " << _pMonster->iAttack << endl;
}
void Print_Item(ITEM* _pItem)
{
	char cTemp[32] = {};
	if (_pItem->bMain_Item)
		strcpy_s(cTemp, sizeof(cTemp), "착용중");
	else
		strcpy_s(cTemp, sizeof(cTemp), "없음");
	cout << "주장비 : " << cTemp << endl;

	if (_pItem->bSub_Item)
		strcpy_s(cTemp, sizeof(cTemp), "착용중");
	else
		strcpy_s(cTemp, sizeof(cTemp), "없음");
	cout << "보조장비 : " << cTemp << endl;

	cout << "체력포션 : " << _pItem->iPotion << " 개" << endl;
	cout << "마나포션 : " << _pItem->iManaPotion << " 개" << endl;
}
void TextRpg_Skill(INFO* _pPlayer, ITEM* _pItem, INFO* _pMonster)
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
			if (5 <= _pPlayer->iCurrentMana)
			{
				cout << "기본 스킬 사용!" << endl;
				_pPlayer->iCurrentMana -= 5;
				_pPlayer->iCurrentHp -= _pMonster->iAttack;
				_pMonster->iCurrentHp -= (_pPlayer->iAttack + 5);
				system("pause");
				return;
			}
			cout << "마나 부족!" << endl;
			break;
		case 2:
			if (20 <= _pPlayer->iCurrentMana)
			{
				cout << "기본 스킬 사용!" << endl;
				_pPlayer->iCurrentMana -= 20;
				_pPlayer->iCurrentHp -= _pMonster->iAttack;
				_pMonster->iCurrentHp -= (_pPlayer->iAttack + 20);
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
void TextRpg_Tool(INFO* _pPlayer, ITEM* _pItem)
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
			if (1 <= _pItem->iPotion)
			{
				cout << "포션 사용!" << endl;
				_pItem->iPotion -= 1;
				_pPlayer->iCurrentHp += 15;
				if (_pPlayer->iMaxHp <= _pPlayer->iCurrentHp)
				{
					_pPlayer->iCurrentHp = _pPlayer->iMaxHp;
				}
				//if (!strcmp(_pPlayer->szName, "전사")) // 이거 구분하는 법 좀더 쉽게 할 수 있도록 생각해보기
				//{
				//	if (_pItem->bSub_Item)
				//	{
				//		if (150 < _pPlayer->iCurrentHp)
				//		{
				//			_pPlayer->iCurrentHp = 150;
				//		}
				//	}
				//	else
				//	{
				//		if (_pPlayer->iMaxHp <= _pPlayer->iCurrentHp)
				//		{
				//			_pPlayer->iCurrentHp = _pPlayer->iMaxHp;
				//		}
				//	}
				//}
				//else if (!strcmp(_pPlayer->szName, "마법사"))
				//{
				//	if (_pItem->bSub_Item)
				//	{
				//		if (100 < _pPlayer->iCurrentHp)
				//		{
				//			_pPlayer->iCurrentHp = 100;
				//		}
				//	}
				//	else
				//	{
				//		if (50 < _pPlayer->iCurrentHp)
				//		{
				//			_pPlayer->iCurrentHp = 50;
				//		}
				//	}
				//}
				//else//(!strcmp(_pPlayer->szName, "도적"))
				//{
				//	if (_pItem->bSub_Item)
				//	{
				//		if (125 < _pPlayer->iCurrentHp)
				//		{
				//			_pPlayer->iCurrentHp = 125;
				//		}
				//	}
				//	else
				//	{
				//		if (75 < _pPlayer->iCurrentHp)
				//		{
				//			_pPlayer->iCurrentHp = 75;
				//		}
				//	}
				//	
				//}
				system("pause");
				return;
			}
			cout << "포션 갯수 부족!" << endl;
			break;
		case 2:
			if (1 <= _pItem->iManaPotion)
			{
				cout << "마나포션 사용!" << endl;
				_pItem->iManaPotion -= 1;
				_pPlayer->iCurrentMana += 15;
				if (_pPlayer->iMaxMana <= _pPlayer->iCurrentMana)
				{
					_pPlayer->iCurrentMana = _pPlayer->iMaxMana;
				}
				//if (!strcmp(_pPlayer->szName, "전사")) // 이거 구분하는 법 좀더 쉽게 할 수 있도록 생각해보기
				//{
				//	if (_pPlayer->iMaxMana <= _pPlayer->iCurrentMana)
				//	{
				//		_pPlayer->iCurrentMana = _pPlayer->iMaxMana;
				//	}
				//}
				//else if (!strcmp(_pPlayer->szName, "마법사"))
				//{
				//	if (100 < _pPlayer->iMana)
				//	{
				//		_pPlayer->iMana = 100;
				//	}
				//}
				//else//(!strcmp(_pPlayer->szName, "도적"))
				//{
				//	if (50 < _pPlayer->iMana)
				//	{
				//		_pPlayer->iMana = 50;
				//	}
				//}
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

void LevelUp(INFO* _pPlayer)
{
	cout << "레벨 업!" << endl;
	_pPlayer->iLevel += 1;
	_pPlayer->iAttack += 10;
	_pPlayer->iMaxExp += 50;
	_pPlayer->iExp = 0;
	_pPlayer->iMaxHp += 30;
	_pPlayer->iMaxMana += 20;
	_pPlayer->iCurrentHp = _pPlayer->iMaxHp;
	_pPlayer->iCurrentMana = _pPlayer->iMaxMana;
}

#pragma endregion