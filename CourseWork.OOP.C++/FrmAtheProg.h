#ifndef FRMATHEPROG_H
#define FRMATHEPROG_H

#include "Frame.h"
#include "FrmSofHelp.h"

class FrmAtheProg : public Frame // About the Programm
{
private:
	FrmAtheProg& operator=(FrmAtheProg&) {}

	///// Variables /////

	///// Initializers /////
	void initVariables() override;

public:
	// Constructors/Destructors
	FrmAtheProg(vector<Frame*>* frames, ProcessData* process_data, map<string, int>* supported_keys);
	~FrmAtheProg();

	///// Functions /////
	void update() override;
};

#endif