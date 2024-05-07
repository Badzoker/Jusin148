#include "0507Student.h"
#include <iostream>



char* CStudent::Get_Name()
{
	return m_szName;
}


void CStudent::Set_Name(char _szName[])
{
	strcpy_s(m_szName, sizeof(m_szName), _szName);
}

int CStudent::Get_Kor()
{
	return m_iKor;
}

void CStudent::Set_Kor(int _iKor)
{
	m_iKor = _iKor;
}

int CStudent::Get_Eng()
{
	return m_iEng;
}

void CStudent::Set_Eng(int _iEng)
{
	m_iEng = _iEng;
}

int CStudent::Get_Math()
{
	return m_iMath;
}

void CStudent::Set_Math(int _iMath)
{
	m_iMath = _iMath;
}

float CStudent::Get_Total()
{
	return m_fTotal;
}

float CStudent::Cal_Total()
{
	return float((m_iKor + m_iEng + m_iMath) / 3);
}

void CStudent::Set_Total(float _fTotal)
{
	m_fTotal = _fTotal;
}
