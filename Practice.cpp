#include <iostream>

using namespace std;

void Pyo();

int main()

{
	Pyo();
	return 0;
}

void Pyo()
{
	int iKor, iMath;
	int iTot;
	float fAvg;

	cout << "���� ������?";
	cin >> iKor;

	cout << "���� ������?";
	cin >> iMath;

	iTot = iKor + iMath;
	cout << "������?" << iTot;

	fAvg = iTot / 2.f;
	cout << "�����?" << fAvg;



}