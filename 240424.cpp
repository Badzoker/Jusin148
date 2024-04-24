#include <iostream>

using namespace std;

enum TEST
{
	INPUT = 100,
	OUTPUT,
	SEARCH,
	EXIT
};

typedef struct tStudent
{
	char szName[32];
	int iKor, iEng, iMath;
	float fAver;
}STU, *PSTU;

void HW();
void HW_Input(STU _tArray[], int* _iStudent_Count);
void HW_Output(STU _tArray[], int* _iStudent_Count);
void HW_Search(STU _tArray[], int* _iStudent_Count);
void HW_Exit(bool* _bCheck);

int main()
{
	//HW();
	cout << TEST(0);
	return 0;
}

//���� ����ü�� �̿��Ͽ� �� ���� �л� ���� ����� ���α׷��� ������.
//1. �Է� 2. ��� 3. �˻� 4. ����
//text rpg �����

void HW()
{
	STU tArray[3] = {};
	int iChoice(0), iStudent_Count(0);
	bool bCheck = true;
	iChoice = TEST();
	while (bCheck)
	{
		cout << "�޴�\n1. �Է� \t 2. ��� \t 3. �˻� \t 4. ���� \t";
		cin >> iChoice;
		switch (iChoice - 1)
		{
		case INPUT:
			HW_Input(tArray, &iStudent_Count);
			++iStudent_Count;
			//cout << "�Է�" << endl;
			break;
		case OUTPUT:
			HW_Output(tArray, &iStudent_Count);
			//cout << "���" << endl;
			break;
		case SEARCH:
			HW_Search(tArray, &iStudent_Count);
			//cout << "�˻�" << endl;
			break;
		case EXIT:
			HW_Exit(&bCheck);
			//cout << "����" << endl;
			break;
		default:
			cout << "�ٽ� �Է��Ͻÿ�" << endl;
			break;
		}
	}
	cout << "����" << endl;
}

void HW_Input(STU _tArray[], int* _iStudent_Count)
{
	char szName1[16] = {};
	cout << "�̸��� �Է��Ͻÿ� : "<< endl;
	cin >> _tArray[*_iStudent_Count].szName;
	/*cin >> szName1;
	for (int i = 0; szName1[i] != '\0'; i++)
	{
		cout << szName1[i] << "\t��"<< endl;
	}*/
	
	cout << _tArray[*_iStudent_Count].szName[0] << _tArray[*_iStudent_Count].szName[1] << _tArray[*_iStudent_Count].szName[2] << "�� ���� ���� : " << endl;
	cin >> _tArray[*_iStudent_Count].iKor;
	cout << _tArray[*_iStudent_Count].szName[0] << _tArray[*_iStudent_Count].szName[1] << _tArray[*_iStudent_Count].szName[2] << "�� ���� ���� : " << endl;
	cin >> _tArray[*_iStudent_Count].iEng;
	cout << _tArray[*_iStudent_Count].szName[0] << _tArray[*_iStudent_Count].szName[1] << _tArray[*_iStudent_Count].szName[2] << "�� ���� ���� : " << endl;
	cin >> _tArray[*_iStudent_Count].iMath;
	_tArray[*_iStudent_Count].fAver = ((float)_tArray[*_iStudent_Count].iKor + (float)_tArray[*_iStudent_Count].iEng + (float)_tArray[*_iStudent_Count].iMath) / 3;
	cout << *_iStudent_Count + 1<< "�� �л� �Է� �Ϸ�"<< endl;
}

void HW_Output(STU _tArray[], int* _iStudent_Count)
{
	cout << "�� �л����� ����ǥ" << endl;
	for (int i = 0; i < *_iStudent_Count; i++)
	{
		cout << i + 1 << " �л� ����ǥ" << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << _tArray[i].szName[j];
		}
		cout << "\t���� ���� : " << _tArray[i].iKor << " ��\t���� ���� :" << _tArray[i].iEng << " ��\t���� ���� :" << _tArray[i].iMath << " ��\t��� : "<< _tArray[i].fAver <<" ��\n\n";
	}
}

void HW_Search(STU _tArray[], int* _iStudent_Count)
{
	char szName[32] = {};
	cin >> szName;
	for (int i = 0; i < *_iStudent_Count; i++)
	{
		if (!strcmp(_tArray[i].szName, szName))
		{
			cout <<i + 1<< " ���� ����" << endl;
			cout << "\t���� ���� : " << _tArray[i].iKor << " ��\t���� ���� :" << _tArray[i].iEng << " ��\t���� ���� :" << _tArray[i].iMath << " ��\t��� : " << _tArray[i].fAver << " ��\n\n";
			break;
		}
	}
	
}

void HW_Exit(bool* _bCheck)
{
	*_bCheck = false;
}