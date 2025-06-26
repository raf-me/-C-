//
// Created by admin on 17.06.2025.
//

#include "Person.h"
#include <iostream>
#include <windows.h>

#include "../globals.h"
#include "Person_begin.h"
#include "../object/ConsoleColor.h"
using namespace std;

Person::Person() {
}

int Person::person_demo = 0;
int Person::choice_next = 0;
int Person::person_choice_final;
std::string Person::choice = "";

void Person::Person_first_action() {
    cout << "Введите возраст";
    cin >> age;

    if (age > 15 && age <= 60) {
        if (k == 0) {
            Person_begin person_begin;
            person_begin.Person_begin_write();
            k += 1;
        }
        else {
            ConsoleColor::set(FOREGROUND_RED | FOREGROUND_INTENSITY);
            cout << globalMessage << endl;
            cout << globalMessageErrorNumber << endl;
            ConsoleColor::reset();
            std::exit(1);
        }
    }

    else if (age <= 15) {
        ConsoleColor::set(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Низкий возраст!" << endl;
        cout << globalMessage << endl;
        cout << globalMessageErrorPerson << endl;
        ConsoleColor::reset();
        std::exit(1);
    }

    else if (age > 60) {
        ConsoleColor::set(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Высокий возраст!";
        cout << globalMessage << endl;
        cout << globalMessageErrorPerson << endl;
        ConsoleColor::reset();
        std::exit(1);
    }
}