//
// Created by admin on 25.06.2025.
//

#ifndef CONSOLECOLOR_H
#define CONSOLECOLOR_H
#include <minwindef.h>


class ConsoleColor {
public:
    static void set(WORD color);

    static void reset();
};



#endif //CONSOLECOLOR_H
