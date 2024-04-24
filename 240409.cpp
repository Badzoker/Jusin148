#include <iostream>
#include <bitset>
using namespace std;

void Test();

int main()
{
#pragma region 240409
	//int iTemp(-9);
	//cout << bitset<8>(iTemp) << endl;
	//cout << bitset<8>(iTemp >> 2) << endl; // iTemp �� 2^2�� ���� ��
	//cout << bitset<8>(iTemp >> 3) << endl; // iTemp �� 2^3�� ���� ��
#pragma endregion 240409
#pragma region HW
//20~30 -> ������ȭ -> 10����ȭ
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