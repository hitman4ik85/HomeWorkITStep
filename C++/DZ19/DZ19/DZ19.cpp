////1
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//void ZrostanniaChusel(int A, int B) {
//    if (A > B) return;
//    cout << A << ' ';
//    ZrostanniaChusel(A + 1, B);
//}
//
//void SpadanniaChusel(int A, int B) {
//    if (A < B) return;
//    cout << A << ' ';
//    SpadanniaChusel(A - 1, B);
//}
//
//void DiapazonChusel(int A, int B) {
//    if (A <= B)
//        ZrostanniaChusel(A, B);
//    else
//        SpadanniaChusel(A, B);
//    cout << endl;
//}
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//    int A, B;
//    cout << "Введіть два числа через пробіл: ";
//    cin >> A >> B;
//    cout << "Числа від " << A << " до " << B << ": ";
//    DiapazonChusel(A, B);
//
//	system("pause");
//	return 0;
//}




////2
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//void ZapovnutuMasuv(int array[], int size, int index = 0) {
//    if (index == size) return;
//    array[index] = 10 + rand() % 90;
//    ZapovnutuMasuv(array, size, index + 1);
//}
//
//int ZnaituMinimym(int array[], int size, int index = 0) {
//    if (index == size - 1) return array[index];
//    int minRez = ZnaituMinimym(array, size, index + 1);
//    return (array[index] < minRez) ? array[index] : minRez;
//}
//
//void DrykMasuvy(int array[], int size, int index = 0) {
//    if (index == size) {
//        cout << endl;
//        return;
//    }
//    cout << array[index] << ' ';
//    DrykMasuvy(array, size, index + 1);
//}
//
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    srand(time(NULL));
//    
//    int array[20];
//
//    ZapovnutuMasuv(array, 20);
//
//    cout << "Масив: ";
//    DrykMasuvy(array, 20);
//
//    int minElement = ZnaituMinimym(array, 20);
//    cout << "Мінімальний елемент: " << minElement << endl;
//
//    system("pause");
//    return 0;
//}




////3
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//void Poslidovnist(int num, int kilkist, int n) {
//    if (n == 0)
//        return;
//
//    if (kilkist == 0) {
//        Poslidovnist(num + 1, num + 1, n);
//    }
//    else {
//        cout << num << " ";
//        Poslidovnist(num, kilkist - 1, n - 1);
//    }
//}
//
//int main()
//{
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    int n;
//    cout << "Ведіть число в діапазоні від 10 до 50: ";
//    cin >> n;
//
//    if (n < 10 || n > 50) {
//        cout << "Невірний ввід! Потрібно в діапазоні від 10 до 50." << endl;
//        return 1;
//    }
//
//    Poslidovnist(1, 1, n);
//    cout << endl;
//
//    system("pause");
//    return 0;
//}