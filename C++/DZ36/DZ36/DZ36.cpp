////1 main
//#include <windows.h>
//#include <iostream>
//#include "DynamicArray.h"
//using namespace std;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    DynamicArray array1;
//    array1.addElement('b');
//    array1.addElement('a');
//    array1.addElement('d');
//    cout << "Початковий масив array1:" << endl;
//    array1.drykArray();
//
//    cout << "Сортування по зростанню array1:" << endl;
//    array1.sortArray(true);
//    array1.drykArray();
//
//    cout << "Сортування по спаданню array1:" << endl;
//    array1.sortArray(false);
//    array1.drykArray();
//
//    char initArray[] = { 'g', 'e', 'f' };
//    DynamicArray array2(initArray, 3);
//    cout << "Початковий масив array2:" << endl;
//    array2.drykArray();
//
//    cout << "Додавання масиву до array2:" << endl;
//    array2.addArray(initArray, 3);
//    array2.drykArray();
//
//    cout << "Додавання елементу 'c' до array2:" << endl;
//    array2.addElement('c');
//    array2.drykArray();
//
//    cout << "Сортування array2 по зростанню:" << endl;
//    array2.sortArray(true);
//    array2.drykArray();
//
//    cout << "Сортування array2 по спаданню:" << endl;
//    array2.sortArray(false);
//    array2.drykArray();
//
//    cout << "Перевірка стану array2:" << endl;
//    cout << "Заповнений: " << (array2.chuZapovnenoArray() ? "Так" : "Ні") << endl;
//    cout << "Відсортований: " << (array2.chuSortedArray() ? "Так" : "Ні") << endl;
//    cout << "По зростанню: " << (array2.chuSortedArrayPoZrosty() ? "Так" : "Ні") << endl;
//
//    return 0;
//}




////2 main
//#include <iostream>
//#include <windows.h>
//#include "Racer.h"
//#include "Runner.h"
//using namespace std;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    Racer racer("Максим", "Петров", 25, "Чоловік", "Україна", "Red Bull Racing", 10, 50);
//    cout << "Інформація про гонщика:" << endl;
//    racer.printInfo();
//    cout << "Ефективність гонщика: " << racer.getEfficiency() << "%" << endl;
//
//    Runner runner("Анна", "Іванова", 22, "Жінка", "Україна", 5.0, 20.5, "Nike");
//    cout << "\nІнформація про бігуна:" << endl;
//    runner.printInfo();
//    cout << "Середня швидкість бігуна: " << runner.getAverageSpeed() << " км/год" << endl;
//
//    return 0;
//}