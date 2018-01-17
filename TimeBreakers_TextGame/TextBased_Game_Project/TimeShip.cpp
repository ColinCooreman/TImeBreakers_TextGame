#include "stdafx.h"
#include "TimeShip.h"
#include "FileRead_Writer.h"
#include <unordered_map>
class Description;
TimeShip::TimeShip(Player *player1)
{
	m_player = player1;
	m_FileReader= new FileRead_Writer();
	m_CommandsData = new Commands();
	m_InputReader = new InputReader(m_player);

}


TimeShip::~TimeShip()
{
	delete m_CommandsData;
	m_CommandsData = nullptr;

	delete m_InputReader;
	m_InputReader = nullptr;

	delete m_FileReader;
	m_FileReader = nullptr;
}


void TimeShip::CheckStory(StoryQuest story) //prints out the story tied to the important objects 
{

	switch (story)
	{
	case StoryQuest::Quest1: //medical pod
		if (m_ExtraInfo.find("soundwave") != string::npos && m_InputReader->GetCurrentLocation() != "cargohold")
		{
			cout << "You cant do that right now." << endl;
		}
		else if (m_ExtraInfo.find("control panel") != string::npos || m_ExtraInfo.find("heavy shipcannons") != string::npos || m_ExtraInfo.find("time drive") != string::npos)
		{
			cout << "I shouldn't touch that" << endl;
		}
		else
		{
			m_InputReader->ExecuteCommand(m_CommandTest, m_ExtraInfo);
		}


		break;
	case StoryQuest::Quest2: //Control_Panel

		if (UnderAttack == true)
		{
			if (m_ExtraInfo.find("soundwave") != string::npos && m_InputReader->GetCurrentLocation() != "bridge")
			{
				cout << "You cant do that right now." << endl;
			}
			else if (m_ExtraInfo.find("time drive") != string::npos || m_ExtraInfo.find("heavy shipcannons") != string::npos)
			{
				cout << "I shouldn't touch that" << endl;
			}
			else
			{
				m_InputReader->ExecuteCommand(m_CommandTest, m_ExtraInfo);
			}

		}
		else
		{
			cout << "I shouldn't touch the control Panel right now the ship is basicly flying it self anyway." << endl;
		}

		break;
	case StoryQuest::Quest3: //HeavyShipcannons
		if (AttackingBack == true)
		{
			if (m_ExtraInfo.find("soundwave") != string::npos && m_InputReader->GetCurrentLocation() != "engineroom")
			{
				cout << "You cant do that right now." << endl;
			}
			else if (m_ExtraInfo.find("time drive") != string::npos)
			{
				cout << "I shouldn't touch that" << endl;
			}
			else
			{
				m_InputReader->ExecuteCommand(m_CommandTest, m_ExtraInfo);
				if (Once == false)
				{
					m_FileReader->FilterReadTxtFile("./Txt_and_dataFiles/Explosion.txt", '\n', m_DataVec);
					m_FileReader->PrintStoryText(m_DataVec, true);
					Once = true;
				}


			}
	
		}
		else
		{
			cout << "Wave doesn't want me to touch the heavy artillery he installed on the ship, wait why do i listen to him i'm the captain.\nAs I move to the weapon controls something metal hits the back of my head. I turn around an Wave is standing behind me, as he plays back a recording of my voice 'Wave doesn't want me to touch the heavy artillery'.\n I glare at him, but it doesn't seem to work because i'm just staring at myself in his visor. 'Fine'" << endl;
		}
		m_DataVec.clear();
		break;
	case StoryQuest::Quest4: //fixing timedrive and engines
		if (FixingShip == true)
		{

			if (m_ExtraInfo.find("soundwave") != string::npos)
			{
				cout << "you cant do that right now" << endl;
			}
			else 
			{
				m_InputReader->ExecuteCommand(m_CommandTest, m_ExtraInfo);
			}
			
		}
		else
		{
			cout << "I reaaaaaaaly shoudn't touch the timedrive it's very dangerous, and highly explosive." << endl;
		}
		break;
	case StoryQuest::Nothing:
		if (m_ExtraInfo.find("soundwave") != string::npos && m_InputReader->GetCurrentLocation() != "cargohold")
		{
			cout << "You cant do that right now." << endl;
		}
		else if (m_ExtraInfo.find("control panel") != string::npos || m_ExtraInfo.find("heavy shipcannons") != string::npos || m_ExtraInfo.find("time drive") != string::npos)
		{
			cout << "I shouldn't touch that" << endl;
		}
		else
		{
			m_InputReader->ExecuteCommand(m_CommandTest, m_ExtraInfo);
		}
		break;
	default:
		break;
	}

}

StoryQuest TimeShip::CheckQuest(string &info)
{
	
	if (info.find("medical pod") != string::npos)
	{
		UnderAttack = true;
		m_Storyquest = Quest1;
		return m_Storyquest;
		
	}
	else if (info.find("control panel") != string::npos && UnderAttack == true)
	{
		AttackingBack = true;
		m_Storyquest = Quest2;
		return m_Storyquest;
		
	}
	else if (info.find("heavy shipcannons") != string::npos&& AttackingBack == true)
	{
		FixingShip = true;
		m_Storyquest = Quest3;
		return m_Storyquest;
	}
	else if(info.find("time drive") && m_player->GetInventory()->SearchInventory("repair kit"))
	{
		ChapterEnd == true;
		m_Storyquest = Quest4;
		return m_Storyquest;
	}
	else 
	{
		return m_Storyquest;
	}
}

void TimeShip::Chapter1Update()
{
	m_CommandTest = CommandType::None;
	m_Input = m_InputReader->ReadInput();

	for (auto command : m_Input)
	{
		if (m_CommandsData->CheckCommand(command) != CommandType::None)
		{
			m_CommandTest = m_CommandsData->CheckCommand(command);
		}
		else
		{
			m_ExtraInfo += command + ' ';
		}

	}

		CheckStory(CheckQuest(m_ExtraInfo));

	m_CommandTest = CommandType::None;
	m_ExtraInfo.clear();
	m_Input.clear();
}

bool TimeShip::IsChapterDone()
{
	return ChapterEnd;
}



