////1
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//void VuklukFynkcii() {
//	static int kilkist = 0;
//    kilkist++;
//	cout << "Дана функція була викликана " << kilkist << " раз" << endl;
//}
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    int vukluku = rand() % 100 + 1;
//    for (int i = 0; i < vukluku; i++) {
//		VuklukFynkcii();
//    }
//
//	system("pause");
//	return 0;
//}





////2
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//template <typename T>
//bool SummEqual(T a, T b, T c) {
//    return (a + b == c) || (a + c == b) || (b + c == a);
//}
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//
//    cout << "int: " << (SummEqual(3, 5, 8) ? "true" : "false") << endl;
//    cout << "float: " << (SummEqual(2.5f, 2.6f, 5.0f) ? "true" : "false") << endl;
//    cout << "double: " << (SummEqual(4.0, 2.0, 6.0) ? "true" : "false") << endl;
//    cout << "char: " << (SummEqual('a', 'b', 'c') ? "true" : "false") << endl;
//    cout << "long: " << (SummEqual(10L, 20L, 30L) ? "true" : "false") << endl;
//
//	system("pause");
//	return 0;
//}





////3
//#include <iostream>
//#include <windows.h>
//using namespace std;
//
//template<typename T>
//int KilkistZminnoi(const T array[], int SIZE, T znach) {
//    int kilkist = 0;
//    for (int i = 0; i < SIZE; i++) {
//        if (array[i] == znach) {
//            kilkist++;
//        }
//    }
//    return kilkist;
//}
//
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//    srand(time(NULL));
//
//    const int SIZE = 10;
//    int intArray[SIZE];
//
//    for (int i = 0; i < SIZE; i++) {
//        intArray[i] = rand() % 10;
//    }
//
//    int poshykZnach = rand() % 10;
//
//    cout << "Масив: ";
//    for (int i = 0; i < SIZE; i++) {
//        cout << intArray[i] << ' ';
//    }
//    cout << endl;
//
//    int kilkistPoyav = KilkistZminnoi(intArray, SIZE, poshykZnach);
//
//    cout << "Кількість значення " << poshykZnach << " у масиві: " << kilkistPoyav << endl;
//
//	system("pause");
//	return 0;
//}