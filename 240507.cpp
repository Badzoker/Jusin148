#include "HomeWork.h"
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
	HomeWork cGame;
	cGame.Menu();
	return 0;
}

//���� �����迭�� Ŭ���� ����ǥ�����
//�Է�-> ������� �Է�
//���-> ��� ����ǥ ���
//�Է� �� ������ �⺻+�߰�
//�ΰ��� Ŭ����(���ΰ���, �л�)