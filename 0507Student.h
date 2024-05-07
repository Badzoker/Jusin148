#pragma once

class CStudent
{
private: // 있어도 되고 없어도 되고
	char m_szName[32];
	int m_iKor, m_iEng, m_iMath;
	float m_fTotal;
public:
	char* Get_Name();
	void Set_Name(char _szName[]);
	int Get_Kor();
	void Set_Kor(int _iKor);
	int Get_Eng();
	void Set_Eng(int _iEng);
	int Get_Math();
	void Set_Math(int _iMath);
	float Get_Total();
	float Cal_Total();
	void Set_Total(float _fTotal);
};