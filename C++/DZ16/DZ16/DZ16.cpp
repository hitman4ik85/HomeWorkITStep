#include <iostream>
#include <windows.h>
using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));


	////1
 //   const int SIZE = 50;
 //   int array[SIZE];
 //   int x;

 //   for (int i = 0; i < SIZE; i++) {
 //       array[i] = rand() % 40 + 10;
 //   }

 //   cout << "Масив:" << endl;
 //   for (int i = 0; i < SIZE; i++) {
 //       cout << array[i] << ' ';
 //       if ((i + 1) % 10 == 0) {
 //           cout << endl;
 //       }
 //   }
 //   cout << endl;

 //   cout << "Введіть число (від 10 до 49): ";
 //   cin >> x;

 //   int pershuiIndex = -1;
 //   int ostanniIndex = -1;
 //   int count = 0;
 //   for (int i = 0; i < SIZE; i++) {
 //       if (array[i] == x) {
 //           if (pershuiIndex == -1) {
 //               pershuiIndex = i;
 //           }
 //           ostanniIndex = i;
 //           count++;
 //       }
 //   }

 //   if (pershuiIndex != -1) {
 //       cout << "Індекс першої появи числа " << x << ": " << pershuiIndex << endl;
 //       cout << "Індекс останньої появи числа " << x << ": " << ostanniIndex << endl;
 //       cout << "Кількість появ числа " << x << " в масиві: " << count << endl;
 //   }
 //   else {
 //       cout << "Число " << x << " не знайдено в масиві." << endl;
 //   }




	////2
 //   const int SIZE = 20;
 //   const int SIZEZ2 = SIZE / 2;
 //   int array1[SIZE], array2[SIZEZ2], array3[SIZEZ2];

 //   cout << "Основний масив:" << endl;
 //   for (int i = 0; i < SIZE; i++) {
 //       array1[i] = rand() % 90 + 10;
 //       cout << array1[i] << ' ';
 //   }
 //   cout << endl;

 //   cout << "Перший масив:" << endl;
 //   for (int i = 0; i < SIZEZ2; i++) {
 //       array2[i] = array1[i];
 //       cout << array2[i] << ' ';
 //   }
 //   cout << endl;

 //   cout << "Другий масив:" << endl;
 //   for (int i = SIZEZ2; i < SIZE; i++) {
 //       array3[i - SIZEZ2] = array1[i];
 //       cout << array3[i - SIZEZ2] << ' ';
 //   }
 //   cout << endl;

 //   int maksumym = array2[0];
 //   for (int i = 1; i < SIZEZ2; i++) {
 //       if (array2[i] > maksumym) {
 //           maksumym = array2[i];
 //       }
 //   }

 //   int minimym = array3[0];
 //   for (int i = 1; i < SIZEZ2; i++) {
 //       if (array3[i] < minimym) {
 //           minimym = array3[i];
 //       }
 //   }

 //   cout << "Максимальний елемент першого масиву: " << maksumym << endl;
 //   cout << "Мінімальний елемент другого масиву: " << minimym << endl;




    ////3
    //const int SIZE = 50;
    //char array[SIZE];
    //char litera;
    //int temp[SIZE];
    //int kilkLiter = 0;

    //for (int i = 0; i < SIZE; i++) {
    //    array[i] = rand() % 26 + 'A';
    //    if (rand() % 2 == 1) {
    //        array[i] += ('a' - 'A');
    //    }
    //}

    //cout << "Масив:" << endl;
    //for (int i = 0; i < SIZE; i++) {
    //    cout << array[i] << ' ';
    //    if ((i + 1) % 10 == 0) {
    //        cout << endl;
    //    }
    //}
    //cout << endl;

    //cout << "Введіть літеру для пошуку у списку: ";
    //cin >> litera;

    //for (int i = 0; i < SIZE; i++) {
    //    if (array[i] == litera || (array[i] - ('a' - 'A')) == litera) {
    //        temp[kilkLiter++] = i;
    //    }
    //}

    //if (kilkLiter > 0) {
    //    cout << "Літера '" << litera << "' знаходиться на наступних позиціях: ";
    //    for (int i = 0; i < kilkLiter; i++) {
    //        cout << temp[i];
    //        if (i < kilkLiter - 1) {
    //            cout << ", ";
    //        }
    //    }
    //    cout << endl;
    //}
    //else {
    //    cout << "Літера '" << litera << "' не знайдена в масиві." << endl;
    //}



	cout << endl;
	system("pause");
	return 0;
}