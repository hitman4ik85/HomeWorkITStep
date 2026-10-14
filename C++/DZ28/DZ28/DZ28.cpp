////1
//#include <iostream>
//#include <string>
//#include <Windows.h>
//using namespace std;
//
//struct Address {
//    string city;
//    string street;
//    int index;
//    int houseNumber;
//};
//
//struct Abonent {
//    string surname;
//    string name;
//    string phoneNumber;
//    Address address;
//};
//
//void addAbonent(Abonent phonebook[], int& size) {
//    if (size >= 100) {
//        cout << "Телефонний довідник заповнений!\n" << endl;
//        return;
//    }
//
//    Abonent newAbonent;
//    cout << "Введіть прізвище: ";
//    cin >> newAbonent.surname;
//    cout << "Введіть ім'я: ";
//    cin >> newAbonent.name;
//    cout << "Введіть номер телефону: ";
//    cin >> newAbonent.phoneNumber;
//    cout << "Введіть індекс: ";
//    cin >> newAbonent.address.index;
//    cout << "Введіть місто: ";
//    cin >> newAbonent.address.city;
//    cout << "Введіть вулицю: ";
//    cin >> newAbonent.address.street;
//    cout << "Введіть номер будинку: ";
//    cin >> newAbonent.address.houseNumber;
//
//    phonebook[size] = newAbonent;
//    size++;
//    cout << "Абонента додано успішно!\n" << endl;
//}
//
//void searchByPhoneNumber(const Abonent phonebook[], int size, const string& phoneNumber) {
//    for (int i = 0; i < size; i++) {
//        if (phonebook[i].phoneNumber == phoneNumber) {
//            cout << "Абонент знайдено: " << phonebook[i].surname << " " << phonebook[i].name << endl << endl;
//            return;
//        }
//    }
//    cout << "Абонента з номером телефону " << phoneNumber << " не знайдено.\n" << endl;
//}
//
//void searchByName(const Abonent phonebook[], int size, const string& surname, const string& name) {
//    for (int i = 0; i < size; i++) {
//        if (phonebook[i].surname == surname && phonebook[i].name == name) {
//            cout << "Абонент знайдено: " << phonebook[i].phoneNumber << endl << endl;
//            return;
//        }
//    }
//    cout << "Абонента з ім'ям " << surname << " " << name << " не знайдено.\n" << endl;
//}
//
//void searchByAddress(const Abonent phonebook[], int size, const Address& address) {
//    for (int i = 0; i < size; i++) {
//        if (phonebook[i].address.index == address.index &&
//            phonebook[i].address.city == address.city &&
//            phonebook[i].address.street == address.street &&
//            phonebook[i].address.houseNumber == address.houseNumber) {
//            cout << "Абонент знайдено: " << phonebook[i].surname << " " << phonebook[i].name << endl << endl;
//            return;
//        }
//    }
//    cout << "Абонента з такою адресою не знайдено.\n" << endl;
//}
//
//void editAbonent(Abonent phonebook[], int size, const string& phoneNumber) {
//    for (int i = 0; i < size; i++) {
//        if (phonebook[i].phoneNumber == phoneNumber) {
//            cout << "Введіть нові дані для абонента:" << endl;
//            cout << "Прізвище: ";
//            cin >> phonebook[i].surname;
//            cout << "Ім'я: ";
//            cin >> phonebook[i].name;
//            cout << "Номер телефону: ";
//            cin >> phonebook[i].phoneNumber;
//            cout << "Індекс: ";
//            cin >> phonebook[i].address.index;
//            cout << "Місто: ";
//            cin >> phonebook[i].address.city;
//            cout << "Вулиця: ";
//            cin >> phonebook[i].address.street;
//            cout << "Номер будинку: ";
//            cin >> phonebook[i].address.houseNumber;
//
//            cout << "Інформацію про абонента успішно оновлено!\n" << endl;
//            return;
//        }
//    }
//    cout << "Абонента з номером телефону " << phoneNumber << " не знайдено.\n" << endl;
//}
//
//void deleteAbonent(Abonent phonebook[], int& size, const string& phoneNumber) {
//    for (int i = 0; i < size; i++) {
//        if (phonebook[i].phoneNumber == phoneNumber) {
//            for (int j = i; j < size - 1; j++) {
//                phonebook[j] = phonebook[j + 1];
//            }
//            size--;
//            cout << "Абонента видалено успішно!\n" << endl;
//            return;
//        }
//    }
//    cout << "Абонента з номером телефону " << phoneNumber << " не знайдено.\n" << endl;
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    const int maxAbonents = 100;
//    Abonent phonebook[maxAbonents];
//    int size = 0;
//    int vubir;
//    string phoneNumber, surname, name;
//    Address address;
//
//    do {
//        cout << "Телефонний довідник" << endl;
//        cout << "1. Додати нового абонента" << endl;
//        cout << "2. Пошук за номером телефону" << endl;
//        cout << "3. Пошук за прізвищем та ім'ям" << endl;
//        cout << "4. Пошук за адресою" << endl;
//        cout << "5. Редагувати інформацію про абонента" << endl;
//        cout << "6. Видалити запис" << endl;
//        cout << "7. Вихід" << endl;
//        cout << "Ваш вибір: ";
//        cin >> vubir;
//
//        switch (vubir) {
//        case 1:
//            addAbonent(phonebook, size);
//            break;
//        case 2:
//            cout << "Введіть номер телефону: ";
//            cin >> phoneNumber;
//            searchByPhoneNumber(phonebook, size, phoneNumber);
//            break;
//        case 3:
//            cout << "Введіть прізвище: ";
//            cin >> surname;
//            cout << "Введіть ім'я: ";
//            cin >> name;
//            searchByName(phonebook, size, surname, name);
//            break;
//        case 4:
//            cout << "Введіть індекс: ";
//            cin >> address.index;
//            cout << "Введіть місто: ";
//            cin >> address.city;
//            cout << "Введіть вулицю: ";
//            cin >> address.street;
//            cout << "Введіть номер будинку: ";
//            cin >> address.houseNumber;
//            searchByAddress(phonebook, size, address);
//            break;
//        case 5:
//            cout << "Введіть номер телефону абонента, інформацію про якого потрібно редагувати: ";
//            cin >> phoneNumber;
//            editAbonent(phonebook, size, phoneNumber);
//            break;
//        case 6:
//            cout << "Введіть номер телефону абонента, якого потрібно видалити: ";
//            cin >> phoneNumber;
//            deleteAbonent(phonebook, size, phoneNumber);
//            break;
//        case 7:
//            cout << "Вихід з програми." << endl;
//            break;
//        default:
//            cout << "Невірний вибір. Спробуйте ще раз." << endl;
//            break;
//        }
//    } while (vubir != 7);
//
//    return 0;
//}




////2
//#include <iostream>
//#include <string>
//#include <Windows.h>
//using namespace std;
//
//const int maxPisni = 100;
//
//struct Pisnja {
//    string vukonavets;
//    string nazva;
//    int rik;
//};
//
//Pisnja pisni[maxPisni];
//int kilk = 0;
//
//void DodatuPisnja(const string& vukonavets, const string& nazva, int rik) {
//    if (kilk < maxPisni) {
//        pisni[kilk].vukonavets = vukonavets;
//        pisni[kilk].nazva = nazva;
//        pisni[kilk].rik = rik;
//        kilk++;
//    }
//    else {
//        cout << "Неможливо додати пісню, масив повний." << endl;
//    }
//}
//
//void PokazatuVsiPisni() {
//    cout << "Список усіх пісень:" << endl;
//    for (int i = 0; i < kilk; i++) {
//        cout << "Пісня " << i + 1 << ": '" << pisni[i].nazva << "' виконавець: " << pisni[i].vukonavets << ", Рік: " << pisni[i].rik << endl;
//    }
//}
//
//void PokazatuZaVukonavcem(const string& vukonavets) {
//    cout << "Пісні виконавця '" << vukonavets << "':" << endl;
//    bool found = false;
//    for (int i = 0; i < kilk; i++) {
//        if (pisni[i].vukonavets == vukonavets) {
//            cout << "'" << pisni[i].nazva << "', Рік: " << pisni[i].rik << endl;
//            found = true;
//        }
//    }
//    if (!found) {
//        cout << "Пісні виконавця '" << vukonavets << "' не знайдено." << endl;
//    }
//}
//
//void VudalutuPisnjy(const string& nazva) {
//    bool found = false;
//    for (int i = 0; i < kilk; i++) {
//        if (pisni[i].nazva == nazva) {
//            cout << "Ви впевнені, що хочете видалити пісню '" << pisni[i].nazva << "' виконавця " << pisni[i].vukonavets << ", Рік: " << pisni[i].rik << "? (y/n): ";
//            char zgoda;
//            cin >> zgoda;
//            if (zgoda == 'y' || zgoda == 'Y') {
//                for (int j = i; j < kilk - 1; ++j) {
//                    pisni[j] = pisni[j + 1];
//                }
//                kilk--;
//                cout << "Пісня '" << nazva << "' видалена." << endl;
//            }
//            else {
//                cout << "Видалення скасоване." << endl;
//            }
//            found = true;
//            break;
//        }
//    }
//    if (!found) {
//        cout << "Пісню '" << nazva << "' не знайдено в архіві." << endl;
//    }
//}
//
//void PoshykZaSlovom(const string& slovo) {
//    bool found = false;
//    for (int i = 0; i < kilk; i++) {
//        size_t foundPos = pisni[i].nazva.find(slovo);
//        if (foundPos != string::npos) {
//            cout << "Знайдено пісню '" << pisni[i].nazva << "' виконавця " << pisni[i].vukonavets << ", Рік: " << pisni[i].rik << endl;
//            found = true;
//        }
//    }
//    if (!found) {
//        cout << "Пісні зі словом '" << slovo << "' в назві не знайдено." << endl;
//    }
//}
//
//void SortovanaZaRokom() {
//    for (int i = 0; i < kilk - 1; i++) {
//        for (int j = 0; j < kilk - i - 1; j++) {
//            if (pisni[j].rik > pisni[j + 1].rik) {
//                Pisnja temp = pisni[j];
//                pisni[j] = pisni[j + 1];
//                pisni[j + 1] = temp;
//            }
//        }
//    }
//    cout << "Пісні відсортовані за роком виходу:" << endl;
//    for (int i = 0; i < kilk; i++) {
//        cout << "Пісня " << i + 1 << ": '" << pisni[i].nazva << "' виконавець: " << pisni[i].vukonavets << ", Рік: " << pisni[i].rik << endl;
//    }
//}
//
//int main() {
//    SetConsoleCP(1251);
//    SetConsoleOutputCP(1251);
//
//    DodatuPisnja("Джамала", "1944", 2016);
//    DodatuPisnja("Okean Elzy", "Все буде добре", 2005);
//    DodatuPisnja("Тік", "Дощ", 2020);
//    DodatuPisnja("Оля Полякова", "Маються права", 2021);
//    DodatuPisnja("Дзі-Дзьо", "Доброго ранку", 2019);
//
//    int vubir;
//    do {
//        cout << "\nМеню вибору операцій:" << endl;
//        cout << "1. Перегляд повного списку наявних пісень" << endl;
//        cout << "2. Перегляд списку пісень окремого виконавця" << endl;
//        cout << "3. Додавання нової пісні в масив" << endl;
//        cout << "4. Видалення пісні з масиву за назвою" << endl;
//        cout << "5. Пошук пісні за словом або частиною слова в назві" << endl;
//        cout << "6. Сортування пісень за роком виходу" << endl;
//        cout << "0. Вихід з програми" << endl;
//        cout << "Оберіть операцію: ";
//        cin >> vubir;
//
//        switch (vubir) {
//        case 1:
//            PokazatuVsiPisni();
//            break;
//        case 2:
//        {
//            string vukonavets;
//            cout << "Введіть виконавця: ";
//            cin.ignore();
//            getline(cin, vukonavets);
//            PokazatuZaVukonavcem(vukonavets);
//        }
//        break;
//        case 3:
//        {
//            string vukonavets, nazva;
//            int rik;
//            cout << "Введіть виконавця: ";
//            cin.ignore();
//            getline(cin, vukonavets);
//            cout << "Введіть назву пісні: ";
//            getline(cin, nazva);
//            cout << "Введіть рік виходу: ";
//            cin >> rik;
//            DodatuPisnja(vukonavets, nazva, rik);
//        }
//        break;
//        case 4:
//        {
//            string deleteName;
//            cout << "Введіть назву пісні для видалення: ";
//            cin.ignore();
//            getline(cin, deleteName);
//            VudalutuPisnjy(deleteName);
//        }
//        break;
//        case 5:
//        {
//            string searchWord;
//            cout << "Введіть слово або частину слова для пошуку: ";
//            cin.ignore();
//            getline(cin, searchWord);
//            PoshykZaSlovom(searchWord);
//        }
//        break;
//        case 6:
//            SortovanaZaRokom();
//            break;
//        case 0:
//            cout << "Дякую за використання програми!" << endl;
//            break;
//        default:
//            cout << "Невірний вибір. Будь ласка, спробуйте ще раз." << endl;
//            break;
//        }
//    } while (vubir != 0);
//
//    return 0;
//}