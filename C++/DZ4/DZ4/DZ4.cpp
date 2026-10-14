//// Завдання 1. Напишіть програму, яка обчислює суму цілих чисел від а до 500 (значення a вводиться з клавіатури).
// 
//#include <iostream>
//#include <Windows.h>
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int a;
//    cout << "Введіть значення a: ";
//    cin >> a;
//
//    int i = a;
//    int sum = 0;
//
//    while (i <= 500) {
//        sum += i;
//        i++;
//    }
//
//    cout << "Сума чисел від " << a << " до 500: " << sum << endl;
//
//    return 0;
//}


//// Завдання 2. Напишіть програму, яка запитує два цілих числа x і y, після чого обчислює і виводить значення x у степені y.
// 
//#include <iostream>
//#include <cmath>
//#include <Windows.h>
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int x, y;
//    double result;
//
//    cout << "Введіть ціле число 'х' для перетворення у степінь: ";
//    cin >> x;
//    cout << "Введіть ціле число 'у' (це степінь): ";
//    cin >> y;
//
//    result = pow(x, y);
//
//    cout << x << " у " << y << " степені = " << result << endl;
//
//    return 0;
//}


//// Завдання 3. Знайти середнє арифметичне всіх цілих чисел від 1 до 1000.
// 
//#include <iostream>
//#include <Windows.h>
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int sum = 0;
//    int i = 0;
//    int num = 1;
//
//    while (num <= 1000) {
//        sum += num;
//        i++;
//        num++;
//    }
//
//    float average = (float)sum / i;
//
//    cout << "Середнє арифметичне всіх цілих чисел від 1 до 1000: " << average << endl;
//
//    return 0;
//}


//// Завдання 4. Знайти добуток усіх цілих чисел від a до 20 (значення a вводиться з клавіатури: 1 <=a <= 20).
// 
//#include <iostream>
//#include <Windows.h>
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int a;
//    long long dob = 1;
//
//    cout << "Введіть число a у діапазоні (1 <= a <= 20): ";
//    cin >> a;
//
//    int i = a;
//
//    if (i < 1 || i > 20) {
//        cout << "Помилка: введене число має бути в межах від 1 до 20." << endl;
//        return 1;
//    }
//
//    while (i <= 20) {
//        dob *= i;
//        i++;
//    }
//
//    cout << "Добуток усіх цілих чисел від " << a << " до 20: " << dob << endl;
//
//    return 0;
//}


//// Завдання 5. Написати програму, яка виводить на екран таблицю множення на 6.
// 
//#include <iostream>
//#include <Windows.h>
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int i = 1;
//
//    cout << "Таблиця множення на 6:" << endl;
//    while (i <= 10) {
//        cout << "6 * " << i << " = " << 6 * i << endl;
//        i++;
//    }
//
//    return 0;
//}