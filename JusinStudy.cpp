// JusinStudy.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

//using namespace std;

//권장하는 문법
using std::cout;
using std::endl;
using std::cin;

int main()
{
    int iTmp = 10;
    int* pTmp;
    pTmp = &iTmp;
    cout << *pTmp;
    *&pTmp;
#pragma region class 0408
    ///*std::*/cout << "이종한!\n";

    //int iKorean(0), iMath(0), iEnglish(0);

    //cout << "숫자를 입력하시오 : ";

    //cin >> iNumber >> iNumber2;

    //국어 영어 수학 점수를 입력받고 총점 및 평균을 표시하시오.
#pragma endregion
    return 0;
}
