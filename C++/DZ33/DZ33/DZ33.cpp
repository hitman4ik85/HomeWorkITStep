////1
//#include <iostream>
//#include <fstream>
//#include <cctype>
//#include <Windows.h>
//
//using namespace std;
//
//void countCharacters(const string& filename) {
//    ifstream inFile(filename);
//
//    if (!inFile.is_open()) {
//        cout << "Помилка відкриття файлу " << filename << endl;
//        return;
//    }
//
//    int totalCount = 0;
//    int letterCount = 0;
//    int digitCount = 0;
//    int otherCount = 0;
//    char ch;
//
//    while (inFile.get(ch)) {
//        totalCount++;
//
//        if (isalpha(ch)) {
//            letterCount++;
//        }
//        else if (isdigit(ch)) {
//            digitCount++;
//        }
//        else {
//            otherCount++;
//        }
//    }
//
//    inFile.close();
//
//    cout << "Загальна кількість символів у файлі " << filename << ": " << totalCount << endl;
//    cout << "Кількість літер: " << letterCount << endl;
//    cout << "Кількість цифр: " << digitCount << endl;
//    cout << "Кількість інших символів: " << otherCount << endl;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    string filename = "text.txt";
//
//    countCharacters(filename);
//
//    return 0;
//}



////2
//#include <iostream>
//#include <fstream>
//#include <string>
//#include <Windows.h>
//
//using namespace std;
//
//void filterRecords(const string& inputFile, const string& outputFile) {
//    ifstream inFile(inputFile);
//    ofstream outFile(outputFile);
//
//    if (!inFile.is_open() || !outFile.is_open()) {
//        cout << "Помилка відкриття файлів." << endl;
//        return;
//    }
//
//    string surname, firstName, gender, phoneNumber;
//    int countFile1 = 0, countFile2 = 0;
//
//    while (inFile >> surname >> firstName >> gender >> phoneNumber) {
//        countFile1++;
//        if (surname[0] == 'A' || surname[0] == 'Z') {
//            outFile << surname << " " << firstName << " " << gender << " " << phoneNumber << endl;
//            countFile2++;
//        }
//    }
//
//    inFile.close();
//    outFile.close();
//
//    cout << "Кількість записів у файлі " << inputFile << ": " << countFile1 << endl;
//    cout << "Кількість записів у файлі " << outputFile << ": " << countFile2 << endl;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//    string inputFile = "file1.txt";
//    string outputFile = "file2.txt";
//
//    filterRecords(inputFile, outputFile);
//
//    return 0;
//}