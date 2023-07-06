#ifndef FRMEOFSA_H
#define FRMEOFSA_H

#include "Frame.h"
#include "FrmTitle.h"

class FrmEofSA : public Frame	// Exposition Of Subject Area	
{
private:
	FrmEofSA& operator=(FrmEofSA&) {}

	///// Variables /////

	///// Initializers /////
	void initVariables() override;

public:
	// Constructors/Destructors
	FrmEofSA(vector<Frame*>* frames, ProcessData* process_data, map<string, int>* supported_keys);
	~FrmEofSA();

	///// Functions /////
	void update() override;
};

#endif