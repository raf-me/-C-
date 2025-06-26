//
// Created by admin on 20.06.2025.
//

#include "Person_choice_failed.h"
#include <iostream>
#include "../globals.h"
#include <windows.h>
#include "../object/ConsoleColor.h"

using namespace std;

void Person_choice_failed::main_person_choice() {
    if (k == 3 && choice_next == 0) {
        cout << "В итоге я не смог повысить цену и поэтому мне пришлось продать плантацию по стандартной цене без доплаты."
                "И при этом, учитывая, что я знал, что мои друзья потенциально могли бы повысить цену, "
                "я всё равно продал его по стандартной цене." << endl;

        cout << sale_choice_plantation << endl;

        cout << "Я, в свою очередь, подписал составленную по всей форме запродажную запись, присланную мне из Лиссабона, "
                "и отправил ее назад старику, а тот прислал мне чеки на " <<  sale_choice_plantation << endl;

        ConsoleColor::set(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << globalMessageFinish << endl;
        ConsoleColor::reset();
        k += 1;
    }

    else {
        ConsoleColor::set(FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << globalMessageErrorNumber;
        ConsoleColor::reset();
    }
}