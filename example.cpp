#include <iostream>

using namespace std;

void Recycle();
void Recycle(int a);

int main()
{
	int iArray[5] = { 1,2,5,7,8 };
	int* pa = iArray + 19;
	int* pb = iArray;
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