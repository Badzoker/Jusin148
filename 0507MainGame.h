#pragma once
#include "0507Student.h"
class CMainGame
{
private:
	int m_iCurrentCount = 0;
	int m_iMaxCount = 0;
public:
	void Set_Count(CStudent _cMax[]);
	void Set_Array(CStudent _cMax[]); // 동적할당 부분
	void Copy_Array(CStudent _cStu[], CStudent _cMax[]); // 기존과 신규
	void Printing_Grade(CStudent _cMax[]); // 출력
	void Set_StudentInfo(CStudent _cStu[], CStudent _cMax[]); // 입력
	void Menu();
	void Free();
};
