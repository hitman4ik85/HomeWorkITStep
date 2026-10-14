////1
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//void ZapovnutuMasuv(int* array, int size, int nuzMezha, int verhMezha) {
//    for (int i = 0; i < size; i++) {
//        *(array + i) = rand() % (verhMezha - nuzMezha + 1) + nuzMezha;
//    }
//}
//
//void DrykMasuvy(const int* array, int size) {
//    for (int i = 0; i < size; i++) {
//        cout << *(array + i) << ' ';
//        if ((i + 1) % 10 == 0) {
//            cout << endl;
//        }
//    }
//    cout << endl;
//}
//
//bool  ChuMaeElement(const int* array, int size, int element) {
//    for (int i = 0; i < size; i++) {
//        if (*(array + i) == element) {
//            return true;
//        }
//    }
//    return false;
//}
//
//int StvorutuUniqMasuv(const int* array1, const int* array2, int size, int* uniqArray) {
//    int uniqIndex = 0;
//
//    for (int i = 0; i < size; i++) {
//        if (!ChuMaeElement(array2, size, *(array1 + i))) {
//            if (!ChuMaeElement(uniqArray, uniqIndex, *(array1 + i))) {
//                *(uniqArray + uniqIndex++) = *(array1 + i);
//            }
//        }
//        if (!ChuMaeElement(array1, size, *(array2 + i))) {
//            if (!ChuMaeElement(uniqArray, uniqIndex, *(array2 + i))) {
//                *(uniqArray + uniqIndex++) = *(array2 + i);
//            }
//        }
//    }
//
//    return uniqIndex;
//}
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    const int SIZE = 30;
//    int array1[SIZE];
//    int array2[SIZE];
//    int uniqArray[2 * SIZE];
//
//    ZapovnutuMasuv(array1, SIZE, 10, 99);
//    ZapovnutuMasuv(array2, SIZE, 10, 99);
//
//    cout << "Початковий масив array1:\n";
//    DrykMasuvy(array1, SIZE);
//    cout << "Початковий масив array2:\n";
//    DrykMasuvy(array2, SIZE);
//
//    int uniqSize = StvorutuUniqMasuv(array1, array2, SIZE, uniqArray);
//
//    cout << "Масив унікальних елементів:\n";
//    DrykMasuvy(uniqArray, uniqSize);
//
//	system("pause");
//	return 0;
//}





////2
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//void ZapovnutuMasuv(int* array, int size, int nuzMezha, int verhMezha) {
//    for (int i = 0; i < size; i++) {
//        *(array + i) = rand() % (verhMezha - nuzMezha + 1) + nuzMezha;
//    }
//}
//
//void DrykMasuvy(const int* array, int size) {
//    for (int i = 0; i < size; i++) {
//        cout << *(array + i) << ' ';
//        if ((i + 1) % 10 == 0) {
//            cout << endl;
//        }
//    }
//    cout << endl;
//}
//
//int PoshykPershogoChusla(const int* array, int size, int K) {
//    for (int i = 0; i < size; i++) {
//        if (*(array + i) > K) {
//            return i;
//        }
//    }
//    return -1;
//}
//
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    const int SIZE = 50;
//    int array[SIZE];
//    int K;
//
//    ZapovnutuMasuv(array, SIZE, 10, 99);
//
//    cout << "Початковий масив:\n";
//    DrykMasuvy(array, SIZE);
//
//    cout << "Введіть значення K: ";
//    cin >> K;
//
//    int index = PoshykPershogoChusla(array, SIZE, K);
//
//    if (index != -1) {
//        cout << "Індекс першого числа більшого за " << K << ": " << index << endl;
//    }
//    else {
//        cout << "Чисел більших за " << K << " в масиві немає." << endl;
//    }
//
//    system("pause");
//    return 0;
//}