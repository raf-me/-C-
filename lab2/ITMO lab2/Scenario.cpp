//
// Created by admin on 17.06.2025.
//

#include "Scenario.h"

#include "activity/First_place_person_doing.h"
#include "object/MemoryMonitor.h"
#include "person/Person.h"
#include "person/Person_choice.h"

void Scenario::run() {
    MemoryMonitor::printMemoryUsage();

    Person person;
    person.Person_first_action();

    First_place_person_doing first_place_person_doing;
    first_place_person_doing.first_place();

    Person_choice person_choice;
    person_choice.choice_number();

    MemoryMonitor::printMemoryUsage();
}
