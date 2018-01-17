#pragma once
#include "stdafx.h"
#include <unordered_map>
#include "Description_Reader.h"
#include "FileRead_Writer.h"
#include "NPC.h"

//this class is still under construction
class NPCReader
{
public:
	NPCReader();
	~NPCReader();
	void AddNPCsToVec(string NpcName);
	vector<NPC*> GetNPCVec();
private:

	vector<string> m_DataVec;

	FileRead_Writer *m_FileReader = nullptr;
	Description_Reader *m_DescriptionsReader = nullptr;
	unordered_map<string, vector<string>> m_DescriptionsMap;
	vector<NPC*> m_NPCVec;



};

