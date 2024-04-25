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

void HW1();
void HW1_Change90(int** _p);
void HW2();
const int iCount_RowCol = 4; // HW1 용 행렬 숫자

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//HW1();
	HW2();
	/*int* p = new int(0);
	int iTemp(0);
	p = &iTemp;

	delete p;
	p = nullptr;*/ //->위험한 행동같음 스택메모리에서 힙메모리로 하는 느낌?
	return 0;
}

#pragma region HW1
void HW1() // 1.  다음의 숫자들을 2차원 배열을 이용하여 출력하고 90도씩 4회 회전을 출력하라
{
	int iArray[4][4] = {};
	int* pArray = &iArray[0][0];

	int** p = new int*[iCount_RowCol]; // 이차원 배열 동적할당 행할당(1)
	for (int i = 0; i < iCount_RowCol; i++)
	{
		p[i] = new int[iCount_RowCol]; // 이차원 배열 동적할당 열할당(2)
	}


	for (int i = 0; i < iCount_RowCol; i++) // 첫 입력
	{
		for (int j = 0; j < iCount_RowCol; j++)
		{
			p[i][j] = 4 * i + j;
			if (i == j)
			{
				p[i][j] *= 10;
			}
			cout << p[i][j] << endl;
		}
	}
	system("pause");
	HW1_Change90(p);
	for (int i = 0; i < iCount_RowCol; i++) 
	{
		delete[] p[i]; //이차원 배열 열반환(2)
	}
	delete[] p; //이차원 배열 행반환(2)
	p = nullptr;//반환한 녀석 중 첫놈 Null 초기화
}

void HW1_Change90(int** _p)
{
	int iCount(0), iSize(4);
	int iArray[4][4] = {}, iArray_Change[4][4] = {}; // 이전에 입력된 놈
	for (int i = 0; i < iSize; i++) //굳이 포인터로 받아와서 입력해봄
	{
		for (int j = 0; j < iSize; j++)
		{
			iArray[i][j] = _p[i][j];
		}
	}
	while (5 > iCount)
	{
		system("cls");

		for (int i = 0; i < iSize; i++) // 바꾸는 과정 
		{
			for (int j = 0; j < iSize; j++)
			{
				iArray_Change[i][j] = iArray[3 - j][i];
				cout << iArray[i][j] << "\t";
			}
			cout << endl;
		}
		for (int i = 0; i < iSize; i++) // 배열1번에 다시 지금 값 넣기
		{
			for (int j = 0; j < iSize; j++)
			{
				iArray[i][j] = iArray_Change[i][j];
			}
		}
		system("pause");
		iCount++;
	}
	
}

#pragma endregion
//대각선도 추가해보기

#pragma region HW2

void HW2() // 2. 0~24에 해당하는 5*5 상태로 출력, 숫자패드 2468 에 따라 이동하도록
{
	int iArray[5][5] = {}; //5x5 행렬
	int iInput(0), iX(1), iY(5); //변수 및 행렬의 Index
	int* pZero = iArray[0]; //처음시작점(0 , 대표주소)
	int* p = new int(*iArray[0]); //-> 동적할당으로 바꿈
	//===========================================================
	//*p = &iArray[0][0]; // 동적할당(1) 이거 위험한행동 같음  이것도 이중포인터로 하는 것 같음 제대로 봐야함
	//===========================================================
	bool bCheck(true); //while문을 위한 bool값
	for (int i = 0; i < 5; i++)//5x5 행렬 index 작성
	{
		for (int j = 0; j < 5; j++)
		{
			iArray[i][j] = 5 * i + j;
		}
	}
	while (bCheck)
	{
		system("cls");
		for (int i = 0; i < 5; i++) //그리기
		{
			for (int j = 0; j < 5; j++)
			{
				cout << iArray[i][j] << "\t";
			}
			cout << endl;
		}
		cout << "\n2. 밑  4. 뒤  6. 앞  8. 위   10. 종료\n";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			if (1 == iY || 1 == iX) //Index 확인 -> (1, 5)-(5, 5)-(1, 1)-(5, 1) 을 벗어나지 않도록
			{
				cout << "대각왼아래불가" << endl;
			}
			else
			{
				swap(*p, *(p + 4)); //1
				p += 4;
				iY--;
				iX--;
			}
			break;
		case 2:
			if (1 == iY) //Index 확인 -> (1, 5)-(5, 5)-(1, 1)-(5, 1) 을 벗어나지 않도록
			{
				cout << p << "맨아래" << endl;
			}
			else
			{
				swap(*p, *(p + 5)); //2
				p += 5;
				iY--;
			}
			break;
		case 3:
			if (1 == iY || 5 == iX) //Index 확인 -> (1, 5)-(5, 5)-(1, 1)-(5, 1) 을 벗어나지 않도록
			{
				cout << "대각오른아래불가" << endl;
			}
			else
			{
				swap(*p, *(p + 6)); //3
				p += 6;
				iY--;
				iX++;
			}
			break;

		case 4:
			if (1 == iX)
			{
				cout << p << "맨왼" << endl;
			}
			else
			{
				swap(*p, *(p - 1)); //4
				p -= 1;
				iX--;
			}
			break;
		case 6:
			if (5 == iX)
			{
				cout << p << "맨오른" << endl;
			}
			else
			{
				swap(*p, *(p + 1)); //6
				p += 1;
				iX++;
			}
			break;
		case 7:
			if (5 == iY || 1 == iX) //Index 확인 -> (1, 5)-(5, 5)-(1, 1)-(5, 1) 을 벗어나지 않도록
			{
				cout << "대각왼위불가" << endl;
			}
			else
			{
				swap(*p, *(p - 6)); //7
				p -= 6;
				iY++;
				iX--;
			}
			break;
		case 8:
			if (5 == iY)
			{
				cout << p << "맨위" << endl;
			}
			else
			{
				swap(*p, *(p - 5)); //8
				p -= 5;
				iY++;
			}
			break;
		case 9:
			if (1 == iY) //Index 확인 -> (1, 5)-(5, 5)-(1, 1)-(5, 1) 을 벗어나지 않도록
			{
				cout << "대각오른위불가" << endl;
			}
			else
			{
				swap(*p, *(p - 4)); //9
				p -= 4;
				iY++;
				iX++;
			}
			break;
		case 10:
			bCheck = false; // 종료
			
			break;
		default:
			cout << "다시 입력하시오 \n"; //예외처리
			break;
		}
		system("pause");
	}
	cout << "끝\n";
	*p = 0;
	delete p;
	p = nullptr; // heap 메모리반환(1)
}

#pragma endregion 