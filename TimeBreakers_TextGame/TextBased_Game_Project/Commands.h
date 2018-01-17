#pragma once
#include "FileRead_Writer.h"
#include "stdafx.h"
#include <unordered_map>
class Commands :
	public FileRead_Writer
{
public:
	Commands();
	~Commands();

	void AddCommandsVec(const string commandId, const string commanConn);
	CommandType CheckCommand(string command);

private:
	unordered_map<CommandType, vector<string>> CommandSynonym;
	vector<string> m_DataVec;
};

