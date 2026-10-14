////1
//#include <iostream>
//#include <conio.h>
//#include <ctime>
//#include <cstdlib>
//#include <iomanip>
//#include <windows.h>
//using namespace std;
//
//void PerestanovkaZnachen(int& A, int& B, int& C) {
//    int minimal = min(A, min(B, C));
//    int maksumal = max(A, max(B, C));
//    int seredne = A + B + C - minimal - maksumal;
//
//    A = minimal;
//    B = seredne;
//    C = maksumal;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int A, B, C;
//
//    cout << "Введіть значення A: ";
//    cin >> A;
//    cout << "Введіть значення B: ";
//    cin >> B;
//    cout << "Введіть значення C: ";
//    cin >> C;
//
//    PerestanovkaZnachen(A, B, C);
//
//    cout << "Після перестановки: " << endl;
//    cout << "A (мінімальне): " << A << endl;
//    cout << "B (середнє): " << B << endl;
//    cout << "C (максимальне): " << C << endl;
//
//    system("pause");
//    return 0;
//}





////2
//#include <iostream>
//#include <conio.h>
//#include <ctime>
//#include <cstdlib>
//#include <iomanip>
//#include <windows.h>
//using namespace std;
//
//const int SIZEZ = 50;
//int aarray[SIZEZ];
//int max_array;
//int min_array;
//
//void AnalizMasuvy() {
//    max_array = aarray[0];
//    min_array = aarray[0];
//
//    for (int i = 1; i < SIZEZ; i++) {
//        if (aarray[i] > max_array) {
//            max_array = aarray[i];
//        }
//        if (aarray[i] < min_array) {
//            min_array = aarray[i];
//        }
//    }
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    for (int i = 0; i < SIZEZ; i++) {
//        aarray[i] = rand() % 90 + 10;
//    }
//
//    AnalizMasuvy();
//
//    cout << "Масив: " << endl;
//    for (int i = 0; i < SIZEZ; i++) {
//        cout << aarray[i] << ' ';
//        if ((i + 1) % 10 == 0) {
//            cout << endl;
//        }
//    }
//
//    cout << "Максимальне значення: " << max_array << endl;
//    cout << "Мінімальне значення: " << min_array << endl;
//
//    system("pause");
//    return 0;
//}




////3
//#include <iostream>
//#include <conio.h>
//#include <ctime>
//#include <cstdlib>
//#include <iomanip>
//#include <windows.h>
//using namespace std;
//
//const int M_SIZE = 7;
//
//void analyzeMatrix(int M[M_SIZE][M_SIZE], int T) {
//    int bilsheZaT = 0;
//    int mensheZaT = 0;
//    int rivnoT = 0;
//
//    for (int i = 0; i < M_SIZE; ++i) {
//        int rowSumm = 0;
//        for (int j = 0; j < M_SIZE; ++j) {
//            rowSumm += M[i][j];
//        }
//
//        if (rowSumm > T) {
//            bilsheZaT++;
//        }
//        else if (rowSumm < T) {
//            mensheZaT++;
//        }
//        else {
//            rivnoT++;
//        }
//    }
//
//    cout << "Кількість рядків, сума елементів яких більше за значення T: " << bilsheZaT << endl;
//    cout << "Кількість рядків, сума елементів яких менша за значення T: " << mensheZaT << endl;
//    cout << "Кількість рядків, сума елементів яких дорівнює значенню T: " << rivnoT << endl;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    int M[M_SIZE][M_SIZE];
//    int T;
//
//    for (int i = 0; i < M_SIZE; i++) {
//        for (int j = 0; j < M_SIZE; j++) {
//            M[i][j] = rand() % 201 - 100;
//        }
//    }
//
//    cout << "Матриця: " << endl;
//    for (int i = 0; i < M_SIZE; i++) {
//        for (int j = 0; j < M_SIZE; j++) {
//            cout << M[i][j] << ' ';
//        }
//        cout << endl;
//    }
//
//    cout << "Введіть значення T: ";
//    cin >> T;
//
//    analyzeMatrix(M, T);
//
//    system("pause");
//    return 0;
//}