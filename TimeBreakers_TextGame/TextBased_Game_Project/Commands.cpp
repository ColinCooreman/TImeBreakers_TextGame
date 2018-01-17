#include "stdafx.h"
#include "Commands.h"


Commands::Commands()
{
	FilterReadTxtFile("./Txt_and_dataFiles/Commands.txt", '\n', m_DataVec);
	AddCommandsVec("(01)", "[01]");
	AddCommandsVec("(02)", "[02]");
	AddCommandsVec("(03)", "[03]");
	AddCommandsVec("(04)", "[04]");
	AddCommandsVec("(05)", "[05]");
	AddCommandsVec("(06)", "[06]");
	AddCommandsVec("(07)", "[07]");
	m_DataVec.clear();

}


Commands::~Commands()
{
}
void Commands::AddCommandsVec(const string commandId, const string commanConn)
{
	auto ConverToCommand = [](string command)
	{
		if (command == "Use")
		{
			return Use;
		}
		else if (command == "Move")
		{
			return Move;
		}
		else if (command == "Attack")
		{
			return Attack;
		}
		else if (command == "Look")
		{
			return Look;
		}
		else if (command == "Grab")
		{
			return Grab;
		}
		else if (command == "Map")
		{
			return Map;
		}
		else if (command == "Speak")
		{
			return Speak;
		}
	};
	pair<CommandType, vector<string>> CommandPair;
	string temp;
	for (auto data : m_DataVec)
	{
		if (data.find(commandId) != string::npos)
		{

			size_t Place = data.find(commandId);
			CommandPair.first = ConverToCommand(data.substr(Place + 4, data.size()));

		}
		if (data.find(commanConn) != string::npos)
		{
			size_t Place = data.find(commanConn);
			temp = data.substr(Place + 4, data.size());
			std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
			Split(temp, ',', CommandPair.second);


		}

	}
	CommandSynonym.insert(CommandPair);
}
CommandType Commands::CheckCommand(string command)
{
	

	auto CheckCommand = [command](pair<CommandType, vector<string>> Commands) 
	{
		bool check = false;
		for (auto com : Commands.second)
		{
			check = (com == command);
			if (check == true)
			{
				return check;
			}
		}
		return check;
	};
	// find_if
	auto it = find_if(CommandSynonym.begin(), CommandSynonym.end(), CheckCommand);
	if (it != CommandSynonym.end())
	{
		return (*it).first;
	}
	return None;
}
