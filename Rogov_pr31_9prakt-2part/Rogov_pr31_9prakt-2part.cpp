#include <iostream>
#include <Windows.h>
#include <conio.h>

int main(int argc, char* argv[])
{
	setlocale(0, "rus");
	HANDLE hThread;
	hThread = (HANDLE)atoi(argv[1]);

	while (true) {
		std::cout << "1 - Стоп\n" << "2 - Возобновить\n" << "0 - Выход\n";
		char answer = _getch();
		if (answer == '1') SuspendThread(hThread);
		else if (answer == '2') ResumeThread(hThread);
		else if (answer == '0') ExitProcess(0);
		system("cls");
	}
}