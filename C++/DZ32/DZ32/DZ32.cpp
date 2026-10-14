////1
//#include <iostream>
//#include <string>
//#include <windows.h>
//
//using namespace std;
//
//int Operation(int x, int y, char op) {
//    switch (op) {
//    case '+':
//        return x + y;
//    case '-':
//        return x - y;
//    case '*':
//        return x * y;
//    case '/':
//        if (y != 0) {
//            return x / y;
//        }
//        else {
//            cout << "Помилка: ділення на нуль." << endl;
//            exit(1);
//        }
//    default:
//        cout << "Помилка: невідома операція." << endl;
//        exit(1);
//    }
//}
//
//int main(int argc, char* argv[]) {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    if (argc != 2) {
//        cout << "Будь ласка, передайте один вираз у форматі «ХХоYY» як параметр командного рядка." << endl;
//        return 1;
//    }
//
//    string vuraz = argv[1];
//    int num1 = 0, num2 = 0;
//    char operacia = '\0';
//
//    for (int i = 0; i < vuraz.length(); i++) {
//        if (vuraz[i] == '+' || vuraz[i] == '-' || vuraz[i] == '*' || vuraz[i] == '/') {
//            operacia = vuraz[i];
//            try {
//                num1 = stoi(vuraz.substr(0, i));
//                num2 = stoi(vuraz.substr(i + 1));
//            }
//            catch (...) {
//                cout << "Невірний формат чисел." << endl;
//                return 1;
//            }
//            break;
//        }
//    }
//
//    if (operacia == '\0') {
//        cout << "Невірний формат виразу." << endl;
//        return 1;
//    }
//
//    int rez = Operation(num1, num2, operacia);
//    cout << "Результат виконання виразу: " << rez << endl;
//
//    return 0;
//}



////2
//#include <iostream>
//#include <string>
//#include <windows.h>
//#include "number_analysis.h"
//
//using namespace std;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    string vvid;
//    cout << "Введіть число: ";
//    cin >> vvid;
//
//    if (isInteger(vvid)) {
//        cout << "Число є цілим." << endl;
//    }
//    else {
//        cout << "Число є дробовим." << endl;
//    }
//
//    if (isEven(vvid)) {
//        cout << "Число є парним." << endl;
//    }
//    else {
//        cout << "Число є непарним." << endl;
//    }
//
//    string format = getNumberFormat(input);
//    cout << "Формат числа: " << format << endl;
//
//    int length = getDecimalLength(input);
//    cout << "Довжина числа в десятковому форматі: " << length << endl;
//
//    return 0;
//}