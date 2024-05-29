#include "TR_Struct.h"
#include "mynamespace.h"

tagInfo::tagInfo()
{
	memset(this, 0, sizeof(INFO));
}

tagItem::tagItem()
{
	memset(this, 0, sizeof(ITEM));
}

tagShop::tagShop()
{
	memset(this, 0, sizeof(SHOP));
}

tagItemInfo::tagItemInfo()
{
	memset(this, 0, sizeof(ITEMINFO));
	eItem_Type = ITEM_TYPE_END;
}
