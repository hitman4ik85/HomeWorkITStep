////1
//#include <iostream>
//#include <string>
//#include <Windows.h>
//using namespace std;
//
//string ShufrZSsyvom(const string& text, int N) {
//    string rez;
//    for (char c : text) {
//        if (isalpha(c)) {
//            char pochatok = isupper(c) ? 'A' : 'a';
//            c = pochatok + (c - pochatok + N) % 26;
//        }
//        rez += c;
//    }
//    return rez;
//}
//
//string DeshufrZiSsyva(const string& text, int N) {
//    return ShufrZSsyvom(text, 26 - N);
//}
//
//string ShufrVChusla(const string& text) {
//    string rez;
//    for (char c : text) {
//        if (isupper(c)) {
//            rez += to_string(c - 'A') + "_";
//        }
//        else if (islower(c)) {
//            rez += to_string(c - 'a' + 26) + "_";
//        }
//        else {
//            rez += c;
//        }
//    }
//    if (!rez.empty() && rez.back() == '_') {
//        rez.pop_back();
//    }
//    return rez;
//}
//
//string DeshufrZChusel(const string& text) {
//    string rez;
//    string temp;
//    for (char c : text) {
//        if (isdigit(c)) {
//            temp += c;
//        }
//        else if (c == '_') {
//            int poz = stoi(temp);
//            if (poz < 26) {
//                rez += 'A' + poz;
//            }
//            else {
//                rez += 'a' + (poz - 26);
//            }
//            temp.clear();
//        }
//        else {
//            rez += c;
//        }
//    }
//    if (!temp.empty()) {
//        int poz = stoi(temp);
//        if (poz < 26) {
//            rez += 'A' + poz;
//        }
//        else {
//            rez += 'a' + (poz - 26);
//        }
//    }
//    return rez;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    string text;
//    int N;
//
//    cout << "Введіть текст: ";
//    getline(cin, text);
//
//    cout << "Введіть значення зсуву N для шифру зсуву: ";
//    cin >> N;
//    cin.ignore();
//
//    string zashufrovane1 = ShufrZSsyvom(text, N);
//    string rozshufrovane1 = DeshufrZiSsyva(zashufrovane1, N);
//    cout << "\nШифр зсуву:\n";
//    cout << "Оригінальний текст: " << text << "\n";
//    cout << "Зашифрований текст: " << zashufrovane1 << "\n";
//    cout << "Розшифрований текст: " << rozshufrovane1 << "\n";
//
//    string zashufrovane2 = ShufrVChusla(text);
//    string rozshufrovane2 = DeshufrZChusel(zashufrovane2);
//    cout << "\nШифр позиції в алфавіті:\n";
//    cout << "Оригінальний текст: " << text << "\n";
//    cout << "Зашифрований текст: " << zashufrovane2 << "\n";
//    cout << "Розшифрований текст: " << rozshufrovane2 << "\n";
//
//    return 0;
//}




////2
//#include <iostream>
//#include <Windows.h>
//using namespace std;
//
//int RivnistChusel(int a, int b) {
//    if (a == b) {
//        cout << a << " і " << b << " рівні" << endl;
//        return 0;
//    }
//    else if (a < b) {
//        cout << a << " менше за " << b << endl;
//        return -1;
//    }
//    else {
//        cout << a << " більше за " << b << endl;
//        return 1;
//    }
//}
//
//int ChuPersheESummDrygogo(int a, int b) {
//    if (b == 0) return -1;
//    if (a < b) return -1;
//    int kilk = 0;
//    while (a >= b) {
//        a -= b;
//        kilk++;
//    }
//    if (a == 0) return kilk;
//    else return -1;
//}
//
//int Stepin(int a, int b) {
//    int rez = 1;
//    for (int i = 0; i < b; i++) {
//        rez *= a;
//    }
//    return rez;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int (*massF[3])(int, int) = { RivnistChusel, ChuPersheESummDrygogo, Stepin };
//
//    int x, y;
//    cout << "Введіть перше число: ";
//    cin >> x;
//    cout << "Введіть друге число: ";
//    cin >> y;
//
//    cout << "Результат порівняння: " << massF[0](x, y) << endl;
//
//    int rez = massF[1](x, y);
//    if (rez == -1) cout << "Неможливо записати " << x << " як суму декількох " << y << endl;
//    else cout << "Можна записати " << x << " як суму " << y << " у " << rez << " разів" << endl;
//
//    cout << x << " у степені " << y << " дорівнює " << massF[2](x, y) << endl;
//
//    return 0;
//}