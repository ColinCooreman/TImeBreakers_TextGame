#include "stdafx.h"
#include "Inventory.h"

Inventory::Inventory()
{
}


Inventory::~Inventory()
{
	for (auto item : m_InvetoryList)
	{
		delete item;
		item = nullptr;
	}
}

void Inventory::PutInInventory(Item *putItem)
{
	if (SearchInventory(putItem->GetItemName()) == false)
	{
		m_InvetoryList.push_back(putItem);
	}
	
}

bool Inventory::SearchInventory(string itemname)
{
	if (m_InvetoryList.size() > 0)
	{
		for (auto Inv : m_InvetoryList)
		{
			return Inv->GetItemName() == itemname ? true : false; //can return anything (if the statement is true) : (if the statement is false)
		}
	}
	else
	{
		return false;
	}

}


void Inventory::RemoveFromInventory(Item *remItem)
{
	// 1) find all
	// 2) erase found items
	for (size_t i = 0; i < m_InvetoryList.size(); i++)
	{
		if (m_InvetoryList[i]->GetItemName() == remItem->GetItemName())
		{
			m_InvetoryList.erase(m_InvetoryList.begin()+i);
		}
	}


}

