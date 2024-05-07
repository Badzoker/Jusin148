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
{//구현단계에서 Stack -> Heap 전환 필요, 생각할 것
	bool bCheck_Live = true; // 살았는가? 
	bool bArray_Direction[4] = { false, false, false, true }; // player 방향 (동서남북, 앞뒤밑위)
	int iTimer_PrintingMap(0), iPlayer_Position(85), iPlayer_Speed(15); //움직이는 타이머, 위치, 얼마나 빨리 움직이냐
	while (bCheck_Live)
	{
		++iTimer_PrintingMap;
		if (iPlayer_Speed < iTimer_PrintingMap)// 입력없을 시 (시험단계) -> 먼저 입력받는지 확인후 이 코드를 else if로 이동
		{//너무 게임속도(Printing) 되는게 빠름 이걸 늦추거나 
			iTimer_PrintingMap = 0;
			Printing_Map(bCheck_Live, iPlayer_Position, bArray_Direction);
		}
	}
	cout << "죽음!" << endl;
	//후에 continue or game off
}

void Printing_Map(bool& _pCheck_Live, int& _pPlayer_Position, bool _bArray_Direction[])
{ // Player_Head -> ● | Player_Tail -> ○ | MapLine -> ■ | Food -> ⊙
	system("cls");
	for (int i = 0; i < Mapsize; i++)
	{
		for (int j = 0; j < Mapsize; j++)
		{
			if (0 == i || 0 == j || Mapsize - 1 == i || Mapsize - 1 == j)
			{
				cout << "■";
			}
			else if (_pPlayer_Position == (10 * i) + j)
			{
				cout << "●";
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
{//이방식 굉장히 마음에는 안들지만 우선 구현이 최우선으로
	if (_bArray_Direction[0])
	{
		cout << "전진" << endl;
		_pPlayer_Position += 1;
		if (9 == (_pPlayer_Position % 10))
		{
			_pCheck_Live = false;
		}
	}
	else if (_bArray_Direction[1])
	{
		cout << "후진" << endl;
		_pPlayer_Position -= 1;
		if (0 == (_pPlayer_Position % 10))
		{
			_pCheck_Live = false;
		}
	}
	else if (_bArray_Direction[2])
	{
		cout << "남진" << endl;
		_pPlayer_Position += 10;
		if (9 == (_pPlayer_Position / 10))
		{
			_pCheck_Live = false;
		}
	}
	else
	{
		cout << "북진" << endl;
		_pPlayer_Position -= 10;
		if (0 == (_pPlayer_Position / 10))
		{
			_pCheck_Live = false;
		}
	}
}
