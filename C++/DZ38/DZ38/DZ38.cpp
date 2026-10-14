////1 main
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <conio.h>
//#include <windows.h>
//#include "Customer.h"
//using namespace std;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    Customer* customers = nullptr;
//    int size = 0;
//
//    cout << "Натисніть '+' для додавання до 10 нових клієнтів.\n";
//    cout << "Натисніть '-' для видалення до 5 клієнтів.\n";
//    cout << "Натисніть 'Esc' для виходу з програми.\n";
//
//    while (true) {
//        char ch = _getch();
//
//        if (ch == '+') {
//            int numToAdd = rand() % 10 + 1;
//            Customer* newCustomers = new Customer[size + numToAdd];
//
//            for (int i = 0; i < size; i++) {
//                newCustomers[i] = customers[i];
//            }
//
//            delete[] customers;
//
//            customers = newCustomers;
//            size += numToAdd;
//
//            cout << "Додано " << numToAdd << " нових клієнтів. " << endl;
//        }
//        else if (ch == '-') {
//            int numToRemove = rand() % 5 + 1;
//            if (numToRemove > size) {
//                numToRemove = size;
//            }
//
//            Customer* newCustomers = new Customer[size - numToRemove];
//
//            for (int i = 0; i < size - numToRemove; i++) {
//                newCustomers[i] = customers[i];
//            }
//
//            delete[] customers;
//
//            customers = newCustomers;
//            size -= numToRemove;
//
//            cout << "Видалено " << numToRemove << " клієнтів. " << endl;
//        }
//        else if (ch == 27) {
//            cout << "Загальна кількість клієнтів: " << Customer::getCounter() << endl;
//            break;
//        }
//    }
//
//    delete[] customers;
//
//    return 0;
//}




////2 main
//#include <iostream>
//#include <windows.h>
//#include "Library.h"
//using namespace std;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    Library lib1("Book A");
//    Library lib2("Book B");
//
//    cout << "Початкові назви книг:" << endl;
//    cout << "Library 1: " << lib1.getBookTitle() << endl;
//    cout << "Library 2: " << lib2.getBookTitle() << endl;
//
//    exchangeBooks(lib1, lib2);
//
//    cout << "Назви книг після обміну:" << endl;
//    cout << "Library 1: " << lib1.getBookTitle() << endl;
//    cout << "Library 2: " << lib2.getBookTitle() << endl;
//
//    return 0;
//}




////3 main
//#include <iostream>
//#include <windows.h>
//#include "Matrix.h"
//using namespace std;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    Matrix m1(3, 3);
//    Matrix m2(3, 3);
//
//    m1.fillRandom();
//    m2.fillRandom();
//
//    cout << "Матриця m1:" << endl;
//    m1.print();
//
//    cout << "Матриця m2:" << endl;
//    m2.print();
//
//    Matrix m3 = m1 + m2;
//    cout << "Матриця m3 (m1 + m2):" << endl;
//    m3.print();
//
//    Matrix m4 = m1 - m2;
//    cout << "Матриця m4 (m1 - m2):" << endl;
//    m4.print();
//
//    m1 += m2;
//    cout << "Матриця m1 після m1 += m2:" << endl;
//    m1.print();
//
//    m1 -= m2;
//    cout << "Матриця m1 після m1 -= m2:" << endl;
//    m1.print();
//
//    cout << "m1 == m2: " << (m1 == m2 ? "так" : "ні") << endl;
//
//    return 0;
//}