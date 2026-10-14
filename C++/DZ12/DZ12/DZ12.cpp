////Завдання 1.
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//int main() {
//    SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//    int a, b, c;
//
//    cout << "Введіть позитивне число №1:";
//    cin >> a;
//    cout << "Введіть позитивне число №2:";
//    cin >> b;
//    cout << "Введіть позитивне число №3:";
//    cin >> c;
//    
//    int count = 0;
//    for (int i = 1; i <= 100000; i++) {
//        if (i % a == 0 && i % b == 0 && i % c == 0) {
//            cout << i << endl;
//            count++;
//        }
//    }
//    cout << endl;
//    cout << "Загальна кількість кратних чисел=" << count;
//
//    return 0;
//}
//
////Завдання 2.
//#include <iostream>
//#include <windows.h>
//#include <iomanip>
//using namespace std;
//
//int main() {
//    SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//    int a;
//
//    cout << "Для створення квадрату введіть ціле число: ";
//    cin >> a;
//
//    int start = a - 5;
//    
//    int nyl = 1;
//
//    for (int i = 1; i <= 5; i++) {
//        int pokaz = start;
//        for (int k = 1; k <= 5; k++) {
//            int znak = 1;
//            if (k > 3) { znak = -1; }
//            pokaz += znak;
//            cout << setw(3) << pokaz;
//        }
//        cout << endl;
//
//        if (i >= 3) { nyl = -1; }
//        start += nyl;
//    }
//    return 0;
//}
//
////Завдання 3.
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//int main() {
//    SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//    int shykane = 0;
//
//    for (int b = 1; b <= 9; b++) {
//        for (int m = 0; m <= 9; m++) {
//            if (m == b) { continue; }
//            for (int w = 0; w <= 9; w++) {
//                if (w == b || w == m) { continue; }
//                for (int z = 1; z <= 9; z++) {
//                    if (z == b || z == m || z == w) { continue; }
//                    for (int a = 0; a <= 9; a++) {
//                        if (a == b || a == m || a == w || a == z) { continue; }
//
//                        int huslo1 = b * 100 + m * 10 + w;
//                        int huslo2 = z * 100 + a * 10 + z;
//
//                        int rez = huslo1 + huslo2;
//
//                        if (rez < 1000) { continue; }
//                        int h1 = rez / 1000;
//                        if (h1 != m) { continue; }
//                        
//                        int vr = rez - h1 * 1000;
//                        int h2 = vr / 100;
//                        if (h2==a || h2 == b || h2 == m || h2 == w || h2 == z || h2==h1) { continue; }
//
//                        vr = vr - h2 * 100;
//                        int h3 = vr / 10;
//                        if (h3==h2 || h3 == a || h3 == b || h3 == m || h3 == w || h3 == z || h3 == h1) { continue; }
//
//                        int h4 = vr - h3 * 10;
//                        if (h4 != h2) { continue; }
//                        
//                        cout << huslo1 << "+" << huslo2 << "=" << rez;
//                        shykane = 1; break;
//                    }
//                    if (shykane == 1) { break; }
//                }
//                if (shykane == 1) { break; }
//            }
//            if (shykane == 1) { break; }
//        }
//        if (shykane == 1) { break; }
//    }
//    return 0;
//}