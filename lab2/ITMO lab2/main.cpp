#include <iostream>
#include "Scenario.h"
#include <windows.h>

using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    Scenario run;
    run.run();
    return 0;
}