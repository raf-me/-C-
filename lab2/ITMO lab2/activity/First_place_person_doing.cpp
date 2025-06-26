//
// Created by admin on 17.06.2025.
//

#include<iostream>
#include "../globals.h"
#include "First_place_person_doing.h"

#include <windows.h>

#include "Activity.h"
#include "../object/ConsoleColor.h"

using namespace std;



void First_place_person_doing::first_place() {

    if (k == 1) {
        cout << "и те ответили мне, что это не трудно устроить и на месте, но,";
        activity_demo += 1;
        k += 1;
    }

    else {
        ConsoleColor::set(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << globalMessage;
        cout << globalMessageErrorNumber;
        ConsoleColor::reset();
        std::exit(1);
    }
}