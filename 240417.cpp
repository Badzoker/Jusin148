#include <iostream>

using namespace std;

int Get_FirstAnswer(int _firstNumber, int _secondNumber);
int Get_SecondAnswer(int _firstNumber, int _secondNumber);
int Get_FirstAnswer2(int* _pfirstNumber, int* _psecondNumber);
int Get_SecondAnswer2(int* _pfirstNumber, int* _psecondNumber);
int iAnswer(0);
void Factorial(int _Insert_Number);
int Insert_Number();
void Matrix();
int Calculate_Fibonacci(int _Insert_Number);

int main()
{
	int iTmp(0);
	int* pTmp = &iTmp;
	cout << *&iTmp << "\t" << pTmp << "\t" << &pTmp;
	//Factorial(Insert_Number());
	//Matrix();
	//cout << Calculate_Fibonacci(6);
	return 0;
}

#pragma region ����Ȱ��

int Get_FirstAnswer(int _firstNumber, int _secondNumber)
{
	cout << "----������ ���� �Ű������� �־�����----" << endl;
	cout << &_firstNumber << "\t" << &_secondNumber << endl;
	return _firstNumber / _secondNumber;
}
int Get_SecondAnswer(int _firstNumber, int _secondNumber)
{
	cout << "----������ ���� �Ű������� �־�����----" << endl;
	cout << &_firstNumber << "\t" << &_secondNumber << endl;
	return _firstNumber % _secondNumber;
}
int Get_FirstAnswer2(int* _pfirstNumber, int* _psecondNumber)
{
	cout << "----�������� �ּҸ� �Ű������� �־�����----" << endl;
	cout << _pfirstNumber << "\t" << _psecondNumber << endl;
	return *_pfirstNumber / *_psecondNumber;
}
int Get_SecondAnswer2(int* _pfirstNumber, int* _psecondNumber)
{
	cout << "----�������� �ּҸ� �Ű������� �־�����----" << endl;
	cout << _pfirstNumber << "\t" << _psecondNumber << endl;
	return *_pfirstNumber % *_psecondNumber;
}
void Matrix()
{
	cout << "���ڸ� �Է��Ͻÿ�\n";
	int iTemp(0), iSour(0);
	int* pTemp = &iTemp, *pSour = &iSour;
	cin >> iTemp;
	cout << "����� ���� ���ڸ� �Է��Ͻÿ�\n";
	cin >> iSour;
	cout << "( " << Get_FirstAnswer(*pSour, *pTemp) << " , " << Get_SecondAnswer(*pSour, *pTemp) << " )\n";
	cout << "( " << Get_FirstAnswer2(pSour, pTemp) << " , " << Get_SecondAnswer2(pSour, pTemp) << " )\n";
	cout << "----�������� �ּ�----" << endl;
	cout << pSour << "\t" << pTemp << endl;
}

#pragma endregion ����Ȱ��

#pragma region 5���丮������Լ�����

void Factorial(int _Insert_Number)
{
	if (_Insert_Number > 1)
	{
		cout << _Insert_Number << " * ";
		--_Insert_Number;
		iAnswer *= _Insert_Number;

		Factorial(_Insert_Number);
	}
	else
	{
		cout << _Insert_Number << " = " << iAnswer;
	}
}
int Insert_Number()
{
	cout << "���ڸ� �Է��Ͻÿ� : ";
	cin >> iAnswer;
	return iAnswer;
}

#pragma endregion 5���丮������Լ�����

#pragma region �Ǻ���ġ

int Calculate_Fibonacci(int _Insert_Number)
{
	int iTemp(0);
	if (4 > _Insert_Number)
	{
		iTemp = _Insert_Number;
	}
	else if (4 <= _Insert_Number)
	{
		iTemp = Calculate_Fibonacci(_Insert_Number - 1) + Calculate_Fibonacci(_Insert_Number - 2);
	}
	return iTemp;
}

#pragma endregion �Ǻ���ġ