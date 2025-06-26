#include "MemoryMonitor.h"
#include <windows.h>
#include <psapi.h>
#include <iostream>

#include "ConsoleColor.h"

void MemoryMonitor::printMemoryUsage() {
    PROCESS_MEMORY_COUNTERS memInfo;
    if (GetProcessMemoryInfo(GetCurrentProcess(), &memInfo, sizeof(memInfo))) {
        double memMB = static_cast<double>(memInfo.WorkingSetSize) / (1024.0 * 1024.0);
        ConsoleColor::set(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

        std::cout << "[MemoryMonitor] Использовано памяти: "
                  << memMB << " МБ" << std::endl;
        ConsoleColor::reset();
    }

    else {
        ConsoleColor::set(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        std::cerr << "[MemoryMonitor] Не удалось получить информацию о памяти" << std::endl;
        ConsoleColor::reset();
    }
}