#include <iostream> 
#include <ctime>

using namespace std;

#pragma region ���Ǳ�����Լ�ȭ


void Menu(int _Money);
void Choice(int _Choice);
int Cal(int _Money, int _Choice);
void Remain(int _Money);
void TheEnd();

int main()
{
	
#pragma region ���������
	/*srand(unsigned(time(NULL)));

	for (int j = 0; j < 25; j++)
	{
		int iTemp = rand() % 10 + 1;
		cout << iTemp << "\n";
	}*/
#pragma endregion ���������

	//���� -> �ִ��� ���� �Լ��� ��������
	int iMoney(0), iChoice(0);
	cout << "�ݾ��� �Է��Ͻÿ� : \n";
	cin >> iMoney;

	while (iMoney > 0)
	{
		Menu(iMoney);
		cin >> iChoice;
		if (4 == iChoice)
		{
			break;
		}
		else if (4 < iChoice || 1 > iChoice)
		{
			continue;
		}
		iMoney = Cal(iMoney, iChoice);
		Remain(iMoney);
	}
	TheEnd();

	return 0;
}

void Menu(int _Money)
{
	system("cls");
	cout << "���� �ݾ� : " << _Money << " �� \n";
	cout << "�޴� : 1. �ݶ�(100��)  2.���̴�(200��)  3.ȯŸ(300��)  4.����\n";
}
void Choice(int _Choice)
{
	if (4 < _Choice || 1 > _Choice)
	{
		cout << "�߸� �Է��ϼ̽��ϴ�.\n";
	}
	else
	{
		cout << _Choice << "���� �Է��ϼ̽��ϴ�.\n";
	}
}
int Cal(int _Money, int _Choice)
{
	if (_Money < _Choice * 100)
	{
		cout << "�������� �����մϴ�.\n";
		return _Money;
	}
	else
	{
		return _Money - (_Choice * 100);
	}
}

void Remain(int _Money)
{
	cout << "���� �ݾ��� " << _Money << " �� ���ҽ��ϴ�.\n";
	system("pause");

}

void TheEnd()
{
	cout << "��\n";
}
#pragma endregion ���Ǳ�����Լ�ȭ
