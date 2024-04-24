#include <iostream>
#include <time.h>

using namespace std;

void Insert_Star();
void MakingStar(int* _pCount);

int main()
{
	/*int iRandom(0);
	srand(unsigned(time(NULL)));
	iRandom = (rand() % 10 + 1); 익숙해지기*///난수 만들기 
	Insert_Star();
	return 0;
}

#pragma region 포인터이전

#pragma region 개인활동
#pragma region int로 배열처럼한것
/*int iTemp1(1), iTemp2(2), iTemp3(3), iTemp4(4), iTemp(0), iCount(0);
cout << iTemp1 << "\t" << iTemp2 << "\n" << iTemp3 << "\t" << iTemp4 << endl;;
cout << "++++++++++++++++" << endl;
while (iCount < 4)
{
	iTemp = iTemp1;
	iTemp1 = iTemp3;
	iTemp3 = iTemp4;
	iTemp4 = iTemp2;
	iTemp2 = iTemp;
	cout << iTemp1 << "\t" << iTemp2 << "\n" << iTemp3 << "\t" << iTemp4 << endl;
	cout << "-----------------" << endl;
	iCount++;
}*/
#pragma endregion int로 배열처럼한것

#pragma region 배열로 해본것
//int iCount(0);
//int iArray[5][5];
//int iArray2[5][5];

//for (int row = 0; row < 5; row++)
//{
//	for (int col = 0; col < 5; col++)
//	{
//		iArray[row][col] = iCount;
//		iCount++;
//	}
//}
//iCount = 0;

//for (int row = 0; row < 5; row++)
//{
//	for (int col = 0; col < 5; col++)
//	{
//		cout << iArray[row][col] << "  ";
//	}
//}
//cout << "\n--------------" << endl;
//while (4 > iCount)
//{
//	for (int row = 0; row < 5; row++)
//	{
//		for (int col = 0; col < 5; col++)
//		{
//			iArray2[row][col] = iArray[col][5 - row - 1];
//			//tmp[j][N - 1 - i] = arr[i][j] -> 반시계
//			//tmp[N - j - 1][i] = arr[i][j] -> 시계
//		}
//	}
//	for (int row = 0; row < 5; row++)
//	{
//		for (int col = 0; col < 5; col++)
//		{
//			iArray[row][col] = iArray2[row][col];
//			cout << iArray[row][col] << "   ";
//		}
//	}
//	cout << "\n--------------" << endl;
//	iCount++;
//}
#pragma endregion 배열로 해본것

#pragma region 트리거

	//bool bTemp = false;
	//cout << "트리거 시작" << endl;
	//char cTemp(1);
	//while (cTemp)
	//{
	//	cin >> cTemp;
	//	bTemp ^= true; //비트연산으로 바꿈 원래는 bTemp != bTemp; 였음
	//	cout << "\t" << bTemp << "\t bool값 출력 ------" << endl;
	//}

#pragma endregion 트리거

#pragma endregion 개인활동

#pragma region 0415과제


#pragma region 단곱구구단과제

	//2중 for문을 이용하여 2~9구구단
	//단 과 곱을 입력받아 그것까지 출력해보시오

	/*system("cls");
	int iTemp1(0), iSour1(0);

	cout << "단 수를 입력하시오 : " << endl;
	cin >> iTemp1;
	cout << "곱의 수를 입력하시오 : " << endl;
	cin >> iSour1;
	system("pause");

	for (int i = 2; i < iTemp1 + 1; i++)
	{
		cout << i << " 단 \n" << endl;
		for (int j = 1; j < iSour1 + 1; j++)
		{
			cout << i << " x " << j << " = " << i * j << endl;
		}
		cout << "\n" << endl;
	}*/

#pragma endregion 단곱구구단과제

#pragma region 별만들기
	//다음과 같이 2중 for문을 이용하여 별을 출력해와라
	//*
	//**
	//***
	//****
	//*****

	//*****
	//****
	//***
	//**
	//*

	//     *
	//    **
	//   ***
	//  ****
	// *****

	// *****
	//  ****
	//   ***
	//    **
	//     *

//int iTemp(0);
//int iSour(0); // 개인활동용
//cout << "별의 최대 갯수를 입력하시오\n";
//cin >> iTemp;

//////1번째 별
//for (int i = 0; i < iTemp; i++)
//{
//	for (int j = 0; j < iTemp; j++)
//	{
//		if (i > j - 1)
//		{
//			cout << "*";
//		}
//		else
//		{
//			cout << " ";
//		}
//	}
//	cout << endl;
//}
//cout << endl;
////2번째 별
//for (int i = 0; i < iTemp; i++)
//{
//	for (int j = 0; j < iTemp; j++)
//	{
//		if (iTemp > i + j)
//		{
//			cout << "*";
//		}
//		else
//		{
//			cout << " ";
//		}
//	}
//	cout << endl;
//}
//cout << endl;
////3번째 별
//for (int i = 0; i < iTemp; i++)
//{
//	for (int j = 0; j < iTemp; j++)
//	{
//		if (iTemp - 2 < i + j)
//		{
//			cout << "*";
//		}
//		else
//		{
//			cout << " ";
//		}
//	}
//	cout << endl;
//}
//cout << endl;
////4번째 별
//for (int i = 0; i < iTemp; i++)
//{
//	for (int j = 0; j < iTemp; j++)
//	{
//		if (i <  j + 1)
//		{
//			cout << "*";
//		}
//		else
//		{
//			cout << " ";
//		}
//	}
//	cout << endl;
//}
// 
#pragma endregion 별만들기

#pragma region 별만들기2

	//for (int i = 0; i < iTemp; i++)
	//{
	//	for (int j = 0; j < iTemp; j++)
	//	{
	//		if (i > j - 1)
	//		{
	//			cout << "*";
	//		}
	//		else
	//		{
	//			cout << " ";
	//		}
	//	}
	//	cout << "\t"; //첫번째 별 완료
	//	for (int j = 0; j < iTemp; j++)
	//	{
	//		if (iTemp > i + j)
	//		{
	//			cout << "*";
	//		}
	//		else
	//		{
	//			cout << " ";
	//		}
	//	}
	//	cout << "\t"; //두번째 별 완료
	//	for (int j = 0; j < iTemp; j++)
	//	{
	//		if (iTemp - 2 < i + j)
	//		{
	//			cout << "*";
	//		}
	//		else
	//		{
	//			cout << " ";
	//		}
	//	}
	//	cout << "\t"; //세번째 별 완료
	//	for (int j = 0; j < iTemp; j++)
	//	{
	//		if (i < j + 1)
	//		{
	//			cout << "*";
	//		}
	//		else
	//		{
	//			cout << " ";
	//		}
	//	}
	//	cout << endl; //네번째 별 완료
	//}
	//cout << endl;

#pragma endregion 별만들기2

#pragma region 별만들기3

	/*for (int i = 0; i < iTemp * 2 - 1; i++)
	{
		iSour = iTemp - i;
		if (i > iTemp - 1)
		{
			iSour = i - iTemp + 2;
		}
		for (int j = 0; j < iSour; j++)
		{
			cout << " ";
		}
		iSour = 2 * i + 1;
		if (i > iTemp - 1)
		{
			iSour = 2 * (2 * iTemp - i) - 3;
		}
		for (int j = 0; j < iSour; j++)
		{
			cout << "*";
		}
		cout << endl;
	}*/

#pragma endregion 별만들기3

#pragma region 별만들기4


	/*for (int i = 0; i < (iTemp * 2) - 1; i++)
	{
		iSour = i + 1;
		if (iSour > iTemp - 1)
		{
			iSour = iTemp * 2 - i - 1;
		}
		for (int j = 0; j < iSour; j++)
		{
			cout << " ";
		}
		iSour = ((iTemp - i) * 2) - 1;
		if (iSour < 0)
		{
			iSour = -iSour + 2;
		}
		for (int j = 0; j < iSour; j++)
		{
			cout << "*";
		}
		cout << endl;
	}*/

#pragma endregion 별만들기4

#pragma region 별만들기5

	/*for (int i = 0; i < (iTemp * 2) - 1; i++)
	{
		iSour = i + 1;
		if (iSour > iTemp - 1)
		{
			iSour = iTemp * 2 - i - 1;
		}

		for (int j = 0; j < iSour; j++)
		{
			cout << "*";
		}

		iSour = ((iTemp - i) * 2) - 1;
		if (iSour < 0)
		{
			iSour = -iSour + 2;
		}

		for (int j = 0; j < iSour; j++)
		{
			cout << " ";
		}

		iSour = i + 1;
		if (iSour > iTemp - 1)
		{
			iSour = iTemp * 2 - i - 1;
		}

		for (int j = 0; j < iSour; j++)
		{
			cout << "*";
		}

		cout << endl;
	}*/

#pragma endregion 별만들기5

#pragma endregion 0415과제

#pragma endregion
void Insert_Star()
{
	int iCount(0);
	int* pCount = &iCount;
	cout << "별만들기 위한 숫자를 입력하시오 : ";
	cin >> *pCount;
	MakingStar(pCount);
}

void MakingStar(int* _pCount)
{
	for (int i = 0; i < *_pCount; i++)
	{
		for (int j = 0; j < *_pCount; j++)
		{
			if (i <= j)
			{
				cout << "*";
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}