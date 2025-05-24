#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>

using namespace std;

// Структура для хранения данных о блюде
struct Dish {
    string name;
    float sale;
    int quantity;
};

void save_receipt(const string& one) {
    // Чтение k из файла
    ifstream num("receipt//count.txt");
    int k = 0;

    if (num.is_open()) {
        string k_str;
        getline(num, k_str);
        if (!k_str.empty()) {
            k = stoi(k_str);
        }
        num.close();
    }

    // Создание имени файла
    string filename = "receipt//receipt" + to_string(k) + ".txt";

    // Запись чека в файл
    ofstream out(filename);
    if (out.is_open()) {
        out << one << endl;
        out.close();
        cout << "\n Чек записан в файл: " << filename << endl;
    } else {
        cout << "\n Ошибка при записи файла: " << filename << endl;
    }

    // Увеличиваем k и сохраняем обратно
    ofstream out_k("receipt//count.txt");
    if (out_k.is_open()) {
        out_k << (k + 1);
        out_k.close();
    }
}


//Создаём перечень меню
void menu_dynamic() {
    int k;
    float main_food = 0;
    int sale;
    string food;
    vector<pair<string, float>> main_menu = {
        {"Стейк", 2200},
        {"Луковый суп", 900},
        {"Капучино 200мл", 160},
        {"Омлет", 400},
        {"Тар-Тар", 900},
        {"Торт Наполеон клубничный", 950},
        {"Шампанское De Cruello", 6000}
    };

    vector<pair<string, float>> ordered;

    cout << "----- Меню -----" << endl;
    for (int i = 0; i < main_menu.size(); i++) {
        cout << (i + 1) << ". " << main_menu[i].first << " - " << main_menu[i].second << " руб." << endl;
    }

    while (true) {
        cout << "Введите номер блюда для заказа (0 для завершения): ";
        cin >> k;

        if (k == 0) {
            cout << "Заказ завершён \n";
            break;
        }

        if (k >= 1 && k <= main_menu.size()) {
            main_food += main_menu[k - 1].second;
            ordered.push_back(main_menu[k - 1]);
            cout << "Добавлено: " << main_menu[k - 1].first << " за " << main_menu[k - 1].second << " руб." << endl;
        } else {
            cout << "Некорректный номер блюда, попробуйте снова.\n";
        }
    }

    float main_food1 = main_food;
    main_food += main_food / 5;

    int dis;
    {
        int discount = 10;
        cout << "Ваша скидка - " << discount << "%\n";
        cout << "У вас есть скидка? ";
        string ask;
        cin >> ask;

        if (ask == "Да" || ask == "Yes" || ask == "yes" || ask == "да") {
            int discount_ask;
            cout << "Введите свою скидку в рублях: ";
            cin >> discount_ask;
            if (main_food - (main_food / 100) * discount < main_food - discount_ask) {
                main_food = main_food - (main_food / 100) * discount;
                dis = discount;
            } else {
                main_food = main_food - discount_ask;
                if (main_food < 0) {
                    main_food = 0;
                    dis = discount_ask;
                }
                dis = discount_ask;
            }
        } else {
            dis = discount;
            main_food = main_food - (main_food / 100) * discount;
        }
    }

    if (main_food >= 4000 && main_food <= 10000) {
        main_food -= main_food * 0.10;
    } else if (main_food > 10000 && main_food <= 20000) {
        main_food -= main_food * 0.13;
    } else if (main_food > 20000) {
        main_food -= main_food * 0.18;
    }

    cout << "Сумма заказа с учётом скидки: " << main_food << " руб.\n";

    cout << "Сохранить чек? - ";
    string ask_receipt;
    cin >> ask_receipt;

    if (ask_receipt == "Yes" || ask_receipt == "yes" || ask_receipt == "Да" || ask_receipt == "да") {
        string one;
        one += "\n-------------Чек:--------------- \n";
        one += "|--Блюдо--|--Цена--|\n";

        for (const auto& dish : ordered) {
            one += dish.first + " -- " + to_string(dish.second) + "\n";
        }

        one += "Скидка - " + to_string(dis) + "\n";
        one += "НДС (20%) - " + to_string(main_food1) + " --> " + to_string(main_food) + "\n";
        one += "Итоговая сумма - " + to_string(main_food) + "\n";
        one += "--------------------------------\n";

        save_receipt(one);
    }
}


// Основная функция ввода и вывода блюд
void sum_cafe() {
    int k;
    float total = 0;

    cout << u8"Введите количество блюд: ";
    cin >> k;
    cin.ignore(); // Удаляем '\n' после cin >> k

    vector<Dish> menu;

    for (int i = 1; i <= k; i++) {
        Dish dish;

        cout << "\n" << u8"Блюдо " << i << ":\n";

        // Сначала читаем название (с пробелами)
        cout << u8"Введите название блюда: ";
        getline(cin, dish.name);

        // Затем цену
        cout << u8"Введите цену: ";
        cin >> dish.sale;

        // Затем количество
        cout << u8"Введите количество: ";
        cin >> dish.quantity;
        cin.ignore(); // удаляем '\n' перед следующим getline

        // Добавляем блюдо в список
        menu.push_back(dish);

        // Увеличиваем общую сумму
        total += dish.sale * dish.quantity;
    }

    //НДС 20%
    int total_Tax = total + (total / 100) * 20;
    int total_Tax1 = total_Tax;

    int dis;
    {
        //Скидка магазина
        int discount;
        discount = 10;
        cout << u8"Ваша скидка - " << discount << "%" << "\n";

        //Скидка клиента
        cout << u8"У вас есть скидка? ";
        string ask;
        cin >> ask;

        //Вопрос по скидке. Если да, то сравниваем, если нет, то пропускаем.
        if (ask == u8"Да" or ask == u8"Yes" or ask == u8"yes" or ask == u8"да") {
            int discount_ask;
            cout << u8"Введите свою скидку в рублях: ";
            cin >> discount_ask;
            cout << u8"  В случае, если ваша скидка будет выгоднее нашей, \n "
                    "ваш заказ будет обработан только по вашей скидке. \n "
                    "В ином случае будет использована только наша скидка \n";

            //Сравнение скидок
            if (total_Tax - (total_Tax / 100) * discount < total_Tax - discount_ask) {
                total_Tax = total_Tax - (total_Tax / 100) * discount;
                dis = discount;
            }
            else {
                total_Tax = total_Tax - discount_ask;
                dis = discount_ask;
            }
        }
        else {
            dis = discount;
        }
    }

    //Дополнительная скидка при высоком чеке 10%
    if (total_Tax >= 4000 && total_Tax <= 10000) {
        total_Tax -= total_Tax * 0.10; // скидка 10%
    }
    else if (total_Tax > 10000 && total_Tax <= 20000){
        total_Tax -= total_Tax * 0.13; // скидка 13%
    }
    else if (total_Tax > 20000){
        total_Tax -= total_Tax * 0.18; // скидка 18%
    }

    // Вывод всех блюд
    cout << u8"\n-------------Чек:--------------- \n";
    cout << u8"|--Блюдо--|--Цена--|--Кол-во--|\n";

    for (int i = 0; i < menu.size(); i++) {
        cout << menu[i].name << " -- " << menu[i].sale << " -- " << menu[i].quantity << endl;
    }
    cout << u8"Скидка - " << dis << "\n";
    cout << u8"НДС (20%) - " << total << " --> " << total_Tax1 << "\n";
    cout << u8"Итоговая сумма - " << total_Tax;
    cout << "\n" << u8"--------------------------------";

    //Работа с файлом чека
    cout << "Сохранить чек? - ";
    string ask_receipt;
    cin >> ask_receipt;

    if (ask_receipt == "Yes" or ask_receipt == "yes" or ask_receipt == "Да" or ask_receipt == "да") {
        // Запись итоговых данных
        string one;
        one += "\n-------------Чек:--------------- \n";
        one += "|--Блюдо--|--Цена--|--Кол-во--|\n";

        for (int i = 0; i < menu.size(); i++) {
            one += menu[i].name + " -- " + to_string(menu[i].sale) + " -- " + to_string(menu[i].quantity) + "\n";
        }

        one += "Скидка - " + to_string(dis) + "\n";
        one += "НДС (20%) - " + to_string(total) + " --> " + to_string(total_Tax1) + "\n";
        one += "Итоговая сумма - " + to_string(total_Tax) + "\n";
        one += "--------------------------------\n";

        save_receipt(one);
    }
}

int login() {
    //Авторизация и разделение прав доступа
    int password = 0;
    cout << "Авторизуйтесь, если вы работник - ";
    cin >> password;
    vector<int> passwords = {1111, 1342, 2222, 1393, 9979, 6261, 8433};
    if (password != 0) {
        for (int p : passwords) {
            if (password == p) {

                int ask_stop;
                cout << u8"Если хотите выйти, введите ноль -";
                cin >> ask_stop;

                if (ask_stop == 0) {
                    return 0;
                }

                cout << "Хотите что-то заказать?";
                string new_ask;
                cin >> new_ask;
                if (new_ask == u8"Да" or new_ask == u8"Yes" or new_ask == u8"yes" or new_ask == u8"да") {
                    sum_cafe();
                }
                else if (new_ask == u8"Нет" or new_ask == u8"No" or new_ask == u8"no" or new_ask == u8"нет"){
                    cout << "Преступайте к редактированию \n";
                    menu_dynamic();
                }
                return 0;
            }
        }
    }
    else {
        sum_cafe();
    }
}

// Точка входа
int main() {
    SetConsoleOutputCP(CP_UTF8);  // Вывод в UTF-8
    SetConsoleCP(CP_UTF8);        // Ввод в UTF-8

    int k;
    cin >> k;
    if (k == 0) {
        menu_dynamic();
    }
    else {
        sum_cafe();
    }

    return 0;
}
