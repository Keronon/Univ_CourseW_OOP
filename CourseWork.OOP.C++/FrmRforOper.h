#ifndef FRMRFOROPER_H
#define FRMRFOROPER_H

#include "Frame.h"
#include "FrmSofHelp.h"

class FrmRforOper : public Frame // Rules for Operator
{
private:
	FrmRforOper& operator=(FrmRforOper&) {}

	///// Variables /////

	///// Initializers /////
	void initVariables() override;

public:
	// Constructors/Destructors
	FrmRforOper(vector<Frame*>* frames, ProcessData* process_data, map<string, int>* supported_keys);
	~FrmRforOper();

	///// Functions /////
	void update() override;
};

#endif