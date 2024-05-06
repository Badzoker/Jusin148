#include <iostream>

using namespace std;

void Recycle();
void Recycle(int a);
void Str();
int main()
{
	int iArray[5] = { 1,2,5,7,8 };
	int* pa = iArray + 2;
	int* pb = iArray;
	//
	///*cout << iArray << endl;
	//cout << *(iArray + 1) << endl;
	//cout << pa + 2 << endl;
	cout << pa[3]<< endl;
	cout << &iArray[4] << endl;
	//cout << *pb << endl;*/
	//cout << pa - pb << endl;
	int a = 'a';
	cout << a << endl;
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
void Str()
{
	//char str[] = "lion";
	//int a[][4] = { {1,1,1,1},{2,2,2,2},{3,3,3,0} };
	//int a[][] = { {1,1,1,1},{2,2,2,2},{3,3,3,0} };
	//int a[][4] = { 1,1,1,2,2,2,2,3,3,3 };
	//char a[][6] = { "apple", "pear", "banana" };
	//char a[][] = { "apple", "pear", "banana" };
	////char* ps[5] = { "king" , "football", "volleyball", "swimming", "golf"};
	// -----------------------------------------
	//|  10진수  |  8진수  |  16진수  |  2진수  |
	// -----------------------------------------
	//|          |         |          |  1011   |
	// -----------------------------------------
	//|    17    |         |          |         |
	// -----------------------------------------
	//|          |         |    1A    |         |
	// -----------------------------------------
	//|          |   101   |          |         |
	// -----------------------------------------
	//strcpy(str, "cat");
}