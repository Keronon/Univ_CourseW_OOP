#ifndef CONFECTION_H
#define CONFECTION_H

#include "Filling.h"

class Confection
{
private:
	///// Variables /////
	string name;				// «Название»
	Date productDate;			// «Дата изготовления»
	Date bestBefore;			// «Срок годности»
	vector<Filling*> filling;	// «Начинка»

public:
	// Constructors/Destructors
	Confection(string name, Date product_date, Date best_before, vector<Filling*> filling);
	virtual ~Confection();

	Confection& operator~ ();			// новое действие - удалить начинку

	///// Functions /////
	string GetName();					// метод получения названия
	Date GetProductDate();				// метод получения даты изготовления
	void AddFilling(Filling* filling);	// метод добавления начинки
	
	vector<string> to_string();
};

#endif