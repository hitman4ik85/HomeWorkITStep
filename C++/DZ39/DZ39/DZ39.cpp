////1
//#include <iostream>
//#include <vector>
//#include <string>
//#include <windows.h>
//using namespace std;
//
//class Student {
//private:
//    string name;
//    double average_grade;
//
//public:
//    Student(string name, double average_grade)
//        : name(name), average_grade(average_grade) {}
//
//    string getName() {
//        return name;
//    }
//
//    double getAverageGrade() {
//        return average_grade;
//    }
//};
//
//class StudentGroup {
//private:
//    vector<Student> students;
//
//public:
//    void addStudent(Student student) {
//        students.push_back(student);
//    }
//
//    void removeStudent(string name) {
//        for (auto it = students.begin(); it != students.end(); ++it) {
//            if (it->getName() == name) {
//                students.erase(it);
//                return;
//            }
//        }
//        cout << "Студент з ім'ям " << name << " не знайдений." << endl;
//    }
//
//    void printGroup() {
//        for (auto& student : students) {
//            cout << "Ім'я: " << student.getName() << ", Середній бал: " << student.getAverageGrade() << endl;
//        }
//    }
//};
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    StudentGroup group;
//
//    group.addStudent(Student("Іван", 90.5));
//    group.addStudent(Student("Марія", 85.3));
//    group.addStudent(Student("Петро", 92.7));
//
//    cout << "Група студентів:" << endl;
//    group.printGroup();
//
//    cout << "\nВидалення студента 'Петро':" << endl;
//    group.removeStudent("Петро");
//
//    cout << "\nГрупа студентів після видалення:" << endl;
//    group.printGroup();
//
//    return 0;
//}



////2
//#include <iostream>
//#include <map>
//#include <string>
//#include <windows.h>
//using namespace std;
//
//class Item {
//private:
//    int code;
//    string name;
//    int kilkist;
//
//public:
//    Item() : code(0), name(""), kilkist(0) {}
//
//    Item(int code, string name, int kilkist)
//        : code(code), name(name), kilkist(kilkist) {}
//
//    int getCode() const {
//        return code;
//    }
//
//    string getName() const {
//        return name;
//    }
//
//    int getKilkist() const {
//        return kilkist;
//    }
//
//    void setKilkist(int newKilkist) {
//        kilkist = newKilkist;
//    }
//};
//
//class Inventory {
//private:
//    map<int, Item> items;
//
//public:
//    void addItem(int code, const Item& item) {
//        items[code] = item;
//    }
//
//    void removeItem(int code) {
//        if (items.erase(code) == 0) {
//            cout << "Товар з кодом " << code << " не знайдено." << endl;
//        }
//    }
//
//    void updateKilkist(int code, int newKilkist) {
//        auto it = items.find(code);
//        if (it != items.end()) {
//            it->second.setKilkist(newKilkist);
//        }
//        else {
//            cout << "Товар з кодом " << code << " не знайдено." << endl;
//        }
//    }
//
//    void printInventory() const {
//        for (const auto& pair : items) {
//            cout << "Код: " << pair.first
//                << ", Назва: " << pair.second.getName()
//                << ", Кількість: " << pair.second.getKilkist() << endl;
//        }
//    }
//};
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    Inventory inventory;
//
//    inventory.addItem(1, Item(1, "Банани", 100));
//    inventory.addItem(2, Item(2, "Ківі", 50));
//    inventory.addItem(3, Item(3, "Апельсини", 75));
//
//    cout << "Інвентар магазину:" << endl;
//    inventory.printInventory();
//
//    cout << "\nОновлення кількості товару з кодом 2:" << endl;
//    inventory.updateKilkist(2, 60);
//    inventory.printInventory();
//
//    cout << "\nВидалення товару з кодом 1:" << endl;
//    inventory.removeItem(1);
//    inventory.printInventory();
//
//    return 0;
//}