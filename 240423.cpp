#include <iostream>

using namespace std;

void Length();
void Flip(char _cArray[], int _iSize);
void Extra();
void Infinity();

int main()
{
	//char szArray[4] = { 's','b','c'};
	//cout << szArray << endl;
	//Length();
	//Extra();
	Infinity();
	return 0;
}
//����
//1. ���ڿ��� �Է¹ް� NULL ���ڸ� ������ ������ ���ڿ��� ���̸� ���ϴ� �Լ��� �����Ͻÿ�
//2. ���ڿ��� �Է¹����� ����� ����ؿ���
//extra. (char)���ڸ� �Է¹ް� int�� �־ int�� ��� int char����1

void Length()
{
	char szArray[32] = {}, szChange[32] = {};
	int iTemp(0), iSize = sizeof(szArray)/sizeof(char);
	cout << sizeof(szArray) / sizeof(char) << " ���� ������ �Է��Ͻÿ�" << endl;
	cin >> szArray;
	for (int i = 0; i < sizeof(szArray) / sizeof(char); i++)
	{
		
		if (szArray[i] != NULL)
		{
			iTemp++;
			//cout << szArray[i] << endl;
		}
	}
	cout << iTemp << "<-- ���ڼ�" << endl;
	/*const char* pName = "jusin";
	strcpy_s(szArray, 5, pName);
	iTemp = 0;

	for (int i = 0; i < sizeof(szArray) / sizeof(char); i++)
	{
		if (szArray[i] != '\0')
		{
			cout << szArray[i] << endl;
			iTemp++;
		}
	}
	cout << iTemp << "<-- ��ģ ���� ���ڼ�" << endl;*/
	Flip(szArray, iTemp);
}

void Flip(char _cArray[], int _iSize)
{
	char szChange[32] = {};
	for (int i = 0; i < _iSize; i++)
	{
		if (_cArray[i] != '\0')
		{
			szChange[i] = _cArray[_iSize - i - 1];
		}
	}
	for (int i = 0; i < sizeof(szChange) / sizeof(char); i++)
	{
		if (szChange[i] != '\0')
		{
			cout << szChange[i] << endl;
		}
	}
	cout << szChange << " <- ������ ����";
}

#pragma region ����Ȱ��

void Extra()
{

	char cTemp = '125';
	int iTemp = cTemp;
	//0  1  2  3  4  5  6  7  8  9
	//48 49 50 51 52 53 54 55 56 57 
	int iCount(0), iDst(0), iSrc(0);
	//cout << iTemp - 48; //���� 48 -> '0'

	char cArray[96] = {};
	cout << "���ڸ� �Է��Ͻÿ�(96�ڸ�����) : ";
	cin >> cArray;

	int iArray[96] = {};
	for (int i = 0; i < sizeof(cArray) / sizeof(char); i++)
	{
		if (cArray[i] == NULL)
		{
			break;
		}
		iArray[i] = cArray[i];
		iArray[i] -= '0';
		iCount++;
	}
	
	for (int i = 0; i < iCount; i++)
	{
		iSrc = 1;
		for (int j = 0; j < iCount - i - 1; j++)
		{
			iSrc *= 10;
		}
		iArray[i] = iArray[i] * iSrc;
		cout << iArray[i] << endl;
		iDst += iArray[i];
	}
	cout << iDst;
}

void Infinity()
{
	char a[32] = {'2','3'}, b[32] = {'2','3'};
	int iCount(0), iTemp(0);
	for (int i = 0; a[i] != '\0'; i++)
	{
		iCount++;
	}
	for (int i = 0; i < iCount; i++)
	{
		iTemp += strcmp(a, b);
	}
	cout << iTemp;

}

#pragma endregion