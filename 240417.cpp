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

#pragma region 개인활동

int Get_FirstAnswer(int _firstNumber, int _secondNumber)
{
	cout << "----참조된 값을 매개변수로 넣었을때----" << endl;
	cout << &_firstNumber << "\t" << &_secondNumber << endl;
	return _firstNumber / _secondNumber;
}
int Get_SecondAnswer(int _firstNumber, int _secondNumber)
{
	cout << "----참조된 값을 매개변수로 넣었을때----" << endl;
	cout << &_firstNumber << "\t" << &_secondNumber << endl;
	return _firstNumber % _secondNumber;
}
int Get_FirstAnswer2(int* _pfirstNumber, int* _psecondNumber)
{
	cout << "----포인터의 주소를 매개변수로 넣었을때----" << endl;
	cout << _pfirstNumber << "\t" << _psecondNumber << endl;
	return *_pfirstNumber / *_psecondNumber;
}
int Get_SecondAnswer2(int* _pfirstNumber, int* _psecondNumber)
{
	cout << "----포인터의 주소를 매개변수로 넣었을때----" << endl;
	cout << _pfirstNumber << "\t" << _psecondNumber << endl;
	return *_pfirstNumber % *_psecondNumber;
}
void Matrix()
{
	cout << "숫자를 입력하시오\n";
	int iTemp(0), iSour(0);
	int* pTemp = &iTemp, *pSour = &iSour;
	cin >> iTemp;
	cout << "행렬을 맞출 숫자를 입력하시오\n";
	cin >> iSour;
	cout << "( " << Get_FirstAnswer(*pSour, *pTemp) << " , " << Get_SecondAnswer(*pSour, *pTemp) << " )\n";
	cout << "( " << Get_FirstAnswer2(pSour, pTemp) << " , " << Get_SecondAnswer2(pSour, pTemp) << " )\n";
	cout << "----변수들의 주소----" << endl;
	cout << pSour << "\t" << pTemp << endl;
}

#pragma endregion 개인활동

#pragma region 5팩토리얼재귀함수과제

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
	cout << "숫자를 입력하시오 : ";
	cin >> iAnswer;
	return iAnswer;
}

#pragma endregion 5팩토리얼재귀함수과제

#pragma region 피보나치

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

#pragma endregion 피보나치