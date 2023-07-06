#include"Processor.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

//	HWND console = GetConsoleWindow();
//	ShowWindow(console, SW_HIDE);

	Processor* processor = Processor::getProcessor();

	processor->run();

	cout << endl;
	system("pause");
	return 0;
}