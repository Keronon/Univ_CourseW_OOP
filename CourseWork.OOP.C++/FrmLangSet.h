#ifndef FRMEOFSA_H
#define FRMEOFSA_H

#include "Frame.h"
#include "FrmTitle.h"

class FrmLangSet : public Frame		// Language Set
{
private:
	FrmLangSet& operator=(FrmLangSet&) {}

	///// Variables /////

	///// Initializers /////
	void initVariables() override;

	void initStringsPath();

public:
	// Constructors/Destructors
	FrmLangSet(vector<Frame*>* frames, ProcessData* process_data, map<string, int>* supported_keys);
	~FrmLangSet();

	///// Functions /////
	void update() override;
};

#endif