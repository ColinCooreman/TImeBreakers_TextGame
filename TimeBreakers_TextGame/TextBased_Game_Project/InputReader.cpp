#include "stdafx.h"
#include "InputReader.h"

InputReader::InputReader(Player *player1)
{
	m_player = player1;
	m_LocationData = new Locations_Reader();
	m_FileReader = new FileRead_Writer();
	m_CommandsData = new Commands();
	m_handle = GetStdHandle(STD_OUTPUT_HANDLE);
}




InputReader::~InputReader()
{
	delete m_FileReader;
	m_FileReader = nullptr;
	delete m_CommandsData;
	m_CommandsData = nullptr;
	delete m_LocationData;
	m_LocationData = nullptr;
}
void InputReader::NameReaderInput()
{
	cin.getline(m_Name, sizeof(m_Name));
	m_player->SetName(m_Name);
	cout << m_Name << endl;
	cout << "Oke initializing adventure ... ... ... \nPress enter to continue";
	cin.get();
}

void InputReader::LocationDescriptionOutput()
{
	if (m_CurrentLocation != m_CurrentLocationCheck)
	{
		cout << "Your Current Location is " << m_CurrentLocation << endl;
		for (auto location : m_LocationData->GetLocationsVec())
		{
			if (m_CurrentLocation == location->GetLocationName())
			{
				for (auto text : location->GetLocationDescription())
				{
					cout << text << endl;
				}
			}

		}
	}
	else
	{
		cout << "You can't move there" << endl;
	}
	m_CurrentLocationCheck = m_CurrentLocation;
}

void InputReader::ExecuteCommand(const CommandType &command, string ExtraInfo)
{
	m_ExtraInfo = ExtraInfo;
	FileRead_Writer *reader = new FileRead_Writer();
	switch (command)
	{
	case Move:
		for (auto loc : m_LocationData->GetLocationsVec())
		{
			if (loc->GetLocationName() == m_CurrentLocation)
			{
				for (auto locationConnection : loc->GetConnections())
				{
					if (m_ExtraInfo.find(locationConnection) != string::npos)
					{
						size_t locationbegin = m_ExtraInfo.find(locationConnection);
						size_t locationEnd = locationConnection.size();
						m_CurrentLocation = m_ExtraInfo.substr(locationbegin, locationEnd);
						m_ExtraInfo.clear();
					}
				}
			}
		}
		SetColor(FOREGROUND_RED, m_handle, FOREGROUND_INTENSITY);
		LocationDescriptionOutput();
		SetColor(FOREGROUND_GREEN, m_handle, FOREGROUND_INTENSITY);

		break;
	case Use:
		for (auto loc : m_LocationData->GetLocationsVec())
		{
			if (loc->GetLocationName() == m_CurrentLocation)
			{
				for (auto storyObject : loc->GetStory_Objects())
				{
					if (m_ExtraInfo.find(storyObject->GetObjectName()) != string::npos)
					{
						m_FileReader->PrintStoryText(storyObject->GetObjectDescription(), false);
						break;
					}
					//else
					//{
					//	cout << "Chrono: Sir, you can't use that." << endl;
					//}
				}
			}
		}
		break;
	case Attack:
		cout << "Command coming soon to a PC near you " << endl;
		break;
	case Look:
		cout << "you see" << endl;
		SetColor(FOREGROUND_BLUE, m_handle, FOREGROUND_INTENSITY);
		for (auto loc : m_LocationData->GetLocationsVec())
		{
			if (loc->GetLocationName() == m_CurrentLocation)
			{
				if (loc->GetStory_Objects().size() > 0)
				{
					for (auto storyObject : loc->GetStory_Objects())
					{
			
						cout << storyObject->GetObjectName() << endl;
					}
				}
				else
				{
					cout << "NOTHING " << endl;
				}
	
			}
			
		}
		SetColor(FOREGROUND_GREEN, m_handle, FOREGROUND_INTENSITY);
		cout << "that seems to be interactable " << endl;

		cout << "you see " << endl;
		SetColor(FOREGROUND_BLUE, m_handle, FOREGROUND_INTENSITY);
		for (auto loc : m_LocationData->GetLocationsVec())
		{
			if (loc->GetLocationName() == m_CurrentLocation)
			{
				if (loc->GetItems().size() > 0)
				{
					for (auto item : loc->GetItems())
					{
						cout << "a " << item->GetItemName() << " " << endl;
					}
				}
				else
				{
					cout << "your feet, very usefull for walking " << endl;
				}

			}

		}

		SetColor(FOREGROUND_GREEN, m_handle, FOREGROUND_INTENSITY);
		cout << "Chrono: Some of these item might be usefull try picking them up." << endl;

		cout << "you see " << endl;
		SetColor(FOREGROUND_BLUE, m_handle, FOREGROUND_INTENSITY);
		for (auto loc : m_LocationData->GetLocationsVec())
		{
			if (loc->GetLocationName() == m_CurrentLocation)
			{
				if (loc->GetNpcs().size() > 0)
				{
					for (auto npc : loc->GetNpcs())
					{
						cout << npc->GetNPCName().substr(0,npc->GetNPCName().find('-')) << " " << endl;
					}
				}
				else
				{
					cout << "Nobody" << endl;
				}

			}

		}
		SetColor(FOREGROUND_GREEN, m_handle, FOREGROUND_INTENSITY);
		cout << "Chrono: Maybe try talking to them" << endl;
		break;
	case Grab:
		for (auto loc : m_LocationData->GetLocationsVec())
		{
			if (loc->GetLocationName() == m_CurrentLocation)
			{
				for (auto item : loc->GetItems())
				{
					if (m_ExtraInfo.find(item->GetItemName()) != string::npos)
					{
						cout << "You found a " << item->GetItemName() << " it may be of use to you." << endl;
						m_player->AddItemToInv(item);
						break; 
					}

				}
			}
		}
		break;
	case Where:
		cout << "Chrono: You are currently in "<< m_CurrentLocation << " ,getting forgetfull, sir?" << endl;
		break;
	case Map:
		reader->FilterReadTxtFile("./Txt_and_dataFiles/Maps.txt", '$', m_DataVec);
		reader->PrintStoryText(m_DataVec, true);
		m_DataVec.clear();
		break;
	case Speak:
		for (auto loc : m_LocationData->GetLocationsVec())
		{
			if (loc->GetLocationName() == m_CurrentLocation)
			{
				if (loc->GetNpcs().size() > 0)
				{
					for (auto npc : loc->GetNpcs())
					{
						if (m_ExtraInfo.find(npc->GetNPCName().substr(0, npc->GetNPCName().find('-'))) != string::npos)
						{
							m_FileReader->PrintStoryText(npc->GetNPCDialogue(), false);
							break;
						}
					}
				}
				else
				{
					cout << "Chrono: are you speaking to yourself again captain?" << endl;
					break;
				}
			}
		}
		break;
	case None:
		cout << "i dont understand the command" << endl;
		break;
	}

}

vector<string> InputReader::ReadInput()
{
	m_Input.clear();
	cin.getline(m_Command, sizeof(m_Command));
	string commandStr = m_Command;
	istringstream commandstream(commandStr);
	string temp = "";
	while (std::getline(commandstream, temp, ' ')) //filters out all " " and changes everything to lower case
	{
		std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
		m_Input.push_back(temp);
		temp.clear();
	}

	return m_Input;

}

void InputReader::SetColor(int color, const HANDLE & handle, int intensity)
{
	SetConsoleTextAttribute(handle, color | intensity);
}

const string & InputReader::GetCurrentLocation()
{
	return m_CurrentLocation;
}
