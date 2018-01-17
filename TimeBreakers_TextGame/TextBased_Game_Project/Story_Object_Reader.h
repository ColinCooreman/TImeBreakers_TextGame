#pragma once
#include "stdafx.h"
#include <unordered_map>
#include "Description_Reader.h"
#include "FileRead_Writer.h"
#include "Story_Object.h"
class Story_Object_Reader
{
public:
	Story_Object_Reader();
	~Story_Object_Reader();

	vector<Story_Object*> GetStoryObjectVec();
	/*unordered_map<string, vector<string>> GetDescriptions();*/

	

private:
	void AddToObjectsVec(string ObjectName);
	FileRead_Writer *m_FileReader = nullptr;
	Description_Reader *m_DescriptionsReader = nullptr;
	unordered_map<string, vector<string>> m_DescriptionsMap;
	vector<Story_Object*> m_StoryObjects;
	vector<string> m_DataVec;
};

