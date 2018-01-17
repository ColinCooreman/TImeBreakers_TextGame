#pragma once
#include "stdafx.h"
#include "Inventory.h"
class Player
{
public:
	Player();
	~Player();

	void AddItemToInv(Item* item);
	void DecreaseHealth(int value);
	void IncreaseHealth(int value);
	void SetName(string name);
	Inventory* &GetInventory();
	const int &GetHealth();
	const string &GetName();
private:
	int m_Health = 100;
	Inventory* m_Inventory;
	string m_Name;
};

