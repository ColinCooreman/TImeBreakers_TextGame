#pragma once
#include "Description_Reader.h"
#include "stdafx.h"
#include "FileRead_Writer.h"
class Story_Object
{
public:
	Story_Object();
	~Story_Object();
	const vector<string> &GetObjectDescription();
	const string &GetObjectName();

	void SetObjectName(string object)
	{
		m_ObjectName = object;
	}
	void SetObjectDescription(vector<string> description)
	{
		m_Description = description;
	}

private:

	string m_ObjectName;
	vector<string> m_Description;
};

