////Завдання 1.
//#include <iostream>
//#include <cmath>
//#include <windows.h>
//using std::cout;
//using std::endl;
//using std::cin;
//
//double NumForStepin(double num, double stepin) {
//    cout << "число " << num << " у степені " << stepin << " = ";
//    return pow(num, stepin);
//}
//
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    double num, stepin;
//
//    cout << "Введіть число для піднесення у степінь: ";
//    cin >> num;
//    cout << "Введіть показник степеня: ";
//    cin >> stepin;
//
//    double result = NumForStepin(num, stepin);
//    cout << result << endl;
//
//    return 0;
//}


////Завдання 2.
//#include <iostream>
//#include <windows.h>
//using std::cout;
//using std::endl;
//using std::cin;
//
//int sumInRange(int start, int end) {
//    int sum = 0;
//    for (int i = start; i <= end; i++) {
//        sum += i;
//    }
//    return sum;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int start, end;
//
//    cout << "Введіть початок діапазону: ";
//    cin >> start;
//    cout << "Введіть кінець діапазону: ";
//    cin >> end;
//
//    cout << "Сума чисел у діапазоні від " << start << " до " << end << " = ";
//    cout << sumInRange(start, end) << endl;
//
//    return 0;
//}


////Завдання 3.
//#include <iostream>
//#include <windows.h>
//using std::cout;
//using std::endl;
//using std::cin;
//
//bool PerfectNum(int num) {
//    int sum = 0;
//    for (int i = 1; i < num; i++) {
//        if (num % i == 0) {
//            sum += i;
//        }
//    }
//    return (sum == num);
//}
//
//bool findPerfectNum(int start, int end) {
//    bool find = false;
//    cout << "Досконалі числа у заданому інтервалі: ";
//    for (int i = start; i <= end; i++) {
//        if (PerfectNum(i)) {
//            cout << i << " ";
//            find = true;
//        }
//    }
//    cout << endl;
//    return find;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int start, end;
//    cout << "Введіть початок інтервалу: ";
//    cin >> start;
//    cout << "Введіть кінець інтервалу: ";
//    cin >> end;
//
//    if (!findPerfectNum(start, end)) {
//        cout << "У заданому інтервалі немає досконалих чисел." << endl;
//    }
//
//    return 0;
//}


////Завдання 4.
//#include <iostream>
//using std::cout;
//using std::endl;
//using std::cin;
//
//void PrintCard(int num, int masti) {
//
//    if (num == 1)
//        cout << "A ";
//    else if (num == 11)
//        cout << "J ";
//    else if (num == 12)
//        cout << "Q ";
//    else if (num == 13)
//        cout << "K ";
//    else
//        cout << num << " ";
//
//    switch (masti) {
//    case 1:
//        cout << char(5); // ASCII код для ♣
//        break;
//    case 2:
//        cout << char(4); // ASCII код для ♦
//        break;
//    case 3:
//        cout << char(3); // ASCII код для ♥
//        break;
//    case 4:
//        cout << char(6); // ASCII код для ♠
//        break;
//    default:
//        cout << "Неправильна масть";
//    }
//    cout << endl;
//}
//
//int main() {
//setlocale(LC_ALL, "RUS");
//
//    int num;
//    int masti;
//
//    cout << "Введiть номер карти (2-10 або 1 - Туз, 11 - Валет, 12 - Дама, 13 - Король): ";
//    cin >> num;
//    cout << "Введiть масть карти (1 - трефи, 2 - бубни, 3 - черви, 4 - пiки): ";
//    cin >> masti;
//
//    PrintCard(num, masti);
//
//    return 0;
//}


////Завдання 5.
//#include <iostream>
//#include <windows.h>
//using std::cout;
//using std::endl;
//using std::cin;
//
//bool isLuckyNumber(int number) {
//    if (number < 100000 || number > 999999) {
//        return false;
//    }
//
//    int leftSum = 0;
//    int rightSum = 0;
//    for (int i = 0; i < 6; i++) {
//        int digit = number % 10;
//        number /= 10;
//
//        if (i < 3) {
//            leftSum += digit;
//        }
//        else {
//            rightSum += digit;
//        }
//    }
//
//    return leftSum == rightSum;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int num;
//    cout << "Введіть шестизначне число: ";
//    cin >> num;
//
//    if (isLuckyNumber(num))
//        cout << "Це щасливе число!" << endl;
//    else
//        cout << "Це число не щасливе!" << endl;
//
//    return 0;
//}