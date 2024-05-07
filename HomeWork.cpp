#include "HomeWork.h"
#include "HomeStudent.h"
#include <iostream>



void HomeWork::Copy_Array(HomeStudent _cStu[], HomeStudent _cMax[], HomeStudent _cDst[])// 신규와 기존
{
	HomeStudent* cTemp = new HomeStudent[m_iMaxCount - m_iCurrentCount];
	for (int i = 0; i < m_iMaxCount - m_iCurrentCount; i++)
	{
		cTemp[i].Set_Name(_cMax[i].Get_Name());
		cTemp[i].Set_Kor(_cMax[i].Get_Kor());
		cTemp[i].Set_Eng(_cMax[i].Get_Eng());
		cTemp[i].Set_Math(_cMax[i].Get_Math());
		cTemp[i].Set_Total(_cMax[i].Get_Total());
	}
	delete[] _cMax;
	_cMax = nullptr;
	_cMax = new HomeStudent[m_iMaxCount];
	for (int i = 0; i < m_iMaxCount - m_iCurrentCount; i++)
	{
		_cMax[i].Set_Name(cTemp[i].Get_Name());
		_cMax[i].Set_Kor(cTemp[i].Get_Kor());
		_cMax[i].Set_Eng(cTemp[i].Get_Eng());
		_cMax[i].Set_Math(cTemp[i].Get_Math());
		_cMax[i].Set_Total(cTemp[i].Get_Total());
	}
	if (nullptr != cTemp)
	{
		delete[] cTemp;
		cTemp = nullptr;
	}

	for (int i = 0; i < m_iCurrentCount; i++)
	{
		_cMax[m_iMaxCount - m_iCurrentCount + i].Set_Name(_cStu[i].Get_Name());
		_cMax[m_iMaxCount - m_iCurrentCount + i].Set_Kor(_cStu[i].Get_Kor());
		_cMax[m_iMaxCount - m_iCurrentCount + i].Set_Eng(_cStu[i].Get_Eng());
		_cMax[m_iMaxCount - m_iCurrentCount + i].Set_Math(_cStu[i].Get_Math());
		_cMax[m_iMaxCount - m_iCurrentCount + i].Set_Total(_cStu[i].Get_Total());
	}
	//pStu = cStu_Max;
}
void HomeWork::Set_StudentInfo(HomeStudent _cStu[], HomeStudent _cMax[], HomeStudent _cDst[])// 입력
{
	char szTemp[32] = {};
	int iInput(0);
	for (int i = 0; i < m_iCurrentCount; i++)
	{
		system("cls");
		std::cout << "학생 이름을 입력하시오 : " << std::endl;
		std::cin >> szTemp;
		_cStu[i].Set_Name(szTemp);

		std::cout << "국어점수를 입력하시오 :" << std::endl;
		std::cin >> iInput;
		_cStu[i].Set_Kor(iInput);

		std::cout << "영어점수를 입력하시오 :" << std::endl;
		std::cin >> iInput;
		_cStu[i].Set_Eng(iInput);

		std::cout << "수학점수를 입력하시오 :" << std::endl;
		std::cin >> iInput;
		_cStu[i].Set_Math(iInput);
		_cStu[i].Set_Total(_cStu[i].Cal_Total());
	}
	std::cout << "입력완료" << std::endl;
	Copy_Array(_cStu, _cMax, _cDst);
	system("pause");
}

void HomeWork::Set_Array(HomeStudent _cMax[], HomeStudent _cDst[])// 동적할당 부분
{
	HomeStudent* cStu = new HomeStudent[m_iCurrentCount];

	Set_StudentInfo(cStu, _cMax, _cDst);
	delete[] cStu;
	cStu = nullptr;
}

void HomeWork::Set_Count() // 숫자 입력 및 증가
{
	int iInput(0);
	std::cout << "학생 수를 입력하시오." << std::endl;
	std::cin >> iInput;
	m_iCurrentCount = iInput;
	m_iMaxCount += m_iCurrentCount;
}
void HomeWork::Printing_Grade(HomeStudent _cMax[])// 출력
{
	system("cls");
	std::cout << "학생이름\t국어점수\t영어점수\t수학점수" << std::endl;
	for (int i = 0; i < m_iMaxCount; i++)
	{
		if (_cMax[i].Get_Eng() != 0 || _cMax[i].Get_Eng() != NULL)
		{
			std::cout << i + 1 << "번째 학생" << std::endl;
			std::cout << _cMax[i].Get_Name() << "\t" << _cMax[i].Get_Kor() << "\t" << _cMax[i].Get_Eng() << "\t" << _cMax[i].Get_Math() << std::endl;
		}
	}
	std::cout << "출력완료" << std::endl;
	system("pause");
}


void HomeWork::Free()
{
	/*if (m_CArray != nullptr)
	{
		delete[] m_CArray;
		m_CArray = nullptr;
	}*/
}

void HomeWork::Menu()
{
	int iInput(0);
	HomeStudent* cArray = new HomeStudent[5]; //max
	HomeStudent* cDst = new HomeStudent[5]; //dst
	while (true)
	{
		system("cls");
		std::cout << "메뉴\n1. 학생입력\t2. 성적출력\t3. 종료" << std::endl;
		std::cin >> iInput;
		switch (iInput)
		{
		case 1:
			Set_Count();
			//cArray = new HomeStudent[m_iMaxCount];
			Set_Array(cArray, cDst);
			break;
		case 2:
			Printing_Grade(cArray);
			break;
		case 3:
			if (cArray != nullptr)
			{
				delete[] cArray;
				cArray = nullptr;
			}
			return;
		default:
			break;
		}
	}
	
}