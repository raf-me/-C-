//
// Created by admin on 25.06.2025.
//

#include "ConsoleColor.h"
#include <windows.h>

void ConsoleColor::set(WORD color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void ConsoleColor::reset() {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7); // стандартный серый
}
