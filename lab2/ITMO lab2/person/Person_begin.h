//
// Created by admin on 17.06.2025.
//

#ifndef PERSON_BEGIN_H
#define PERSON_BEGIN_H

#include <string>
#include "Person.h"

class Person_begin : protected Person {


public:
    int age_friend;
    std::string write_person;
    Person_begin();

    void Person_begin_write();
};



#endif //PERSON_BEGIN_H
