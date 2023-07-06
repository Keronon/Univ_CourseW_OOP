#ifndef STRINGPROCESSES_H
#define STRINGPROCESSES_H

#include "Core.h"

class StringProcesses
{
protected:

	///// TRIM-functionality /////
	string WHITESPACE = " \n\r\t\f\v";

	string ltrim(const string& s)
	{
		size_t start = s.find_first_not_of(WHITESPACE);
		return (start == string::npos) ? "" : s.substr(start);
	}

	string rtrim(const string& s)
	{
		string WHITESPACE = " \n\r\t\f\v";
		size_t end = s.find_last_not_of(WHITESPACE);
		return (end == string::npos) ? "" : s.substr(0, end + 1);
	}

	string trim(const string& s)
	{
		return rtrim(ltrim(s));
	}
	//////////////////////////////

	vector<string> split(string str, string delimiter)
	{
		vector<string> parts;

		size_t pos = 0;

		while ((pos = str.find(delimiter)) != string::npos)
		{
			parts.push_back(str.substr(0, pos));
			str.erase(0, pos + delimiter.length());
		}
		parts.push_back(str);

		return parts;
	}
};

#endif