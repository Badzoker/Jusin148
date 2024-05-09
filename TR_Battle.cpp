#include "TR_Battle.h"

CBattle::CBattle()
{
}

CBattle::~CBattle()
{
}

void CBattle::Initialize()
{
	
}

void CBattle::Update()
{
}

void CBattle::Release()
{
}

void CBattle::Battle_Map(CPlayer* _pPlayer, CMonster* _pMonster)
{
	int iInput(0);
	while (true)
	{
		_pPlayer->Update();
		cout << "===============  v    s  ===============" << endl;
		_pMonster->Update();
		cout << "1. 공격    2. 스킬    3. 도구    4. 도망" << endl;
		cin >> iInput;
		switch (iInput)
		{
		case 1:
			Battle_Normal(_pPlayer, _pMonster);
			if (0 >= _pMonster->Get_Info()->iCurrentHp)
			{
				_pPlayer->Take_Reward(_pMonster->Reward());
				return;
			}
			else if (0 >= _pPlayer->Get_Info()->iCurrentHp)
			{
				_pPlayer->Respawn();
				return;
			}
			system("pause");
			break;
		case 2:
			Battle_Skill(_pPlayer, _pMonster);
			if (0 >= _pMonster->Get_Info()->iCurrentHp)
			{
				_pPlayer->Take_Reward(_pMonster->Reward());
				return;
			}
			else if (0 >= _pPlayer->Get_Info()->iCurrentHp)
			{
				_pPlayer->Respawn();
				return;
			}
			system("pause");
			break;
		case 3:
			_pPlayer->Using_Tools();
			system("pause");
			break;
		case 4:
			return;
		default:
			break;
		}
	}
}

void CBattle::Battle_Normal(CPlayer* _pPlayer, CMonster* _pMonster)
{

	_pMonster->Damaged(_pPlayer->Attack());
	if (0 >= _pMonster->Get_Info()->iCurrentHp)
		return;
	_pPlayer->Damaged(_pMonster->Attack());
	if (0 >= _pPlayer->Get_Info()->iCurrentHp)
		return;
}

void CBattle::Battle_Skill(CPlayer* _pPlayer, CMonster* _pMonster)
{
	if (0 != _pPlayer->Skill())
	{
		_pMonster->Damaged(_pPlayer->Skill());
		if (0 >= _pMonster->Get_Info()->iCurrentHp)
		{
			_pPlayer->Take_Reward(_pMonster->Reward());
			return;
		}
		_pPlayer->Damaged(_pMonster->Attack());
		if (0 >= _pPlayer->Get_Info()->iCurrentHp)
		{
			_pPlayer->Respawn();
			return;
		}
		system("pause");
	}
	else
	{
		cout << "mana less(Battle)" << endl;
	}
}

void CBattle::Battle_UsingTools(CPlayer* _pPlayer)
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
			if (1 <= _pPlayer->Get_Item()->iPotion)
			{
				cout << "포션 사용!" << endl;
				_pPlayer->Get_Item()->iPotion -= 1;
				_pPlayer->Get_Info()->iCurrentHp += 15;
				if (_pPlayer->Get_Info()->iMaxHp <= _pPlayer->Get_Info()->iCurrentHp)
				{
					_pPlayer->Get_Info()->iCurrentHp = _pPlayer->Get_Info()->iMaxHp;
				}
				system("pause");
				return;
			}
			cout << "포션 갯수 부족!" << endl;
			break;
		case 2:
			if (1 <= _pPlayer->Get_Item()->iManaPotion)
			{
				cout << "마나포션 사용!" << endl;
				_pPlayer->Get_Item()->iManaPotion -= 1;
				_pPlayer->Get_Info()->iCurrentMana += 15;
				if (_pPlayer->Get_Info()->iMaxMana <= _pPlayer->Get_Info()->iCurrentMana)
				{
					_pPlayer->Get_Info()->iCurrentMana = _pPlayer->Get_Info()->iMaxMana;
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
