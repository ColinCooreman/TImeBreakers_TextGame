#pragma once
#include "stdafx.h"
class Item
{
public:
	Item();
	~Item();

	void SetItemName(string name);
	void SetItemDescription(vector<string> itemDescription);
	void SetItemType(itemType type);
	const string &GetItemName() const; 
	const vector<string> &GetItemDescription();
	const itemType &GetItemType();
private:
	string m_ItemName;
	vector<string> m_ItemDescription;
	itemType m_ItemType;
};

