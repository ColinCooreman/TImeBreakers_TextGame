#include "stdafx.h"
#include "Item.h"


Item::Item()
{
	
	//switch (m_ItemType)
	//{
	//	case Weapon:
	//		std::cout << "Chrono: This Item is a Weapon, use these to unalive people" << endl;   
	//		break;
	//	case Clothes: 
	//		std::cout << "Chrono: This Item is Clothing" << endl; 
	//		break;
	//	case Key_item: 
	//		std::cout << "Chrono: This Item is Important, make sure to keep it close" << endl;  
	//		break;
	//}
}


Item::~Item()
{
}

void Item::SetItemName(string name)
{
	m_ItemName = name;
}

void Item::SetItemDescription(vector<string> itemDescription)
{
	m_ItemDescription = itemDescription;
}

void Item::SetItemType(itemType type)
{
	m_ItemType = type;
}

const string & Item::GetItemName() const
{
	return m_ItemName;
}

const vector<string>& Item::GetItemDescription()
{
	return m_ItemDescription;
}

const itemType & Item::GetItemType()
{
	return m_ItemType;
}


