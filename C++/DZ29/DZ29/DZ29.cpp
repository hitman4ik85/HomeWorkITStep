////1
//#include <iostream>
//#include <Windows.h>
//
//using namespace std;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    unsigned int N;
//    cout << "Введіть ціле число N: ";
//    cin >> N;
//
//    bool isPowerOfTwo = (N != 0) && ((N & (N - 1)) == 0);
//
//    if (isPowerOfTwo) {
//        cout << N << " є степенем числа 2." << endl;
//    }
//    else {
//        cout << N << " не є степенем числа 2." << endl;
//    }
//
//    return 0;
//}




////2
//#include <iostream>
//#include <Windows.h>
//
//using namespace std;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int N;
//    cout << "Введіть ціле число N: ";
//    cin >> N;
//
//    int kilk = 0;
//    int maxKilk = 0;
//
//    while (N != 0) {
//        if (N & 1) {
//            kilk++;
//            if (kilk > maxKilk) {
//                maxKilk = kilk;
//            }
//        }
//        else {
//            kilk = 0;
//        }
//        N >>= 1;
//    }
//
//    cout << "Максимально підряд кількість одиниць в двійковому записі числа N: " << maxKilk << endl;
//
//    return 0;
//}




////3
//#include <iostream>
//#include <string>
//#include <Windows.h>
//using namespace std;
//
//string DecToHex(int n) {
//    string hex = "";
//    char hexChars[] = "0123456789ABCDEF";
//
//    if (n == 0)
//        return "0";
//
//    while (n > 0) {
//        int ostacha = n % 16;
//        hex = hexChars[ostacha] + hex;
//        n /= 16;
//    }
//
//    return hex;
//}
//
//int hexToDec(string hex) {
//    int dec = 0;
//    int base = 1;
//
//    for (int i = hex.length() - 1; i >= 0; i--) {
//        if (hex[i] >= '0' && hex[i] <= '9') {
//            dec += (hex[i] - '0') * base;
//            base *= 16;
//        }
//        else if (hex[i] >= 'A' && hex[i] <= 'F') {
//            dec += (hex[i] - 'A' + 10) * base;
//            base *= 16;
//        }
//    }
//
//    return dec;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int vubir;
//    cout << "Виберіть опцію:\n";
//    cout << "1. Перевести з десяткової в шістнадцяткову систему\n";
//    cout << "2. Перевести з шістнадцяткової в десяткову систему\n";
//    cout << "Ваш вибір: ";
//    cin >> vubir;
//
//    if (vubir == 1) {
//        int decNum;
//        cout << "Введіть десяткове число: ";
//        cin >> decNum;
//        string hexNum = DecToHex(decNum);
//        cout << "Шістнадцяткове: " << hexNum << endl;
//    }
//    else if (vubir == 2) {
//        string hexNum;
//        cout << "Введіть шістнадцяткове число: ";
//        cin >> hexNum;
//        int decNum = hexToDec(hexNum);
//        cout << "Десяткове: " << decNum << endl;
//    }
//    else {
//        cout << "Невірний вибір." << endl;
//    }
//
//    return 0;
//}
