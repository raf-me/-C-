//
// Created by admin on 17.06.2025.
//

#ifndef PERSON_H
#define PERSON_H
#include <iostream>


class Person {
protected:
    static int person_demo;
    static int person_choice_final;
    static int choice_next;
    static std::string choice;

public:
    int age;
    Person();

    void Person_first_action();
};

#endif //PERSON_H
