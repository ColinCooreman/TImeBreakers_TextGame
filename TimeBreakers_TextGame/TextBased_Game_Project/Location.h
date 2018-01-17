#pragma once
#include "stdafx.h"
#include "NPC.h"
#include "Story_Object.h"
#include "item.h"
class Location
{
public:
	Location();
	~Location();
	const vector<string> &GetConnections();
	const vector<string> &GetLocationDescription();
	const string &GetLocationName();
	const vector<NPC*> &GetNpcs();
	const vector<Story_Object*> &GetStory_Objects();
	const vector<Item*> &GetItems();

	void SetLocationName(string &location);
	void SetLocationConnections(vector<string> &connections);
	void SetLocationDescription(vector<string> &description);
	void AddStory_Objects(Story_Object* Object);
	void AddNPCs(NPC* npc);
	void AddItems(Item* item);
private:
	string m_LocationName;
	vector<string> m_Connections;
	vector<string> m_LocationDescription;
	vector<NPC*> m_NPCs;
	vector<Story_Object*> m_Story_Objects;
	vector<Item*> m_Items;
};

