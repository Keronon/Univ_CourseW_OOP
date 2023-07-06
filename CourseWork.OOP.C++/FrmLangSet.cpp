#include "FrmLangSet.h"

///// Initializers /////
void FrmLangSet::initVariables()
{
	this->className = "FrmLangSet";
	this->textStringsCount = 0;

	stringstream ss;
	ss << "DeBUG::" << this->className << "::CORRECT::Variables_initializing\n";
	DeBUG::listing(ss.str());
}

void FrmLangSet::initStringsPath()
{
	stringstream ss;
	ss << "\nDeBUG::" << this->className;

	OPENFILENAME openFileName;											// common dialog box structure
	char fileNameSize[260];												// buffer for file name
	HWND hwnd = GetActiveWindow();										// owner window
	HANDLE handleFile;													// file handle		

	TCHAR g_BackupDir[MAX_PATH];
	GetCurrentDirectory(ARRAYSIZE(g_BackupDir), g_BackupDir);

	// Initialize OPENFILENAME
	ZeroMemory(&openFileName, sizeof(openFileName));
	openFileName.lStructSize = sizeof(openFileName);
	openFileName.hwndOwner = hwnd;
	openFileName.lpstrFile = fileNameSize;

	// Set lpstrFile[0] to 0 so that GetOpenFileName does not 
	// use the contents of fileNameSize to initialize itself.
	openFileName.lpstrFile[0] = 0;
	openFileName.nMaxFile = sizeof(fileNameSize);
	openFileName.lpstrFilter = "All0*.*0Text0*.TXT0";
	openFileName.nFilterIndex = 1;
	openFileName.lpstrFileTitle = NULL;
	openFileName.nMaxFileTitle = 0;
	openFileName.lpstrInitialDir = NULL;
	openFileName.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	// Display the Open dialog box. 
	if (GetOpenFileName(&openFileName) == TRUE)
	{
		handleFile = CreateFile(openFileName.lpstrFile,
			GENERIC_READ,
			0,
			(LPSECURITY_ATTRIBUTES)NULL,
			OPEN_EXISTING,
			FILE_ATTRIBUTE_NORMAL,
			(HANDLE)NULL);

		for (int i = 0; i < openFileName.nFileOffset; i++)
			this->processData->stringsPath += openFileName.lpstrFile[i];
		
		CloseHandle(handleFile);

		ss << "::CORRECT::Strings_path_initializing::\n_______" << this->processData->stringsPath << endl;
	}
	else
	{
		ss << "::!ERROR!::Strings_path_initializing::\ninitiated::\n_______" << g_BackupDir << "\\Resourses\\Strings\\" << endl;

		this->processData->stringsPath += g_BackupDir;
		this->processData->stringsPath += "\\Resourses\\Strings\\";
	}

	DeBUG::listing(ss.str());
	SetCurrentDirectory(g_BackupDir);

	/* all openFileName params */
	//		<< "::"	<< openFileName.lpstrFile				// file path
	//		<< "::" << openFileName.lStructSize				// all path length
	//		<< "::" << openFileName.nFileExtension			// path length without extension
	//		<< "::" << openFileName.nFileOffset				// path length without file
	//		<< "::"	<< openFileName.lpstrFilter				// mask of serch

	//		<< "::"	<< openFileName.dwReserved				//smth strange [0]
	//		<< "::" << openFileName.Flags					//smth strange [6114]
	//		<< "::"	<< openFileName.FlagsEx					//smth strange [0]
	//		<< "::"	<< openFileName.hInstance				//smth strange [00000000]
	//		<< "::"	<< openFileName.hwndOwner				//smth strange [00000000]
	//		<< "::" << openFileName.lCustData				//smth strange [0]
	//		<< "::" << openFileName.lpfnHook				//smth strange [00000000]
	//		<< "::" << openFileName.lpTemplateName			// [!error!]
	//		<< "::"	<< openFileName.lpstrFileTitle			// [!error!]
	//		<< "::"	<< openFileName.lpstrInitialDir			// [!error!]
	//		<< "::"	<< openFileName.lpstrTitle				// [!error!]
	//		<< "::"	<< openFileName.lpstrCustomFilter		// [!error!]
	//		<< "::" << openFileName.lpstrDefExt				// [!error!]
	//		<< "::" << openFileName.nFilterIndex			//smth strange [1]
	//		<< "::" << openFileName.nMaxCustFilter			//smth strange [0]
	//		<< "::" << openFileName.nMaxFile				//smth strange [100]
	//		<< "::" << openFileName.nMaxFileTitle			//smth strange [0]
	//		<< "::" << openFileName.pvReserved				//smth strange [00000000]
}

///// Constructors/Destructors /////
FrmLangSet::FrmLangSet(vector<Frame*>* frames, ProcessData* process_data, map<string, int>* supported_keys)
	: Frame(frames, process_data, supported_keys)
{
	this->initVariables();
	initKeys("Resourses/Configs/" + this->className + ".keys");

	stringstream ss;
	ss << "DeBUG::" << this->className << "::CORRECT::Creating::" << this << "\n\n";
	DeBUG::listing(ss.str());
}

FrmLangSet::~FrmLangSet() {}

///// Functions /////
void FrmLangSet::update()
{
	stringstream ss;
	ss << "\nDeBUG::" << this->className;

	system("cls");
	cout << "LANGUAGE \ ЯЗЫК\n\n"
		<< "-----------------------------------------------\n"
		<< "\\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/\n\n"
		<< "If you want to work with this app by english\n"
		<< "press button \"1\"\n\n"
		<< "/\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\\n"
		<< "-----------------------------------------------\n"
		<< "\\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/ \\/\n\n"
		<< "Для работы с приложением на русском языке\n"
		<< "нажмите кнопку \"2\"\n\n"
		<< "/\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\ /\\\n"
		<< "-----------------------------------------------\n";

	char key = _getch();
	bool just_continue = true;
	if (key == this->keys["EN"]) // если клавиша 1
	{
		this->processData->language = "en";

		while (just_continue)
		{
			system("cls");
			cout << "LANGUAGE \ ЯЗЫК\n\n"
				<< "If text folder path was changed\n"
				<< "select in the window that opens the \"path.set\"-file\n"
				<< "[this file should be inside of \"Strings\"-folder]\n"
				<< "[along language folders]\n\n"
				<< "else just close the window that opens\n\n"
				<< "Press \"Escape\" for quit the app\n"
				<< "or\n"
				<< "Press any other button to continue\n\n";

			key = _getch();
			if (key != this->keys["QUIT"]) // если не клавиша Escape
			{
				this->initStringsPath();
				ifstream ifs(this->processData->stringsPath + "ru\\FrmTitle\\menu.strings");
				if (ifs.is_open())
				{
					just_continue = false;
					this->frames->insert(this->frames->cbegin(), new FrmTitle(this->frames, this->processData, this->supportedKeys));
				}
				else
				{
					cout << "Something wrong at place of selected file,\n"
						<< "try again\n\n";
					this->processData->stringsPath = "";
					system("pause");
				}
				ifs.close();
			}
			else just_continue = false;
		}
		this->quit = true;
	}
	else
		if (key == this->keys["RU"]) // если клавиша 2
		{
			this->processData->language = "ru";

			while (just_continue)
			{
				system("cls");
				cout << "LANGUAGE \ ЯЗЫК\n\n"
					<< "Если путь к папке с текстами был изменён\n"
					<< "выберите в откроющемся окне \"path.set\"-файл\n"
					<< "[этот файл должен быть в \"Strings\"-папке]\n"
					<< "[вместе с языковыми папками]\n\n"
					<< "иначе просто закройте откроющееся окно\n\n"
					<< "Нажмите \"Escape\" для выхода из приложения\n"
					<< "или\n"
					<< "Нажмите любую другую кнопку для продолжения\n\n";

				key = _getch();
				if (key != this->keys["QUIT"]) // если не клавиша Escape
				{
					this->initStringsPath();
					ifstream ifs(this->processData->stringsPath + "ru\\FrmTitle\\menu.strings");
					if (ifs.is_open())
					{
						just_continue = false;
						this->frames->insert(this->frames->cbegin(), new FrmTitle(this->frames, this->processData, this->supportedKeys));
					}
					else
					{
						cout << "Что-то не так с расположением выбранного файла,\n"
							<< "попробуйте ещё раз\n\n";
						this->processData->stringsPath = "";
						system("pause");
					}
					ifs.close();
				}
				else just_continue = false;
			}
			this->quit = true;
		}

	ss << "::CORRECT::Updating\n";
	DeBUG::listing(ss.str());
}