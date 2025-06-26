//
// Created by admin on 18.06.2025.
//

#include "Person_choice.h"
#include "../globals.h"
#include <iostream>
#include "Person.h"
#include "Person_choice_failed.h"
#include "Person_choice_win_1.h"
#include "Person_choice_win_2.h"
#include <windows.h>
#include "../object/ConsoleColor.h"


using namespace std;
std::string Person_choice::choice_friend = "";


void Person_choice::choice_number() {
    if (k == 2) {
        cout << "если я дам ему разрешение действовать от моего имени... \n "
                "(Выберите какого друга послушать: для выбора используйте 1 для первого, 2 для второго, 0 для одиночного. \n"
                "При этом учтите, что первый друг заберёт 5% от полученных денег, а второй 10%). \n ";

        cin >> choice_friend;

        if (choice_friend == "0") {
            choice_next += 0;
            cout << "Я решил работать в одиночку. Мои доводы не были столь убедительными даже для меня самого, \n"
                    "но я думал, что моя плантация достоина хорошей цены" << endl;

            k += 1;

            Person_choice_failed person_choice_failed;
            person_choice_failed.main_person_choice();
        }

        if (choice_friend == "1") {
            choice_next += 1;
            cout << "Я выбрал план Майкла. По его словам, он сможет продать товар двум купцам, взяв всего 5%. \n"
                    "Он решил использовать финансовую стратегию и в кредит продать мою плантацию. \n"
                    "Я не был уверен в его словах, но решил довериться, так как он является банкиром со стажем." << endl;

            k += 1;

            Person_choice_win_1 person_choice_win_1;
            person_choice_win_1.person_choice_win_1();
        }

        if (choice_friend == "2") {
            choice_next += 2;
            cout << "он находит более выгодным предложить купить мою часть имения двум купцам, " << endl;

            k += 1;

            Person_choice_win_2 person_choice_win_2;
            person_choice_win_2.person_choice_win_2();
        }
    }

    else {
        ConsoleColor::set(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << globalMessageErrorNumber;
        ConsoleColor::reset();
    }
}

