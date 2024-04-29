#include <iostream>

using namespace std;

void Recycle();
void Recycle(int a);

int main()
{
	int a = 100;
	bool b = true;
	bool b2 = false;
	cout << (char)a<< endl;
	cout << (int)(char)a << endl;
	cout << (char)b << endl;
	cout << (char)b2 << endl;
	cout << (bool)(char)b << endl;
	cout << (bool)(char)b2 << endl;
	//int iArray[5] = { 1,2,5,7,8 };
	//int* pa = iArray + 19;
	//int* pb = iArray;
	//
	///*cout << iArray << endl;
	//cout << *(iArray + 1) << endl;
	//cout << pa + 2 << endl;
	//cout << pa[3] << endl;
	//cout << *pb << endl;*/
	//cout << pa - pb << endl;
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