#include <iostream>
#include <clocale>
#include "spisok.h"
#include "container.h"
#include "price.h"
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
            Container* con=new Container;
            while (true) {
                cout << "Выберите действие:\n";
                cout << "1. Добавить товар\n";
                cout << "2. Удалить товар\n";
                cout << "3. Информация о всех товарах\n";
                cout << "4. Информация о конкретном товаре\n";
                cout << "5. Демонстрация >> и << для Price\n";
                cout << "6. Назад\n";
                cout << "Введите номер выбранного действия: ";
                int choice2;
                cin >> choice2;
                if (choice2 == 1) {
                    Price* price;
                    system("cls");
                    price = new Price;
                    cout << "Введите название товара: ";
                    string name;
                    cin >> name;
                    system("cls");
                    price->setGood(name);
                    cout << "Введите название магазина: ";
                    cin >> name;
                    price->setMarket(name);
                    system("cls");
                    cout << "Введите цену товара: ";
                    int nu;
                    cin >> nu;
                    system("cls");
                    price->setCost(nu);
                    con->addElement(price);
                    con->sorty();
                }
                else if (choice2 == 2) {
                    system("cls");
                    if (con->getCount() > 0) {
                        con->displayContainer();
                        cout << "Введите индекс товара для удаления: ";
                        int index;
                        cin >> index;
                        if (index > 0 and index <= (con->getCount())) {
                        system("cls");
                        con->deleteElement(index);
                        }
                        else {
                            system("cls");
                            cout << "Неверно выбран индекс\n"<<endl;
                        }
                    }
                    else {
                        cout << "EMPTY\n\n";
                    }
                }
                else if (choice2 == 3) {
                    system("cls");
                    con->displayContainer();
                }
                else if (choice2 == 4) {
                    system("cls");
                    if (con->getCount() == 0) {
                        cout << "EMPTY\n\n";
                    }
                    else {
                        cout << "Введите название искомого товара: ";
                        string isk;
                        cin >> isk;
                        system("cls");
                        con->displayAbout(isk);
                    }
                }
                else if (choice2 == 6) {
                    system("cls");
                    if (con->getCount() > 0) {
                        int tem = con->getCount();
                        for (int k = 1; k <= tem; k++) {
                            con->deleteElement(1);
                        }
                    }
                    delete con;
                    break;
                }
                else if (choice2 == 5) {
                    system("cls");
                    Price* ba = new Price;
                    cin >> *ba;
                    cout << *ba;
                    delete ba;
                }
                else {
                    system("cls");
                    cout << "Неверный выбор\n";
                }
            }
        }
        else if (choice == 2) {
            ifstream file1("text.txt");
            system("cls");
            Spisok predlojenia;
            predlojenia.func2(file1);
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
    return 0;
}
