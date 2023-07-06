#ifndef FILLING_H
#define FILLING_H

#include "Core.h"

class Filling
{
private:
	///// Variables /////
	string name;					// ���������
	int number;						// ����������� ������������

	vector<string> ingredients;		// �����������

public:
	// Constructors/Destructors
	Filling(string name);
	~Filling();

	///// Functions /////
	void AddIngredient(string ingredient);			// ����� ��������� ����������
	void DelIngredient(int ingredient);				// ����� �������� ����������

	Filling& operator++ () { ++number; return *this; }

	vector<string> to_string();
};

#endif