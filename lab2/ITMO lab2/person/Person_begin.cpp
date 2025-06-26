
#include "Person_begin.h"
#include "Person.h"
#include <iostream>
#include <windows.h>
#include "../globals.h"
#include "../object/ConsoleColor.h"
using namespace std;

Person_begin::Person_begin() {
    cout << "Введите возраст друга";
    std::cin >> age_friend;
}

void Person_begin::Person_begin_write() {

    if (age_friend <= 18) {
        ConsoleColor::set(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Низкий возраст друга!";
        cout << globalMessage << endl;
        cout << globalMessageErrorPerson << endl;
        ConsoleColor::reset();
        std::exit(1);
    }

    if (age_friend > 18) {
        cout << "Я надписал об этом в Лиссабон своему старому другу,";
        person_demo += 1;
    }
}