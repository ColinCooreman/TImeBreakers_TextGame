// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <stdlib.h>  
#include <crtdbg.h> 



using namespace std;

enum CommandType
{
	Move,
	Use,
	Attack,
	Look,
	Grab,
	Where,
	Map,
	Speak,
	None
};
enum itemType
{
	Weapon,
	Clothes,
	Key_item
};
enum NPCType
{
	enemy,
	merchant,
	normal
};

enum StoryQuest
{
	Quest1,
	Quest2,
	Quest3,
	Quest4,
	Quest5,
	Quest6,
	Quest7,
	Quest8,
	Quest9,
	Quest10,
	Nothing
};