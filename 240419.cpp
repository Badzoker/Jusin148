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

// 1. ����for���� �迭�� �̿��Ͽ� ������ ���� ����ؿ���
// 1~25���� 5x5 ���

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

// 2. �ζ� �����
// �迭�� �̿��Ͽ� 1~45������ ������ 6���� �����Ͽ� 5ȸ ����ϱ�
// ���� ȸ�������� �ߺ��Ǵ� ���ڰ� �߻� �� �� ����
// ��� ��, ���� ������ �̿��Ͽ� �������� ������ �� ��(�����ڸ�)

void HW2()
{
	int iArray[45] = {}, iLotto[6] = {}, iCount(0);
	HW2_Lotto(&iCount, iArray, iLotto);
}

void HW2_Lotto(int* _pCount, int _iArray[], int _iLotto[])
{
	cout << *_pCount + 1 << "ȸ�� �ζ�" << endl;
	for (int i = 0; i < 45; i++) // �ܼ� �۾�(������� �ֱ�)
	{
		_iArray[0] = i + 1;
	}
	for (int i = 0; i < 6; i++) // ���� 6�� �ζ� ��ȣ�� ������� �ֱ�
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
				Swap(&_iLotto[j], &_iLotto[i]); //�����ߴµ� �������������� Ȯ��
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

// 3. �߱� ���� �����
// 1~9������ ���� �� �������� �� ���� �߻���Ŵ (����x)
// �÷��̾ ���ڸ� �� �� �Է� �޾� ��ġ�� �� ��� ��ġ�� ��� ��Ʈ����ũ
// ���� ��ġ�� ��� �� ����
// �� ȸ �� ��Ʈ����ũ �� �� ���� ���
// 3 ��Ʈ����ũ �� ��� �¸� ��� ��, ���� ����
// 9ȸ�� �� ������ 3��Ʈ����ũ�� �ϼ����� ���ϸ� �й� ��� ��, ����

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
				cout << iRandom<<" <- ��ġ�� �� ����\n";
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
	cout << "���� ����\n";
	cout << _iArray[0] << "\t" << _iArray[1] << "\t" << _iArray[2] << "\n";
	for (int i = 0; i < 9; i++)
	{
		cout << i + 1 << "ȸ�� �����մϴ�.\n";
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
		cout << "�¸�";
	}
	else
	{
		cout << "�й�";
	}
}

void HW3_Play(int _iArray[], int _iArray2[], int* _pStrike, int* _pWrong)
{
	int iBall(0);
	cout << "1�� �� : ";
	cin >> _iArray[0];
	cout << "2�� �� : ";
	cin >> _iArray[1];
	cout << "3�� �� : ";
	cin >> _iArray[2];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (Check_Same(_iArray[i],_iArray[j]))
			{
				cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
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

// 4. ���� ���� �����
// 1~25���� 5x5 ���
// ���ڸ� �Է��Ͽ� ��ġ�ϴ� ������ ��� * �� ���
// ���� ���� �밢�� �������� *�� �ټ����� ������� ��� ���� 1�� ����
// 5 ���� �̻��̸� �¸��� ���� ����
// ���� �������� ����

void HW4()
{
	int iArray_Player[25] = {}, iArray_Computer[25] = {}, iArray_RandomChoice[25] = {}, iArray_Number[5] = {}, iArray_Bingo[12] = {}, iArray_ComBingo[12] = {}; // Number = Random, Choice, ChoiceCount, Player_Bingo, Computer_Bingo, 
	int* pArray[6] = { iArray_Player, iArray_Computer, iArray_RandomChoice, iArray_Number, iArray_Bingo, iArray_ComBingo}; // ������ �迭(���� ������?)
	//�ʿ��� ���� �ִ��� �迭�ȿ� ��ġ �� ������ �迭�� ���� �Ű����� �ϳ��� ��� �����ϴ� ����
	for (int i = 0; i < size(iArray_Player); i++) //�÷��̾� ������ ����
	{
		iArray_Player[i] = i + 1;
	}
	for (int i = 0; i < size(iArray_Computer); i++) // ��ǻ�� ������ ����
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
	for (int i = 0; i < size(iArray_RandomChoice); i++) // ��ǻ�� �� �� ����
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
	cout << "���� ����" << endl;
	HW4_Multi(pArray);
}
void HW4_Multi(int* _pArray[]) // p[] -> player, computer, randomchoice, ���ڸ���(random, choice, choicecount(computer����), player_bingo, computer_bingo)
{
	system("cls");
	cout << "        ======player======                                     ======computer======\n";
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++) // �÷��̾� ������ ���(�� ����)
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
		for (int j = 0; j < 5; j++) // ��ǻ�� ������ ���(�� ����)
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
	cout << "�÷��̾� ���� : " << *(_pArray[3] + 3) << endl;
	cout << "��ǻ�� ���� : " << *(_pArray[3] + 4) << endl;
	cout << "�÷��̾ ������ ���� : " << endl;
	cin >> *(_pArray[3] + 1); 
	if (0 < *(_pArray[3] + 1) && 26 > *(_pArray[3] + 1) && 50 != *(_pArray[0] + (*(_pArray[3] + 1) - 1)))
	{
		for (int i = 0; i < 25; i++) //�÷��̾ �� ���� �迭���� ����(50����)
		{
			for (int j = 0; j < 3; j++)
			{
				if (*(_pArray[3] + 1) == *(_pArray[j] + i))
				{
					*(_pArray[j] + i) = 50;
				}
			}
		}

		cout << "��ǻ�Ͱ� ������ ���� : \t";

		*(_pArray[3] + 2) = 0;
		for (int i = 0; i < 25; i++) // ��ǻ�Ͱ� �� �� Ž��
		{
			if (50 == *(_pArray[2] + (*(_pArray[3] + 2))))
			{
				*(_pArray[3] + 2) += 1;
			}
		}
		cout << *(_pArray[2] + *(_pArray[3] + 2)) << endl; // ��ǻ�Ͱ� RandomChoice���� �� ����

		for (int i = 0; i < 25; i++) //��ǻ�Ͱ� �� ���� �迭���� ����(50����)
		{
			for (int j = 0; j < 2; j++)
			{
				if (*(_pArray[2] + *(_pArray[3] + 2)) == *(_pArray[j] + i))
				{
					*(_pArray[j] + i) = 50;
				}
			}
		}
		for (int i = 0; i < 25; i++) // �������� �� ���ڵ� �ٽ� 50����
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
		cout << "�߸� �Է�. �ٽ� ���ư��ϴ�." << endl;
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
	* (_pArray[3] + 3) = 0; //���� �ʱ�ȭ
	for (int i = 0; i < 5; i++) // ������
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
	for (int i = 0; i < 5; i++) // ������
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
	for (int i = 0; i < 5; i++) // �»�밢��
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
	for (int i = 0; i < 5; i++) // ���밢��
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
	//cout << "�÷��̾� ���� : " << *(p[3] + 3) << endl;
}
void HW4_ComputerBingo(int* _pArray[])//1,5, 3-4
{
	*(_pArray[3] + 4) = 0; // ��ǻ�Ϳ� ���� �ʱ�ȭ
	for (int i = 0; i < 5; i++) // ������
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
	for (int i = 0; i < 5; i++) // ������
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
	for (int i = 0; i < 5; i++) // �»�밢��
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

	for (int i = 0; i < 5; i++) // ���밢��
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
	if (4 < *(_pArray[3] + 4) || 4 < *(_pArray[3] + 3)) // �¸����� ������
	{
		if (4 < *(_pArray[3] + 3) && 4 < *(_pArray[3] + 4))
		{
			cout << "�÷��̾� ���� : " << *(_pArray[3] + 3) << "\t-->5 �����̻� �ϼ�!!" << endl;
			cout << "��ǻ�� ���� : " << *(_pArray[3] + 4) << "\t-->5 �����̻� �ϼ�!!" << endl;
			cout << "���º�" << endl;
		}
		else if (4 < *(_pArray[3] + 3))
		{
			cout << "�÷��̾� ���� : " << *(_pArray[3] + 3) << "\t-->5 �����̻� �ϼ�!!" << endl;
			cout << "��ǻ�� ���� : " << *(_pArray[3] + 4) << endl;
			cout << "�÷��̾� �¸�" << endl;
		}
		else
		{
			cout << "�÷��̾� ���� : " << *(_pArray[3] + 3)  << endl;
			cout << "��ǻ�� ���� : " << *(_pArray[3] + 4) << "\t-->5 �����̻� �ϼ�!!" << endl;
			cout << "��ǻ�� �¸�(�÷��̾� �й�)" << endl;
		}
	}
	else // ���� ���� �ʿ��
	{
		system("pause");
		HW4_Multi(_pArray);
	}
}

#pragma endregion