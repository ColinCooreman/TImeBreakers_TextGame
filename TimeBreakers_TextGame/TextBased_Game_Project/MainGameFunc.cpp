#include "stdafx.h"
#include "MainGameFunc.h"


MainGameFunc::MainGameFunc()
{
	m_Player = new Player();
}


MainGameFunc::~MainGameFunc()
{
	delete m_Player;
	m_Player = nullptr;
	delete m_InputReaderptr;
	m_InputReaderptr = nullptr;
	delete m_Chaper1;
	m_Chaper1 = nullptr;
}

void MainGameFunc::GameStart()
{
	system("mode 650");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	FileRead_Writer * Reader = new FileRead_Writer();
	vector<string> DataVec;
	SetColor(FOREGROUND_GREEN, handle, FOREGROUND_INTENSITY);
	
	//reading text
	Reader->FilterReadTxtFile("./Txt_and_dataFiles/Prologue.txt",'\n', DataVec);
	Reader->PrintStoryText(DataVec, false);
	m_InputReaderptr = new InputReader(m_Player);
	m_InputReaderptr->NameReaderInput();
	
	DataVec.clear();
	SetColor(FOREGROUND_BLUE, handle, FOREGROUND_INTENSITY);
	Reader->FilterReadTxtFile("./Txt_and_dataFiles/Instructions.txt",'\n', DataVec);
	Reader->PrintStoryText(DataVec,true);
	
	DataVec.clear();
	SetColor(FOREGROUND_GREEN, handle, FOREGROUND_INTENSITY);
	Reader->FilterReadTxtFile("./Txt_and_dataFiles/TimeShip.txt",'\n', DataVec);
	Reader->PrintStoryText(DataVec,false);

	m_Chaper1 = new TimeShip(m_Player);


}

void MainGameFunc::GameUpdate()
{
	while (m_stopUpdate == true)
	{
		m_LoopTime += 1;
		if (Chapter1 == true)
		{
			m_Chaper1->Chapter1Update();
		}
		
		if (m_LoopTime == 50)
		{
			m_stopUpdate = false;
		}
	}
	cin.get();
}

void MainGameFunc::SetColor(int color, const HANDLE & handle, int intensity)
{
	SetConsoleTextAttribute(handle, color | intensity);
}
