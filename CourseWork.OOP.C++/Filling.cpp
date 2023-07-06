#include "Filling.h"

Filling::Filling(string name)
{
	this->name = name;
	this->number = 0;

	stringstream ss;
	ss << "\nDeBUG::Filling::CORRECT::Creating::" << this << "::" << this->name << endl;
	DeBUG::listing(ss.str());
}

Filling::~Filling()
{
	this->ingredients.clear();

	stringstream ss;
	ss << "DeBUG::Filling::CORRECT::Deleting::" << this << "::" << this->name << endl;
	DeBUG::listing(ss.str());
}

void Filling::AddIngredient(string ingredient)
{
	this->ingredients.push_back(ingredient);

	stringstream ss;
	ss << "DeBUG::Filling::CORRECT::Ingredient_adding::" << this->name << "::" << this->ingredients.back() << endl;
	DeBUG::listing(ss.str());
}

void Filling::DelIngredient(int ingredient_num)
{
	stringstream ss;
	ss << "DeBUG::Filling::CORRECT::Ingredient_deleting::" << this->name << "::" << this->ingredients[ingredient_num] << endl;
	DeBUG::listing(ss.str());

	this->ingredients[ingredient_num].clear();
	this->ingredients.resize(this->ingredients.size());
}

vector<string> Filling::to_string()
{
	vector<string> params = this->ingredients;

	params.insert(params.cbegin(), this->name);
	return params;
}