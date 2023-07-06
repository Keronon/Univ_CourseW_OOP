#ifndef FRMTITLE_H
#define FRMTITLE_H

#include "Frame.h"
#include "FrmEofSA.h"
#include "FrmDofObj.h"
#include "FrmSofHelp.h"

class FrmTitle : public Frame
{
private:
	FrmTitle& operator=(FrmTitle&) {}

	///// Variables /////

	///// Initializers /////
	void initVariables() override;

public:
	// Constructors/Destructors
	FrmTitle(vector<Frame*>* frames, ProcessData* process_data, map<string, int>* supported_keys);
	~FrmTitle();

	///// Functions /////
	void update() override;
};

#endif