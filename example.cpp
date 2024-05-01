#include <iostream>

using namespace std;

void Recycle();
void Recycle(int a);

void Function(int a);

void Example();

int main()
{
	//int x = 1;
	//Function(x);
	int iArray[5] = { 1,2,5,7,8 };
	int* pa = iArray + 2;
	int* pb = iArray;
	//
	cout << iArray << endl;
	cout << *(iArray + 1) << endl;
	cout << pa + 2 << endl;
	//cout << pa[3] << endl;
	cout << *pb << endl;
	cout << pa - pb << endl;
	cout << pa[1] << endl;
	cout << pa[-2] << endl;
	//cout << *(pa + 3) << endl;
	cout << *(++pa) << endl;
	//cout << iArray[5] << endl;
	//cout << iArray++ << endl;
	Example();
}

void Example()
{
	int hour, min, sec;
	float time = 3.76f;

	hour = (int)time;
	time = time - hour;
	time = time * 60.0f;

	min = (int)time;
	time = time - min;
	time = time * 60.0f;

	sec = (int)time;
	
	cout << hour << "½Ã " << min << "ºÐ " << sec << "ÃÊ";
}
void Function(int a)
{
	cout << ++a << a++ << --a << endl;
}
void Recycle()
{
	cout << "Recycle" << endl;
	Recycle();
}
void Recycle(int a)
{
	if (a > 0)
	{
		cout << "Recycle" << endl;
		--a;
		Recycle(a);
	}
}