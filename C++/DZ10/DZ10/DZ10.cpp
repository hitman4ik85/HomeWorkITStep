#include <iostream>
#include <windows.h>
using namespace std;

const int rows = 10;
const int cols = 10;

void initMasuv(int salary[rows][cols], int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            salary[i][j] = rand() % 100;
        }
    }
}

void printMasuv(int salary[rows][cols], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << "[" << salary[i][j] << "]";
        }
        cout << endl;
    }
    cout << endl;
}

void sortRows(int salary[rows][cols], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - 1; j++) {
            for (int k = 0; k < size - j - 1; k++) {
                if (salary[i][k] > salary[i][k + 1]) {
                    int temp = salary[i][k];
                    salary[i][k] = salary[i][k + 1];
                    salary[i][k + 1] = temp;
                }
            }
        }
    }
    cout << endl;
}

struct MinMaxDiagonal {
    int max;
    int min;
};

MinMaxDiagonal findMinMaxDiagonal(int salary[rows][cols], int size) {
    MinMaxDiagonal result;
    result.max = salary[0][0];
    result.min = salary[0][0];
    for (int i = 0; i < size; i++) {
        if (salary[i][i] > result.max) {
            result.max = salary[i][i];
        }
        if (salary[i][i] < result.min) {
            result.min = salary[i][i];
        }
    }
    return result;
}

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

    int salary[rows][cols];
    int size;

    cout << "Введіть розмір квадратного масиву: ";
    cin >> size;
    cout << endl;

    initMasuv(salary, size);

    cout << "Масив:" << endl;
    printMasuv(salary, size);

    MinMaxDiagonal minMaxDiagonal = findMinMaxDiagonal(salary, size);

    cout << "Максимальний елемент по діагоналі: " << minMaxDiagonal.max << endl;
    cout << "Мінімальний елемент по діагоналі: " << minMaxDiagonal.min << endl;

    sortRows(salary, size);

    cout << "Відсортований масив:" << endl;
    printMasuv(salary, size);

    return 0;
}