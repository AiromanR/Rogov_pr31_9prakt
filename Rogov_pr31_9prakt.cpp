#include <Windows.h>
#include <iostream>
#include <conio.h>

HANDLE globalHandle = NULL;

void createApp(int num) {
    const wchar_t* currentPath = L"";
    switch (num)
    {
        case 1:
            currentPath = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE";
            break;
        case 3:
            currentPath = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE";
            break;
        case 5:
            currentPath = L"C:\\WINDOWS\\system32\\mspaint.exe";
            break;
        case 7:
            currentPath = L"C:\\WINDOWS\\system32\\notepad.exe";
            break;
    }
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);

    if (!CreateProcess(currentPath, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &si, &pi)) {
        std::cout << "неа";
        _getch();
    }
    else {
        CloseHandle(pi.hThread);
        CloseHandle(pi.hProcess);
    }
}

int main()
{
    setlocale(0, "rus");
    int choice;
    while (true) {
        std::cout << "Выберите действие:\n";
        std::cout << "1. Открыть Microsoft Word\n";
        std::cout << "2. Закрыть Microsoft Word\n";
        std::cout << "3. Открыть Microsoft Excel\n";
        std::cout << "4. Закрыть Microsoft Excel\n";
        std::cout << "5. Открыть Paint\n";
        std::cout << "6. Закрыть Paint\n";
        std::cout << "7. Открыть Notepad\n";
        std::cout << "8. Закрыть Notepad\n";
        std::cout << "9. Счётчик\n";
        std::cout << "0. Выход\n";
        std::cin >> choice;
        if (choice == 0) break;
        if (choice < 0 || choice > 10) {
            std::cout << "Неверный выбор" << std::endl;
            continue;
        }
        createApp(choice);
    }
    return 0;
}

    //wchar_t wordPath[] = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE";
    //STARTUPINFO wordSi;
    //PROCESS_INFORMATION wordPi;
    //ZeroMemory(&wordSi, sizeof(STARTUPINFO));
    //wordSi.cb = sizeof(STARTUPINFO);

    //if (!CreateProcess(wordPath, NULL, NULL, NULL, FALSE, NULL, NULL, NULL, &wordSi, &wordPi)) {
    //    std::cout << "неа";
    //    _getch();
    //    return 0;
    //}
    //WaitForSingleObject(wordPi.hProcess, INFINITE);
    //CloseHandle(wordPi.hThread);
    //CloseHandle(wordPi.hProcess);