#include <Windows.h>
#include <iostream>
#include <conio.h>

PROCESS_INFORMATION piAppsWord[100] = { 0 }; int wordCount = 0;
PROCESS_INFORMATION piAppsExcel[100] = { 0 }; int excelCount = 0;
PROCESS_INFORMATION piAppsPaint[100] = { 0 }; int paintCount = 0;
PROCESS_INFORMATION piAppsNotepad[100] = { 0 }; int notepadCount = 0;

void createApp(int num) {
    const wchar_t* currentPath = L"";

    switch (num)
    {
    case 1:
        currentPath = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE";
        break;
    case 2:
        currentPath = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE";
        break;
    case 3:
        currentPath = L"C:\\WINDOWS\\system32\\mspaint.exe";
        break;
    case 4:
        currentPath = L"C:\\WINDOWS\\system32\\notepad.exe";
        break;
    }

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    if (!CreateProcess(currentPath, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi)) {
        std::cout << "Неа" << std::endl;
        _getch();
    }
    else {
        switch (num)
        {
        case 1:
            if (wordCount < 100) {
                piAppsWord[wordCount] = pi;
                wordCount++;
            }
            break;
        case 2:
            if (excelCount < 100) {
                piAppsExcel[excelCount] = pi;
                excelCount++;
            }
            break;
        case 3:
            if (paintCount < 100) {
                piAppsPaint[paintCount] = pi;
                paintCount++;
            }
            break;
        case 4:
            if (notepadCount < 100) {
                piAppsNotepad[notepadCount] = pi;
                notepadCount++;
            }
            break;
        }
    }
}

void closeLastApp(int num) {
    switch (num)
    {
    case 5:
        if (wordCount > 0) {
            TerminateProcess(piAppsWord[wordCount - 1].hProcess, 0);
            CloseHandle(piAppsWord[wordCount - 1].hProcess);
            CloseHandle(piAppsWord[wordCount - 1].hThread);
            wordCount--;
        }
        else std::cout << "Нет процессов Word" << std::endl;
        break;

    case 6:
        if (excelCount > 0) {
            TerminateProcess(piAppsExcel[excelCount - 1].hProcess, 0);
            CloseHandle(piAppsExcel[excelCount - 1].hProcess);
            CloseHandle(piAppsExcel[excelCount - 1].hThread);
            excelCount--;
        }
        else std::cout << "Нет процессов Excel" << std::endl;
        break;

    case 7:
        if (paintCount > 0) {
            TerminateProcess(piAppsPaint[paintCount - 1].hProcess, 0);
            CloseHandle(piAppsPaint[paintCount - 1].hProcess);
            CloseHandle(piAppsPaint[paintCount - 1].hThread);
            paintCount--;
        }
        else std::cout << "Нет процессов Paint" << std::endl;
        break;

    case 8:
        if (notepadCount > 0) {
            TerminateProcess(piAppsNotepad[notepadCount - 1].hProcess, 0);
            CloseHandle(piAppsNotepad[notepadCount - 1].hProcess);
            CloseHandle(piAppsNotepad[notepadCount - 1].hThread);
            notepadCount--;
        }
        else std::cout << "Нет процессов Notepad" << std::endl;
        break;
    }
}

volatile int n = 0;
DWORD WINAPI Counter() {
    while (true) {
        std::cout << n << std::endl;
        n++;
        Sleep(1000);
    }
    return 0;
}
void createCounter() {
    wchar_t lpszNewProc[256] = L"C:\\Users\\Drunchik\\source\\repos\\Rogov_pr31_9prakt\\x64\\Debug\\Rogov_pr31_9prakt-2part.exe ";
    wchar_t lpz[256] = L"";

    HANDLE hThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)Counter, NULL, 0, NULL);
    SetHandleInformation(hThread, HANDLE_FLAG_INHERIT, HANDLE_FLAG_INHERIT);
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);


    _itow_s((int)hThread, lpz, 10);
    wcscat_s(lpszNewProc, lpz);
    CreateProcess(NULL, lpszNewProc, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
}

int main()
{
    createCounter();

    setlocale(0, "rus");
    int choice;
    while (true) {
        std::cout << "Выберите действие:\n";
        std::cout << "1. Открыть Microsoft Word\n";
        std::cout << "2. Открыть Microsoft Excel\n";
        std::cout << "3. Открыть Paint\n";
        std::cout << "4. Открыть Notepad\n";
        std::cout << "5. Закрыть Microsoft Word\n";
        std::cout << "6. Закрыть Microsoft Excel\n";
        std::cout << "7. Закрыть Paint\n";
        std::cout << "8. Закрыть Notepad\n";
        std::cout << "0. Выход\n";
        std::cin >> choice;

        if (choice == 0) break;
        if (choice < 0 || choice > 9) {
            std::cout << "Неверный выбор" << std::endl;
            continue;
        }

        if (choice >= 1 && choice <= 4) createApp(choice);

        else if (choice >= 5 && choice <= 8) closeLastApp(choice);
        
        else if (choice == 9) {

        }
    }
}