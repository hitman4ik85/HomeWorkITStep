////1
//#include <iostream>
//#include <string>
//#include <windows.h>
//#include <filesystem>
//
//using namespace std;
//namespace fs = std::filesystem;
//
//void PoshykFailivNaA(const fs::path& directoryPath) {
//    try {
//        if (fs::exists(directoryPath) && fs::is_directory(directoryPath)) {
//            cout << "Файли, що починаються на 'A':" << endl;
//
//            for (const auto& entry : fs::directory_iterator(directoryPath)) {
//                if (fs::is_regular_file(entry)) {
//                    string filename = entry.path().filename().string();
//                    if (filename[0] == 'A' || filename[0] == 'а') {
//                        cout << "Файл: " << filename << ", Розмір: " << fs::file_size(entry.path()) << " байтів" << endl;
//                    }
//                }
//            }
//        }
//        else {
//            cout << "Шлях не існує або не є директорією." << endl;
//        }
//    }
//    catch (const fs::filesystem_error& e) {
//        cout << "Помилка файлової системи: " << e.what() << endl;
//    }
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    cout << "Введіть шлях до директорії: ";
//    string directoryPath;
//    getline(cin, directoryPath);
//
//    PoshykFailivNaA(directoryPath);
//
//    system("pause");
//    return 0;
//}




////2
//#include <iostream>
//#include <conio.h>
//#include <string>
//#include <filesystem>
//#include <windows.h>
//
//using namespace std;
//namespace fs = std::filesystem;
//
//void deleteTmpFiles(const fs::path& directoryPath) {
//    int count = 0;
//    try {
//        if (fs::exists(directoryPath) && fs::is_directory(directoryPath)) {
//            for (const auto& entry : fs::recursive_directory_iterator(directoryPath)) {
//                if (fs::is_regular_file(entry) && entry.path().extension() == ".tmp") {
//                    cout << "Видаляється файл: " << entry.path().string() << endl;
//                    fs::remove(entry);
//                    count++;
//                }
//            }
//            cout << "Кількість видалених файлів: " << count << endl;
//        }
//        else {
//            cout << "Шлях не існує або не є директорією." << endl;
//        }
//    }
//    catch (const fs::filesystem_error& e) {
//        cout << "Помилка файлової системи: " << e.what() << endl;
//    }
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    cout << "Введіть шлях до директорії: ";
//    string directoryPath;
//    getline(cin, directoryPath);
//
//    deleteTmpFiles(directoryPath);
//
//    system("pause");
//    return 0;
//}




////3
//#include <iostream>
//#include <conio.h>
//#include <string>
//#include <fstream>
//#include <filesystem>
//#include <windows.h>
//
//using namespace std;
//namespace fs = std::filesystem;
//
//void createFileList(const fs::path& directoryPath) {
//    fs::path listFilePath = directoryPath / "list.dir";
//
//    ofstream listFile(listFilePath);
//    if (!listFile) {
//        cout << "Не вдалося створити файл list.dir" << endl;
//        return;
//    }
//
//    for (const auto& entry : fs::directory_iterator(directoryPath)) {
//        if (fs::is_regular_file(entry)) {
//            listFile << entry.path().filename().string() << endl;
//        }
//    }
//
//    cout << "Файл list.dir створено та записано." << endl;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    cout << "Введіть шлях до директорії: ";
//    string directoryPath;
//    getline(cin, directoryPath);
//
//    createFileList(directoryPath);
//
//    system("pause");
//    return 0;
//}