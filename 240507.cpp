#include "0507MainGame.h"
#ifdef _DEBUG

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

#ifndef DBG_NEW 
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ ) 
#define new DBG_NEW 

#endif
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CMainGame cGame;
	cGame.Menu();
	return 0;
}

//숙제 동적배열로 클래스 성적표만들기
//입력-> 몇명일지 입력
//출력-> 모두 성적표 출력
//입력 또 누르면 기본+추가
//두개의 클래스(메인게임, 학생)