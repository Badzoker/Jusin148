#include <iostream>
#include <time.h>
using namespace std;

void MultiplicationTable();
void Calculate_Multiply(int* _pFirstNumber, int* _pSecondNumber);
void DrinkMachine();
void PickingDrink(int& _pMoney,int* _pChoice);
int main()
{
	MultiplicationTable();
	//DrinkMachine();

#pragma region 구구단
	//while문을 이용하여 2~9단까지 출력
	/*int i(2), j(1);
	while (10 > i)
	{
		cout << "\n" << i << " 단 ------------" << endl;
		while (10 > j)
		{
			cout << i << " x " << j << " = " << i * j << endl;
			j++;
		}
		i++;
		j = 1;
	}
	cout << " 끝 ";*/

#pragma endregion 구구단

#pragma region 자판기게임
	//소지금을 입력 받고, 항상 보유잔액을 표시
	//메뉴는 콜라 100 사이다 200 환타 300 반환
	// 메뉴 구매시 'xx 구매 완료' 출력후 잔액변경
	// 소지금이 부족하면 '소지금이 부족합니다' 를 출력
	// 4번 '잔액은 xx원 입니다. ' 출력 후 종료

	/*int iMoney(0), iChoice(0);

	cout << "소지하실 금액을 입력해주세요" << endl;
	cin >> iMoney;
	
	while (4 != iChoice)
	{
		system("cls");
		cout << "현재 소지금은 : " << iMoney << "원입니다." << endl;
		cout << "메뉴는 1. 콜라 100원, 2. 사이다 200원, 3. 환타 300원, 4. 종료" << endl;

		cin >> iChoice;
		
		switch (iChoice)
		{
		case 1:
			if (100 <= iMoney)
			{
				iMoney -= 100;
				cout << "콜라를 구매했습니다. 남은 소지금은 : " << iMoney << "입니다." << endl;
			}
			else
			{
				cout << "소지금이 부족합니다" << endl;
			}
			break;
		case 2:
			if (200 <= iMoney)
			{
				iMoney -= 200;
				cout << "사이다를 구매했습니다. 남은 소지금은 : " << iMoney << "입니다." << endl;
			}
			else
			{
				cout << "소지금이 부족합니다" << endl;
			}
			break;
		case 3:
			if (300 <= iMoney)
			{
				iMoney -= 300;
				cout << "환타를 구매했습니다. 남은 소지금은 : " << iMoney << "입니다." << endl;
			}
			else
			{
				cout << "소지금이 부족합니다" << endl;
			}
			break;
		case 4:
			cout << "종료합니다" << endl;
			break;
		default:
			cout << "잘못된 입력입니다. 다시 입력해주세요";
			break;
		}
		system("pause");
	}*/


#pragma endregion 자판기게임

#pragma region 홀짝게임
	//난수로 숫자 만들고 1~10
	//맞출 숫자 일부러 화면에 출력
	//메뉴는 1.홀 2.짝 3.종료
	// 총 5라운드 종료하면 몇승 몇패
	/*int iRound(0), iTemp(0), iChoice(0), iWin(0), iLose(0);
	while (5 != iRound)
	{
		system("cls");
		srand(unsigned(time(NULL)));
		iTemp = (rand() % 10) + 1;
		cout << "맞출 숫자 : " << iTemp << endl;
		cout << "\t" << iRound + 1 << "라운드 입니다.\n" << "선택을 하시오 1. 홀   2. 짝   3. 종료" << endl;
		cin >> iChoice;
		if (0 < iChoice && 4 > iChoice)
		{
			if (3 == iChoice)
			{
				cout << "종료합니다." << endl;
				break;
			}
			else
			{
				if (iTemp % 2 == iChoice % 2)
				{
					iWin++;
				}
				else
				{
					iLose++;
				}
			}
		}
		else
		{
			cout << "잘못된 입력입니다." << endl;
			continue;
		}
		iRound++;
		system("pause");
	}
	cout << iWin << " 승" << "\t" << iLose << " 패" << endl;*/

#pragma endregion 홀짝게임

#pragma region 가위바위보 게임
	//난수를 사용하여 컴퓨터(0~2)가 낼 0.가위 1. 바위 2. 보 3. 종료
	//가위바위보 승패를 결정하고
	//총 5라운드 라운드 종료시 몇승 몇패 몇무 인지 출력
	/*int iRound(0), iTemp(0), iChoice(0), iWin(0), iLose(0), iNot(0);
	while (5 != iRound)
	{
		system("cls");
	  srand(unsigned(time(NULL)));
		iTemp = rand() % 3; // 컴 가위바위보 결정
		switch (iTemp)
		{
		case 0:
			cout << "컴퓨터는 가위입니다.\n";
			break;
		case 1:
			cout << "컴퓨터는 바위입니다.\n";
			break;
		case 2:
			cout << "컴퓨터는 보입니다.\n";
			break;
		default:
			cout << "오류\n";
			break;
		}

		cout << "\t" << iRound + 1 << "라운드 입니다.\n메뉴를 선택하세요.\t0. 가위\t1. 바위\t2. 보\t3. 종료" << endl;
		cin >> iChoice;
		if (1 > iChoice / 3)
		{
			if (1 == (iChoice - iTemp) || -2 == (iChoice - iTemp))
			{
				iWin++;
			}
			else if (0 == (iChoice - iTemp))
			{
				iNot++;
			}
			else
			{
				iLose++;
			}
		}
		else if (3 == iChoice)
		{
			break;
		}
		else
		{
			cout << "잘못 입력하셨습니다." << endl;
			continue;
		}
		system("pause");
		iRound++;
	}

	cout << iWin << " 승\t" << iNot << " 무\t" << iLose << " 패\t"  << "게임을 종료합니다." << endl;*/

	
#pragma endregion 가위바위보 게임
	return 0;
}

void MultiplicationTable()
{
	int iFirstNumber(0), iSecondNumber(0);
	int *pFirstNumber = &iFirstNumber, *pSecondNumber = &iSecondNumber;

	cout << "몇 단을 원하십니까? : ";
	cin >> *pFirstNumber;
	cout << "몇 곱을 원하십니까? : ";
	cin >> *pSecondNumber;

	Calculate_Multiply(pFirstNumber, pSecondNumber);
	cout << *pFirstNumber << " <-다른 곳에서 1만큼 더한 첫번째 입력한 수" << endl;
	cout << *pSecondNumber << " <-다른 곳에서 2만큼 더한 두번째 입력한 수" << endl;
}
void Calculate_Multiply(int* _pFirstNumber, int* _pSecondNumber)
{
	for (int i = 2; i < *_pFirstNumber + 1; i++)
	{
		cout << "------- " << i << "단 -------" << endl;
		for (int j = 1; j < *_pSecondNumber + 1; j++)
		{
			cout << i << " x " << j << " = " << i * j << endl;
		}
	}

	*_pFirstNumber += 1;
	*_pSecondNumber += 2;
}
void DrinkMachine()
{
	int iMoney(0), iChoice(0);
	int* pMoney = &iMoney, * pChoice = &iChoice;
	cout << "소지할 금액을 입력하시오 : " << endl;
	cin >> *pMoney;
	PickingDrink(iMoney, pChoice);
	cout << "종료됨" << endl;
}
void PickingDrink(int& _pMoney, int* _pChoice)
{
	
	while (100 < _pMoney)
	{
		system("cls");
		cout << "현재 금액 : " << _pMoney << "원" << endl;
		cout << "\t----메뉴판----\n 1. 콜라(100원),  2. 사이다(200원),  3. 환타(300원),  4. 종료" << endl;
		cin >> *_pChoice;
		if (4 == *_pChoice)
		{
			break;
		}
		else if (0 < *_pChoice && 4 > *_pChoice)
		{
			if (_pMoney < (*_pChoice * 100))
			{
				cout << "소지금액이 부족합니다." << endl;
				cout << "남은 금액 : " << _pMoney << endl;
			}
			else
			{
				_pMoney -= (*_pChoice * 100);
				cout << "남은 금액 : " << _pMoney << endl;
			}
			
		}
		else
		{
			cout << "잘못 입력했습니다." << endl;
		}
		system("pause");
	}
}
//