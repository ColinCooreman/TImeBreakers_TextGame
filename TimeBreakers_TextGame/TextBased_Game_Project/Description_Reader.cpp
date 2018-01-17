#include "stdafx.h"
#include "Description_Reader.h"


Description_Reader::Description_Reader(const vector<string> dataVec): m_DataVec(dataVec)
{
}


Description_Reader::~Description_Reader()
{

}

void  Description_Reader::DescriptionReader(string Name)
{
	pair<string, vector<string>> description;
	string temp;
	vector<string> tempVec;
	for (size_t i = 0; i < m_DataVec.size(); i++)
	{

		if (m_DataVec[i].find(Name) != string::npos)
		{
			size_t start = m_DataVec[i].find(Name);
			std::transform(Name.begin(), Name.end(), Name.begin(), ::tolower);
			description.first = Name;


			if (m_DataVec[i].find("//") != string::npos)// -2 doen gewoon ipv start
			{
				size_t end = m_DataVec[i].find("//") - (Name.size() + 1);
				auto data = m_DataVec[i].substr(Name.size() + 1, end);
				description.second.push_back(data);
			}

		}

	}
	m_Descriptions.insert(description);
}

unordered_map<string, vector<string>> Description_Reader::GetDescriptionsMap()
{
	return m_Descriptions;
}

vector<string> Description_Reader::GetDescription(string Name)//wrong name = acces violation? why
{
	vector<string> description;
	std::transform(Name.begin(), Name.end(), Name.begin(), ::tolower);
	for (auto Object : m_Descriptions)
	{
		if (Object.first == Name)
		{
			description = Object.second;
		}
	}
	return description;
}