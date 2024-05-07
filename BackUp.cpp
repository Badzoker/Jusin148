#include<iostream>
#include "BackUp.h"
using namespace std;

const int Mapsize = 10;

int main()
{
	Play_WormGame();
	return 0;
}
void Play_WormGame()
{//�����ܰ迡�� Stack -> Heap ��ȯ �ʿ�, ������ ��
	bool bCheck_Live = true; // ��Ҵ°�? 
	bool bArray_Direction[4] = { false, false, false, true }; // player ���� (��������, �յڹ���)
	int iTimer_PrintingMap(0), iPlayer_Position(85), iPlayer_Speed(15); //�����̴� Ÿ�̸�, ��ġ, �󸶳� ���� �����̳�
	while (bCheck_Live)
	{
		++iTimer_PrintingMap;
		if (iPlayer_Speed < iTimer_PrintingMap)// �Է¾��� �� (����ܰ�) -> ���� �Է¹޴��� Ȯ���� �� �ڵ带 else if�� �̵�
		{//�ʹ� ���Ӽӵ�(Printing) �Ǵ°� ���� �̰� ���߰ų� 
			iTimer_PrintingMap = 0;
			Printing_Map(bCheck_Live, iPlayer_Position, bArray_Direction);
		}
	}
	cout << "����!" << endl;
	//�Ŀ� continue or game off
}

void Printing_Map(bool& _pCheck_Live, int& _pPlayer_Position, bool _bArray_Direction[])
{ // Player_Head -> �� | Player_Tail -> �� | MapLine -> �� | Food -> ��
	system("cls");
	for (int i = 0; i < Mapsize; i++)
	{
		for (int j = 0; j < Mapsize; j++)
		{
			if (0 == i || 0 == j || Mapsize - 1 == i || Mapsize - 1 == j)
			{
				cout << "��";
			}
			else if (_pPlayer_Position == (10 * i) + j)
			{
				cout << "��";
			}
			else
			{
				cout << "  ";
			}
		}
		cout << endl;
	}
	Check_PlayerDirection(_pCheck_Live, _pPlayer_Position, _bArray_Direction);
}

void Check_PlayerDirection(bool& _pCheck_Live, int& _pPlayer_Position, bool _bArray_Direction[])
{//�̹�� ������ �������� �ȵ����� �켱 ������ �ֿ켱����
	if (_bArray_Direction[0])
	{
		cout << "����" << endl;
		_pPlayer_Position += 1;
		if (9 == (_pPlayer_Position % 10))
		{
			_pCheck_Live = false;
		}
	}
	else if (_bArray_Direction[1])
	{
		cout << "����" << endl;
		_pPlayer_Position -= 1;
		if (0 == (_pPlayer_Position % 10))
		{
			_pCheck_Live = false;
		}
	}
	else if (_bArray_Direction[2])
	{
		cout << "����" << endl;
		_pPlayer_Position += 10;
		if (9 == (_pPlayer_Position / 10))
		{
			_pCheck_Live = false;
		}
	}
	else
	{
		cout << "����" << endl;
		_pPlayer_Position -= 10;
		if (0 == (_pPlayer_Position / 10))
		{
			_pCheck_Live = false;
		}
	}
}
