////1
//#include <iostream>
//#include <windows.h>
//#include "Block.h"
//using namespace std;
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    Block block1;
//    block1.showInfo();
//
//    Block block2("Цегла", "червоний", 20, 10, 5.5f);
//    block2.showInfo();
//
//    block1.setBlockParameters("Блок", "сірий", 25, 12, 6.0f);
//    cout << "Оновлений block1 ->" << endl;
//    block1.showInfo();
//
//    int wallHeight = 200;
//    int wallWidth = 100;
//    int blocksNeeded = block2.KilkistBloсkiv(wallHeight, wallWidth);
//    cout << "Кількість блоків для стіни (висотою: " << wallHeight << " см, шириною: " << wallWidth << " см) потрібно: " << blocksNeeded << " шт" << endl;
//
//    float costForWall = block2.VartistStinu(wallHeight, wallWidth);
//    cout << "Вартість побудови стіни: " << costForWall << " грн" << endl;
//
//    return 0;
//}



//2
#include <iostream>
#include <windows.h>
#include "Student.h"
using namespace std;

void findStudentWithMaxAverage(const Student students[], int size);
void findStudentWithMinAverage(const Student students[], int size);
void findStudentsByRegion(const Student students[], int size, const string& region);
void findStudentsByGroup(const Student students[], int size, const string& group);
void findStudentsBySeason(const Student students[], int size, const string& season);
void findStudentsYoungerThan(const Student students[], int size, int age);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int NUM_STUDENTS = 5;
    Student students[NUM_STUDENTS];

    int grades1[5] = { 12, 11, 10, 12, 9 };
    int grades2[5] = { 7, 8, 9, 6, 5 };
    int grades3[5] = { 10, 11, 12, 9, 8 };
    int grades4[5] = { 5, 6, 7, 8, 9 };
    int grades5[5] = { 8, 7, 6, 9, 10 };

    students[0] = Student("Іван", "Іванов", "ІНЗ-101", grades1, 90.0f, { "10.01.2000", "Київ" }, { "Київ", "Київська", "Шевченка", 1, 1 });
    students[1] = Student("Петро", "Петров", "ІНЗ-102", grades2, 80.0f, { "15.02.2001", "Львів" }, { "Львів", "Львівська", "Лисенка", 2, 2 });
    students[2] = Student("Олег", "Олегов", "ІНЗ-103", grades3, 85.0f, { "20.03.2002", "Одеса" }, { "Одеса", "Одеська", "Пушкіна", 3, 3 });
    students[3] = Student("Андрій", "Андрієв", "ІНЗ-104", grades4, 75.0f, { "25.04.2000", "Суми" }, { "Суми", "Сумська", "Холодногірська", 4, 4 });
    students[4] = Student("Сергій", "Сергієв", "ІНЗ-105", grades5, 70.0f, { "30.05.2001", "Харків" }, { "Харків", "Харківська", "Маяковського", 5, 5 });

    int choice;
    do {
        cout << endl;
        cout << "Меню:" << endl;
        cout << "1. Визначити студента з максимальним середнім балом" << endl;
        cout << "2. Визначити студента з мінімальним середнім балом" << endl;
        cout << "3. Визначити студентів які проживають в заданій області" << endl;
        cout << "4. Визначити студентів з заданої академічної групи" << endl;
        cout << "5. Визначити студентів, що народились в задану пору року" << endl;
        cout << "6. Визначити студентів, молодших за заданий вік" << endl;
        cout << "0. Вийти" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        switch (choice) {
        case 1:
            findStudentWithMaxAverage(students, NUM_STUDENTS);
            break;
        case 2:
            findStudentWithMinAverage(students, NUM_STUDENTS);
            break;
        case 3: {
            string region;
            cout << "Введіть область: ";
            cin >> region;
            findStudentsByRegion(students, NUM_STUDENTS, region);
            break;
        }
        case 4: {
            string group;
            cout << "Введіть групу: ";
            cin >> group;
            findStudentsByGroup(students, NUM_STUDENTS, group);
            break;
        }
        case 5: {
            string season;
            cout << "Введіть пору року (весна, літо, осінь, зима): ";
            cin >> season;
            findStudentsBySeason(students, NUM_STUDENTS, season);
            break;
        }
        case 6: {
            int age;
            cout << "Введіть вік: ";
            cin >> age;
            findStudentsYoungerThan(students, NUM_STUDENTS, age);
            break;
        }
        case 0:
            cout << "Вихід" << endl;
            break;
        default:
            cout << "Неправильний вибір, спробуйте ще раз." << endl;
        }
    } while (choice != 0);

    return 0;
}

void findStudentWithMaxAverage(const Student students[], int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (students[i].calculateAverageGrade() > students[maxIndex].calculateAverageGrade()) {
            maxIndex = i;
        }
    }
    cout << "Студент з максимальним середнім балом:" << endl;
    students[maxIndex].showInfo();
}

void findStudentWithMinAverage(const Student students[], int size) {
    int minIndex = 0;
    for (int i = 1; i < size; i++) {
        if (students[i].calculateAverageGrade() < students[minIndex].calculateAverageGrade()) {
            minIndex = i;
        }
    }
    cout << "Студент з мінімальним середнім балом:" << endl;
    students[minIndex].showInfo();
}

void findStudentsByRegion(const Student students[], int size, const string& region) {
    cout << "Студенти з області " << region << ":" << endl;
    for (int i = 0; i < size; i++) {
        if (students[i].getRegion() == region) {
            students[i].showInfo();
            cout << endl;
        }
    }
}

void findStudentsByGroup(const Student students[], int size, const string& group) {
    cout << "Студенти з групи " << group << ":" << endl;
    for (int i = 0; i < size; i++) {
        if (students[i].getGroup() == group) {
            students[i].showInfo();
            cout << endl;
        }
    }
}

void findStudentsBySeason(const Student students[], int size, const string& season) {
    cout << "Студенти, що народились у " << season << ":" << endl;
    for (int i = 0; i < size; i++) {
        string month = students[i].getDateOfBirth().substr(3, 2);
        int monthInt = stoi(month);
        if ((season == "весна" && (monthInt >= 3 && monthInt <= 5)) ||
            (season == "літо" && (monthInt >= 6 && monthInt <= 8)) ||
            (season == "осінь" && (monthInt >= 9 && monthInt <= 11)) ||
            (season == "зима" && (monthInt == 12 || monthInt == 1 || monthInt == 2))) {
            students[i].showInfo();
            cout << endl;
        }
    }
}

void findStudentsYoungerThan(const Student students[], int size, int age) {
    cout << "Студенти молодші за " << age << " років:" << endl;
    for (int i = 0; i < size; i++) {
        if (students[i].isYoungerThan(age)) {
            students[i].showInfo();
            cout << endl;
        }
    }
}