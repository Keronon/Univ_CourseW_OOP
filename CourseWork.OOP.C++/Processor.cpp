#include "Processor.h"

Processor* Processor::_processor = NULL;

///// Initializers /////
void Processor::initVariables()
{
	DeBUG::listing("DeBUG::Processor::CORRECT::Variables_initializing\n");
}

void Processor::initKeys()
{
	stringstream ss;
	ss << "\nDeBUG::Processor";

	ifstream ifs("Resourses/Configs/all_supported.keys");

	if (ifs.is_open())
	{
		string key = "";
		int key_value = 0;

		while (ifs >> key >> key_value)
		{
			this->supportedKeys[key] = key_value;
		}

		ss << "::CORRECT::Supported_keys_initializing::\n";
		for (auto i : this->supportedKeys)
		{
			ss << i.first << " " << i.second << "\n";
		}
	}
	else ss << "::!ERROR!::Supported_keys_initializing\n";
	ss << "\n";
	DeBUG::listing(ss.str());
	ifs.close();
}

///// Constructors/Destructors /////
Processor::Processor()
{
	DeBUG::clearFile();
	this->initVariables();
	this->initKeys();

	stringstream ss;
	ss << "DeBUG::Processor::CORRECT::Creating::" << this << "\n";
	DeBUG::listing(ss.str());
}

Processor::~Processor()
{
	while (!this->frames.empty())
	{
		delete this->frames.back();
		this->frames.pop_back();
	}

	stringstream ss;
	ss << "DeBUG::Processor::CORRECT::Deleting::" << this << "\n";
	DeBUG::listing(ss.str());
}

Processor* Processor::getProcessor()
{
	if (!_processor)
		_processor = new Processor();

	return _processor;
}

///// Functions /////
void Processor::run()
{
	stringstream ss;
	ss << "DeBUG::Processor::CORRECT::Starting::" << this << "\n\n";
	DeBUG::listing(ss.str());

	// frames processor
	this->frames.push_back(new FrmLangSet(&this->frames, &this->processData, &this->supportedKeys));
	do
	{
		this->frames.back()->update();

		if (this->frames.back()->getQuit())
		{
			delete this->frames.back();
			this->frames.pop_back();
		}
	}
	while (!this->frames.empty());
	delete this; //Application end
}