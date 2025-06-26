//
// Created by admin on 20.06.2025.
//

#include "Person_choice_win_2.h"
#include <iostream>
#include <windows.h>

#include "Person_choice.h"
#include "Person_choice_failed.h"
#include "../globals.h"
#include "Person_begin.h"
#include "../object/ConsoleColor.h"

using namespace std;

void Person_choice_win_2::person_choice_win_2() {
    if (k == 3 && choice_next == 2) {
        cout << "заведывавшим ею теперь вместо прежних опекунов, - как мне известно, людям очень богатым, \n "
                "живущим в Бразилии и, следовательно, знающим настоящую цену моей плантации. \n "
                "Капитан не сомневался, что они охотно купят мою часть и дадут за нее на четыре, \n  "
                "на пять тысяч больше всякого другого покупателя. \n "
                " -- Сделайте выбор (Да или Нет) -- ";
        cin >> choice;

        while (choice != "Да" && choice != "да" && choice != "Нет" && choice != "нет") {
            cout << globalMessageChoice;
            cin >> choice;
        }

        if (choice == "Да" || choice == "да") {
            cout << "Я признал его доводы вполне убедительными и поручил ему сделать это предложение, \n"
                    "а через восемь месяцев вернувшийся из Португалии корабль привез мне письмо, \n"
                    "в котором мой старый друг сообщал, что купцы приняли предложение \n"
                    "и поручили своему агенту в Лиссабоне уплатить мне тридцать три тысячи золотых. \n"
                    "Я, в свою очередь, подписал составленную по всей форме запродажную запись, \n"
                    "присланную мне из Лиссабона, и отправил ее назад старику, \n"
                    "а тот прислал мне чеки на тридцать три тысячи." << endl;
            sale_choice_plantation += 5000;
            cout << "Итоговая цена продажи " << sale_choice_plantation << endl;
            cout << "Помесячная выплата " << sale_choice_plantation_sub << endl;
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