#include "FrmDofObj.h"

///// Initializers /////
void FrmDofObj::initVariables()
{
	this->className = "FrmDofObj";
	this->textStringsCount = 1;

	for (int i = 0; i < 4; i++)
	{
		ifstream ifs(this->processData->stringsPath + this->processData->language + "/" + this->className + "/" + to_string(i) + ".function");
		if (ifs.is_open())
		{
			string text = "";
			string tmp = "";

			while (!ifs.eof())
			{
				getline(ifs, text);
				tmp += text + "\n";
			}

			this->functionsSupportText.push_back(tmp);
		}
		ifs.close();
	}

	stringstream ss;
	ss << "DeBUG::" << this->className << "::CORRECT::Variables_initializing\n";
	DeBUG::listing(ss.str());
}

///// Constructors/Destructors /////
FrmDofObj::FrmDofObj(vector<Frame*>* frames, ProcessData* process_data, map<string, int>* supported_keys)
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

FrmDofObj::~FrmDofObj() {}

///// Functions /////
void FrmDofObj::update()
{
	stringstream ss;
	ss << "\nDeBUG::" << this->className;

	char key = _getch();
	if (key == this->keys["C_NEW"]) // если клавиша 1
	{
		show();
		cout << "\n";

		cout << functionsSupportText[0];
		cout << "\n";

		string tmp;
		vector<string> tmpV;

		string name;
		Date product_date;
		Date best_before;
		vector<Filling*> filling;

		setConsoleColor(LIGHT_WHITE, SAPPHIRINE);
		cin >> name;

		cin >> tmp;
		tmpV = split(tmp, ".");
		product_date.day = stoi(tmpV[0]);
		product_date.month = stoi(tmpV[1]);
		product_date.year = stoi(tmpV[2]);

		cin >> tmp;
		tmpV = split(tmp, ".");
		best_before.day = stoi(tmpV[0]);
		best_before.month = stoi(tmpV[1]);
		best_before.year = stoi(tmpV[2]);

		getline(cin, tmp);
		getline(cin, tmp);
		tmpV = split(tmp, " ");
		setDefaultConsoleColor();

		for (int i = 0; i < tmpV.size(); i++)
		{
			for (int j = 0; j < this->fillings.size(); j++)
			{
				if (tmpV[i] == this->fillings[j]->to_string()[0]) filling.push_back(this->fillings[j]);
			}
		}

		this->confections.push_back(new Confection(name, product_date, best_before, filling));

		cout << "\nOK\n\n";
		system("pause");
		show();
	}
	else
	if (key == this->keys["C_SEE"]) // если клавиша 2
	{
		show();
		cout << "\n";

		string str = "";
		for (int i = 0; i < this->confections.size(); i++)
		{
			vector<string> strgs;
			strgs = this->confections[i]->to_string();
			for (int j = 0; j < strgs.size(); j++)
			{
				str += strgs[j] + " ";
			}
			str += "\n";
		}
		cout << str;

		cout << "\n";
		system("pause");
		show();
	}
	else
	if (key == this->keys["F_NEW"]) // если клавиша 3
	{
		show();
		cout << "\n";

		cout << functionsSupportText[1];
		cout << "\n";

		string name;

		setConsoleColor(LIGHT_WHITE, SAPPHIRINE);
		cin >> name;
		setDefaultConsoleColor();

		this->fillings.push_back(new Filling(name));

		cout << "\nOK\n\n";
		system("pause");
		show();
	}
	else
	if (key == this->keys["F_SEE"]) // если клавиша 4
	{
		show();
		cout << "\n";

		string str = "";
		for (int i = 0; i < this->fillings.size(); i++)
		{
			vector<string> strgs;
			strgs = this->fillings[i]->to_string();
			for (int j = 0; j < strgs.size(); j++)
			{
				str += strgs[j] + " ";
			}
			str += "\n";
		}
		cout << str;

		cout << "\n";
		system("pause");
		show();
	}
	else
	if (key == this->keys["C_SHOW"]) // если клавиша 5
	{
		show();
		cout << "\n";

		cout << functionsSupportText[2];
		cout << "\n";

		int num;

		setConsoleColor(LIGHT_WHITE, SAPPHIRINE);
		cin >> num;
		setDefaultConsoleColor();

		if (num > 0 && num < this->confections.size())
		{
			vector<string> strgs;
			strgs = this->confections[num - 1]->to_string();
			cout << "\n";
			for (int i = 0; i < strgs.size(); i++)
			{
				cout << strgs[i] + " ";
			}
			cout << "\n";
		}

		cout << "\n";
		system("pause");
		show();
	}
	else
	if (key == this->keys["F_SHOW"]) // если клавиша 6
	{
		show();
		cout << "\n";

		cout << functionsSupportText[3];
		cout << "\n";

		int num;

		setConsoleColor(LIGHT_WHITE, SAPPHIRINE);
		cin >> num;
		setDefaultConsoleColor();

		if (num > 0 && num <= this->fillings.size())
		{
			vector<string> strgs;
			strgs = this->fillings[num - 1]->to_string();
			cout << "\n";
			for (int i = 0; i < strgs.size(); i++)
			{
				cout << strgs[i] + " ";
			}
			cout << "\n";
		}

		cout << "\n";
		system("pause");
		show();
	}
	else
	if (key == this->keys["BACK"]) // если клавиша esc
	{
		this->quit = true;
		this->frames->insert(this->frames->cbegin(), new FrmTitle(this->frames, this->processData, this->supportedKeys));
	}
	else
	if (key == this->keys["LANGUAGE_RU"] || key == this->keys["LANGUAGE_EN"]) // если клавиша L
	{
		if (this->processData->language == "ru")
			this->processData->language = "en";
		else
			this->processData->language = "ru";

		this->quit = true;
		this->frames->insert(this->frames->cbegin(), new FrmDofObj(this->frames, this->processData, this->supportedKeys));
	}

	ss << "::CORRECT::Updating\n";
	DeBUG::listing(ss.str());
}

std::ostream& operator<< (std::ostream &out, Confection &obj)
{
	vector<string> params = obj.to_string();

	out << "\n" << params[0] << "\n";
	out << params[1] << "\n";
	out << params[2] << "\n";
	for (int i = 3; i < params.size(); i++)
	{
		out << params[i] << "\n";
	}
	out << "\n";
	return out;
}

std::ostream& operator<< (std::ostream &out, Filling &obj)
{
	vector<string> params = obj.to_string();

	out << "\n" << params[0] << "\n";
	for (int i = 1; i < params.size(); i++)
	{
		out << params[i] << "\n";
	}
	out << "\n";
	return out;
}

std::istream& operator>> (std::istream &in, Filling &obj)
{
	string key;
	cout << "Введите ингридиент для начинки:\n";
	cin >> key;
	obj.AddIngredient(key);
	cout << endl;

	return in;
}