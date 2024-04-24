#include <iostream>

using namespace std;
void HW1();
void HW1_Change90(int* _pArray);
void HW2();
void Test();
void Test2(int(*pTemp)[3]);

int main()
{
	//HW1();
	//HW2();
	//Test();
	return 0;
}
//숙제
#pragma region HW1
void HW1() // 1.  다음의 숫자들을 2차원 배열을 이용하여 출력하고 90도씩 4회 회전을 출력하라
{
	int iArray[4][4] = {};
	int* pArray = &iArray[0][0];
	for (int i = 0; i < 4; i++) // 첫 입력
	{
		for (int j = 0; j < 4; j++)
		{
			iArray[i][j] = 4 * i + j;
			if (i == j)
			{
				iArray[i][j] *= 10;
			}
		}
	}
	HW1_Change90(pArray);
}

void HW1_Change90(int* _pArray)
{
	int iCount(0), iSize(4);
	int iArray[4][4] = {}, iArray_Change[4][4] = {}; // 이전에 입력된 놈
	for (int i = 0; i < iSize; i++) //굳이 포인터로 받아와서 입력해봄
	{
		for (int j = 0; j < iSize; j++)
		{
			iArray[i][j] = *(_pArray + iSize * i + j);
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
	int* pZero = &iArray[0][0]; //처음시작점(0 , 대표주소)
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
		
		cin >> iInput;

		switch (iInput)
		{
		case 2:
			if (1 == iY) //Index 확인 -> (1, 5)-(5, 5)-(1, 1)-(5, 1) 을 벗어나지 않도록
			{
				cout << pZero << "맨아래" << endl;
			}
			else
			{
				swap(*pZero, *(pZero + 5)); //2
				pZero += 5;
				iY--;
			}
			break;
		case 4:
			if (1 == iX)
			{
				cout << pZero << "맨왼" << endl;
			}
			else
			{
				swap(*pZero, *(pZero - 1)); //4
				pZero -= 1;
				iX--;
			}
			break;
		case 6:
			if (5 == iX)
			{
				cout << pZero << "맨오른" << endl;
			}
			else
			{
				swap(*pZero, *(pZero + 1)); //6
				pZero += 1;
				iX++;
			}
			break;
		case 8:
			if (5 == iY)
			{
				cout << pZero << "맨위" << endl;
			}
			else
			{
				swap(*pZero, *(pZero - 5)); //8
				pZero -= 5;
				iY++;
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
}

#pragma endregion 
#pragma region 개인활동
void Test()
{
	int iArray[4][3] = {}, iArray2[8][3] = {};
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			iArray[i][j] = 3 * i + j;
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			iArray2[i][j] = 3 * i + j;
		}
	}
	Test2(iArray);
}
void Test2(int (*pTemp)[3])
{
	cout << pTemp[2][2];
}

#pragma endregion