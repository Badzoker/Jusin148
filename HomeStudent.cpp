#include "HomeStudent.h"
#include <iostream>

char* HomeStudent::Get_Name()
{
	return m_szName;
}


void HomeStudent::Set_Name(char _szName[])
{
	strcpy_s(m_szName, sizeof(m_szName), _szName);
}

int HomeStudent::Get_Kor()
{
	return m_iKor;
}

void HomeStudent::Set_Kor(int _iKor)
{
	m_iKor = _iKor;
}

int HomeStudent::Get_Eng()
{
	return m_iEng;
}

void HomeStudent::Set_Eng(int _iEng)
{
	m_iEng = _iEng;
}

int HomeStudent::Get_Math()
{
	return m_iMath;
}

void HomeStudent::Set_Math(int _iMath)
{
	m_iMath = _iMath;
}

float HomeStudent::Get_Total()
{
	return m_fTotal;
}

float HomeStudent::Cal_Total()
{
	return float((m_iKor + m_iEng + m_iMath) / 3);
}

void HomeStudent::Set_Total(float _fTotal)
{
	m_fTotal = _fTotal;
}