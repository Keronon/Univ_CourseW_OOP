#ifndef FRMSOFHELP_H
#define FRMSOFHELP_H

#include "Frame.h"
#include "FrmTitle.h"
#include "FrmRforOper.h"
#include "FrmAtheProg.h"
#include "FrmAtheAuth.h"

class FrmSofHelp : public Frame		// System Of Help
{
private:
	FrmSofHelp& operator=(FrmSofHelp&) {}

	///// Variables /////

	///// Initializers /////
	void initVariables() override;

public:
	// Constructors/Destructors
	FrmSofHelp(vector<Frame*>* frames, ProcessData* process_data, map<string, int>* supported_keys);
	~FrmSofHelp();

	///// Functions /////
	void update() override;
};

#endif