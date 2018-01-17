#include "stdafx.h"
#include "Location.h"


Location::Location()
{
}


Location::~Location()
{
	for (auto npc : m_NPCs)
	{
		delete npc;
		npc = nullptr;
	}
	for (auto object : m_Story_Objects)
	{
		delete object;
		object = nullptr;
	}
	for (auto item : m_Items)
	{
		delete item;
		item = nullptr;
	}
}

const vector<string> &Location::GetConnections()
{
	return m_Connections;
}

const vector<string>& Location::GetLocationDescription()
{
	return m_LocationDescription;
}

const string &Location::GetLocationName()
{
	return m_LocationName;
}
const vector<NPC*> & Location::GetNpcs()
{
	return m_NPCs;
}
const vector<Story_Object*>& Location::GetStory_Objects()
{
	return m_Story_Objects;
}

const vector<Item*>& Location::GetItems()
{
	return m_Items;
}


void Location::SetLocationName(string &location)
{
	m_LocationName = location;
}
void Location::SetLocationConnections(vector<string> &connections)
{
	m_Connections = connections;
}
void Location::SetLocationDescription(vector<string> &description)
{
	m_LocationDescription = description;
}
void Location::AddStory_Objects(Story_Object* Object)
{
	m_Story_Objects.push_back(Object);
}
void Location::AddNPCs(NPC* npc)
{
	m_NPCs.push_back(npc);
}

void Location::AddItems(Item * item)
{
	m_Items.push_back(item);
}
