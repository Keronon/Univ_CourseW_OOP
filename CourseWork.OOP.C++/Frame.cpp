#include "Frame.h"

///// Initializers /////
void Frame::initKeys(string keys_path)
{
	stringstream ss;
	ss << "\nDeBUG::" << this->className;

	ifstream ifs(keys_path);
	if (ifs.is_open())
	{
		string key = "";
		string key_value = "";

		while (ifs >> key >> key_value)
		{
			this->keys[key] = this->supportedKeys->at(key_value);
		}

		ss << "::CORRECT::Keys_initializing::\n";
		for (auto i : this->keys)
		{
			ss << i.first << " " << i.second << "\n";
		}
	}
	else ss << "::!ERROR!::Keys_initializing\n";
	ss << endl;
	DeBUG::listing(ss.str());
	ifs.close();
}

void Frame::initText(string text_path)
{
	stringstream ss;
	ss << "DeBUG::" << this->className;

	ifstream ifs(text_path);
	try
	{
		if (ifs.is_open())
		{
			string text = "";

			while (!ifs.eof())
			{
				getline(ifs, text);
				this->text.push_back(text);
			}
			if (this->text.size() != textStringsCount | (this->text.size() == 1 && this->text[0] == "\0")) throw exception();
		}
		else throw exception();

		ss << "::CORRECT::Text_initializing\n";
	}
	catch (exception)
	{
		ss << "::!ERROR!::Text_initializing\n";

		setConsoleColor(LIGHT_WHITE, RED);
		if (this->processData->language == "ru") cout
			<< "\nВ процессе инициализации текста были обнаружены ошибки.\n"
			<< "проверьте файлы приложения\n\n";
		else cout
			<< "\nErrors were encountered during text initialization.\n"
			<< "check your application files\n\n";
		setDefaultConsoleColor();

		system("pause");

		this->quit = true;
	}

	DeBUG::listing(ss.str());
	ifs.close();
}

void Frame::initMenu(string menu_path)
{
	stringstream ss;
	ss << "DeBUG::" << this->className;

	ifstream ifs(menu_path);
	if (ifs.is_open())
	{
		string key = "";
		string keyValue = "";

		while (!ifs.eof())
		{
			ifs >> key;
			getline(ifs, keyValue);
			this->menu[key] = trim(keyValue);
		}

		ss << "::CORRECT::Menu_initializing\n";
	}
	else ss << "::!ERROR!::Menu_initializing\n";
	DeBUG::listing(ss.str());
	ifs.close();
}

///// Constructors/Destructors /////
Frame::Frame(vector<Frame*>* frames, ProcessData* process_data, map<string, int>* supported_keys)
{
	this->frames = frames;
	this->processData = process_data;
	this->supportedKeys = supported_keys;

	DeBUG::listing("DeBUG::Frame_core::CORRECT::Creating\n\n");
}

Frame::~Frame()
{
	this->keys.clear();
	this->menu.clear();
	this->text.clear();
	this->text.resize(this->text.size());

	stringstream ss;
	ss << "DeBUG::Frame_core of " << this->className << "::CORRECT::Deleting\n";
	DeBUG::listing(ss.str());
}

///// Functions /////

bool Frame::getQuit()
{
	stringstream ss;
	ss << "DeBUG::Frame_core of " << this->className << "::CORRECT::Quit_sent::" << this->quit << endl;
	DeBUG::listing(ss.str());

	return this->quit;
}

void Frame::show()
{
	stringstream ss;
	ss << "DeBUG::Frame_core of " << this->className << "::CORRECT::Show\n";
	DeBUG::listing(ss.str());

	system("cls");
	for (string str : text)
	{
		cout << str << endl;
	}
	cout << endl;
	if (menu.size() > 1)
		if (this->processData->language == "ru")
			for (pair<string, string> element : menu)
			{
				cout << "Нажмите " << element.first << " для " << element.second << endl;
			}
		else
			for (pair<string, string> element : menu)
			{
				cout << "Press " << element.first << " for " << element.second << endl;
			}
}