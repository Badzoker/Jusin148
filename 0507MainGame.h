#pragma once
#include "0507Student.h"
class CMainGame
{
private:
	int m_iCurrentCount = 0;
	int m_iMaxCount = 0;
public:
	void Set_Count(CStudent _cMax[]);
	void Set_Array(CStudent _cMax[]); // �����Ҵ� �κ�
	void Copy_Array(CStudent _cStu[], CStudent _cMax[]); // ������ �ű�
	void Printing_Grade(CStudent _cMax[]); // ���
	void Set_StudentInfo(CStudent _cStu[], CStudent _cMax[]); // �Է�
	void Menu();
	void Free();
};
