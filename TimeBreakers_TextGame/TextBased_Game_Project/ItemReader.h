#pragma once
#include "stdafx.h"
#include <unordered_map>
#include "Description_Reader.h"
#include "FileRead_Writer.h"
#include "Item.h"
class ItemReader
{
public:
	ItemReader();
	~ItemReader();

	void AddItemsToVec(string ItemName, itemType type);
	vector<Item*> GetItemVec();
private:

	vector<string> m_DataVec;

	FileRead_Writer *m_FileReader = nullptr;
	Description_Reader *m_DescriptionsReader = nullptr;
	unordered_map<string, vector<string>> m_DescriptionsMap;
	FileRead_Writer *m_Reader;
	vector<Item*> m_ItemVec;

};

