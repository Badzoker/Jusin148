#include "TR_Struct.h"
#include "mynamespace.h"

tagInfo::tagInfo()
{
	cout << "INFO 구조체 생성자 호출" << endl;
	memset(this, 0, sizeof(INFO));
}

tagInfo::~tagInfo()
{
}

tagItem::tagItem()
{
	cout << "ITEM 구조체 생성자 호출" << endl;
	memset(this, 0, sizeof(ITEM));
}

tagItem::~tagItem()
{
}

//tagInfo_Mon::tagInfo_Mon()
//{
//	cout << "INFOMON 구조체 생성자 호출" << endl;
//	memset(this, 0, sizeof(INFOMON));
//}
//
//tagInfo_Mon::~tagInfo_Mon()
//{
//}
