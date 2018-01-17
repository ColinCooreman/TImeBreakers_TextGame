#pragma once
#include "stdafx.h"
class FileRead_Writer
{
public:
	FileRead_Writer() 
	{

	};
	~FileRead_Writer()
	{

	};

	void FilterReadTxtFile(const string &path,char filter, vector<string> &data)
	{
		ifstream ifileStream;
		ifileStream.open(path);
		string extractedLine;

		//*********************************//FILE reading
		if (ifileStream.fail() == true)
		{
			return;
		}
		while (ifileStream.eof() == false)
		{
			getline(ifileStream, extractedLine, filter);
			data.push_back(extractedLine);
		}
		ifileStream.close();
		//**********************
	}
	ifstream TxtToIfstream(const string &path)
	{
		ifstream ifileStream;
		ifileStream.open(path);
		return ifileStream;
	}

	void PrintStoryText( const vector<string> &data ,bool printLines)
	{
		
		for (auto line : data)
		{
			if (printLines == true)
			{
				cout << line;
				Sleep(100);
			}
			else
			{
				for each(char i in line)
				{
					cout << i;
					Sleep(30);

				}
			}

			cout << endl;
		}
		
	}
	void Split(string toSplit, const char &splitBy, vector<string>& result)
	{
		string input = toSplit;
		istringstream ss(input);
		string token;
		while (getline(ss, token, splitBy))
		{
			result.push_back(token);
		}
	}

};

