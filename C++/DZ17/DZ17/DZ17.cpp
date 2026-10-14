////1
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//int KilkistCufr(const char array[]) {
//    int kilkist = 0;
//    for (int i = 0; array[i] != '\0'; i++) {
//        if (array[i] >= '0' && array[i] <= '9') {
//            kilkist++;
//        }
//    }
//    return kilkist;
//}
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//    const int ROW = 100;
//    char array[ROW];
//
//    cout << "Введіть ціле число (з додатніх та від’ємних чисел): ";
//    cin >> array;
//
//    int ysiCufru = KilkistCufr(array);
//
//    if (ysiCufru == 0) {
//        cout << "Число не знайдено у введеному рядку." << endl;
//    }
//    else {
//        cout << "Кількість цифр у введеному числі: " << ysiCufru << endl;
//    }
//
//	system("pause");
//	return 0;
//}




////2
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//char KodovanaLitera(char litera, int zmishenna) {
//    if (litera >= 'a' && litera <= 'z') {
//        return 'a' + (litera - 'a' + zmishenna + 26) % 26;
//    }
//    else if (litera >= 'A' && litera <= 'Z') {
//        return 'A' + (litera - 'A' + zmishenna + 26) % 26;
//    }
//    else {
//        return litera;
//    }
//}
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//    char litera;
//    int zmishenna;
//
//    cout << "Введіть літеру (латинь): ";
//    cin >> litera;
//
//    cout << "Введіть цифру з (+ або -), на скільки буде зміщення від літери: ";
//    cin >> zmishenna;
//
//    char kodLitera = KodovanaLitera(litera, zmishenna);
//    cout << "Кодована літера: " << kodLitera << endl;
//
//    system("pause");
//    return 0;
//}





////3
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//double Calculator(double num1, double num2, char pruklad) {
//    switch (pruklad) {
//    case '+':
//        return num1 + num2;
//    case '-':
//        return num1 - num2;
//    case '*':
//        return num1 * num2;
//    case '/':
//        if (num2 == 0) {
//            cout << "Помилка: ділення на нуль неможливе" << endl;
//            return -1;
//        }
//        return num1 / num2;
//    default:
//        cout << "Невірна операція!" << endl;
//        return 0;
//    }
//}
//
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    double num1, num2;
//    char pruklad;
//
//    cout << "Введіть перше число: ";
//    cin >> num1;
//
//    cout << "Введіть друге число: ";
//    cin >> num2;
//
//    cout << "Введіть математичну операцію (+, -, *, /): ";
//    cin >> pruklad;
//
//    double rez = Calculator(num1, num2, pruklad);
//
//    if (rez != -1) {
//        switch (pruklad) {
//        case '+':
//            cout << "Результат: " << num1 << " + " << num2 << " = " << rez << endl;
//            break;
//        case '-':
//            cout << "Результат: " << num1 << " - " << num2 << " = " << rez << endl;
//            break;
//        case '*':
//            cout << "Результат: " << num1 << " * " << num2 << " = " << rez << endl;
//            break;
//        case '/':
//            cout << "Результат: " << num1 << " / " << num2 << " = " << rez << endl;
//            break;
//        default:
//            cout << "Невірна операція!" << endl;
//            return 1;
//        }
//    }
//
//    system("pause");
//    return 0;
//}


