#ifndef PROCESSOR_H
#define PROCESSOR_H

#include "FrmLangSet.h"

class Processor
{
private:
	Processor();
	Processor(const Processor&);
	Processor& operator=(Processor&){}

	///// Variables /////
	static Processor* _processor;
	ProcessData processData;
	map<string, int> supportedKeys;

	vector<Frame*> frames;
	Confection* confection;

	// Initializers
	void initVariables();
	void initKeys();

public:
	// Constructors/Destructors
	virtual ~Processor();

	///// Functions /////
	static Processor* getProcessor();
	
	// Core
	void run();
};

#endif