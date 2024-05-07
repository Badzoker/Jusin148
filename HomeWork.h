#pragma once
#include "HomeStudent.h"
class HomeWork
{
private:
	int m_iCurrentCount = 0;
	int m_iMaxCount = 0;
public:
	void Set_Count();
	void Set_Array(HomeStudent _cMax[], HomeStudent _cDst[]); // 동적할당 부분
	void Copy_Array(HomeStudent _cStu[], HomeStudent _cMax[], HomeStudent _cDst[]); // 기존과 신규
	void Printing_Grade(HomeStudent _cMax[]); // 출력
	void Set_StudentInfo(HomeStudent _cStu[], HomeStudent _cMax[], HomeStudent _cDst[]); // 입력
	void Menu();
	void Free();
};

