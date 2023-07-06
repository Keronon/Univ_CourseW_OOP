#ifndef CONFECTION_H
#define CONFECTION_H

#include "Filling.h"

class Confection
{
private:
	///// Variables /////
	string name;				// ���������
	Date productDate;			// ����� �������������
	Date bestBefore;			// ����� ��������
	vector<Filling*> filling;	// ��������

public:
	// Constructors/Destructors
	Confection(string name, Date product_date, Date best_before, vector<Filling*> filling);
	virtual ~Confection();

	Confection& operator~ ();			// ����� �������� - ������� �������

	///// Functions /////
	string GetName();					// ����� ��������� ��������
	Date GetProductDate();				// ����� ��������� ���� ������������
	void AddFilling(Filling* filling);	// ����� ���������� �������
	
	vector<string> to_string();
};

#endif