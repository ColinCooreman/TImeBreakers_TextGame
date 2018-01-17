#pragma once
#include "FileRead_Writer.h"
#include "stdafx.h"
#include <unordered_map>

class Description_Reader
{
public:
	Description_Reader(const vector<string> dataVec);
	~Description_Reader();
	void DescriptionReader(string PlaceName);
	unordered_map<string, vector<string>> GetDescriptionsMap();
	vector<string> GetDescription(string PlaceName);
private:

	vector<string> m_DataVec;
	unordered_map<string, vector<string>> m_Descriptions;
};

