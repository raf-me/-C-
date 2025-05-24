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

// Точка входа
int main() {
    SetConsoleOutputCP(CP_UTF8);  // Вывод в UTF-8
    SetConsoleCP(CP_UTF8);        // Ввод в UTF-8

    sum_cafe();

    return 0;
}
