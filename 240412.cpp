#include <iostream>
#include <time.h>
using namespace std;

void MultiplicationTable();
void Calculate_Multiply(int* _pFirstNumber, int* _pSecondNumber);
void DrinkMachine();
void PickingDrink(int& _pMoney,int* _pChoice);
int main()
{
	MultiplicationTable();
	//DrinkMachine();

#pragma region ������
	//while���� �̿��Ͽ� 2~9�ܱ��� ���
	/*int i(2), j(1);
	while (10 > i)
	{
		cout << "\n" << i << " �� ------------" << endl;
		while (10 > j)
		{
			cout << i << " x " << j << " = " << i * j << endl;
			j++;
		}
		i++;
		j = 1;
	}
	cout << " �� ";*/

#pragma endregion ������

#pragma region ���Ǳ����
	//�������� �Է� �ް�, �׻� �����ܾ��� ǥ��
	//�޴��� �ݶ� 100 ���̴� 200 ȯŸ 300 ��ȯ
	// �޴� ���Ž� 'xx ���� �Ϸ�' ����� �ܾ׺���
	// �������� �����ϸ� '�������� �����մϴ�' �� ���
	// 4�� '�ܾ��� xx�� �Դϴ�. ' ��� �� ����

	/*int iMoney(0), iChoice(0);

	cout << "�����Ͻ� �ݾ��� �Է����ּ���" << endl;
	cin >> iMoney;
	
	while (4 != iChoice)
	{
		system("cls");
		cout << "���� �������� : " << iMoney << "���Դϴ�." << endl;
		cout << "�޴��� 1. �ݶ� 100��, 2. ���̴� 200��, 3. ȯŸ 300��, 4. ����" << endl;

		cin >> iChoice;
		
		switch (iChoice)
		{
		case 1:
			if (100 <= iMoney)
			{
				iMoney -= 100;
				cout << "�ݶ� �����߽��ϴ�. ���� �������� : " << iMoney << "�Դϴ�." << endl;
			}
			else
			{
				cout << "�������� �����մϴ�" << endl;
			}
			break;
		case 2:
			if (200 <= iMoney)
			{
				iMoney -= 200;
				cout << "���̴ٸ� �����߽��ϴ�. ���� �������� : " << iMoney << "�Դϴ�." << endl;
			}
			else
			{
				cout << "�������� �����մϴ�" << endl;
			}
			break;
		case 3:
			if (300 <= iMoney)
			{
				iMoney -= 300;
				cout << "ȯŸ�� �����߽��ϴ�. ���� �������� : " << iMoney << "�Դϴ�." << endl;
			}
			else
			{
				cout << "�������� �����մϴ�" << endl;
			}
			break;
		case 4:
			cout << "�����մϴ�" << endl;
			break;
		default:
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���";
			break;
		}
		system("pause");
	}*/


#pragma endregion ���Ǳ����

#pragma region Ȧ¦����
	//������ ���� ����� 1~10
	//���� ���� �Ϻη� ȭ�鿡 ���
	//�޴��� 1.Ȧ 2.¦ 3.����
	// �� 5���� �����ϸ� ��� ����
	/*int iRound(0), iTemp(0), iChoice(0), iWin(0), iLose(0);
	while (5 != iRound)
	{
		system("cls");
		srand(unsigned(time(NULL)));
		iTemp = (rand() % 10) + 1;
		cout << "���� ���� : " << iTemp << endl;
		cout << "\t" << iRound + 1 << "���� �Դϴ�.\n" << "������ �Ͻÿ� 1. Ȧ   2. ¦   3. ����" << endl;
		cin >> iChoice;
		if (0 < iChoice && 4 > iChoice)
		{
			if (3 == iChoice)
			{
				cout << "�����մϴ�." << endl;
				break;
			}
			else
			{
				if (iTemp % 2 == iChoice % 2)
				{
					iWin++;
				}
				else
				{
					iLose++;
				}
			}
		}
		else
		{
			cout << "�߸��� �Է��Դϴ�." << endl;
			continue;
		}
		iRound++;
		system("pause");
	}
	cout << iWin << " ��" << "\t" << iLose << " ��" << endl;*/

#pragma endregion Ȧ¦����

#pragma region ���������� ����
	//������ ����Ͽ� ��ǻ��(0~2)�� �� 0.���� 1. ���� 2. �� 3. ����
	//���������� ���и� �����ϰ�
	//�� 5���� ���� ����� ��� ���� � ���� ���
	/*int iRound(0), iTemp(0), iChoice(0), iWin(0), iLose(0), iNot(0);
	while (5 != iRound)
	{
		system("cls");
	  srand(unsigned(time(NULL)));
		iTemp = rand() % 3; // �� ���������� ����
		switch (iTemp)
		{
		case 0:
			cout << "��ǻ�ʹ� �����Դϴ�.\n";
			break;
		case 1:
			cout << "��ǻ�ʹ� �����Դϴ�.\n";
			break;
		case 2:
			cout << "��ǻ�ʹ� ���Դϴ�.\n";
			break;
		default:
			cout << "����\n";
			break;
		}

		cout << "\t" << iRound + 1 << "���� �Դϴ�.\n�޴��� �����ϼ���.\t0. ����\t1. ����\t2. ��\t3. ����" << endl;
		cin >> iChoice;
		if (1 > iChoice / 3)
		{
			if (1 == (iChoice - iTemp) || -2 == (iChoice - iTemp))
			{
				iWin++;
			}
			else if (0 == (iChoice - iTemp))
			{
				iNot++;
			}
			else
			{
				iLose++;
			}
		}
		else if (3 == iChoice)
		{
			break;
		}
		else
		{
			cout << "�߸� �Է��ϼ̽��ϴ�." << endl;
			continue;
		}
		system("pause");
		iRound++;
	}

	cout << iWin << " ��\t" << iNot << " ��\t" << iLose << " ��\t"  << "������ �����մϴ�." << endl;*/

	
#pragma endregion ���������� ����
	return 0;
}

void MultiplicationTable()
{
	int iFirstNumber(0), iSecondNumber(0);
	int *pFirstNumber = &iFirstNumber, *pSecondNumber = &iSecondNumber;

	cout << "�� ���� ���Ͻʴϱ�? : ";
	cin >> *pFirstNumber;
	cout << "�� ���� ���Ͻʴϱ�? : ";
	cin >> *pSecondNumber;

	Calculate_Multiply(pFirstNumber, pSecondNumber);
	cout << *pFirstNumber << " <-�ٸ� ������ 1��ŭ ���� ù��° �Է��� ��" << endl;
	cout << *pSecondNumber << " <-�ٸ� ������ 2��ŭ ���� �ι�° �Է��� ��" << endl;
}
void Calculate_Multiply(int* _pFirstNumber, int* _pSecondNumber)
{
	for (int i = 2; i < *_pFirstNumber + 1; i++)
	{
		cout << "------- " << i << "�� -------" << endl;
		for (int j = 1; j < *_pSecondNumber + 1; j++)
		{
			cout << i << " x " << j << " = " << i * j << endl;
		}
	}

	*_pFirstNumber += 1;
	*_pSecondNumber += 2;
}
void DrinkMachine()
{
	int iMoney(0), iChoice(0);
	int* pMoney = &iMoney, * pChoice = &iChoice;
	cout << "������ �ݾ��� �Է��Ͻÿ� : " << endl;
	cin >> *pMoney;
	PickingDrink(iMoney, pChoice);
	cout << "�����" << endl;
}
void PickingDrink(int& _pMoney, int* _pChoice)
{
	
	while (100 < _pMoney)
	{
		system("cls");
		cout << "���� �ݾ� : " << _pMoney << "��" << endl;
		cout << "\t----�޴���----\n 1. �ݶ�(100��),  2. ���̴�(200��),  3. ȯŸ(300��),  4. ����" << endl;
		cin >> *_pChoice;
		if (4 == *_pChoice)
		{
			break;
		}
		else if (0 < *_pChoice && 4 > *_pChoice)
		{
			if (_pMoney < (*_pChoice * 100))
			{
				cout << "�����ݾ��� �����մϴ�." << endl;
				cout << "���� �ݾ� : " << _pMoney << endl;
			}
			else
			{
				_pMoney -= (*_pChoice * 100);
				cout << "���� �ݾ� : " << _pMoney << endl;
			}
			
		}
		else
		{
			cout << "�߸� �Է��߽��ϴ�." << endl;
		}
		system("pause");
	}
}
//