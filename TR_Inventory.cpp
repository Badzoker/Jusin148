#include "TR_Inventory.h"

CInventory::CInventory(): m_iSize(5)
{
	m_vecItem.reserve(m_iSize);
	iCount_Item = 0;
}

CInventory::~CInventory()
{
	Release();
}

void CInventory::Initialize()
{
}

void CInventory::Update()
{
}

void CInventory::Release()
{
	for_each(m_vecItem.begin(), m_vecItem.end(), Safe_Delete<CItem*>);
	m_vecItem.clear();
	m_vecItem.shrink_to_fit();
}

void CInventory::Render()
{
	for (size_t i = 0; i < m_vecItem.size(); i++)
	{
		cout << i + 1 << " 번째 아이템 " << endl;
		m_vecItem[i]->Render();
	}
	system("pause");
}

void CInventory::Create_Main(JOB _eJob)
{
	if (m_iSize > iCount_Item)
	{
		CItem* pTemp = new CItem_Equip;
		dynamic_cast<CItem_Equip*>(pTemp)->Initialize(true, _eJob);
		m_vecItem.push_back(pTemp);
		iCount_Item++;
	}
	else
	{
		cout << "인벤토리가 꽉 찼습니다." << endl;
	}
	system("pause");
}

void CInventory::Create_Sub(JOB _eJob)
{
	if (m_iSize > iCount_Item)
	{
		CItem* pTemp = new CItem_Equip;
		dynamic_cast<CItem_Equip*>(pTemp)->Initialize(false, _eJob);
		m_vecItem.push_back(pTemp);
		iCount_Item++;
	}
	else
	{
		cout << "인벤토리가 꽉 찼습니다." << endl;
	}
	system("pause");
}

void CInventory::Create_Potion()
{
	if (m_iSize > iCount_Item)
	{
		CItem* pTemp = new CItem_Consumable;
		dynamic_cast<CItem_Consumable*>(pTemp)->Initialize(true);
		m_vecItem.push_back(pTemp);
		iCount_Item++;
	}
	else
	{
		cout << "인벤토리가 꽉 찼습니다." << endl;
	}
	system("pause");
}

void CInventory::Create_ManaPotion()
{
	if (m_iSize > iCount_Item)
	{
		CItem* pTemp = new CItem_Consumable;
		dynamic_cast<CItem_Consumable*>(pTemp)->Initialize(false);
		m_vecItem.push_back(pTemp);
		iCount_Item++;
	}
	else
	{
		cout << "인벤토리가 꽉 찼습니다." << endl;
	}
	system("pause");
}

void CInventory::Sell_Item()
{
	int iInput(0);
	cout << "몇 번째 아이템을 판매할까요? : ";
	cin >> iInput;
	iInput--;
	if (0 < iCount_Item)
	{
		m_Itemiter = m_vecItem.begin();
		m_Itemiter += iInput;
		Safe_Delete(*(m_Itemiter));
		m_Itemiter = m_vecItem.erase(m_Itemiter);
		iCount_Item--;
	}
	else
	{
		cout << "아이템 없음" << endl;
	}
	system("pause");
}
