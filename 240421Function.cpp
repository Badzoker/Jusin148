#include <iostream>
#include <ctime>

using namespace std;

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
	int* pArray[6] = { iArray_Player, iArray_Computer, iArray_RandomChoice, iArray_Number, iArray_Bingo, iArray_ComBingo }; // ������ �迭(���� ������?)
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
			*_pArray[3] += *(_pArray[0] + (5 * i) + j);
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
			cout << "�÷��̾� ���� : " << *(_pArray[3] + 3) << endl;
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