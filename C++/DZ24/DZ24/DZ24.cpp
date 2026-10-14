////1
//#include <iostream>
//#include <cstring>
//#include <cctype>
//#include <windows.h>
//using namespace std;
//
//bool isWordChar(char c) {
//    return isalpha(c) || isdigit(c);
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    const int SIZE = 256;
//    char str[SIZE];
//
//    cout << "Введіть рядок: ";
//    cin.getline(str, SIZE);
//
//    int slova = 0, literu = 0, cufru = 0, inshe = 0;
//
//    char* context = nullptr;
//    char* token = strtok_s(str, " ", &context);
//    while (token != nullptr) {
//        bool word = false;
//        for (int i = 0; i < strlen(token); i++) {
//            if (isalpha(token[i])) {
//                literu++;
//                word = true;
//            }
//            else if (isdigit(token[i])) {
//                cufru++;
//            }
//            else {
//                inshe++;
//            }
//        }
//        if (word) {
//            slova++;
//        }
//        token = strtok_s(nullptr, " ", &context);
//    }
//
//    cout << "Кількість слів: " << slova << endl;
//    cout << "Кількість літер: " << literu << endl;
//    cout << "Кількість цифр: " << cufru << endl;
//    cout << "Кількість символів: " << inshe << endl;
//
//    system("pause");
//    return 0;
//}



////2
//#include <iostream>
//#include <cstring>
//#include <windows.h>
//using namespace std;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    const int SIZE = 256;
//    char str[SIZE];
//
//    cout << "Введіть рядок: ";
//    cin.getline(str, SIZE);
//
//    int lengths[9] = { 0 };
//
//    char* context = nullptr;
//    char* token = strtok_s(str, " ", &context);
//    while (token != nullptr) {
//        int len = strlen(token);
//        if (len >= 2 && len <= 10) {
//            lengths[len - 2]++;
//        }
//        token = strtok_s(nullptr, " ", &context);
//    }
//
//    for (int i = 2; i <= 10; i++) {
//        cout << "Кількість слів довжиною " << i << " символів: " << lengths[i - 2] << endl;
//    }
//
//    system("pause");
//    return 0;
//}




////3
//#include <iostream>
//#include <cstring>
//#include <conio.h>
//#include <windows.h>
//using namespace std;
//
//const char correctPassword[] = "pas123";
//
//void hideInput(char* input, int size) {
//    int i = 0;
//    char ch;
//    while (i < size - 1) {
//        ch = _getch();
//        if (ch == '\r') {
//            break;
//        }
//        else if (ch == '\b' && i > 0) {
//            cout << "\b \b";
//            i--;
//        }
//        else {
//            input[i++] = ch;
//            cout << "*";
//        }
//    }
//    input[i] = '\0';
//    cout << endl;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    const int SIZE = 256;
//    char password[SIZE];
//    int attempts = 3;
//
//    while (attempts > 0) {
//        cout << "Введіть пароль: ";
//        hideInput(password, SIZE);
//
//        int len = strlen(password);
//        if (len > 0 && password[len - 1] == '\n') {
//            password[len - 1] = '\0';
//        }
//
//        if (strcmp(password, correctPassword) == 0) {
//            cout << "Привітання! Ви ввели правильний пароль." << endl;
//            return 0;
//        }
//        else {
//            attempts--;
//            if (attempts > 0) {
//                cout << "Неправильний пароль. Спробуйте ще раз. Залишилось спроб: " << attempts << endl;
//            }
//            else {
//                cout << "У вас закінчилися спроби. Доступ заборонено." << endl;
//            }
//        }
//    }
//
//    system("pause");
//    return 0;
//}
