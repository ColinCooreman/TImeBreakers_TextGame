#include "stdafx.h"
#include "NPC.h"


NPC::NPC()
{
}


NPC::~NPC()
{
}

const string & NPC::GetNPCName()
{
	return m_NPCname;
}

const vector<string> & NPC::GetNPCDialogue()
{
	return m_NPCDialogue;
}

const NPCType & NPC::GetNPCType()
{
	return m_NPCType;
}
