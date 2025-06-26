//
// Created by admin on 20.06.2025.
//

#include "Person_choice_win_1.h"
#include <iostream>

#include "Person_choice.h"
#include "Person_choice_failed.h"
#include "../globals.h"
#include <windows.h>
#include "../object/ConsoleColor.h"

using namespace std;

void Person_choice_win_1::person_choice_win_1() {
    if (k == 3 && choice_next == 1) {
        cout << "заведывавшим ею теперь вместо прежних опекунов, - как мне известно, людям не сильно богатым, \n"
                "живущим в Бразилии и, следовательно, знающим настоящую цену моей плантации. \n"
                "Майкл сомневался, что они охотно купят мою часть в кредит под 15% годовых на 7 лет. \n"
                " -- Сделайте выбор (Да или Нет) -- ";

        cin >> choice;
        while (choice != "Да" && choice != "да" && choice != "Нет" && choice != "нет") {
            cout << globalMessageChoice;
        }

        if (choice == "Да" || choice == "да") {
            cout << "Я признал его доводы вполне убедительными и поручил ему сделать это предложение, \n"
                    "а через восемь недель вернувшийся из Португалии корабль привез мне письмо, \n"
                    "в котором мой старый друг сообщал, что купец принял предложение \n"
                    "и поручили своему агенту в Лиссабоне уплатить мне ежемесячно 466 в течение 7 лет под 10% годовых \n"
                    "Я, в свою очередь, подписал составленную по всей форме запродажную запись, \n"
                    "присланную мне из Лиссабона, и отправил ее назад старику, \n"
                    "а тот прислал мне залог на 4000" << endl;

            int* sale_choice_plantation_first = new int(4000);
            sale_choice_plantation_sub = 466;
            cout << "Ежемесячная выплата: " << sale_choice_plantation_sub << endl;
            sale_choice_plantation = 39121;
            cout << "Итоговая сумма: " << sale_choice_plantation << endl;
            std::cout << "Залог: " << *sale_choice_plantation_first << endl;
            delete sale_choice_plantation_first;
            sale_choice_plantation_first = nullptr;

            ConsoleColor::set(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            cout << globalMessageFinish << endl;
            ConsoleColor::reset();

            k += 1;
        }

        else if (choice == "Нет" || choice == "нет") {
            choice_next = 0;

            cout << "Я отказался от помощи и действовал в одиночку." << endl;
            person_choice_final = 1;
            Person_choice_failed person_choice_failed;
            person_choice_failed.main_person_choice();
        }
    }

    else {
        ConsoleColor::set(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << globalMessageErrorNumber;
        ConsoleColor::reset();
    }
}
