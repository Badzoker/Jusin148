#include <iostream>

using namespace std;

void Grade();

int main()
{
#pragma region 240411
	//ex
	//int iTemp(0), iSrc(2);
	//if ((iTemp < iSrc) && (iTemp = 999))
	//{
	//	cout << iTemp << endl;
	//}

#pragma endregion

#pragma region HW
	
	Grade();
	
    //if문
	#pragma region if문
	
	#pragma endregion
	#pragma region switch문
	//switch(iResult)
	//{
	//	case 10:
	//	case 9:
	//		cout << cTemp << endl;
	//		break;
	//	case 8:
	//		cout << cSour << endl;
	//		break;
	//	case 7:
	//		cout << cDest << endl;
	//		break;
	//	case 6:
	//		cout << cResult << endl;
	//		break;
	//	default:
	//		cout << cFail << endl;
	//		break;
	//}
	#pragma endregion
#pragma endregion
	return 0;
}


void Grade()
{
	//1. 성적표 프로그램에 성적 등급매기기
	//	- 평균 점수를 이용하여 성적 등급을 부여하라
	//
	//	90점 이상이면 A
	//	80점 이상이면 B
	//	70점 이상이면 C
	//	60점 이상이면 D
	//  나머지는 F
	int iKor(0), iEng(0), iMath(0), iResult(0);
	int *pKor(nullptr), *pEng(nullptr), *pMath(nullptr), *pResult(nullptr);

	pKor = &iKor;
	pEng = &iEng;
	pMath = &iMath;
	pResult = &iResult;

	char cAgrade('A'), cBgrade('B'), cCgrade('C'), cDgrade('D'), cFail('F');
	char* pAgrade(nullptr), * pBgrade(nullptr), * pCgrade(nullptr), * pDgrade(nullptr), * pFail(nullptr);

	pAgrade = &cAgrade;
	pBgrade = &cBgrade;
	pCgrade = &cCgrade;
	pDgrade = &cDgrade;
	pFail = &cFail;

	float fTotal(0);
	float* pTotal(nullptr);

	pTotal = &fTotal;
	
	cout << "국어점수를 입력하시오 : ";
	cin >> *pKor;
	//cout << pKor << endl;
	//cout << *pKor << endl;
	//cout << iKor << endl;
	cout << "영어점수를 입력하시오 : ";
	cin >> *pEng;

	cout << "수학점수를 입력하시오 : ";
	cin >> *pMath;

	*pTotal = *pKor + *pEng + *pMath;

	cout << "국어 : " << *pKor << ", 영어 : " << *pEng << ", 수학 : " << *pMath << endl;

	cout << "총점은 : " << *pTotal << ", 평균은 : " << /*fTotal * 0.333f*/*pTotal / 3 << endl;
	*pResult = (int)*pTotal / 30;
	cout << "이사람의 등급은 : ";

	if (*pResult>= 9)
	{
		cout << *pAgrade << endl;
	}
	else if (*pResult >= 8)
	{
		cout << *pBgrade << endl;
	}
	else if (*pResult >= 7)
	{
		cout << *pCgrade << endl;
	}
	else if (*pResult >= 6)
	{
		cout << *pDgrade << endl;
	}
	else
	{
		cout << *pFail << endl;
	}
}