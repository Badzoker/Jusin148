#pragma once
#include "HomeStudent.h"
class HomeWork
{
private:
	int m_iCurrentCount = 0;
	int m_iMaxCount = 0;
public:
	void Set_Count();
	void Set_Array(HomeStudent _cMax[], HomeStudent _cDst[]); // �����Ҵ� �κ�
	void Copy_Array(HomeStudent _cStu[], HomeStudent _cMax[], HomeStudent _cDst[]); // ������ �ű�
	void Printing_Grade(HomeStudent _cMax[]); // ���
	void Set_StudentInfo(HomeStudent _cStu[], HomeStudent _cMax[], HomeStudent _cDst[]); // �Է�
	void Menu();
	void Free();
};

