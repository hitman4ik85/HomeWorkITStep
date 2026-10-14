//Завдання 1.

/*#include <iostream>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double R1;      //Опор 1
    double R2;      //Опор 2
    double R3;      //Опор 3

    cout << "Введіть значення опору R1: ";
    cin >> R1;
    cout << "Введіть значення опору R2: ";
    cin >> R2;
    cout << "Введіть значення опору R3: ";
    cin >> R3;

    double valueResist = 1 / (1 / R1 + 1 / R2 + 1 / R3);     //Значення опору r0

    cout << "Значення опору R0: " << valueResist << " Ом" << endl;

    return 0;
}*/




//Завдання 2.

/*#include <iostream>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double L;   //Довжина кола
    const double pi = 3.14;

    cout << "Введіть довжину кола: ";
    cin >> L;
        
    double R = L / (2 * pi);  //Радіус кола
        
    double S = pi * R * R;    //Площа кола

    cout << "Площа кола: " << S << endl;

    return 0;
}*/


//Завдання 3.

/*#include <iostream>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    double v;   //швидкість
    double t;   //час
    double a;   //прискорення

    cout << "Введіть швидкість (в м/с): ";
    cin >> v;
    cout << "Введіть час (в секундах): ";
    cin >> t;
    cout << "Введіть прискорення (в м/с^2): ";
    cin >> a;
    
    double S = v * t + (a * t * t) / 2;     //Пройдена відстань

    cout << "Пройдена відстань: " << S << " м" << endl;

    return 0;
}*/



//Завдання 4.

/*#include <iostream>
#include <windows.h>

using std::cout;
using std::cin;
using std::endl;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int maxNumber;      //Змінна для максимального числа

    cout << "Введіть число 1: ";    //Запитуємо перше число
    cin >> maxNumber;      //Присвоюємо його як максимальне

    int number;     //Змінна для зберігання подальшого числа
    cout << "Введіть число 2: ";   //Зчитуємо подальше число та порівнюємо його з максимальним
    cin >> number;
    if (number > maxNumber) {       //Якщо число буде більшим за максимальне то записуємо його до максимального
        maxNumber = number;
    }

    cout << "Введіть число 3: ";
    cin >> number;
    if (number > maxNumber) {
        maxNumber = number;
    }

    cout << "Введіть число 4: ";
    cin >> number;
    if (number > maxNumber) {
        maxNumber = number;
    }

    cout << "Введіть число 5: ";
    cin >> number;
    if (number > maxNumber) {
        maxNumber = number;
    }

    cout << "Введіть число 6: ";
    cin >> number;
    if (number > maxNumber) {
        maxNumber = number;
    }

    cout << "Введіть число 7: ";
    cin >> number;
    if (number > maxNumber) {
        maxNumber = number;
    }

    cout << "Максимальне число: " << maxNumber << endl;

    return 0;
}*/