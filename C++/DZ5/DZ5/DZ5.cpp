////Завдання 1. 
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
//    const int pervuiDen = 15;
//    const int nastypniDni = 2;
//    int Ndniv;
//
//    cout << "Введіть кількість днів: ";
//    cin >> Ndniv;
//
//    int zagalinaVidstan = pervuiDen;
//    int zrostanieVidstani = nastypniDni;
//
//    for (int den = 1; den < Ndniv; ++den) {
//        zagalinaVidstan += pervuiDen + zrostanieVidstani;
//        zrostanieVidstani += nastypniDni;
//    }
//
//    cout << "Загальна відстань, яку проповз равлик за " << Ndniv << " дні(в): " << zagalinaVidstan << " см" << endl;
//
//    return 0;
//
//}



////Завдання 2. 
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
//    int countOrliv = 0;
//
//    cout << "Підкиньте монету 9 разів (1 - 'Орел', або 0 - 'Решка'): " << endl;
//    for (int i = 1; i <= 9; i++) {
//        int result;
//        cout << "Спроба №:" << i << ": ";
//        cin >> result;
//
//        if (result == 1) {
//            countOrliv++;
//        }
//    }
//
//    if (countOrliv % 2 == 0) {
//        cout << "Студент Д. приймає рішення в позитивну сторону." << endl;
//    }
//    else {
//        cout << "Студент Д. приймає рішення в негативну сторону." << endl;
//    }
//
//    return 0;
//
//}