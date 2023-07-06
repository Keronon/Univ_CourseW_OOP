#ifndef FILLING_H
#define FILLING_H

#include "Core.h"

class Filling
{
private:
	///// Variables /////
	string name;					// «Название»
	int number;						// «количество ингредиентов»

	vector<string> ingredients;		// ингридиенты

public:
	// Constructors/Destructors
	Filling(string name);
	~Filling();

	///// Functions /////
	void AddIngredient(string ingredient);			// метод «Добавить ингредиент»
	void DelIngredient(int ingredient);				// метод «Удалить ингредиент»

	Filling& operator++ () { ++number; return *this; }

	vector<string> to_string();
};

#endif