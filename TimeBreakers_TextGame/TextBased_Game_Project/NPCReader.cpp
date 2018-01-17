#include "stdafx.h"
#include "NPCReader.h"

//this class is still under construction

NPCReader::NPCReader()
{
	m_FileReader = new FileRead_Writer();
	m_FileReader->FilterReadTxtFile("./Txt_and_dataFiles/NPC_Description.txt", '@', m_DataVec);
	m_DescriptionsReader = new Description_Reader(m_DataVec);
	m_DescriptionsReader->DescriptionReader("SoundWave-Bridge");
	m_DescriptionsReader->DescriptionReader("SoundWave-CargoHold");
	m_DescriptionsReader->DescriptionReader("SoundWave-EngineRoom");

	m_DescriptionsMap = m_DescriptionsReader->GetDescriptionsMap();


	AddNPCsToVec("SoundWave-Bridge");
	AddNPCsToVec("SoundWave-CargoHold");
	AddNPCsToVec("SoundWave-EngineRoom");

	m_DataVec.clear();
}


NPCReader::~NPCReader()
{

	delete m_FileReader;
	m_FileReader = nullptr;
	delete m_DescriptionsReader;
	m_DescriptionsReader = nullptr;
	for (auto npc : m_NPCVec)
	{
		delete npc;
		npc = nullptr;
	}
}

void NPCReader::AddNPCsToVec(string NpcName)
{
	std::transform(NpcName.begin(), NpcName.end(), NpcName.begin(), ::tolower);
	NPC *NPCData = new NPC();
	for (auto description : m_DescriptionsMap)
	{
		if (description.first == NpcName)
		{
			NPCData->SetNPCName(description.first);
			NPCData->SetNPCDialogue(description.second);
		}
	}
	m_NPCVec.push_back(NPCData);
}

vector<NPC*> NPCReader::GetNPCVec()
{
	return m_NPCVec;
}
