#include <iostream>

using namespace std;

void Recycle();
void Recycle(int a);

int main()
{
	Recycle();
	//Recycle(3);
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