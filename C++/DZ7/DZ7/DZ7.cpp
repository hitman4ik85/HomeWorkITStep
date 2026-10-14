////Завдання 1.
//#include <iostream>
//#include <windows.h>
//using std::cout;
//using std::endl;
//using std::cin;
//
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int num;
//    cout << "Введіть початкове число: ";
//    cin >> num;
//    
//    const int rows = 3;
//    const int cols = 3;
//    int salary[rows][cols];
//    
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            if (j == 0) {
//                salary[i][j] = num * (1 << i);
//            }
//            else {
//                salary[i][j] = salary[i][j - 1] * 2;
//            }
//        }
//    }    
//    cout << "Отриманий масив:" << endl;
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << "[" << salary[i][j] << "] ";
//        }
//        cout << endl;
//    }
//    return 0;
//}



////Завдання 2.
//#include <iostream>
//#include <windows.h>
//using std::cout;
//using std::endl;
//using std::cin;
//
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int num;
//    cout << "Введіть початкове число: ";
//    cin >> num;
//
//    const int rows = 3;
//    const int cols = 3;
//    int salary[rows][cols];
//
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            if (j == 0) {
//                salary[i][j] = num + i;
//            }
//            else {
//                salary[i][j] = salary[i][j - 1] + 1;
//            }
//        }
//    }
//    cout << "Отриманий масив:" << endl;
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << "[" << salary[i][j] << "] ";
//        }
//        cout << endl;
//    }
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
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    const int rows = 2;
//    const int cols = 6;
//    int salary[rows][cols];
//
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            salary[i][j] = rand() % 10;
//        }
//    }
//
//    cout << "Початковий масив:" << endl;
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << "[" << salary[i][j] << "] ";
//        }
//        cout << endl;
//    }
//
//    int zsyvu;
//    int pozucia;
//    cout << "Введіть кількість зсувів: ";
//    cin >> zsyvu;
//    cout << "Введіть напрямок (1 - вправо, 2 - вліво, 3 - вгору, 4 - вниз) : ";
//    cin >> pozucia;
//
//    switch (pozucia) {
//    case 1: {
//        int vremennui[rows][cols];
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                vremennui[i][(j + zsyvu) % cols] = salary[i][j];
//            }
//        }
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                salary[i][j] = vremennui[i][j];
//            }
//        }
//        break;
//    }
//    case 2: {
//        int vremennui[rows][cols];
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                vremennui[i][(j + cols - zsyvu) % cols] = salary[i][j];
//            }
//        }
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                salary[i][j] = vremennui[i][j];
//            }
//        }
//        break;
//    }
//    case 3: {
//        int vremennui[rows][cols];
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                vremennui[(i + zsyvu) % rows][j] = salary[i][j];
//            }
//        }
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                salary[i][j] = vremennui[i][j];
//            }
//        }
//        break;
//    }
//    case 4: {
//        int vremennui[rows][cols];
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                vremennui[(i + rows - zsyvu) % rows][j] = salary[i][j];
//            }
//        }
//        for (int i = 0; i < rows; i++) {
//            for (int j = 0; j < cols; j++) {
//                salary[i][j] = vremennui[i][j];
//            }
//        }
//        break;
//    }
//    default:
//        cout << "Невірний напрям зсуву!" << endl;
//        return 1;
//    }
//
//    cout << "Масив після зсуву:" << endl;
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << "[" << salary[i][j] << "] ";
//        }
//        cout << endl;
//    }
//
//    return 0;
//}
