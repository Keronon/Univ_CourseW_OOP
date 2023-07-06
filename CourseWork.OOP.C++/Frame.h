#ifndef FRAME_H
#define FRAME_H

#include "ConsoleColorControl.h"
#include "StringProcesses.h"

#include "Confection.h"

class Frame : public StringProcesses, public ConsoleColorControl
{
protected:
	///// Variables /////
	string className;
	int textStringsCount;
	bool quit;

	vector<Frame*>* frames;
	ProcessData* processData;

	map<string, int>* supportedKeys;
	map<string, int> keys;
	map<string, string> menu;
	vector<string> text;

	///// Initializers /////
	virtual void initVariables() {}
	void initKeys(string keys_path);
	void initText(string text_path);
	void initMenu(string menu_path);

public:
	// Constructors/Destructors
	Frame(vector<Frame*>* frames, ProcessData* process_data, map<string, int>* supported_keys);
	virtual ~Frame();

	///// Functions /////
	bool getQuit();
	void show();

	virtual void update() {}
};

#endif