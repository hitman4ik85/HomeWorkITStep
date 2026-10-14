////1
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <windows.h>
//using namespace std;
//
//int* Masuv(int size) {
//    int* array = new int[size];
//    for (int i = 0; i < size; i++) {
//        array[i] = rand() % 90 + 10;
//    }
//    return array;
//}
//
//void DrykMasuvy(int* array, int size) {
//    for (int i = 0; i < size; i++) {
//        cout << array[i] << ' ';
//        if ((i + 1) % 10 == 0) {
//            cout << endl;
//        }
//    }
//    cout << endl;
//}
//
//void KopievatuMasuv(int* pershui, int rozmirPershogo, int*& drygui, int& rozmirDrygogo) {
//    if (rozmirDrygogo < rozmirPershogo) {
//        cout << "Масив А містить більшу кількість елементів ніж масив В" << endl;
//        return;
//    }
//
//    for (int i = 0; i < rozmirPershogo; i++) {
//        drygui[i] = pershui[i];
//    }
//
//    int* newArray = new int[rozmirPershogo];
//    for (int i = 0; i < rozmirPershogo; i++) {
//        newArray[i] = drygui[i];
//    }
//    delete[] drygui;
//    drygui = newArray;
//    rozmirDrygogo = rozmirPershogo;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    int sizeA, sizeB;
//    cout << "Введіть розмір масиву А: ";
//    cin >> sizeA;
//
//    int* arrayA = Masuv(sizeA);
//    sizeB = rand() % 100;
//
//    int* arrayB = Masuv(sizeB);
//
//    cout << "Масив А:" << endl;
//    DrykMasuvy(arrayA, sizeA);
//
//    cout << "Масив B:" << endl;
//    DrykMasuvy(arrayB, sizeB);
//
//    KopievatuMasuv(arrayA, sizeA, arrayB, sizeB);
//
//    if (sizeB >= sizeA) {
//        cout << "Масив B після копіювання з масиву А:" << endl;
//        DrykMasuvy(arrayB, sizeB);
//    }
//
//    delete[] arrayA;
//    delete[] arrayB;
//
//    system("pause");
//    return 0;
//}





////2
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <windows.h>
//using namespace std;
//
//void ElementPlys(int*& array, int& size, int element) {
//    int* newArray = new int[size + 1];
//    for (int i = 0; i < size; i++) {
//        newArray[i] = array[i];
//    }
//    newArray[size] = element;
//
//    delete[] array;
//
//    array = newArray;
//    size++;
//}
//
//void DrykMasuvy(int* array, int size) {
//    for (int i = 0; i < size; i++) {
//        cout << array[i] << ' ';
//    }
//    cout << endl;
//}
//
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    int sizeM = 1;
//    int* array = new int[sizeM];
//    int size = 0;
//
//    cout << "Вводьте цілі числа. Для зупинки вводу ведіть від’ємне число:" << endl;
//    while (true) {
//        int element;
//        cin >> element;
//        if (element < 0) {
//            break;
//        }
//        ElementPlys(array, size, element);
//    }
//
//    cout << "Отриманий масив:" << endl;
//    DrykMasuvy(array, size);
//
//    delete[] array;
//
//    system("pause");
//    return 0;
//}





////3
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <windows.h>
//using namespace std;
//
//void SortBylbashka(int* array, int size) {
//    for (int i = 0; i < size - 1; i++) {
//        for (int j = 0; j < size - i - 1; j++) {
//            if (array[j] > array[j + 1]) {
//                int temp = array[j];
//                array[j] = array[j + 1];
//                array[j + 1] = temp;
//            }
//        }
//    }
//}
//
//void DrykMasuvy(int* array, int size) {
//    for (int i = 0; i < size; i++) {
//        cout << array[i] << ' ';
//        if ((i + 1) % 10 == 0) {
//            cout << endl;
//        }
//    }
//    cout << endl;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    int size;
//    cout << "Введіть розмір масиву (не менше 30): ";
//    cin >> size;
//
//    if (size < 30) {
//        cout << "Розмір масиву повинен бути не менше 30!" << endl;
//        return 1;
//    }
//
//    int* array = new int[size];
//    for (int i = 0; i < size; i++) {
//        array[i] = rand() % 90 + 10;
//    }
//
//    cout << "Масив до сортування:" << endl;
//    DrykMasuvy(array, size);
//
//    SortBylbashka(array, size);
//
//    cout << "Масив після сортування:" << endl;
//    DrykMasuvy(array, size);
//
//    delete[] array;
//
//    system("pause");
//    return 0;
//}