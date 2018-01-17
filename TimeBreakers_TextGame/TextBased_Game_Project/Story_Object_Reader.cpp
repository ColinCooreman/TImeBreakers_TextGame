#include "stdafx.h"
#include "Story_Object_Reader.h"


Story_Object_Reader::Story_Object_Reader()
{
	m_FileReader = new FileRead_Writer();
	m_FileReader->FilterReadTxtFile("./Txt_and_dataFiles/Objects_Descriptions.txt", '@', m_DataVec);
	m_DescriptionsReader = new Description_Reader(m_DataVec);
	m_DescriptionsReader->DescriptionReader("Control Panel");
	m_DescriptionsReader->DescriptionReader("Analyzer");
	m_DescriptionsReader->DescriptionReader("Medical Pod");
	m_DescriptionsReader->DescriptionReader("Heavy shipcannons");
	m_DescriptionsReader->DescriptionReader("AI Interface");
	m_DescriptionsReader->DescriptionReader("engines");
	m_DescriptionsReader->DescriptionReader("Time Drive");
	m_DescriptionsMap = m_DescriptionsReader->GetDescriptionsMap();


	AddToObjectsVec("Control Panel");
	AddToObjectsVec("Analyzer");
	AddToObjectsVec("Medical Pod");
	AddToObjectsVec("Heavy Shipcannons");
	AddToObjectsVec("AI Interface");
	AddToObjectsVec("engines");
	AddToObjectsVec("Time Drive");
	m_DataVec.clear();
}


Story_Object_Reader::~Story_Object_Reader()
{
	delete m_FileReader;
	m_FileReader = nullptr;
	delete m_DescriptionsReader;
	m_DescriptionsReader = nullptr;
	vector<Story_Object*> m_StoryObjects;
	for (auto object : m_StoryObjects)
	{
		delete object;
		object = nullptr;
	}
}

vector<Story_Object*> Story_Object_Reader::GetStoryObjectVec()
{
	return m_StoryObjects;
}

void Story_Object_Reader::AddToObjectsVec(string ObjectName)
{
	std::transform(ObjectName.begin(), ObjectName.end(), ObjectName.begin(), ::tolower);
	Story_Object *storyobjectData = new Story_Object();
	for (auto description : m_DescriptionsMap)
	{
		if (description.first == ObjectName)
		{
			storyobjectData->SetObjectName(description.first);
			storyobjectData->SetObjectDescription(description.second);
		}
	}
	m_StoryObjects.push_back(storyobjectData);
}



