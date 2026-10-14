////1
//#include <iostream>
//#include <iomanip>
//#include <cstdlib>
//#include <string>
//#include <Windows.h>
//
//using namespace std;
//
//union Number {
//    char c;
//    short s;
//    int i;
//    float f;
//};
//
//enum DataType { CHAR_TYPE = 1, SHORT_TYPE, INT_TYPE, FLOAT_TYPE };
//
//void displayMenu() {
//    cout << "Виберіть тип даних:\n";
//    cout << "1. char\n";
//    cout << "2. short\n";
//    cout << "3. int\n";
//    cout << "4. float\n";
//}
//
//void displayOperations() {
//    cout << "Виберіть операцію:\n";
//    cout << "1. Додавання (+)\n";
//    cout << "2. Віднімання (-)\n";
//    cout << "3. Множення (*)\n";
//    cout << "4. Ділення (/)\n";
//}
//
//bool isValidTypeChoice(int choice) {
//    return choice >= 1 && choice <= 4;
//}
//
//bool isValidOperationChoice(char choice) {
//    return choice == '+' || choice == '-' || choice == '*' || choice == '/';
//}
//
//void performOperation(int type, char operation, Number num1, Number num2) {
//    switch (type) {
//    case CHAR_TYPE:
//        switch (operation) {
//        case '+':
//            cout << "Результат: " << (num1.c - '0') + (num2.c - '0') << endl;
//            break;
//        case '-':
//            cout << "Результат: " << (num1.c - '0') - (num2.c - '0') << endl;
//            break;
//        case '*':
//            cout << "Результат: " << (num1.c - '0') * (num2.c - '0') << endl;
//            break;
//        case '/':
//            if (num2.c == '0') {
//                cerr << "Помилка: Ділення на нуль!" << endl;
//            }
//            else {
//                cout << "Результат: " << (num1.c - '0') / (num2.c - '0') << endl;
//            }
//            break;
//        }
//        break;
//    case SHORT_TYPE:
//        switch (operation) {
//        case '+':
//            cout << "Результат: " << num1.s + num2.s << endl;
//            break;
//        case '-':
//            cout << "Результат: " << num1.s - num2.s << endl;
//            break;
//        case '*':
//            cout << "Результат: " << num1.s * num2.s << endl;
//            break;
//        case '/':
//            if (num2.s == 0) {
//                cerr << "Помилка: Ділення на нуль!" << endl;
//            }
//            else {
//                cout << "Результат: " << num1.s / num2.s << endl;
//            }
//            break;
//        }
//        break;
//    case INT_TYPE:
//        switch (operation) {
//        case '+':
//            cout << "Результат: " << num1.i + num2.i << endl;
//            break;
//        case '-':
//            cout << "Результат: " << num1.i - num2.i << endl;
//            break;
//        case '*':
//            cout << "Результат: " << num1.i * num2.i << endl;
//            break;
//        case '/':
//            if (num2.i == 0) {
//                cerr << "Помилка: Ділення на нуль!" << endl;
//            }
//            else {
//                cout << "Результат: " << num1.i / num2.i << endl;
//            }
//            break;
//        }
//        break;
//    case FLOAT_TYPE:
//        switch (operation) {
//        case '+':
//            cout << "Результат: " << num1.f + num2.f << endl;
//            break;
//        case '-':
//            cout << "Результат: " << num1.f - num2.f << endl;
//            break;
//        case '*':
//            cout << "Результат: " << num1.f * num2.f << endl;
//            break;
//        case '/':
//            if (num2.f == 0.0f) {
//                cerr << "Помилка: Ділення на нуль!" << endl;
//            }
//            else {
//                cout << "Результат: " << num1.f / num2.f << endl;
//            }
//            break;
//        }
//        break;
//    }
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    Number num1, num2;
//    int typeChoice;
//    char operationChoice;
//
//    displayMenu();
//    cin >> typeChoice;
//
//    if (!isValidTypeChoice(typeChoice)) {
//        cerr << "Неправильний вибір типу даних. Спробуйте ще раз." << endl;
//        return 1;
//    }
//
//    int type = typeChoice;
//
//    cout << "Введіть перше число: ";
//    switch (type) {
//    case CHAR_TYPE:
//        cin >> num1.c;
//        break;
//    case SHORT_TYPE:
//        cin >> num1.s;
//        break;
//    case INT_TYPE:
//        cin >> num1.i;
//        break;
//    case FLOAT_TYPE:
//        cin >> num1.f;
//        break;
//    }
//
//    cout << "Введіть друге число: ";
//    switch (type) {
//    case CHAR_TYPE:
//        cin >> num2.c;
//        break;
//    case SHORT_TYPE:
//        cin >> num2.s;
//        break;
//    case INT_TYPE:
//        cin >> num2.i;
//        break;
//    case FLOAT_TYPE:
//        cin >> num2.f;
//        break;
//    }
//
//    displayOperations();
//    cin >> operationChoice;
//
//    if (!isValidOperationChoice(operationChoice)) {
//        cerr << "Неправильний вибір операції. Спробуйте ще раз." << endl;
//        return 1;
//    }
//
//    performOperation(type, operationChoice, num1, num2);
//
//    return 0;
//}




////2
//#include <iostream>
//#include <string>
//#include <Windows.h>
//
//using namespace std;
//
//const int NUM_COLORS = 7;
//const string colors[NUM_COLORS] = { "red", "orange", "yellow", "green", "blue", "indigo", "violet" };
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    bool colorSelected[NUM_COLORS] = { false };
//
//    string colorInput;
//    cout << "Введіть назви кольорів (red, orange, yellow, green, blue, indigo, violet) \nчерез пробіл (наприклад, green red blue): ";
//    getline(cin, colorInput);
//
//    string token;
//    size_t pos = 0;
//    string delimiter = " ";
//    while ((pos = colorInput.find(delimiter)) != string::npos) {
//        token = colorInput.substr(0, pos);
//        bool found = false;
//        for (int i = 0; i < NUM_COLORS; i++) {
//            if (token == colors[i]) {
//                colorSelected[i] = true;
//                found = true;
//                break;
//            }
//        }
//        if (!found) {
//            cout << "Колір '" << token << "' не знайдено у списку." << endl;
//        }
//        colorInput.erase(0, pos + delimiter.length());
//    }
//
//    bool found = false;
//    for (int i = 0; i < NUM_COLORS; i++) {
//        if (colorInput == colors[i]) {
//            colorSelected[i] = true;
//            found = true;
//            break;
//        }
//    }
//    if (!found && !colorInput.empty()) {
//        cout << "Колір '" << colorInput << "' не знайдено у списку." << endl;
//    }
//
//    cout << "Результат роботи програми: ";
//    for (int i = 0; i < NUM_COLORS; i++) {
//        cout << (colorSelected[i] ? '1' : '0');
//    }
//    cout << endl;
//
//    return 0;
//}