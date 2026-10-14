////1
//#include <iostream>
//#include <Windows.h>
//using namespace std;
//
//#define MIN_INT(A, B) ((A) < (B) ? (A) : (B))
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int A, B;
//
//    cout << "Введіть число A: ";
//    cin >> A;
//    cout << "Введіть число B: ";
//    cin >> B;
//
//    int min_value = MIN_INT(A, B);
//
//    cout << "Менше з чисел A і B: " << min_value << endl;
//
//    return 0;
//}



////2
//#include <iostream>
//#include <cmath>
//#include <Windows.h>
//using namespace std;
//
//#define ADD(A, B) ((A) + (B))
//#define SUB(A, B) ((A) - (B))
//#define MUL(A, B) ((A) * (B))
//#define DIV(A, B) ((B) != 0 ? (A) / (B) : 0)
//#define POW(A, B) pow((A), (B))
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    int A, B;
//
//    cout << "Введіть число A: ";
//    cin >> A;
//    cout << "Введіть число B: ";
//    cin >> B;
//
//    int sum = ADD(A, B);
//    int minus = SUB(A, B);
//    int mnozh = MUL(A, B);
//    int dilenna = DIV(A, B);
//    double stepin = POW(A, B);
//
//    cout << "Сума A + B: " << sum << endl;
//    cout << "Різниця A - B: " << minus << endl;
//    cout << "Добуток A * B: " << mnozh << endl;
//    cout << "Частка A / B: " << dilenna << endl;
//    cout << "A піднесене до степені B: " << stepin << endl;
//
//    return 0;
//}



////3
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <Windows.h>
//
//using namespace std;
//
//#define RAND_MAX 100
//
//int findMin(int a, int b, int c, int d) {
//    int min_value = a;
//    if (b < min_value) min_value = b;
//    if (c < min_value) min_value = c;
//    if (d < min_value) min_value = d;
//    return min_value;
//}
//
//int findMax(int a, int b, int c, int d) {
//    int max_value = a;
//    if (b > max_value) max_value = b;
//    if (c > max_value) max_value = c;
//    if (d > max_value) max_value = d;
//    return max_value;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    int A = rand() % (RAND_MAX + 1);
//    int B = rand() % (RAND_MAX + 1);
//    int C = rand() % (RAND_MAX + 1);
//    int D = rand() % (RAND_MAX + 1);
//
//    cout << "Числа: A = " << A << ", B = " << B << ", C = " << C << ", D = " << D << endl;
//
//    int min_value = findMin(A, B, C, D);
//    int max_value = findMax(A, B, C, D);
//
//    cout << "Мінімальне значення: " << min_value << endl;
//    cout << "Максимальне значення: " << max_value << endl;
//
//    return 0;
//}