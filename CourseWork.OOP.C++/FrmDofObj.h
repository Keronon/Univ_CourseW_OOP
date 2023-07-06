#ifndef FRMDOFOBJ_H
#define FRMDOFOBJ_H

#include "Frame.h"
#include "FrmTitle.h"

#include "Confection.h"
#include "Filling.h"

class FrmDofObj : public Frame		// Demo Of Objects
{
private:
	FrmDofObj& operator=(FrmDofObj&) {}

	///// Variables /////
	vector<Confection*> confections;
	vector<Filling*> fillings;

	vector<string> functionsSupportText;

	///// Initializers /////
	void initVariables() override;

public:
	// Constructors/Destructors
	FrmDofObj(vector<Frame*>* frames, ProcessData* process_data, map<string, int>* supported_keys);
	~FrmDofObj();

	///// Functions /////
	void update() override;

	///// operators /////
	friend std::ostream& operator<< (std::ostream &out, Confection &obj);
	friend std::ostream& operator<< (std::ostream &out, Filling &obj);
	friend std::istream& operator>> (std::istream &in, Filling &obj);
};

#endif