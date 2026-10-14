////1
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//bool ChuGolosna(char c) {
//    //char golosna[] = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
//    char golosna[] = "aeiouAEIOU";
//    for (int i = 0; i < 10; i++) {
//        if (c == golosna[i]) {
//            return true;
//        }
//    }
//    return false;
//}
//
//void ZaminaGolosnoi(char* str, char ch) {
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (ChuGolosna(str[i])) {
//            str[i] = ch;
//        }
//    }
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    const int SIZE = 100;
//    char str[SIZE];
//    char ch;
//
//    cout << "Введіть рядок: ";
//    cin.getline(str, SIZE);
//
//    cout << "Введіть голосну букву для заміни: ";
//    cin >> ch;
//
//    ZaminaGolosnoi(str, ch);
//
//    cout << "Рядок після заміни: " << str << endl;
//
//    system("pause");
//    return 0;
//}




////2
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//bool SpivpadLiter(const char* slovo, int dovzhuna) {
//    if (dovzhuna <= 1) {
//        return false;
//    }
//    return slovo[0] != slovo[dovzhuna - 1];
//}
//
//void ObrobkaRiadka(const char* str) {
//    int start = 0;
//    bool ySlovi = false;
//
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (str[i] != ' ' && !ySlovi) {
//            start = i;
//            ySlovi = true;
//        }
//        else if ((str[i] == ' ' || str[i + 1] == '\0') && ySlovi) {
//            int end = (str[i] == ' ') ? i : i + 1;
//            if (SpivpadLiter(&str[start], end - start)) {
//                for (int j = start; j < end; j++) {
//                    cout << str[j];
//                }
//                cout << " ";
//            }
//            ySlovi = false;
//        }
//    }
//    cout << endl;
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
//    cout << "Слова, де перша та остання літери не співпадають: ";
//    ObrobkaRiadka(str);
//
//    system("pause");
//    return 0;
//}




////3
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//void KorekciaSlova(char* slovo, int dovzhuna) {
//    if (dovzhuna % 2 == 0) {
//        int mid = dovzhuna / 2;
//        char temp = slovo[mid - 1];
//        slovo[mid - 1] = slovo[mid];
//        slovo[mid] = temp;
//    }
//    else {
//        int mid = dovzhuna / 2;
//        slovo[mid] = slovo[0];
//    }
//}
//
//void ObrobkaRiadka(char* str) {
//    int start = 0;
//    bool ySlovi = false;
//
//    for (int i = 0; str[i] != '\0'; i++) {
//        if (str[i] != ' ' && !ySlovi) {
//            start = i;
//            ySlovi = true;
//        }
//        else if ((str[i] == ' ' || str[i + 1] == '\0') && ySlovi) {
//            int end = (str[i] == ' ') ? i : i + 1;
//            int dovzhuna = end - start;
//            KorekciaSlova(&str[start], dovzhuna);
//            ySlovi = false;
//        }
//    }
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
//    ObrobkaRiadka(str);
//
//    cout << "Відкориговані слова: " << str << endl;
//
//    system("pause");
//    return 0;
//}