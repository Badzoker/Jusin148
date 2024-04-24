#include <iostream> 
#include <ctime>

using namespace std;

#pragma region 자판기게임함수화


void Menu(int _Money);
void Choice(int _Choice);
int Cal(int _Money, int _Choice);
void Remain(int _Money);
void TheEnd();

int main()
{
	
#pragma region 난수만들기
	/*srand(unsigned(time(NULL)));

	for (int j = 0; j < 25; j++)
	{
		int iTemp = rand() % 10 + 1;
		cout << iTemp << "\n";
	}*/
#pragma endregion 난수만들기

	//과제 -> 최대한 많은 함수를 만들어봐라
	int iMoney(0), iChoice(0);
	cout << "금액을 입력하시오 : \n";
	cin >> iMoney;

	while (iMoney > 0)
	{
		Menu(iMoney);
		cin >> iChoice;
		if (4 == iChoice)
		{
			break;
		}
		else if (4 < iChoice || 1 > iChoice)
		{
			continue;
		}
		iMoney = Cal(iMoney, iChoice);
		Remain(iMoney);
	}
	TheEnd();

	return 0;
}

void Menu(int _Money)
{
	system("cls");
	cout << "현재 금액 : " << _Money << " 원 \n";
	cout << "메뉴 : 1. 콜라(100원)  2.사이다(200원)  3.환타(300원)  4.종료\n";
}
void Choice(int _Choice)
{
	if (4 < _Choice || 1 > _Choice)
	{
		cout << "잘못 입력하셨습니다.\n";
	}
	else
	{
		cout << _Choice << "번을 입력하셨습니다.\n";
	}
}
int Cal(int _Money, int _Choice)
{
	if (_Money < _Choice * 100)
	{
		cout << "소지금이 부족합니다.\n";
		return _Money;
	}
	else
	{
		return _Money - (_Choice * 100);
	}
}

void Remain(int _Money)
{
	cout << "지금 금액은 " << _Money << " 원 남았습니다.\n";
	system("pause");

}

void TheEnd()
{
	cout << "끝\n";
}
#pragma endregion 자판기게임함수화
