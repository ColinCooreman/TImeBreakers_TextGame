#pragma once
#include "FileRead_Writer.h"
#include "stdafx.h"
#include "Locations_Reader.h"
#include "Location.h"
#include "Commands.h"
#include "FileRead_Writer.h"
#include "player.h"
#include <unordered_map>
class InputReader : public FileRead_Writer
{
public:
	InputReader(Player *player1);
	~InputReader();

	void NameReaderInput();

	//these functions need to be moved to Location.h
	void LocationDescriptionOutput();

	//these functions need to be put in a Command.h
	void ExecuteCommand(const CommandType &command, string extraInfo);
	vector<string> ReadInput();
	char m_Name[256];
	void SetColor(int color, const HANDLE & handle, int intensity);
	const string& GetCurrentLocation();
	HANDLE m_handle;
	//string WaitForInput();

private:
	unordered_map<CommandType,vector<string>> CommandSynonym;
	Locations_Reader *m_LocationData = nullptr;
	FileRead_Writer *m_FileReader = nullptr;


	int m_InputSize = 20;
	char m_Command[1000];
	vector<string> m_DataVec;
	vector<string> m_Input;
	string m_ExtraInfo;
	string m_CurrentLocation = "yourroom";
	string m_CurrentLocationCheck = "";
	Player* m_player = nullptr;
	Commands *m_CommandsData = nullptr;
};

