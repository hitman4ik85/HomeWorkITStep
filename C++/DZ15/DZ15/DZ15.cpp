//#include <iostream>
//#include <conio.h>
//#include <windows.h>
//using namespace std;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    ////1
//    //const int SIZE = 50;
//    //int array[SIZE];
//    //int negatuv[SIZE];
//    //int pozutuv[SIZE];
//    //int negKilk = 0;
//    //int pozKilk = 0;
//
//    //for (int i = 0; i < SIZE; i++) {
//    //    array[i] = rand() % 201 - 100;
//    //}
//
//    //for (int i = 0; i < SIZE; i++) {
//    //    if (array[i] < 0) {
//    //        negatuv[negKilk++] = array[i];
//    //    }
//    //    else {
//    //        pozutuv[pozKilk++] = array[i];
//    //    }
//    //}
//
//    //for (int i = 1; i < negKilk; i++) {
//    //    int key = negatuv[i];
//    //    int j = i - 1;
//    //    while (j >= 0 && negatuv[j] < key) {
//    //        negatuv[j + 1] = negatuv[j];
//    //        j = j - 1;
//    //    }
//    //    negatuv[j + 1] = key;
//    //}
//
//    //for (int i = 0; i < pozKilk - 1; i++) {
//    //    for (int j = 0; j < pozKilk - i - 1; j++) {
//    //        if (pozutuv[j] > pozutuv[j + 1]) {
//    //            int temp = pozutuv[j];
//    //            pozutuv[j] = pozutuv[j + 1];
//    //            pozutuv[j + 1] = temp;
//    //        }
//    //    }
//    //}
//
//    //cout << "Початковий масив: " << endl;
//    //for (int i = 0; i < SIZE; i++) {
//    //    cout << array[i] << ' ';
//    //    if ((i + 1) % 10 == 0) {
//    //        cout << endl;
//    //    }
//    //}
//    //if (SIZE % 10 != 0) {
//    //    cout << endl;
//    //}
//
//    //cout << "Масив з від'ємними числами (за спаданням): " << endl;
//    //for (int i = 0; i < negKilk; i++) {
//    //    cout << negatuv[i] << ' ';
//    //    if ((i + 1) % 10 == 0) {
//    //        cout << endl;
//    //    }
//    //}
//    //if (negKilk % 10 != 0) {
//    //    cout << endl;
//    //}
//
//    //cout << "Масив з додатними числами (за зростанням): " << endl;
//    //for (int i = 0; i < pozKilk; i++) {
//    //    cout << pozutuv[i] << ' ';
//    //    if ((i + 1) % 10 == 0) {
//    //        cout << endl;
//    //    }
//    //}
//    //if (pozKilk % 10 != 0) {
//    //    cout << endl;
//    //}
//
//
//
//
//
//    ////2
//    //const int ROWS = 7;
//    //const int COLS = 7;
//    //int matrix[ROWS][COLS];
//
//    //for (int i = 0; i < ROWS; i++) {
//    //    for (int j = 0; j < COLS; j++) {
//    //        matrix[i][j] = rand() % 90 + 10;
//    //    }
//    //}
//
//    //cout << "Початкова матриця: " << endl;
//    //for (int i = 0; i < ROWS; i++) {
//    //    for (int j = 0; j < COLS; j++) {
//    //        cout << matrix[i][j] << ' ';
//    //    }
//    //    cout << endl;
//    //}
//
//    //for (int i = 0; i < ROWS; i++) {
//    //    for (int j = 1; j < COLS; j++) {
//    //        int key = matrix[i][j];
//    //        int k = j - 1;
//    //        while (k >= 0 && matrix[i][k] < key) {
//    //            matrix[i][k + 1] = matrix[i][k];
//    //            k = k - 1;
//    //        }
//    //        matrix[i][k + 1] = key;
//    //    }
//    //}
//
//    //cout << "\nВідсортована матриця: " << endl;
//    //for (int i = 0; i < ROWS; i++) {
//    //    for (int j = 0; j < COLS; j++) {
//    //        cout << matrix[i][j] << ' ';
//    //    }
//    //    cout << endl;
//    //}
//
//
//
//
//    ////3
//    //const int ROWS = 4; //при 7, майже неможливо це зробити
//    //const int COLS = 4;
//    //int matrix[ROWS][COLS];
//
//    //cout << "Вхідна матриця:" << endl;
//    //for (int i = 0; i < ROWS; i++) {
//    //    for (int j = 0; j < COLS; j++) {
//    //        matrix[i][j] = rand() % 90 + 10;
//    //        cout << matrix[i][j] << ' ';
//    //    }
//    //    cout << endl;
//    //}
//    //cout << endl;
//
//    //for (int i = 0; i < ROWS; i++) {
//    //    int minIn = i;
//    //    for (int j = i + 1; j < COLS; j++) {
//    //        if (matrix[j][j] < matrix[minIn][minIn]) {
//    //            minIn = j;
//    //        }
//    //    }
//    //    if (minIn != i) {
//    //        for (int k = 0; k < ROWS; k++) {
//    //            int temp = matrix[k][i];
//    //            matrix[k][i] = matrix[k][minIn];
//    //            matrix[k][minIn] = temp;
//    //        }
//    //    }
//    //}
//
//    //bool neSort = true;
//    //for (int i = 1; i < ROWS; i++) {
//    //    if (matrix[i][i] < matrix[i - 1][i - 1]) {
//    //        neSort = false;
//    //        break;
//    //    }
//    //}
//
//    //if (!neSort) {
//    //    cout << "Сортування неможливе!" << endl;
//    //}
//    //else {
//    //    cout << "Відсортована матриця:" << endl;
//    //    for (int i = 0; i < ROWS; i++) {
//    //        for (int j = 0; j < COLS; j++) {
//    //            cout << matrix[i][j] << ' ';
//    //        }
//    //        cout << endl;
//    //    }
//    //}
//
//
//    system("pause");
//    return 0;
//}


#include <iostream>
#include <cstdlib> // Для використання функції rand()
#include <ctime>   // Для генерації наступних випадкових чисел

using namespace std;

const int ROWS = 7;
const int COLS = 7;

int main() {
    int matrix[ROWS][COLS] = {
        {45, 23, 12, 43, 36, 34, 13},
        {23, 12, 42, 23, 47, 93, 52},
        {65, 34, 63, 32, 59, 13, 84},
        {38, 65, 47, 16, 71, 42, 79},
        {71, 23, 26, 63, 32, 66, 36},
        {96, 78, 13, 63, 35, 78, 83},
        {99, 81, 70, 55, 12, 32, 45}
    };

    // Вивід вхідної матриці
    cout << "Вхідна матриця:" << endl;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    cout << endl;

    // Переставляємо стовпці, щоб елементи на головній діагоналі були відсортовані
    for (int i = 0; i < ROWS; i++) {
        int min_index = i;
        for (int j = i + 1; j < COLS; j++) {
            if (matrix[j][j] < matrix[min_index][min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            for (int k = 0; k < ROWS; k++) {
                int temp = matrix[k][i];
                matrix[k][i] = matrix[k][min_index];
                matrix[k][min_index] = temp;
            }
        }
    }

    // Перевірка чи можливе сортування по головній діагоналі
    bool canSort = true;
    for (int i = 1; i < ROWS; i++) {
        if (matrix[i][i] < matrix[i - 1][i - 1]) {
            canSort = false;
            break;
        }
    }

    // Виведення відсортованої матриці
    if (!canSort) {
        cout << "Сортування неможливе!" << endl;
    }
    else {
        cout << "Відсортована матриця:" << endl;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                cout << matrix[i][j] << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
