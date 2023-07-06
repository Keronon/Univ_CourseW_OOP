#include "Confection.h"

Confection::Confection(string name, Date product_date, Date best_before, vector<Filling*> filling)
{
	this->name = name;
	this->productDate = product_date;
	this->bestBefore = best_before;
	this->filling = filling;

	stringstream ss;
	ss << "\nDeBUG::Confection::CORRECT::Creating::" << this << "::" << this->name << endl;
	DeBUG::listing(ss.str());
}

Confection::~Confection()
{
	this->filling.clear();

	stringstream ss;
	ss << "DeBUG::Confection::CORRECT::Deleting::" << this << "::" << this->name << endl;
	DeBUG::listing(ss.str());
}

Confection& Confection::operator~ ()
{
	this->filling.clear();

	stringstream ss;
	ss << "DeBUG::Confection::CORRECT::Fillings_clearing::" << this << "::" << this->name << endl;
	DeBUG::listing(ss.str());

	return *this;
}

string Confection::GetName()
{
	stringstream ss;
	ss << "DeBUG::Confection::CORRECT::Name_sent::" << this << "::" << this->name << endl;
	DeBUG::listing(ss.str());

	return this->name;
}

Date Confection::GetProductDate()
{
	stringstream ss;
	ss << "DeBUG::Confection::CORRECT::ProductDate_sent::" << this << "::" << this->name << endl;
	DeBUG::listing(ss.str());

	return this->productDate;
}

void Confection::AddFilling(Filling* filling)
{
	this->filling.push_back(filling);

	stringstream ss;
	ss << "DeBUG::Confection::CORRECT::Filling_adding::" << this->name << "::" << this->filling.back()->to_string()[0] << endl;
	DeBUG::listing(ss.str());
}

vector<string> Confection::to_string()
{
	vector<string> params;
	params.push_back(this->name);

	stringstream ss;
	ss << this->productDate.day << "." << this->productDate.month << "." << this->productDate.year;
	params.push_back(ss.str());

	ss.str("");
	ss << this->bestBefore.day << "." << this->bestBefore.month << "." << this->bestBefore.year;
	params.push_back(ss.str());

	for (int i = 0; i < this->filling.size(); i++)
	{
		params.push_back(this->filling[i]->to_string()[0]);
	}

	return params;
}
