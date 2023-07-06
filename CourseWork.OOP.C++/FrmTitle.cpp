#include "FrmTitle.h"

///// Initializers /////
void FrmTitle::initVariables()
{
	this->className = "FrmTitle";
	this->textStringsCount = 18;

	stringstream ss;
	ss << "DeBUG::" << this->className << "::CORRECT::Variables_initializing\n";
	DeBUG::listing(ss.str());
}

///// Constructors/Destructors /////
FrmTitle::FrmTitle(vector<Frame*>* frames, ProcessData* process_data, map<string, int>* supported_keys)
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

FrmTitle::~FrmTitle(){}

///// Functions /////
void FrmTitle::update()
{
	stringstream ss;
	ss << "\nDeBUG::" << this->className;

	char key = _getch();
	if (key != '\0') {}
	if (key == this->keys["EofSA"]) // если клавиша 1
	{
		this->quit = true;
		this->frames->insert(this->frames->cbegin(), new FrmEofSA(this->frames, this->processData, this->supportedKeys));
	}
	else
	if (key == this->keys["DofObj"]) // если клавиша 2
	{
		this->quit = true;
		this->frames->insert(this->frames->cbegin(), new FrmDofObj(this->frames, this->processData, this->supportedKeys));
	}
	else
	if (key == this->keys["SofHelp"]) // если клавиша 3
	{
		this->quit = true;
		this->frames->insert(this->frames->cbegin(), new FrmSofHelp(this->frames, this->processData, this->supportedKeys));
	}
	else
	if (key == this->keys["LANGUAGE_RU"] || key == this->keys["LANGUAGE_EN"]) // если клавиша L
	{
		if (this->processData->language == "ru")
			this->processData->language = "en";
		else
			this->processData->language = "ru";

		this->quit = true;
		this->frames->insert(this->frames->cbegin(), new FrmTitle(this->frames, this->processData, this->supportedKeys));
	}
	else
	if (key == this->keys["QUIT"]) // если клавиша esc
	{
		this->quit = true;
	}

	ss << "::CORRECT::Updating\n";
	DeBUG::listing(ss.str());
}