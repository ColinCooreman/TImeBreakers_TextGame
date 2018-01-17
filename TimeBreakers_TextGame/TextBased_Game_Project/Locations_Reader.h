#pragma once
#include "stdafx.h"
#include <unordered_map>
#include "Description_Reader.h"
#include "FileRead_Writer.h"
#include "Location.h"
#include "Story_Object_Reader.h"
#include "NPCReader.h"
#include "Story_Object.h"
#include "ItemReader.h"

class Locations_Reader
{

public:
	Locations_Reader();
	~Locations_Reader();

	vector<Location*> GetLocationsVec();
	void AddDescriptionsToLocations(string LocationName);

	bool MoveToLocation(string Location, string targetLocation);
	
private:
	FileRead_Writer *m_FileReader = nullptr;
	Description_Reader *m_Descriptions = nullptr;
	Story_Object_Reader *m_Story_Object_Reader = nullptr;
	ItemReader *m_ItemReader = nullptr;
	NPCReader *m_NPCReader = nullptr;
	unordered_map<string, vector<string>> m_DescriptionsMap;
	vector<Location*> m_Locations;
	vector<Story_Object*> m_StoryObjects;
	vector<NPC*> m_NPCs;
	vector<Item*> m_Items;

	vector<string> m_DataVec;
	unordered_map<string, vector<string>> StoryObjectConnections;

	void AddToLocationsVec(ifstream &data);
	//void AddToLocationsVec(string LocationID, string LocationConnection);


};

