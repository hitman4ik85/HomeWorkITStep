////Завдання 1.
//#include <iostream>
//#include <windows.h>
//using std::cout;
//using std::endl;
//using std::cin;
//
//double SeredneArufmetu4ne(int mas[], int size) {
//    double sum = 0;
//    for (int i = 0; i < size; i++) {
//        sum += mas[i];
//    }
//    return sum / size;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    const int size = 10;
//    int salary[size];
//
//    for (int i = 0; i < size; i++) {
//        salary[i] = rand() % 11;
//    }
//    cout << "Масив: ";
//    for (int i = 0; i < size; i++) {
//        cout << "["<<salary[i]<<"]";
//    }
//    cout << endl;
//
//    double result = SeredneArufmetu4ne(salary, size);
//    cout << "Середнє арифметичне: " << result << endl;
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
//void SearchElements(int mas[], int size) {
//    int pliys = 0, minys = 0, zero = 0;
//    for (int i = 0; i < size; i++) {
//        if (mas[i] > 0) {
//            pliys++;
//        }
//        else if (mas[i] < 0) {
//            minys++;
//        }
//        else {
//            zero++;
//        }
//    }
//    cout << "Кількість додатніх: " << pliys << endl;
//    cout << "Кількість від'ємних: " << minys << endl;
//    cout << "Кількість нулів: " << zero << endl;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    const int size = 10;
//    int salary[size];
//
//    for (int i = 0; i < size; i++) {
//        salary[i] = rand() % 21 - 10;
//    }
//    cout << "Масив: ";
//    for (int i = 0; i < size; i++) {
//    cout << "[" << salary[i] << "]";
//    }
//    cout << endl;
//
//    SearchElements(salary, size);
//
//    return 0;
//}