#pragma once
#include "stdafx.h"
#include "FileRead_Writer.h"
#include <unordered_map>
#include "Description_Reader.h"
#include "Story_Object.h"
#include "InputReader.h"
#include "Player.h"
class TimeShip
{
public:
	TimeShip(Player *player1);
	virtual ~TimeShip();
	void Chapter1Update();
	bool IsChapterDone();
private:
	void CheckStory(StoryQuest story);
	StoryQuest CheckQuest(string &info);
	FileRead_Writer * m_FileReader;
	unordered_map<string, vector<string>> m_LocationObjects;
	vector<string> m_DataVec;
	bool Once = false;
	unordered_map<string, vector<string>> m_Descriptions;

	InputReader* m_InputReader;
	vector<string> m_Input;

	string m_ExtraInfo;
	CommandType m_CommandTest;
	Commands *m_CommandsData = nullptr;
	StoryQuest m_Storyquest = StoryQuest::Nothing;
	Player *m_player = nullptr;
	bool ChapterEnd = false;
	bool UnderAttack = false;
	bool FixingShip = false;
	bool AttackingBack = false;


};

