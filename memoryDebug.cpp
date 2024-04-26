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
const int iCount_RowCol = 4; // HW1 �� ��� ����

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	//HW1();
	//HW2();
	//int* pArray = new int[25]; //�����Ҵ� 5��
	int** ppArray = new int* [5];
	cout << ppArray << endl;
	for (int i = 0; i < 5; i++)
	{
		ppArray[i] = new int[5];
		cout << ppArray[i] << endl;
	}
	for (int i = 0; i < 5; i++)
	{
		delete[] ppArray[i];
	}
	delete[] ppArray;
	return 0;
}

#pragma region HW1
void HW1() // 1.  ������ ���ڵ��� 2���� �迭�� �̿��Ͽ� ����ϰ� 90���� 4ȸ ȸ���� ����϶�
{
	int iArray[4][4] = {};
	int* pArray = &iArray[0][0];

	int** p = new int*[iCount_RowCol]; // ������ �迭 �����Ҵ� ���Ҵ�(1)
	for (int i = 0; i < iCount_RowCol; i++)
	{
		p[i] = new int[iCount_RowCol]; // ������ �迭 �����Ҵ� ���Ҵ�(2)
	}


	for (int i = 0; i < iCount_RowCol; i++) // ù �Է�
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
		delete[] p[i]; //������ �迭 ����ȯ(2)
	}
	delete[] p; //������ �迭 ���ȯ(2)
	p = nullptr;//��ȯ�� �༮ �� ù�� Null �ʱ�ȭ
}

void HW1_Change90(int** _p)
{
	int iCount(0), iSize(4);
	int iArray[4][4] = {}, iArray_Change[4][4] = {}; // ������ �Էµ� ��
	for (int i = 0; i < iSize; i++) //���� �����ͷ� �޾ƿͼ� �Է��غ�
	{
		for (int j = 0; j < iSize; j++)
		{
			iArray[i][j] = _p[i][j];
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
	int iInput(0), iX(1), iY(5); //���� �� ����� Index
	int* pArray = new int[25]; //�����Ҵ� 5��
	/*int** ppArray = new int* [5];
	for (int i = 0; i < 5; i++)
	{
		ppArray[i] = new int[5];
	}*/
	bool bCheck(true); //while���� ���� bool��
	int iArray[5][5] = {};
	for (int i = 0; i < 5; i++)//5x5 ��� index �ۼ�
	{
		for (int j = 0; j < 5; j++)
		{
			pArray[5 *i + j] = 5 * i + j;
		}
	}
	int* p = pArray;
	
	while (bCheck)
	{
		system("cls");
		for (int i = 0; i < 5; i++) //�׸���
		{
			for (int j = 0; j < 5; j++)
			{
				cout << pArray[5 * i + j] << "\t";
			}
			cout << endl;
		}
		cout << "\n2. ��  4. ��  6. ��  8. ��   10. ����\n";
		cin >> iInput;

		switch (iInput)
		{
		case 1:
			if (1 == iY || 1 == iX) //Index Ȯ�� -> (1, 5)-(5, 5)-(1, 1)-(5, 1) �� ����� �ʵ���
			{
				cout << "�밢�޾Ʒ��Ұ�" << endl;
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
			if (1 == iY) //Index Ȯ�� -> (1, 5)-(5, 5)-(1, 1)-(5, 1) �� ����� �ʵ���
			{
				cout << p << "�ǾƷ�" << endl;
			}
			else
			{
				swap(*p, *(p + 5)); //2
				p += 5;
				iY--;
			}
			break;
		case 3:
			if (1 == iY || 5 == iX) //Index Ȯ�� -> (1, 5)-(5, 5)-(1, 1)-(5, 1) �� ����� �ʵ���
			{
				cout << "�밢�����Ʒ��Ұ�" << endl;
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
				cout << p << "�ǿ�" << endl;
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
				cout << p << "�ǿ���" << endl;
			}
			else
			{
				swap(*p, *(p + 1)); //6
				p += 1;
				iX++;
			}
			break;
		case 7:
			if (5 == iY || 1 == iX) //Index Ȯ�� -> (1, 5)-(5, 5)-(1, 1)-(5, 1) �� ����� �ʵ���
			{
				cout << "�밢�����Ұ�" << endl;
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
				cout << p << "����" << endl;
			}
			else
			{
				swap(*p, *(p - 5)); //8
				p -= 5;
				iY++;
			}
			break;
		case 9:
			if (1 == iY) //Index Ȯ�� -> (1, 5)-(5, 5)-(1, 1)-(5, 1) �� ����� �ʵ���
			{
				cout << "�밢�������Ұ�" << endl;
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
			bCheck = false; // ����
			break;
		default:
			cout << "�ٽ� �Է��Ͻÿ� \n"; //����ó��
			break;
		}
		system("pause");
	}
	cout << "��\n";
	
	
	delete[] pArray;
	pArray = nullptr; // heap �޸𸮹�ȯ(1)
}

#pragma endregion 