////Завдання 1.
//#include <iostream>
//#include <windows.h>;
//using std::cout;
//using std::endl;
//using std::cin;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    const int SIZE = 10;
//    int salary[SIZE];
//
//    cout << "Введіть " << SIZE << " чисел:" << endl;
//    for (int i = 0; i < SIZE; ++i) {
//        cout << "Елемент " << i + 1 << ": ";
//        cin >> salary[i];
//    }
//
//    int minI = salary[0];
//    int maxI = salary[0];
//
//    for (int i = 1; i < SIZE; ++i) {
//        if (salary[i] < minI) {
//            minI = salary[i];
//        }
//        if (salary[i] > maxI) {
//            maxI = salary[i];
//        }
//    }
//
//    cout << "Мінімальний елемент: " << minI << endl;
//    cout << "Максимальний елемент: " << maxI << endl;
//
//    return 0;
//}


////Завдання 2.
//#include <iostream>
//#include <windows.h>;
//using std::cout;
//using std::endl;
//using std::cin;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    const int misaci = 12;
//    double prubytok[misaci];
//
//    for (int i = 0; i < misaci; ++i) {
//        cout << "Введіть прибуток за " << i + 1 << "-й місяць: ";
//        cin >> prubytok[i];
//    }
//
//    // Введення діапазону місяців
//    int pershuiMisac, ostanniMisac;
//    cout << "Введіть початковий місяць діапазону: ";
//    cin >> pershuiMisac;
//    cout << "Введіть кінцевий місяць діапазону: ";
//    cin >> ostanniMisac;
//
//    // Перевірка правильності введеного діапазону
//    if (pershuiMisac < 1 || pershuiMisac > misaci || ostanniMisac < 1 || ostanniMisac > misaci || pershuiMisac > ostanniMisac) {
//        cout << "Неправильно введений діапазон місяців." << endl;
//        return 1;
//    }
//
//    // Пошук максимального та мінімального прибутку у вказаному діапазоні
//    double maxPrubytok = prubytok[pershuiMisac - 1];
//    double minPrubytok = prubytok[pershuiMisac - 1];
//    int maxMisac = pershuiMisac;
//    int minMisac = pershuiMisac;
//
//    for (int i = pershuiMisac - 1; i < ostanniMisac; ++i) {
//        if (prubytok[i] > maxPrubytok) {
//            maxPrubytok = prubytok[i];
//            maxMisac = i + 1;
//        }
//        if (prubytok[i] < minPrubytok) {
//            minPrubytok = prubytok[i];
//            minMisac = i + 1;
//        }
//    }
//
//    // Виведення результатів
//    cout << "Максимальний прибуток (" << maxPrubytok << ") був у місяці " << maxMisac << endl;
//    cout << "Мінімальний прибуток (" << minPrubytok << ") був у місяці " << minMisac << endl;
//
//    return 0;
//}



////Завдання 3.
//#include <iostream>
//#include <windows.h>;
//using std::cout;
//using std::endl;
//using std::cin;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    const int size = 6;
//    double salary[size];
//
//    cout << "Введіть " << size << " дійсних чисел для масиву:" << endl;
//    for (int i = 0; i < size; ++i) {
//        cout << "Елемент " << i+1 << ": ";
//        cin >> salary[i];
//    }
//
//    double sumMinys = 0;
//    double minimalne = salary[0];
//    double maximalne = salary[0];
//    int persheMinys = -1;
//    int ostanneMinys = -1;
//    int indexMin = 0;
//    int indexMax = 0;
//
//    for (int i = 0; i < size; ++i) {
//        if (salary[i] < 0) {
//            sumMinys += salary[i];
//            if (persheMinys == -1)
//                persheMinys = i;
//            ostanneMinys = i;
//        }
//    }
//
//    for (int i = 1; i < size; ++i) {
//        if (salary[i] < minimalne) {
//            minimalne = salary[i];
//            indexMin = i;
//        }
//        if (salary[i] > maximalne) {
//            maximalne = salary[i];
//            indexMax = i;
//        }
//    }
//
//    double dobParnuh = 1;
//    for (int i = 0; i < size; i += 2) {
//        dobParnuh *= salary[i];
//    }
//
//    double dobMizhMinTaMax = 1;
//    int start = indexMin < indexMax ? indexMin : indexMax;
//    int end = indexMin > indexMax ? indexMin : indexMax;
//    for (int i = start + 1; i < end; ++i) {
//        dobMizhMinTaMax *= salary[i];
//    }
//
//    double sumMizhMinysamu = 0;
//    if (persheMinys != -1 && ostanneMinys != -1) {
//        for (int i = persheMinys + 1; i < ostanneMinys; ++i) {
//            sumMizhMinysamu += salary[i];
//        }
//    }
//
//    cout << "Сума від'ємних елементів масиву: " << sumMinys << endl;
//    cout << "Добуток елементів між мінімальним та максимальним: " << dobMizhMinTaMax << endl;
//    cout << "Добуток елементів, що стоять на парних місцях масиву: " << dobParnuh << endl;
//    cout << "Сума елементів між першим і останнім від'ємними елементами масиву: " << sumMizhMinysamu << endl;
//
//    return 0;
//}