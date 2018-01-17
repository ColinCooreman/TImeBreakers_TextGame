#include "stdafx.h"
#include "ItemReader.h"


ItemReader::ItemReader()
{
	m_FileReader = new FileRead_Writer();
	m_FileReader->FilterReadTxtFile("./Txt_and_dataFiles/Item_Decription.txt", '@', m_DataVec);
	m_DescriptionsReader = new Description_Reader(m_DataVec);
	m_DescriptionsReader->DescriptionReader("Blaster Pistol");
	m_DescriptionsReader->DescriptionReader("Repair kit");


	m_DescriptionsMap = m_DescriptionsReader->GetDescriptionsMap();


	AddItemsToVec("Blaster Pistol", itemType::Weapon);
	AddItemsToVec("Repair kit", itemType::Key_item);


	m_DataVec.clear();
}


ItemReader::~ItemReader()
{
	delete m_FileReader;
	m_FileReader = nullptr;
	delete m_DescriptionsReader;
	m_DescriptionsReader = nullptr;
	delete m_Reader;
	m_Reader = nullptr;
	for (auto item : m_ItemVec)
	{
		delete item;
		item = nullptr;
	}
}

void ItemReader::AddItemsToVec(string ItemName, itemType type)
{
	std::transform(ItemName.begin(), ItemName.end(), ItemName.begin(), ::tolower);
	Item *itemData = new Item();
	for (auto description : m_DescriptionsMap)
	{
		if (description.first == ItemName)
		{
			itemData->SetItemName(description.first);
			itemData->SetItemDescription(description.second);
			itemData->SetItemType(type);
		}
	}
	m_ItemVec.push_back(itemData);
}

vector<Item*> ItemReader::GetItemVec()
{
	return m_ItemVec;
}
