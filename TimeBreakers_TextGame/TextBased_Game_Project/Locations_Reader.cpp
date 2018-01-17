#include "stdafx.h"
#include "Locations_Reader.h"
#define _CRTDBG_MAP_ALLOC  

class Description;
class Location;
Locations_Reader::Locations_Reader()
{

	m_FileReader = new FileRead_Writer();
	

	m_Story_Object_Reader = new Story_Object_Reader();
	m_NPCReader = new NPCReader();
	m_ItemReader = new ItemReader();
	AddToLocationsVec(m_FileReader->TxtToIfstream("./Txt_and_dataFiles/NewLocation_Data.txt"));
	m_DataVec.clear();

	m_FileReader->FilterReadTxtFile("./Txt_and_dataFiles/Location_Descriptions.txt", '@', m_DataVec);
	m_Descriptions = new Description_Reader(m_DataVec);
	m_Descriptions->DescriptionReader("YourRoom");
	m_Descriptions->DescriptionReader("Medbay");
	m_Descriptions->DescriptionReader("CargoHold");
	m_Descriptions->DescriptionReader("EngineRoom");
	m_Descriptions->DescriptionReader("ExitRamp");
	m_Descriptions->DescriptionReader("Bridge");
	m_Descriptions ->DescriptionReader("Stop");
	m_DataVec.clear();

	AddDescriptionsToLocations("YourRoom");
	AddDescriptionsToLocations("Medbay");
	AddDescriptionsToLocations("CargoHold");
	AddDescriptionsToLocations("EngineRoom");
	AddDescriptionsToLocations("ExitRamp");
	AddDescriptionsToLocations("Bridge");


	//cout << "location reader test";
}


Locations_Reader::~Locations_Reader()
{
	delete m_FileReader;
	m_FileReader = nullptr;
	delete m_Descriptions;
	m_Descriptions = nullptr;
	delete m_Story_Object_Reader;
	m_Story_Object_Reader = nullptr;
	delete m_ItemReader;
	m_ItemReader = nullptr;
	delete m_NPCReader;
	m_NPCReader = nullptr;
	for (auto location : m_Locations)
	{
		delete location;
		location = nullptr;
	}
	for (auto npc : m_NPCs)
	{
		delete npc;
		npc = nullptr;
	}
	for (auto storyObj : m_StoryObjects)
	{
		delete storyObj;
		storyObj = nullptr;
	}
	for (auto item : m_Items)
	{
		delete item;
		item = nullptr;
	}
}

vector<Location*> Locations_Reader::GetLocationsVec()
{
	return m_Locations;
}


void Locations_Reader::AddToLocationsVec(ifstream &data)
{
	//Addlocations + names
	char input[1000];
	string extractedline;
	int amount = 0;
	data.getline(input, sizeof(input));
	extractedline = input;
	vector <string> Locationconnections;
	if (extractedline == "Locations:")
	{
		data.getline(input, sizeof(input)); // is zowizo de volgende lijn
		amount = stoi(input);
		for (size_t i = 0; i < amount; i++)
		{
			Location *LocationInfo = new Location();
			data.getline(input, sizeof(input));
			string inputtemp = input;
			inputtemp = inputtemp.substr(4, inputtemp.size());
			std::transform(inputtemp.begin(), inputtemp.end(), inputtemp.begin(), ::tolower);
			LocationInfo->SetLocationName(inputtemp);
			m_Locations.push_back(LocationInfo);

		}
	}

	//AddConnectionsToLocations
	data.getline(input, sizeof(input));
	extractedline = input;
	if (extractedline == "Connections:")
	{
		data.getline(input, sizeof(input)); // is zowizo de volgende lijn
		amount = stoi(input);
		for (size_t i = 0; i < amount; i++)
		{
			data.getline(input, sizeof(input));
			string inputtemp = input;
			inputtemp = inputtemp.substr(4, inputtemp.size());
			std::transform(inputtemp.begin(), inputtemp.end(), inputtemp.begin(), ::tolower);

			m_FileReader->Split(inputtemp, ',', Locationconnections);
			m_Locations[i]->SetLocationConnections(Locationconnections);
			Locationconnections.clear();
		}
	}

	//AddObjectToLocations

	data.getline(input, sizeof(input));
	extractedline = input;
	m_StoryObjects = m_Story_Object_Reader->GetStoryObjectVec();
	if (extractedline == "Objects:")
	{
		data.getline(input, sizeof(input)); // is zowizo de volgende lijn
		amount = stoi(input);
		for (size_t i = 0; i < amount; i++)
		{
			data.getline(input, sizeof(input));
			string inputtemp = input;
			inputtemp = inputtemp.substr(4, inputtemp.size());
			std::transform(inputtemp.begin(), inputtemp.end(), inputtemp.begin(), ::tolower);

			for (auto object : m_StoryObjects)
			{
				if (inputtemp.find(object->GetObjectName()) != string::npos)
				{
					m_Locations[i]->AddStory_Objects(object);
				}
			}
			
		}
	}

	//AddNpcToLocations
	data.getline(input, sizeof(input));
	extractedline = input;
	m_NPCs = m_NPCReader->GetNPCVec();
	string Name;
	if (extractedline == "NPCS:")
	{
		data.getline(input, sizeof(input)); // is zowizo de volgende lijn
		amount = stoi(input);
		for (size_t i = 0; i < amount; i++)
		{
			data.getline(input, sizeof(input));
			string inputtemp = input;
			inputtemp = inputtemp.substr(4, inputtemp.size());
			std::transform(inputtemp.begin(), inputtemp.end(), inputtemp.begin(), ::tolower);
		
			for (auto npc : m_NPCs)
			{
				Name = npc->GetNPCName();
				std::transform(Name.begin(), Name.end(), Name.begin(), ::tolower);
				if (inputtemp.find(Name) != string::npos)
				{
					m_Locations[i]->AddNPCs(npc);
				}
			}

		}
	}

	//AddItemsToLocations
	data.getline(input, sizeof(input));
	extractedline = input;
	m_Items = m_ItemReader->GetItemVec();

	if (extractedline == "Items:")
	{
		data.getline(input, sizeof(input)); // leest het aantal en wordt omgezet naar int
		amount = stoi(input);
		for (size_t i = 0; i < amount; i++)
		{
			data.getline(input, sizeof(input));// leest de data 
			string inputtemp = input;
			inputtemp = inputtemp.substr(4, inputtemp.size());
			std::transform(inputtemp.begin(), inputtemp.end(), inputtemp.begin(), ::tolower);


			for (auto item : m_Items)
			{
				Name = item->GetItemName();
				std::transform(Name.begin(), Name.end(), Name.begin(), ::tolower);
				if (inputtemp.find(Name) != string::npos)
				{
					m_Locations[i]->AddItems(item);
				}
			}
		}
	}
}

bool Locations_Reader::MoveToLocation(string LocationName, string targetLocation)
{
	auto CheckConnection = [LocationName, targetLocation](Location *location)
	{
		if (location->GetLocationName() == LocationName)
		{
			for (int i = 0; i < location->GetConnections().size(); i++)
			{
				return (location->GetConnections()[i] == targetLocation);
			}
		}
	};
	auto it = find_if(m_Locations.begin(), m_Locations.end(), CheckConnection);
	if (it != m_Locations.end())
	{
		return true;
	}
}

void Locations_Reader::AddDescriptionsToLocations(string LocationName)
{

	std::transform(LocationName.begin(), LocationName.end(), LocationName.begin(), ::tolower);
	for (auto location : m_Locations)
	{
		if (location->GetLocationName() == LocationName && location->GetLocationDescription() != m_Descriptions->GetDescription(LocationName))
		{
			location->SetLocationDescription(m_Descriptions->GetDescription(LocationName));
		}
	}

}
//void Locations_Reader::AddStoryObjectsToLocations(string LocationName, vector<Story_Object*> StoryObjects)
//{
//	std::transform(LocationName.begin(), LocationName.end(), LocationName.begin(), ::tolower);
//	for (auto location : m_Locations)
//	{
//		if (location->GetLocationName() == LocationName)
//		{
//			for (auto storyobject : StoryObjects)
//			{
//				location->AddStory_Objects(storyobject);
//			}
//		}
//	}
//
//}
//void Locations_Reader::AddToLocationsVec(string LocationID, string LocationConnection)
//{
//	Location *LocationInfo = new Location();
//	vector <string> Locationconnections;
//	string temp;
//	int amountOfLocations = 0;
//	for (auto data : m_DataVec)
//	{
//		std::transform(data.begin(), data.end(), data.begin(), ::tolower);
//		if (data.find(LocationID) != string::npos)
//		{
//		
//			size_t Place = data.find(LocationID);
//			string placeName = data.substr(Place + 4, data.size());
//			LocationInfo->SetLocation(placeName); //+4 because the ID is 4 charcters like this "(XX)" or "[XX]"
//		}
//		if (data.find(LocationConnection) != string::npos)
//		{
//				size_t Place = data.find(LocationConnection);
//				temp = data.substr(Place + 4, data.size()); //+4 because the ID is 4 charcters like this "(XX)" or "[XX]"
//				m_FileReader->Split(temp, ',', Locationconnections);
//				LocationInfo->SetLocationConnections(Locationconnections);
//		}
//		
//	}
//	m_Locations.push_back(LocationInfo);
//
//}