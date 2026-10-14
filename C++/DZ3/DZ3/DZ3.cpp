//// Завдання 1. Користувач вводить із клавіатури символ. Визначити який це символ: буква, цифра, розділовий знак або інше.
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
//    char simvol;
//
//    cout << "Введіть символ: ";
//    cin >> simvol;
//
//    if ((simvol >= 'a' && simvol <= 'z') || (simvol >= 'A' && simvol <= 'Z')) {
//        cout << "Введений символ є буквою." << endl;
//    }
//
//    else if (simvol >= '0' && simvol <= '9') {
//        cout << "Введений символ є цифрою." << endl;
//    }
//
//    else if ((simvol >= 32 && simvol <= 47) || (simvol >= 58 && simvol <= 64) || (simvol >= 91 && simvol <= 96) || (simvol >= 123 && simvol <= 126)) {
//        cout << "Введений символ є розділовим знаком." << endl;
//    }
//
//    else {
//        cout << "Введений символ є іншим." << endl;
//    }
//
//    return 0;
//}



//// Завдання 2. Написати програму підрахунку вартості розмови для різних мобільних операторів. Користувач вводить вартість розмови 
//// та обирає з якого на який оператор він телефонує. Вивести вартість на екран.
// 
//#include <iostream>
//#include <iomanip>
//#include <Windows.h>
//using std::cout;
//using std::cin;
//using std::endl;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//double cost;
//int option;
//
//cout << "Введіть вартість розмови на хвилину: ";
//cin >> cost;
//
//cout << "Оберіть оператора: " << endl;
//cout << "1. Київстар" << endl;
//cout << "2. Vodafone" << endl;
//cout << "3. Lifecell" << endl;
//cin >> option;
//
//switch (option) {
//case 1:
//    cout << "Вартість розмови з Київстар: " << cost * 1.1 << " грн" << endl;
//    break;
//case 2:
//    cout << "Вартість розмови з Vodafone: " << cost * 1.2 << " грн" << endl;
//    break;
//case 3:
//    cout << "Вартість розмови з Lifecell: " << cost * 1.15 << " грн" << endl;
//    break;
//default:
//    cout << "Невірний вибір. Будь ласка, введіть число від 1 до 3." << endl;
//    break;
//}
//
//return 0;
//}


//// Завдання 3. Вася працює програмістом і отримує 50$ за кожні 100 рядків коду. За кожне третє запізнення Васю штрафують на 20$. 
//// Реалізувати меню:
////1.користувач вводить бажаний дохід Васі та кількість запізнень.Порахувати скільки рядків коду йому треба написати;
////2.користувач вводить кількість рядків коду, написаних Васею, і бажаний обсяг зарплати.Порахувати скільки разів Вася може запізнитися;
////3.користувач вводить кількість рядків коду і кількість запізнень.Визначити скільки грошей заплатять Васі та чи заплатять взагалі.
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
//    int dohid, delays, code;
//
//    cout << "Меню:" << endl;
//    cout << "1. Порахувати кількість рядків коду" << endl;
//    cout << "2. Порахувати кількість можливих запізнень" << endl;
//    cout << "3. Порахувати кількість грошей і перевірити, чи відбудеться оплата" << endl;
//
//    int choice;
//    cout << "Виберіть опцію: ";
//    cin >> choice;
//
//    switch (choice) {
//    case 1:
//        cout << "Введіть бажаний дохід Васі: ";
//        cin >> dohid;
//        cout << "Та кількість його запізнень: ";
//        cin >> delays;
//        code = (dohid / 50) * 100;
//        cout << "Вам потрібно написати " << code << " рядків коду." << endl;
//        break;
//    case 2:
//        cout << "Введіть кількість рядків коду, написаних Васею: ";
//        cin >> code;
//        cout << "Та бажаний обсяг зарплати: ";
//        cin >> dohid;
//        delays = ((dohid / 50) * 100 - code) / 3;
//        cout << "Ви можете запізнитися " << delays << " раз(ів)." << endl;
//        break;
//    case 3:
//        int allDohid;
//        cout << "Введіть кількість рядків коду: ";
//        cin >> code;
//        cout << "Та кількість запізнень: ";
//        cin >> delays;
//        allDohid = (code / 100) * 50 - (delays / 3) * 20;
//        if (allDohid < 0) {
//            cout << "Вас оштрафують, та не заплатять." << endl;
//        }
//        else {
//            cout << "Вам заплатять " << allDohid << "$." << endl;
//        }
//        break;
//    default:
//        cout << "Невірний вибір опції." << endl;
//        break;
//    }
//
//    return 0;
//}