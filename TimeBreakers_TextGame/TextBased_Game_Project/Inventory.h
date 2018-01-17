#pragma once
#include "stdafx.h"
#include "Item.h"
class Inventory
{
public:
	Inventory();
	~Inventory();

	void PutInInventory(Item *putItem);
	bool SearchInventory(string searchItem);
	void RemoveFromInventory(Item *remItem);
private:
	vector<Item*> m_InvetoryList;


};

