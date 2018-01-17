#pragma once
#include "stdafx.h"
#include "FileRead_Writer.h"
#include "InputReader.h"
#include "TimeShip.h"
#include "Player.h"
class MainGameFunc
{
public:
	MainGameFunc();
	~MainGameFunc();
	void GameStart();
	void GameUpdate();
private:

	Player *m_Player;
	bool m_stopUpdate = true;
	bool m_Reset = false;
	string m_CurrentLocation = "TimeShip";
	int m_LoopTime = 0;
	void SetColor(int color, const HANDLE &handle, int intensity);
	InputReader *m_InputReaderptr = nullptr;
	TimeShip* m_Chaper1 = nullptr;
	bool Chapter1 = true;
	bool Chapter2 = false;
	bool Chapter3 = false;
};

