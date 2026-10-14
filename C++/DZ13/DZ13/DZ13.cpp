#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
    srand(time(NULL));

    ////1
    //int n;
    //cout << "Введіть кількість випадкових чисел: ";
    //cin >> n;

    //int summa = 0;

    //boolean znaideno = true;
    //for (int i = 1; i <= n; i++) {
    //    int num = rand() % 1001;
    //    cout << num << endl;
    //    if (num % 5 == 0) { summa += num; znaideno = false; }
    //}
    //if (znaideno == false) {
    //    cout << "Сумма чисел які діляться на 5 = " << summa;
    //}
    //else {
    //    cout << "error";
    //}
    //cout << endl;



    ////2
    //char a;
    //long long int num = 0;

    //cout << "Введіть дев'ятизначне число: ";

    //for (int i = 1; i <= 9; i++) {
    //    a = _getch();
    //    cout << a;
    //    num = num * 10 + (a - '0');
    //}

    //long long int vidobragenna = 0;
    //while (num != 0) {
    //    vidobragenna = vidobragenna * 10 + num % 10;
    //    num /= 10;
    //}
    //cout << endl;
    //cout << "Дзеркальне відображення: " << vidobragenna << endl;
 


    ////3
    //int n;
    //cout << "Введіть кількість ігор: ";
    //cin >> n;

    //int userWins = 0, computerWins = 0, draws = 0;
    //int rockCount = 0, paperCount = 0, scissorsCount = 0;

    //for (int i = 0; i < n; ++i) {
    //    char userInput;
    //    cout << "Гра " << (i + 1) << " - Виберіть (1)камінь, (2)папір, (3)ножиці: ";
    //    cin >> userInput;

    //    int userMove;
    //    if (userInput == '1') userMove = 0;
    //    else if (userInput == '2') userMove = 1;
    //    else if (userInput == '3') userMove = 2;
    //    else userMove = 0;

    //    if (userMove == 0) rockCount++;
    //    else if (userMove == 1) paperCount++;
    //    else if (userMove == 2) scissorsCount++;

    //    int computerMove = rand() % 3;

    //    cout << "Комп'ютер вибрав ";
    //    if (computerMove == 0) cout << "камінь";
    //    else if (computerMove == 1) cout << "папір";
    //    else cout << "ножиці";
    //    cout << "." << endl;

    //    if (userMove == computerMove) {
    //        cout << "Нічия!" << endl;
    //        draws++;
    //    } else if ((userMove == 0 && computerMove == 2) ||
    //               (userMove == 1 && computerMove == 0) ||
    //               (userMove == 2 && computerMove == 1)) {
    //        cout << "Ви виграли!" << endl;
    //        userWins++;
    //    } else {
    //        cout << "Ви програли!" << endl;
    //        computerWins++;
    //    }
    //}

    //cout << "\nРезультати гри:" << endl;
    //cout << "Виграшів користувача: " << userWins << endl;
    //cout << "Виграшів комп'ютера: " << computerWins << endl;
    //cout << "Нічиїх: " << draws << endl;

    //cout << "\nЧастота вибору користувача:" << endl;
    //cout << "Камінь: " << rockCount << endl;
    //cout << "Папір: " << paperCount << endl;
    //cout << "Ножиці: " << scissorsCount << endl;



    ////4
    //int n;
    //cout << "Введіть початкове число: ";
    //cin >> n;

    //if (n % 2 != 0) { n++; }

    //for (int i = 1; i <= 25; i++) {
    //    cout << i << ") " << n << endl;
    //    n += 2;
    //}



    ////5
 //   int const SIZE = 100;
 //   int masiv[SIZE];

 //   for (int i = 1; i <= SIZE; i++) {
 //       masiv[i - 1] = rand() % 201 - 100;
 //       cout << masiv[i - 1] << ' ';
 //       if ((i + 1) % 10 == 0) {
	//	cout << endl;
	//}
 //   }

 //   int x;
 //   do {
 //       cout << "Введіть число (від -100 до 100): ";
 //       cin >> x;
 //       if (x < -100 || x>100) {
 //           cout << "\t Число виходить за межі діапазону. Повторіть введдення\n";
 //       }
 //   } while (x < -100 || x>100);
 //   
 //   int kilkist = 0;
 //   for (int i = 1; i <= SIZE; i++) {
 //       if (masiv[i-1] == x) {
 //           kilkist++;
 //       }
 //   }

 //   if (kilkist > 0) {
 //       cout << "Кількість чисел " << x << " в масиві = " << kilkist;
 //   }
 //   else {
 //       cout << "Число " << x << " не зустрічається в масиві";
 //   }
 //   cout << endl;



    ////6
    //int masiv[20];
    //masiv[0] = 0;
    //masiv[1] = 1;
    //cout << "0  1  ";
    //for (int i = 2; i < 20; i++) {
    //    masiv[i] = masiv[i - 1] + masiv[i - 2];
    //    cout << masiv[i] << ' ';
    //}
    //cout << endl;


    system("pause");
    return 0;
}