#include "FrmEofSA.h"

///// Initializers /////
void FrmEofSA::initVariables()
{
	this->className = "FrmEofSA";
	this->textStringsCount = 19;

	stringstream ss;
	ss << "DeBUG::" << this->className << "::CORRECT::Variables_initializing\n";
	DeBUG::listing(ss.str());
}

///// Constructors/Destructors /////
FrmEofSA::FrmEofSA(vector<Frame*>* frames, ProcessData* process_data, map<string, int>* supported_keys)
	: Frame(frames, process_data, supported_keys)
{
	this->initVariables();
	initKeys("Resourses/Configs/" + this->className + ".keys");
	initText(this->processData->stringsPath + this->processData->language + "/" + this->className + "/text.strings");
	initMenu(this->processData->stringsPath + this->processData->language + "/" + this->className + "/menu.strings");

	show();

	stringstream ss;
	ss << "DeBUG::" << this->className << "::CORRECT::Creating::" << this << "\n\n";
	DeBUG::listing(ss.str());
}

FrmEofSA::~FrmEofSA() {}

///// Functions /////
void FrmEofSA::update()
{
	stringstream ss;
	ss << "\nDeBUG::" << this->className;

	char key = _getch();
	if (key == this->keys["LANGUAGE_RU"] || key == this->keys["LANGUAGE_EN"]) // если клавиша L
	{
		if (this->processData->language == "ru")
			this->processData->language = "en";
		else
			this->processData->language = "ru";

		this->quit = true;
		this->frames->insert(this->frames->cbegin(), new FrmEofSA(this->frames, this->processData, this->supportedKeys));
	}
	else
		if (key == this->keys["BACK"]) // если клавиша esc
		{
			this->quit = true;
			this->frames->insert(this->frames->cbegin(), new FrmTitle(this->frames, this->processData, this->supportedKeys));
		}

	ss << "::CORRECT::Updating\n";
	DeBUG::listing(ss.str());
}