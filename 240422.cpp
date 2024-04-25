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
void HW1_Change90(int* _pArray);
void HW2();
void Test();
void Test2(int(*pTemp)[3]);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	//HW1();
	//HW2();
	//Test();
	return 0;
}
//����
#pragma region HW1
void HW1() // 1.  ������ ���ڵ��� 2���� �迭�� �̿��Ͽ� ����ϰ� 90���� 4ȸ ȸ���� ����϶�
{
	int iArray[4][4] = {};
	
	int* pArray = &iArray[0][0];
	for (int i = 0; i < 4; i++) // ù �Է�
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
	int iArray[4][4] = {}, iArray_Change[4][4] = {}; // ������ �Էµ� ��
	for (int i = 0; i < iSize; i++) //���� �����ͷ� �޾ƿͼ� �Է��غ�
	{
		for (int j = 0; j < iSize; j++)
		{
			iArray[i][j] = *(_pArray + iSize * i + j);
		}
	}
	while (5 > iCount)
	{
		system("cls");

		for (int i = 0; i < iSize; i++) // �ٲٴ� ���� 
		{
			for (int j = 0; j < iSize; j++)
			{
				iArray_Change[i][j] = iArray[3 - j][i];
				cout << iArray[i][j] << "\t";
			}
			cout << endl;
		}
		for (int i = 0; i < iSize; i++) // �迭1���� �ٽ� ���� �� �ֱ�
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
//�밢���� �߰��غ���
#pragma region HW2

void HW2() // 2. 0~24�� �ش��ϴ� 5*5 ���·� ���, �����е� 2468 �� ���� �̵��ϵ���
{
	int iArray[5][5] = {}; //5x5 ���
	int iInput(0), iX(1), iY(5); //���� �� ����� Index
	int* pZero = &iArray[0][0]; //ó��������(0 , ��ǥ�ּ�)
	bool bCheck(true); //while���� ���� bool��
	for (int i = 0; i < 5; i++)//5x5 ��� index �ۼ�
	{
		for (int j = 0; j < 5; j++)
		{
			iArray[i][j] = 5 * i + j;
		}
	}
	while (bCheck)
	{
		system("cls");
		for (int i = 0; i < 5; i++) //�׸���
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
			if (1 == iY) //Index Ȯ�� -> (1, 5)-(5, 5)-(1, 1)-(5, 1) �� ����� �ʵ���
			{
				cout << pZero << "�ǾƷ�" << endl;
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
				cout << pZero << "�ǿ�" << endl;
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
				cout << pZero << "�ǿ���" << endl;
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
				cout << pZero << "����" << endl;
			}
			else
			{
				swap(*pZero, *(pZero - 5)); //8
				pZero -= 5;
				iY++;
			}
			break;
		case 10:
			bCheck = false; // ����
			break;
		default:
			cout << "�ٽ� �Է��Ͻÿ� \n"; //����ó��
			break;
		}
		system("pause");
	}
	cout << "��\n";
}

#pragma endregion 
#pragma region ����Ȱ��
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