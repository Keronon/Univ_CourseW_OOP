#ifndef CORE_H
#define CORE_H

// Core
#include <windows.h>
#include <exception>

#include <string>
#include <cstdlib>

#include <algorithm>
#include <cmath>

#include <iostream>
#include <sstream>
#include <fstream>
#include <conio.h>

#include <set>
#include <list>
#include <vector>
#include <map>
#include <deque>

#include <memory>
#include <stack>

#include <thread>
#include <utility>

// Namespaces
using namespace std;

// Structs
struct Date
{
	int year;
	int month;
	int day;
};

struct ProcessData
{
	string language = "ru";
	string stringsPath = "";
};

class DeBUG
{
public:
	static void clearFile()
	{
		ofstream outf("Resourses\\DeBUG.listing");
		outf << "";
		outf.close();
	}

	static void listing(string text)
	{
		ofstream outf("Resourses\\DeBUG.listing", ios::app);
		outf << text;
		outf.close();
	}
};

#endif