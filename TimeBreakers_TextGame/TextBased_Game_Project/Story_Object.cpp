#include "stdafx.h"
#include "Story_Object.h"


Story_Object::Story_Object()
{

}


Story_Object::~Story_Object()
{

}

const vector<string>& Story_Object::GetObjectDescription()
{
	return m_Description;
}

const string & Story_Object::GetObjectName()
{
	return m_ObjectName;
}
