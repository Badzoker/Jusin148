#include <iostream>
#include <time.h>

using namespace std;

void Insert_Star();
void MakingStar(int* _pCount);

int main()
{
	/*int iRandom(0);
	srand(unsigned(time(NULL)));
	iRandom = (rand() % 10 + 1); �ͼ�������*///���� ����� 
	Insert_Star();
	return 0;
}

#pragma region ����������

#pragma region ����Ȱ��
#pragma region int�� �迭ó���Ѱ�
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
#pragma endregion int�� �迭ó���Ѱ�

#pragma region �迭�� �غ���
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
//			//tmp[j][N - 1 - i] = arr[i][j] -> �ݽð�
//			//tmp[N - j - 1][i] = arr[i][j] -> �ð�
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
#pragma endregion �迭�� �غ���

#pragma region Ʈ����

	//bool bTemp = false;
	//cout << "Ʈ���� ����" << endl;
	//char cTemp(1);
	//while (cTemp)
	//{
	//	cin >> cTemp;
	//	bTemp ^= true; //��Ʈ�������� �ٲ� ������ bTemp != bTemp; ����
	//	cout << "\t" << bTemp << "\t bool�� ��� ------" << endl;
	//}

#pragma endregion Ʈ����

#pragma endregion ����Ȱ��

#pragma region 0415����


#pragma region �ܰ������ܰ���

	//2�� for���� �̿��Ͽ� 2~9������
	//�� �� ���� �Է¹޾� �װͱ��� ����غ��ÿ�

	/*system("cls");
	int iTemp1(0), iSour1(0);

	cout << "�� ���� �Է��Ͻÿ� : " << endl;
	cin >> iTemp1;
	cout << "���� ���� �Է��Ͻÿ� : " << endl;
	cin >> iSour1;
	system("pause");

	for (int i = 2; i < iTemp1 + 1; i++)
	{
		cout << i << " �� \n" << endl;
		for (int j = 1; j < iSour1 + 1; j++)
		{
			cout << i << " x " << j << " = " << i * j << endl;
		}
		cout << "\n" << endl;
	}*/

#pragma endregion �ܰ������ܰ���

#pragma region �������
	//������ ���� 2�� for���� �̿��Ͽ� ���� ����ؿͶ�
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
//int iSour(0); // ����Ȱ����
//cout << "���� �ִ� ������ �Է��Ͻÿ�\n";
//cin >> iTemp;

//////1��° ��
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
////2��° ��
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
////3��° ��
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
////4��° ��
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
#pragma endregion �������

#pragma region �������2

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
	//	cout << "\t"; //ù��° �� �Ϸ�
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
	//	cout << "\t"; //�ι�° �� �Ϸ�
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
	//	cout << "\t"; //����° �� �Ϸ�
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
	//	cout << endl; //�׹�° �� �Ϸ�
	//}
	//cout << endl;

#pragma endregion �������2

#pragma region �������3

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

#pragma endregion �������3

#pragma region �������4


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

#pragma endregion �������4

#pragma region �������5

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

#pragma endregion �������5

#pragma endregion 0415����

#pragma endregion
void Insert_Star()
{
	int iCount(0);
	int* pCount = &iCount;
	cout << "������� ���� ���ڸ� �Է��Ͻÿ� : ";
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