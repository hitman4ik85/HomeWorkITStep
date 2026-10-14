////1
//#include <iostream>
//#include <string>
//#include <windows.h>
//using namespace std;
//
//int mystrcmp(string str1, string str2) {
//    int len1 = str1.length();
//    int len2 = str2.length();
//    int minLen = (len1 < len2) ? len1 : len2;
//
//    for (int i = 0; i < minLen; ++i) {
//        if (str1[i] > str2[i]) {
//            return 1;
//        }
//        else if (str1[i] < str2[i]) {
//            return -1;
//        }
//    }
//    if (len1 > len2) {
//        return 1;
//    }
//    else if (len1 < len2) {
//        return -1;
//    }
//    else {
//        return 0;
//    }
//}
//
//int StringToNumber(string str) {
//    int number = stoi(str);
//    return number;
//}
//
//string NumberToString(int number) {
//    return to_string(number);
//}
//
//string UpperCase(string str) {
//    for (char& c : str) {
//        c = toupper(c);
//    }
//    return str;
//}
//
//string LowerCase(string str) {
//    for (char& c : str) {
//        c = tolower(c);
//    }
//    return str;
//}
//
//string mystrrev(string str) {
//    int n = str.length();
//    for (int i = 0; i < n / 2; i++) {
//        swap(str[i], str[n - i - 1]);
//    }
//    return str;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    string s1 = "hellow";
//    string s2 = "hello";
//    int cmpResult = mystrcmp(s1, s2);
//    cout << "Рядки: " << s1 << " та " << s2 << " -> Результат їх порівняння: " << cmpResult << endl;
//
//    string numStr = "12345";
//    int num = StringToNumber(numStr);
//    cout << "Рядок: " << numStr << " -> Після конвертації з рядка: " << num << endl;
//
//    int number = 54321;
//    string strNum = NumberToString(number);
//    cout << "Число: " << number << " -> Після конвертації з числа: " << strNum << endl;
//
//    string mixedCase = "HeLLo WoRlD";
//    string upperCase = UpperCase(mixedCase);
//    cout << "Рядок: " << mixedCase << " -> У верхньому регістрі: " << upperCase << endl;
//
//    string mixedCase2 = "HeLLo WoRlD";
//    string lowerCase = LowerCase(mixedCase2);
//    cout << "Рядок: " << mixedCase2 << " -> У нижньому регістрі: " << lowerCase << endl;
//
//    string strToReverse = "hello";
//    string reversedStr = mystrrev(strToReverse);
//    cout << "Рядок: " << strToReverse << " -> Його реверс: " << reversedStr << endl;
//
//    return 0;
//}