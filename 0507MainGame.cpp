#include "0507Student.h"
#include "0507MainGame.h"
#include <iostream>

//int CMainGame::Set_StudentCount(int _iCount)
//{
//	m_iArrayMaxCount += _iCount;
//}
//
//void CMainGame::Get_StudentArray() 
//{
//	system("cls");
//	std::cout << "�л��̸�\t��������\t��������\t��������" << std::endl;
//	for (int i = 0; i < m_iArrayMaxCount; i++)
//	{
//		std::cout << i + 1 << " �� �л�" << std::endl;
//		for (int j = 0; j < sizeof(m_CArray[i].Get_Name()); j++)
//		{
//			std::cout <<m_CArray[i].Get_Name()[j];
//		}
//		std::cout << "\t" << m_CArray[i].Get_Kor() << " ��\t" << m_CArray[i].Get_Eng() << " ��\t" << m_CArray[i].Get_Math() << " ��\t" << std::endl;
//	}
//	std::cout << "��¿Ϸ�" << std::endl;
//	system("pause");
//}
//
//void CMainGame::Set_StudentArray()
//{
//	system("cls");
//	char szTemp[32] = {};
//	int iInput(0);
//	std::cout << "�л� ���� �Է��Ͻÿ�" << std::endl;
//	std::cin >> iInput;
//	m_iArrayCurrentCount = iInput;
//	Copy_StudentArray();
//	for (int i = 0; i < m_iArrayCurrentCount; i++)
//	{
//		std::cout << "�л� �̸��� �Է��Ͻÿ� : " << std::endl;
//		std::cin >> szTemp;
//		m_CArray[m_iArrayMaxCount - m_iArrayCurrentCount + i].Set_Name(szTemp);
//
//		std::cout << "���������� �Է��Ͻÿ� :" << std::endl;
//		std::cin >> iInput;
//		m_CArray[m_iArrayMaxCount - m_iArrayCurrentCount + i].Set_Kor(iInput);
//
//		std::cout << "���������� �Է��Ͻÿ� :" << std::endl;
//		std::cin >> iInput;
//		m_CArray[m_iArrayMaxCount - m_iArrayCurrentCount + i].Set_Eng(iInput);
//
//		std::cout << "���������� �Է��Ͻÿ� :" << std::endl;
//		std::cin >> iInput;
//		m_CArray[m_iArrayMaxCount - m_iArrayCurrentCount + i].Set_Math(iInput);
//	}
//	std::cout << "�Է¿Ϸ�" << std::endl;
//	system("pause");
//}
//
//void CMainGame::Copy_StudentArray()
//{
//	CStudent* cArray = new CStudent[m_iArrayMaxCount]; //�ӽ� �迭
//	for (int i = 0; i < m_iArrayMaxCount; i++)
//	{
//		m_CArray[i].Cpy_Name(cArray[i].Get_Name());
//		cArray[i].Set_Kor(m_CArray[i].Get_Kor());
//		cArray[i].Set_Eng(m_CArray[i].Get_Eng());
//		cArray[i].Set_Math(m_CArray[i].Get_Math());
//	}
//	Set_StudentCount(m_iArrayCurrentCount); // Max Student �ø���
//	if (m_CArray != nullptr)
//	{
//		delete[] m_CArray;
//		m_CArray = nullptr;
//	}
//	m_CArray = new CStudent[m_iArrayMaxCount];
//	for (int i = 0; i < m_iArrayMaxCount - m_iArrayCurrentCount; i++)
//	{
//		cArray[i].Cpy_Name(m_CArray[i].Get_Name());
//		m_CArray[i].Set_Kor(cArray[i].Get_Kor());
//		m_CArray[i].Set_Eng(cArray[i].Get_Eng());
//		m_CArray[i].Set_Math(cArray[i].Get_Math());
//	}
//	delete[] cArray;
//	cArray = nullptr;
//}

void CMainGame::Copy_Array(CStudent _cStu[], CStudent _cMax[])// ������ �ű�
{
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
void CMainGame::Set_StudentInfo(CStudent _cStu[], CStudent _cMax[])// �Է�
{
	char szTemp[32] = {};
	int iInput(0);
	for (int i = 0; i < m_iCurrentCount; i++)
	{
		system("cls");
		std::cout << "�л� �̸��� �Է��Ͻÿ� : " << std::endl;
		std::cin >> szTemp;
		_cStu[i].Set_Name(szTemp);

		std::cout << "���������� �Է��Ͻÿ� :" << std::endl;
		std::cin >> iInput;
		_cStu[i].Set_Kor(iInput);

		std::cout << "���������� �Է��Ͻÿ� :" << std::endl;
		std::cin >> iInput;
		_cStu[i].Set_Eng(iInput);

		std::cout << "���������� �Է��Ͻÿ� :" << std::endl;
		std::cin >> iInput;
		_cStu[i].Set_Math(iInput);
		_cStu[i].Set_Total(_cStu[i].Cal_Total());
	}
	std::cout << "�Է¿Ϸ�" << std::endl;
	Copy_Array(_cStu, _cMax);
	system("pause");
}

void CMainGame::Set_Array(CStudent _cMax[])// �����Ҵ� �κ�
{
	CStudent* cStu = new CStudent[m_iCurrentCount];

	Set_StudentInfo(cStu, _cMax);
	delete[] cStu;
	cStu = nullptr;
}

void CMainGame::Set_Count(CStudent _cMax[]) // ���� �Է� �� ����
{
	int iInput(0);
	std::cout << "�л� ���� �Է��Ͻÿ�." << std::endl;
	std::cin >> iInput;
	m_iCurrentCount = iInput;
	m_iMaxCount += m_iCurrentCount;
	Set_Array(_cMax);
}
void CMainGame::Printing_Grade(CStudent _cMax[])// ���
{
	system("cls");
	std::cout << "�л��̸�\t��������\t��������\t��������" << std::endl;
	for (int i = 0; i < m_iMaxCount; i++)
	{
		if (_cMax[i].Get_Eng() != 0 || _cMax[i].Get_Eng() != NULL)
		{
			std::cout << i + 1 << "��° �л�" << std::endl;
			std::cout << _cMax[i].Get_Name() << "\t" << _cMax[i].Get_Kor() << "\t" << _cMax[i].Get_Eng() << "\t" << _cMax[i].Get_Math() << std::endl;
		}
	}
	std::cout << "��¿Ϸ�" << std::endl;
	system("pause");
}


void CMainGame::Free()
{
	/*if (m_CArray != nullptr)
	{
		delete[] m_CArray;
		m_CArray = nullptr;
	}*/
}

void CMainGame::Menu()
{
	CStudent* cArray = new CStudent[50];
	int iInput(0);
	while (true)
	{
		system("cls");
		std::cout << "�޴�\n1. �л��Է�\t2. �������\t3. ����" << std::endl;
		std::cin >> iInput;
		switch (iInput)
		{
		case 1:
			Set_Count(cArray);
			break;
		case 2:
			Printing_Grade(cArray);
			break;
		case 3:
			delete[] cArray;
			cArray = nullptr;
			return;
		default:
			break;
		}
	}
}