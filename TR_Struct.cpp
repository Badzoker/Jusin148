#include "TR_Struct.h"
#include "mynamespace.h"

tagInfo::tagInfo()
{
	memset(this, 0, sizeof(INFO));
}

tagInfo::~tagInfo()
{
}

tagItem::tagItem()
{
	memset(this, 0, sizeof(ITEM));
}

tagItem::~tagItem()
{
}

//tagInfo_Mon::tagInfo_Mon()
//{
//	cout << "INFOMON ����ü ������ ȣ��" << endl;
//	memset(this, 0, sizeof(INFOMON));
//}
//
//tagInfo_Mon::~tagInfo_Mon()
//{
//}

tagShop::tagShop()
{
	memset(this, 0, sizeof(SHOP));
}

tagShop::~tagShop()
{
}
