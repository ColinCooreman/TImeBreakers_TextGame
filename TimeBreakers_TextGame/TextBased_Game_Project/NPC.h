#pragma once
#include "stdafx.h"
class NPC
{
public:
	NPC();
	~NPC();

	const string &GetNPCName();
	const vector<string> &GetNPCDialogue();
	const NPCType &GetNPCType();
	void SetNPCName(string npcName)
	{
		m_NPCname = npcName;
	}
	void SetNPCDialogue(vector<string> npcDialogue)
	{
		m_NPCDialogue = npcDialogue;
	}
	void SetNPCType(NPCType npcType)
	{
		m_NPCType = npcType;
	}

private:
	string m_NPCname;
	vector<string> m_NPCDialogue;
	int Health;
	NPCType m_NPCType = NPCType::normal;
};

