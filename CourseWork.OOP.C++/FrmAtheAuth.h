#ifndef FRMATHEAUTH_H
#define FRMATHEAUTH_H

#include "Frame.h"
#include "FrmSofHelp.h"

class FrmAtheAuth : public Frame // About the Author
{
private:
	FrmAtheAuth& operator=(FrmAtheAuth&) {}

	///// Variables /////

	///// Initializers /////
	void initVariables() override;

public:
	// Constructors/Destructors
	FrmAtheAuth(vector<Frame*>* frames, ProcessData* process_data, map<string, int>* supported_keys);
	~FrmAtheAuth();

	///// Functions /////
	void update() override;
};

#endif