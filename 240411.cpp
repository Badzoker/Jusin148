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
	
    //if��
	#pragma region if��
	
	#pragma endregion
	#pragma region switch��
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
	//1. ����ǥ ���α׷��� ���� ��޸ű��
	//	- ��� ������ �̿��Ͽ� ���� ����� �ο��϶�
	//
	//	90�� �̻��̸� A
	//	80�� �̻��̸� B
	//	70�� �̻��̸� C
	//	60�� �̻��̸� D
	//  �������� F
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
	
	cout << "���������� �Է��Ͻÿ� : ";
	cin >> *pKor;
	//cout << pKor << endl;
	//cout << *pKor << endl;
	//cout << iKor << endl;
	cout << "���������� �Է��Ͻÿ� : ";
	cin >> *pEng;

	cout << "���������� �Է��Ͻÿ� : ";
	cin >> *pMath;

	*pTotal = *pKor + *pEng + *pMath;

	cout << "���� : " << *pKor << ", ���� : " << *pEng << ", ���� : " << *pMath << endl;

	cout << "������ : " << *pTotal << ", ����� : " << /*fTotal * 0.333f*/*pTotal / 3 << endl;
	*pResult = (int)*pTotal / 30;
	cout << "�̻���� ����� : ";

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