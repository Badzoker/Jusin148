#include <iostream>
#include <ctime>

using namespace std;

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
	int* pArray[6] = { iArray_Player, iArray_Computer, iArray_RandomChoice, iArray_Number, iArray_Bingo, iArray_ComBingo }; // 포인터 배열(이중 포인터?)
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
			*_pArray[3] += *(_pArray[0] + (5 * i) + j);
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
			cout << "플레이어 빙고 : " << *(_pArray[3] + 3) << endl;
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