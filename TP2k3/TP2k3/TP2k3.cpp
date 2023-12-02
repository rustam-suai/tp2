#include <iostream>
#include <clocale>
#include "spisok.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    while (true) {
        cout << "Выберите задание:\n";
        cout << "1. Стандартные потоки\n";
        cout << "2. Файловые и строковые потоки\n";
        cout << "3. Выйти\n";
        cout << "Введите номер выбранного действия: ";

        int choice;
        cin >> choice;

        if (choice == 1) {
            system("cls");
            cout << "тут будут стандартные потоки:\n";
        }
        else if (choice == 2) {
            system("cls");
            Spisok predlojenia;
            string waaa = "trsthsrsh";
            predlojenia.add(waaa);
            waaa = "aaaaaaaaa";
            predlojenia.add(waaa);
            predlojenia.print();
        }
        else if (choice == 3) {
            break;
        }
        else {
            system("cls");
            cout << "Неверный выбор." << endl;
        }
    }
}
