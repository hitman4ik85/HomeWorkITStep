////1
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <windows.h>
//using namespace std;
//
//int** Matrix2D(int rows, int cols) {
//    int** matrix = new int* [rows];
//    for (int i = 0; i < rows; i++) {
//        matrix[i] = new int[cols];
//    }
//    return matrix;
//}
//
//void ZapovnutuMatrix(int** matrix, int rows, int cols) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            if (rand() % 2 == 0) {
//                matrix[i][j] = rand() % 90 + 10;
//            }
//            else {
//                matrix[i][j] = rand() % 90 - 99;
//            }
//        }
//    }
//}
//
//void DrykMatrix(int** matrix, int rows, int cols) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << matrix[i][j] << ' ';
//        }
//        cout << endl;
//    }
//}
//
//int MaxMatrix(int** matrix, int rows, int cols) {
//    int maxVal = matrix[0][0];
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            if (matrix[i][j] > maxVal) {
//                maxVal = matrix[i][j];
//            }
//        }
//    }
//    return maxVal;
//}
//
//int MinMatrix(int** matrix, int rows, int cols) {
//    int minVal = matrix[0][0];
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            if (matrix[i][j] < minVal) {
//                minVal = matrix[i][j];
//            }
//        }
//    }
//    return minVal;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    int N, M;
//    cout << "Введіть рядки: ";
//    cin >> N;
//    cout << "Введіть стовпці: ";
//    cin >> M;
//
//    int** matrix = Matrix2D(N, M);
//    ZapovnutuMatrix(matrix, N, M);
//    cout << "Матриця:" << endl;
//    DrykMatrix(matrix, N, M);
//
//    int maxValue = MaxMatrix(matrix, N, M);
//    cout << "Максимальне значення в матриці: " << maxValue << endl;
//    int minValue = MinMatrix(matrix, N, M);
//    cout << "Мінімальне значення в матриці: " << minValue << endl;
//
//    for (int i = 0; i < N; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//
//    return 0;
//}




////2
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <windows.h>
//using namespace std;
//
//int** Matrix2D(int rows, int cols) {
//    int** matrix = new int* [rows];
//    for (int i = 0; i < rows; i++) {
//        matrix[i] = new int[cols];
//    }
//    return matrix;
//}
//
//void ZapovnutuMatrix(int** matrix, int rows, int cols) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            matrix[i][j] = rand() % 199 - 99;
//        }
//    }
//}
//
//void DrykMatrix(int** matrix, int rows, int cols) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << matrix[i][j] << ' ';
//        }
//        cout << endl;
//    }
//}
//
//int PoshykPozPislaNeg(int* row, int cols) {
//    bool pNeg = false;
//    int kilk = 0;
//
//    for (int j = 0; j < cols; j++) {
//        if (row[j] < 0) {
//            pNeg = true;
//        }
//        else if (pNeg && row[j] > 0) {
//            kilk++;
//        }
//        else if (pNeg && row[j] <= 0) {
//            break;
//        }
//    }
//
//    return kilk;
//}
//
//void DodatuRiadok(int**& matrix, int& rows, int cols, int poz) {
//    int** newMatrix = new int* [rows + 1];
//    for (int i = 0; i < poz; i++) {
//        newMatrix[i] = new int[cols];
//        for (int j = 0; j < cols; j++) {
//            newMatrix[i][j] = matrix[i][j];
//        }
//    }
//    newMatrix[poz] = new int[cols];
//    for (int j = 0; j < cols; ++j) {
//        newMatrix[poz][j] = rand() % 199 - 99;
//    }
//    for (int i = poz; i < rows; i++) {
//        newMatrix[i + 1] = new int[cols];
//        for (int j = 0; j < cols; j++) {
//            newMatrix[i + 1][j] = matrix[i][j];
//        }
//    }
//
//    for (int i = 0; i < rows; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//    matrix = newMatrix;
//    rows++;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    int N, M;
//    cout << "Введіть рядки: ";
//    cin >> N;
//    cout << "Введіть стовпці: ";
//    cin >> M;
//
//    int** matrix = Matrix2D(N, M);
//    ZapovnutuMatrix(matrix, N, M);
//    cout << "Матриця:" << endl;
//    DrykMatrix(matrix, N, M);
//
//    int poz;
//    cout << "Введіть позицію для вставки нового рядка (від 0 до " << N << "): ";
//    cin >> poz;
//
//    if (poz < 0 || poz > N) {
//        cout << "Некоректна позиція для вставки. Рядок не додано." << endl;
//    }
//    else {
//        DodatuRiadok(matrix, N, M, poz);
//        cout << "Матриця після додавання нового рядка:" << endl;
//        DrykMatrix(matrix, N, M);
//    }
//
//    for (int i = 0; i < N; i++) {
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//
//    return 0;
//}



////3
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <windows.h>
//using namespace std;
//
//int*** Matrix3D(int M, int N, int K) {
//    int*** matrix = new int** [M];
//    for (int i = 0; i < M; i++) {
//        matrix[i] = new int* [N];
//        for (int j = 0; j < N; j++) {
//            matrix[i][j] = new int[K];
//            for (int k = 0; k < K; k++) {
//                matrix[i][j][k] = rand() % 90 + 10;
//            }
//        }
//    }
//    return matrix;
//}
//
//void ZaminaElementa(int*** matrix, int M, int N, int K, int x, int y, int z) {
//    if (x >= 0 && x < M && y >= 0 && y < N && z >= 0 && z < K) {
//        cout << "Поточне значення елемента [" << x << "][" << y << "][" << z << "]: " << matrix[x][y][z] << endl;
//        int noveZnach;
//        cout << "Введіть нове значення для елемента: ";
//        cin >> noveZnach;
//        matrix[x][y][z] = noveZnach;
//        cout << "Значення елемента змінено успішно." << endl;
//    }
//    else {
//        cout << "Некоректні індекси!" << endl;
//    }
//}
//
//void DrykMatrix(int*** matrix, int M, int N, int K) {
//    for (int j = 0; j < N; j++) {
//        for (int i = 0; i < M; i++) {
//            for (int k = 0; k < K; k++) {
//                cout << matrix[i][j][k] << ' ';
//            }
//            cout << ' ';
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    int M, N, K;
//    cout << "Введіть розміри матриці (M N K): ";
//    cin >> M >> N >> K;
//
//    int*** matrix = Matrix3D(M, N, K);
//    cout << "Матриця:" << endl;
//    DrykMatrix(matrix, M, N, K);
//
//    int x, y, z;
//    cout << "Введіть індекси (x-рівень, y-рядок, z-стовпець) елемента, для заміни: ";
//    cin >> x >> y >> z;
//    ZaminaElementa(matrix, M, N, K, x, y, z);
//    cout << "Оновлена матриця:" << endl;
//    DrykMatrix(matrix, M, N, K);
//
//    for (int i = 0; i < M; i++) {
//        for (int j = 0; j < N; j++) {
//            delete[] matrix[i][j];
//        }
//        delete[] matrix[i];
//    }
//    delete[] matrix;
//
//    return 0;
//}