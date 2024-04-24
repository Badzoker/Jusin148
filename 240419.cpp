#include <iostream>
#include <ctime>

using namespace std;

void Swap(int* a, int* b);
void Test();
void Test(int* a[]);
bool Check_Same(int _iNumber1, int _iNumber2);
void HW1();
void HW2();
void HW2_Lotto(int* _pCount, int _iArray[], int _iLotto[]);
void HW3();
void HW3_Game(int _iArray[]);
void HW3_Play(int _iArray[], int _iArray2[], int* _pStrike, int* _pWrong);
void HW4();
void HW4_Multi(int* _pArray[]);
void HW4_PlayerBingo(int* _pArray[]);
void HW4_ComputerBingo(int* _pArray[]);

int main()
{
	srand(unsigned(time(NULL)));

	//HW1();
	//HW2();
	//HW3();
	//HW4();
	return 0;
}
void Test()
{
	int iArray_A[10], iArray_B[10], iArray_C[10], iArray_D[10];
	for (int i = 0; i < 10; i++)
	{
		iArray_A[i] = i + 1;
	}
	for (int i = 0; i < 10; i++)
	{
		iArray_B[i] = i + 11;
	}
	for (int i = 0; i < 10; i++)
	{
		iArray_C[i] = i + 21;
	}
	for (int i = 0; i < 10; i++)
	{
		iArray_D[i] = i + 31;
	}
	int* pArray_A[4] = { iArray_A,iArray_B, iArray_C, iArray_D };
	cout << iArray_A[0] << endl;
	cout << iArray_B[1] << endl;
	cout << iArray_C[2] << endl;
	cout << iArray_D[3] << endl;
	cout << "--------" << endl;
	Test(pArray_A);
}
void Test(int* a[])
{
	cout << *a[0] << endl;
	cout << *(a[1]+1) << endl;
	cout << *(a[2]+2) << endl;
	cout << *(a[3]+3) << endl;
}

bool Check_Same(int _iNumber1, int _iNumber2)
{
	if (_iNumber1 == _iNumber2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Swap(int* a, int* b)
{
	int iTemp(0);
	iTemp = *a;
	*a = *b;
	*b = iTemp;
}

#pragma region HW 1

// 1. 이중for문과 배열을 이용하여 다음과 같이 출력해오기
// 1~25까지 5x5 행렬

void HW1()
{
	int iArray[25] = {};
	//int* pArray = iArray;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			iArray[(i * 5) + j] = i * 5 + (j + 1);
			cout << iArray[(i * 5) + j] << "\t";
		}
		cout << endl;
	}
}

#pragma endregion

#pragma region HW 2

// 2. 로또 만들기
// 배열을 이용하여 1~45사이의 숫자중 6개를 선정하여 5회 출력하기
// 같은 회차에서는 중복되는 숫자가 발생 할 수 없음
// 출력 시, 버블 정렬을 이용하여 오름차순 정렬을 할 것(전공자만)

void HW2()
{
	int iArray[45] = {}, iLotto[6] = {}, iCount(0);
	HW2_Lotto(&iCount, iArray, iLotto);
}

void HW2_Lotto(int* _pCount, int _iArray[], int _iLotto[])
{
	cout << *_pCount + 1 << "회차 로또" << endl;
	for (int i = 0; i < 45; i++) // 단순 작업(순서대로 넣기)
	{
		_iArray[0] = i + 1;
	}
	for (int i = 0; i < 6; i++) // 난수 6개 로또 번호에 순서대로 넣기
	{
		int iRandom = rand() % 45 + 1;
		_iLotto[i] = iRandom;
		for (int j = 0; j < i; j++)
		{
			if (_iLotto[j] == iRandom)
			{
				i--;
				break;
			}
			if (_iLotto[j] > _iLotto[i])
			{
				Swap(&_iLotto[j], &_iLotto[i]); //정렬했는데 버블정렬인지는 확인
			}
		}
	}
	for (int i = 0; i < 6; i++)
	{
		cout << _iLotto[i] << "\t";
		_iLotto[i] = NULL;
	}
	cout << endl;
	if (*_pCount < 5)
	{
		*_pCount += 1;
		//HW2();
		HW2_Lotto(_pCount, _iArray, _iLotto);
	}
}

#pragma endregion

#pragma region HW 3

// 3. 야구 게임 만들기
// 1~9까지의 숫자 중 무작위로 세 개를 발생시킴 (정렬x)
// 플레이어가 숫자를 세 개 입력 받아 위치와 값 모두 일치할 경우 스트라이크
// 값만 일치할 경우 볼 증가
// 매 회 몇 스트라이크 몇 볼 인지 출력
// 3 스트라이크 일 경우 승리 출력 후, 게임 종료
// 9회차 일 때까지 3스트라이크를 완성하지 못하면 패배 출력 후, 종료

void HW3()
{
	int iArray[3] = {};
	for (int i = 0; i < 3; i++)
	{
		int iRandom = rand() % 9 + 1;
		for (int j = 0; j < i; j++)
		{
			if (Check_Same(iRandom, iArray[j]))
			{
				cout << iRandom<<" <- 겹치는 게 있음\n";
				i = 0;
				continue;
			}
		}
		iArray[i] = iRandom;
	}
	HW3_Game(iArray);
}

void HW3_Game(int _iArray[])
{
	int iArray[3],iStrike(0),iWin(0),iWrong(0);
	int* pStrike = &iStrike, *pWrong = &iWrong;
	cout << "게임 시작\n";
	cout << _iArray[0] << "\t" << _iArray[1] << "\t" << _iArray[2] << "\n";
	for (int i = 0; i < 9; i++)
	{
		cout << i + 1 << "회차 진행합니다.\n";
		HW3_Play(iArray, _iArray, pStrike, pWrong);
		if (0 < iWrong)
		{
			i--;
			iWrong = 0;
		}
		else if (2 < iStrike)
		{
			iWin++;
			break;
		}
		iStrike = 0;
	}
	if (0 < iWin )
	{
		cout << "승리";
	}
	else
	{
		cout << "패배";
	}
}

void HW3_Play(int _iArray[], int _iArray2[], int* _pStrike, int* _pWrong)
{
	int iBall(0);
	cout << "1번 공 : ";
	cin >> _iArray[0];
	cout << "2번 공 : ";
	cin >> _iArray[1];
	cout << "3번 공 : ";
	cin >> _iArray[2];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (Check_Same(_iArray[i],_iArray[j]))
			{
				cout << "잘못 입력하셨습니다." << endl;
				*_pWrong += 1;
			}
		}
	}
	if (1 > *_pWrong)
	{
		cout << _iArray[0] << "\t" << _iArray[1] << "\t" << _iArray[2] << "\n";
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j && _iArray[i] == _iArray2[j])
				{
					*_pStrike += 1;
				}
				else if (_iArray[i] == _iArray2[j])
				{
					iBall++;
				}
			}
		}
		cout << *_pStrike << "strike\t" << iBall << "ball\n";
		iBall = 0;
	}
}

#pragma endregion

#pragma region HW 4

// 4. 빙고 게임 만들기
// 1~25까지 5x5 행렬
// 숫자를 입력하여 일치하는 숫자인 경우 * 로 출력
// 가로 세로 대각선 방향으로 *이 다섯개가 만들어질 경우 빙고 1이 증가
// 5 빙고 이상이면 승리로 게임 종료
// 대전 형식으로 구현

void HW4()
{
	int iArray_Player[25] = {}, iArray_Computer[25] = {}, iArray_RandomChoice[25] = {}, iArray_Number[5] = {}, iArray_Bingo[12] = {}, iArray_ComBingo[12] = {}; // Number = Random, Choice, ChoiceCount, Player_Bingo, Computer_Bingo, 
	int* pArray[6] = { iArray_Player, iArray_Computer, iArray_RandomChoice, iArray_Number, iArray_Bingo, iArray_ComBingo}; // 포인터 배열(이중 포인터?)
	//필요한 변수 최대한 배열안에 위치 후 포인터 배열을 통해 매개변수 하나로 모두 통제하는 연습
	for (int i = 0; i < size(iArray_Player); i++) //플레이어 빙고판 순서
	{
		iArray_Player[i] = i + 1;
	}
	for (int i = 0; i < size(iArray_Computer); i++) // 컴퓨터 빙고판 난수
	{
		iArray_Number[0] = rand() % 25 + 1;
		iArray_Computer[i] = iArray_Number[0];
		for (int j = 0; j < i; j++)
		{
			if (iArray_Computer[j] == iArray_Number[0])
			{
				i--;
				break;
			}
		}
	}
	for (int i = 0; i < size(iArray_RandomChoice); i++) // 컴퓨터 고를 수 난수
	{
		iArray_Number[0] = rand() % 25 + 1;
		iArray_RandomChoice[i] = iArray_Number[0];
		for (int j = 0; j < i; j++)
		{
			if (iArray_RandomChoice[j] == iArray_Number[0])
			{
				i--;
				break;
			}
		}
	}
	cout << "게임 시작" << endl;
	HW4_Multi(pArray);
}
void HW4_Multi(int* _pArray[]) // p[] -> player, computer, randomchoice, 숫자모음(random, choice, choicecount(computer전용), player_bingo, computer_bingo)
{
	system("cls");
	cout << "        ======player======                                     ======computer======\n";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) // 플레이어 빙고판 찍기(별 포함)
		{
			if (50 == *(_pArray[0] + ((5 * i) + j)))
			{
				cout << "*\t";
			}
			else
			{
				cout << *(_pArray[0] + ((5 * i) + j)) << "\t";
			}
		}
		cout << "\t\t";
		for (int j = 0; j < 5; j++) // 컴퓨터 빙고판 찍기(별 포함)
		{
			if (50 == *(_pArray[1] + ((5 * i) + j)))
			{
				cout << "*\t";
			}
			else
			{
				cout << *(_pArray[1] + ((5 * i) + j)) << "\t";
			}
		}
		cout << endl;
	}
	cout << "플레이어 빙고 : " << *(_pArray[3] + 3) << endl;
	cout << "컴퓨터 빙고 : " << *(_pArray[3] + 4) << endl;
	cout << "플레이어가 선택할 숫자 : " << endl;
	cin >> *(_pArray[3] + 1); 
	if (0 < *(_pArray[3] + 1) && 26 > *(_pArray[3] + 1) && 50 != *(_pArray[0] + (*(_pArray[3] + 1) - 1)))
	{
		for (int i = 0; i < 25; i++) //플레이어가 고른 숫자 배열에서 제외(50으로)
		{
			for (int j = 0; j < 3; j++)
			{
				if (*(_pArray[3] + 1) == *(_pArray[j] + i))
				{
					*(_pArray[j] + i) = 50;
				}
			}
		}

		cout << "컴퓨터가 선택할 숫자 : \t";

		*(_pArray[3] + 2) = 0;
		for (int i = 0; i < 25; i++) // 컴퓨터가 고를 수 탐색
		{
			if (50 == *(_pArray[2] + (*(_pArray[3] + 2))))
			{
				*(_pArray[3] + 2) += 1;
			}
		}
		cout << *(_pArray[2] + *(_pArray[3] + 2)) << endl; // 컴퓨터가 RandomChoice에서 고른 숫자

		for (int i = 0; i < 25; i++) //컴퓨터가 고른 숫자 배열에서 제외(50으로)
		{
			for (int j = 0; j < 2; j++)
			{
				if (*(_pArray[2] + *(_pArray[3] + 2)) == *(_pArray[j] + i))
				{
					*(_pArray[j] + i) = 50;
				}
			}
		}
		for (int i = 0; i < 25; i++) // 랜덤으로 고른 숫자도 다시 50으로
		{
			if (*(_pArray[2] + *(_pArray[3] + 2)) == *(_pArray[2] + i))
			{
				*(_pArray[2] + i) = 50;
			}
		}
		HW4_PlayerBingo(_pArray);
		HW4_ComputerBingo(_pArray);
		
	}
	else
	{
		cout << "잘못 입력. 다시 돌아갑니다." << endl;
		HW4_PlayerBingo(_pArray);
		HW4_ComputerBingo(_pArray);
	}
	
}
void HW4_PlayerBingo(int* _pArray[])//0,4, 3-3
{
	/**p[3] = (*p[0] + *(p[0] + 1) + *(p[0] + 2) + *(p[0] + 3) + *(p[0] + 4));
	if (250 == *p[3])
	{
		*(p[4] + 0) = 1;
	}
	*p[3] = 0;
	*p[3] = (*(p[0] + 0) + *(p[0] + 5) + *(p[0] + 10) + *(p[0] + 15) + *(p[0] + 20));
	if (250 == *p[3])
	{
		*(p[4] + 1) = 1;
	}*/
	* (_pArray[3] + 3) = 0; //변수 초기화
	for (int i = 0; i < 5; i++) // 가로줄
	{
		for (int j = 0; j < 5; j++)
		{
			*_pArray[3] += *(_pArray[0] + (5*i)+ j);
		}
		if (250 == *_pArray[3])
		{
			*(_pArray[4] + i) = 1;
		}
		*_pArray[3] = 0;
	}
	for (int i = 0; i < 5; i++) // 세로줄
	{
		for (int j = 0; j < 5; j++)
		{
			*_pArray[3] += *(_pArray[0] + (5 * j) + i);
		}
		if (250 == *_pArray[3])
		{
			*(_pArray[4] + i + 5) = 1;
		}
		*_pArray[3] = 0;
	}
	for (int i = 0; i < 5; i++) // 좌상대각선
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == j)
			{
				*_pArray[3] += *(_pArray[0] + (5 * j) + i);
			}
		}
		if (250 == *_pArray[3])
		{
			*(_pArray[4] + 10) = 1;
		}
	}
	*_pArray[3] = 0;
	for (int i = 0; i < 5; i++) // 우상대각선
	{
		for (int j = 0; j < 5; j++)
		{
			if (4 == i + j)
			{
				*_pArray[3] += *(_pArray[0] + ((5 * j) + i));
			}
		}
		if (250 == *_pArray[3])
		{
			*(_pArray[4] + 11) = 1;
		}
	}
	*_pArray[3] = 0;
	for (int i = 0; i < 12; i++)
	{
		*(_pArray[3] + 3) += *(_pArray[4] + i);
	}
	//cout << "플레이어 빙고 : " << *(p[3] + 3) << endl;
}
void HW4_ComputerBingo(int* _pArray[])//1,5, 3-4
{
	*(_pArray[3] + 4) = 0; // 컴퓨터용 변수 초기화
	for (int i = 0; i < 5; i++) // 가로줄
	{
		for (int j = 0; j < 5; j++)
		{
			*_pArray[3] += *(_pArray[1] + (5 * i) + j);
		}
		if (250 == *_pArray[3])
		{
			*(_pArray[5] + i) = 1;
		}
		*_pArray[3] = 0;
	}
	for (int i = 0; i < 5; i++) // 세로줄
	{
		for (int j = 0; j < 5; j++)
		{
			*_pArray[3] += *(_pArray[1] + (5 * j) + i);
		}
		if (250 == *_pArray[3])
		{
			*(_pArray[5] + i + 5) = 1;
		}
		*_pArray[3] = 0;
	}
	for (int i = 0; i < 5; i++) // 좌상대각선
	{
		for (int j = 0; j < 5; j++)
		{
			if (i == j)
			{
				*_pArray[3] += *(_pArray[1] + (5 * j) + i);
			}
		}
		if (250 == *_pArray[3])
		{
			*(_pArray[5] + 10) = 1;
		}
	}
	*_pArray[3] = 0;

	for (int i = 0; i < 5; i++) // 우상대각선
	{
		for (int j = 0; j < 5; j++)
		{
			if (4 == i + j)
			{
				*_pArray[3] += *(_pArray[1] + ((5 * j) + i));
			}
		}
		if (250 == *_pArray[3])
		{
			*(_pArray[5] + 11) = 1;
		}
	}
	*_pArray[3] = 0;

	for (int i = 0; i < 12; i++)
	{
		*(_pArray[3] + 4) += *(_pArray[5] + i);
	}
	if (4 < *(_pArray[3] + 4) || 4 < *(_pArray[3] + 3)) // 승리조건 만족시
	{
		if (4 < *(_pArray[3] + 3) && 4 < *(_pArray[3] + 4))
		{
			cout << "플레이어 빙고 : " << *(_pArray[3] + 3) << "\t-->5 빙고이상 완성!!" << endl;
			cout << "컴퓨터 빙고 : " << *(_pArray[3] + 4) << "\t-->5 빙고이상 완성!!" << endl;
			cout << "무승부" << endl;
		}
		else if (4 < *(_pArray[3] + 3))
		{
			cout << "플레이어 빙고 : " << *(_pArray[3] + 3) << "\t-->5 빙고이상 완성!!" << endl;
			cout << "컴퓨터 빙고 : " << *(_pArray[3] + 4) << endl;
			cout << "플레이어 승리" << endl;
		}
		else
		{
			cout << "플레이어 빙고 : " << *(_pArray[3] + 3)  << endl;
			cout << "컴퓨터 빙고 : " << *(_pArray[3] + 4) << "\t-->5 빙고이상 완성!!" << endl;
			cout << "컴퓨터 승리(플레이어 패배)" << endl;
		}
	}
	else // 게임 진행 필요시
	{
		system("pause");
		HW4_Multi(_pArray);
	}
}

#pragma endregion