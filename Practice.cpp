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

	cout << "국어 점수는?";
	cin >> iKor;

	cout << "수학 점수는?";
	cin >> iMath;

	iTot = iKor + iMath;
	cout << "총점은?" << iTot;

	fAvg = iTot / 2.f;
	cout << "평균은?" << fAvg;



}