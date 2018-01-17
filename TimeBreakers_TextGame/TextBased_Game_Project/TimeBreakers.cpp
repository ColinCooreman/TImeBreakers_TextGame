// TimeBreakers.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "MainGameFunc.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	MainGameFunc* mainGame = new MainGameFunc();
	mainGame->GameStart();
	mainGame->GameUpdate();
}

