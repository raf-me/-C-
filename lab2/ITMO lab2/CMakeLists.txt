cmake_minimum_required(VERSION 3.31)
project(ITMO_lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(ITMO_lab2 main.cpp
        person/Person_begin.cpp
        person/Person_begin.h
        globals.h
        globals.cpp
        person/Person.cpp
        person/Person.h
        activity/first_place_person_doing.cpp
        activity/first_place_person_doing.h
        activity/activity.cpp
        activity/activity.h
        Scenario.cpp
        Scenario.h
        person/Person_choice.cpp
        person/Person_choice.h
        person/Scenario_person.cpp
        person/Scenario_person.h
        person/Person_choice_win_1.cpp
        person/Person_choice_win_1.h
        person/Person_choice_win_2.cpp
        person/Person_choice_win_2.h
        person/Person_choice_failed.cpp
        person/Person_choice_failed.h
        object/MemoryMonitor.cpp
        object/MemoryMonitor.h
        object/ConsoleColor.cpp
        object/ConsoleColor.h)
