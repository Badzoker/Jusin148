#include <iostream>
#include <bitset>
using namespace std;

void Test();

int main()
{
#pragma region 240409
	//int iTemp(-9);
	//cout << bitset<8>(iTemp) << endl;
	//cout << bitset<8>(iTemp >> 2) << endl; // iTemp 에 2^2을 곱한 값
	//cout << bitset<8>(iTemp >> 3) << endl; // iTemp 에 2^3을 나눈 값
#pragma endregion 240409
#pragma region HW
//20~30 -> 이진법화 -> 10진법화
#pragma endregion
	Test();
	return 0;
}

void Test()
{
	int iTemp(8), iDst(24);
	cout << iTemp << endl;

	cout << bitset<8>(iTemp) << endl;
	cout << "------------" << endl;

	cout << bitset<8>(iDst) << endl;

	cout << "------------" << endl;
	cout << bitset<8>(iDst&iTemp) << endl;

	cout << "------------" << endl;
	cout << bitset<8>(iDst|iTemp) << endl;

	cout << "------------" << endl;
	cout << bitset<8>(iDst^iTemp) << endl;

	cout << "------------" << endl;
	cout << bitset<8>(~iTemp) << endl;

	cout << "------------" << endl;
	cout << bitset<8>(~iDst) << endl;
}