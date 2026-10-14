#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));


    ////1
    //const int ROWS = 5;
    //const int COLS = 5;
    //int matrix[ROWS][COLS];
    //int minValue = 99, maxValue = 10;
    //int minRow = 0, minCol = 0;
    //int maxRow = 0, maxCol = 0;

    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = 0; j < COLS; j++) {
    //        matrix[i][j] = 10 + rand() % 90;
    //        if (matrix[i][j] < minValue) {
    //            minValue = matrix[i][j];
    //            minRow = i;
    //            minCol = j;
    //        }
    //        if (matrix[i][j] > maxValue) {
    //            maxValue = matrix[i][j];
    //            maxRow = i;
    //            maxCol = j;
    //        }
    //    }
    //}

    //cout << "Масив:" << endl;
    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = 0; j < COLS; j++) {
    //        cout << matrix[i][j] << ' ';
    //    }
    //    cout << endl;
    //}

    //cout << "Мінімальне значення: " << minValue << " на позиції (" << minRow << ", " << minCol << ")" << endl;
    //cout << "Максимальне значення: " << maxValue << " на позиції (" << maxRow << ", " << maxCol << ")" << endl;




    ////2
    //const int ROWS = 7;
    //const int COLS = 7;
    //int matrix[ROWS][COLS];

    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = 0; j < COLS; j++) {
    //        matrix[i][j] = 10 + rand() % 90;
    //    }
    //}

    //cout << "Початкова матриця:" << endl;
    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = 0; j < COLS; j++) {
    //        cout << matrix[i][j] << ' ';
    //    }
    //    cout << endl;
    //}

    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = i + 1; j < COLS; j++) {
    //        int temp = matrix[i][j];
    //        matrix[i][j] = matrix[j][i];
    //        matrix[j][i] = temp;
    //    }
    //}

    //cout << "Перетворена матриця:" << endl;
    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = 0; j < COLS; j++) {
    //        cout << matrix[i][j] << ' ';
    //    }
    //    cout << endl;
    //}




    ////3
    //const int ROWS = 3;
    //const int COLS = 3;
    //char board[ROWS][COLS];
    //char winner = ' ';
    //bool isBoardFull = false;

    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = 0; j < COLS; j++) {
    //        board[i][j] = ' ';
    //    }
    //}

    //while (true) {
    //    for (int i = 0; i < ROWS; i++) {
    //        for (int j = 0; j < COLS; j++) {
    //            cout << board[i][j];
    //            if (j < COLS - 1) cout << " | ";
    //        }
    //        cout << endl;
    //        if (i < ROWS - 1) cout << "--+---+--" << endl;
    //    }

    //    int row, col;
    //    cout << "Введіть індекс квадрата через пробіл (1 1 - верхній лівий квадрат, 2 2 - центральний і т.д.): ";
    //    cin >> row >> col;
    //    row--;
    //    col--;
    //    if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == ' ') {
    //        board[row][col] = 'X';
    //    }
    //    else {
    //        cout << "Некоректний хід. Спробуйте ще раз." << endl;
    //        continue;
    //    }

    //    if ((board[row][0] == 'X' && board[row][1] == 'X' && board[row][2] == 'X') ||
    //        (board[0][col] == 'X' && board[1][col] == 'X' && board[2][col] == 'X') ||
    //        (row == col && board[0][0] == 'X' && board[1][1] == 'X' && board[2][2] == 'X') ||
    //        (row + col == 2 && board[0][2] == 'X' && board[1][1] == 'X' && board[2][0] == 'X')) {
    //        winner = 'X';
    //        break;
    //    }

    //    isBoardFull = true;
    //    for (int i = 0; i < ROWS; i++) {
    //        for (int j = 0; j < COLS; j++) {
    //            if (board[i][j] == ' ') {
    //                isBoardFull = false;
    //                break;
    //            }
    //        }
    //        if (!isBoardFull) break;
    //    }
    //    if (isBoardFull) break;

    //    do {
    //        row = rand() % ROWS;
    //        col = rand() % COLS;
    //    } while (board[row][col] != ' ');
    //    board[row][col] = 'O';

    //    if ((board[row][0] == 'O' && board[row][1] == 'O' && board[row][2] == 'O') ||
    //        (board[0][col] == 'O' && board[1][col] == 'O' && board[2][col] == 'O') ||
    //        (row == col && board[0][0] == 'O' && board[1][1] == 'O' && board[2][2] == 'O') ||
    //        (row + col == 2 && board[0][2] == 'O' && board[1][1] == 'O' && board[2][0] == 'O')) {
    //        winner = 'O';
    //        break;
    //    }

    //    isBoardFull = true;
    //    for (int i = 0; i < ROWS; i++) {
    //        for (int j = 0; j < COLS; j++) {
    //            if (board[i][j] == ' ') {
    //                isBoardFull = false;
    //                break;
    //            }
    //        }
    //        if (!isBoardFull) break;
    //    }
    //    if (isBoardFull) break;
    //}

    //cout << "Кінцева дошка:" << endl;
    //for (int i = 0; i < ROWS; i++) {
    //    for (int j = 0; j < COLS; j++) {
    //        cout << board[i][j];
    //        if (j < COLS - 1) cout << " | ";
    //    }
    //    cout << endl;
    //    if (i < ROWS - 1) cout << "--+---+--" << endl;
    //}
    //if (winner == 'X') {
    //    cout << "Ви перемогли!" << endl;
    //}
    //else if (winner == 'O') {
    //    cout << "Комп'ютер переміг!" << endl;
    //}
    //else {
    //    cout << "Нічия!" << endl;
    //}


    system("pause");
    return 0;
}