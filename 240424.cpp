#include <iostream>

using namespace std;

enum TEST
{
	INPUT,
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
	HW();
	return 0;
}

//숙제 구조체를 이용하여 세 명의 학생 성적 입출력 프로그램을 만들어라.
//1. 입력 2. 출력 3. 검색 4. 종료
//text rpg 만들기

void HW()
{
	STU tArray[3] = {};
	int iChoice(0), iStudent_Count(0);
	bool bCheck = true;
	iChoice = TEST();
	while (bCheck)
	{
		cout << "메뉴\n1. 입력 \t 2. 출력 \t 3. 검색 \t 4. 종료 \t";
		cin >> iChoice;
		switch (iChoice - 1)
		{
		case INPUT:
			HW_Input(tArray, &iStudent_Count);
			++iStudent_Count;
			//cout << "입력" << endl;
			break;
		case OUTPUT:
			HW_Output(tArray, &iStudent_Count);
			//cout << "출력" << endl;
			break;
		case SEARCH:
			HW_Search(tArray, &iStudent_Count);
			//cout << "검색" << endl;
			break;
		case EXIT:
			HW_Exit(&bCheck);
			//cout << "종료" << endl;
			break;
		default:
			cout << "다시 입력하시오" << endl;
			break;
		}
	}
	cout << "종료" << endl;
}

void HW_Input(STU _tArray[], int* _iStudent_Count)
{
	char szName1[16] = {};
	cout << "이름을 입력하시오 : "<< endl;
	cin >> _tArray[*_iStudent_Count].szName;
	/*cin >> szName1;
	for (int i = 0; szName1[i] != '\0'; i++)
	{
		cout << szName1[i] << "\t앗"<< endl;
	}*/
	
	cout << _tArray[*_iStudent_Count].szName[0] << _tArray[*_iStudent_Count].szName[1] << _tArray[*_iStudent_Count].szName[2] << "의 국어 점수 : " << endl;
	cin >> _tArray[*_iStudent_Count].iKor;
	cout << _tArray[*_iStudent_Count].szName[0] << _tArray[*_iStudent_Count].szName[1] << _tArray[*_iStudent_Count].szName[2] << "의 영어 점수 : " << endl;
	cin >> _tArray[*_iStudent_Count].iEng;
	cout << _tArray[*_iStudent_Count].szName[0] << _tArray[*_iStudent_Count].szName[1] << _tArray[*_iStudent_Count].szName[2] << "의 수학 점수 : " << endl;
	cin >> _tArray[*_iStudent_Count].iMath;
	_tArray[*_iStudent_Count].fAver = ((float)_tArray[*_iStudent_Count].iKor + (float)_tArray[*_iStudent_Count].iEng + (float)_tArray[*_iStudent_Count].iMath) / 3;
	cout << *_iStudent_Count + 1<< "번 학생 입력 완료"<< endl;
}

void HW_Output(STU _tArray[], int* _iStudent_Count)
{
	cout << "전 학생들의 성적표" << endl;
	for (int i = 0; i < *_iStudent_Count; i++)
	{
		cout << i + 1 << " 학생 성적표" << endl;
		for (int j = 0; j < 3; j++)
		{
			cout << _tArray[i].szName[j];
		}
		cout << "\t국어 성적 : " << _tArray[i].iKor << " 점\t영어 성적 :" << _tArray[i].iEng << " 점\t수학 성적 :" << _tArray[i].iMath << " 점\t평균 : "<< _tArray[i].fAver <<" 점\n\n";
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
			cout <<i + 1<< " 번과 같음" << endl;
			cout << "\t국어 성적 : " << _tArray[i].iKor << " 점\t영어 성적 :" << _tArray[i].iEng << " 점\t수학 성적 :" << _tArray[i].iMath << " 점\t평균 : " << _tArray[i].fAver << " 점\n\n";
			break;
		}
	}
	
}

void HW_Exit(bool* _bCheck)
{
	*_bCheck = false;
}