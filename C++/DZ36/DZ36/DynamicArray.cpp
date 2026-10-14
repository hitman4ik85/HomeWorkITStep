#include "DynamicArray.h"

DynamicArray::DynamicArray() : array(nullptr), size(0), chuInicializovan(false), chuSorted(false), sortPoZrosty(true) {}
DynamicArray::DynamicArray(const char* arr, int sz) {
    initialize(arr, sz);
}

DynamicArray::~DynamicArray() {
    delete[] array;
}

void DynamicArray::initialize(const char* arr, int sz) {
    size = sz;
    array = new char[size];
    for (int i = 0; i < size; i++) {
        array[i] = arr[i];
    }
    chuInicializovan = true;
    chuSorted = false;
}

void DynamicArray::drykArray() {
    if (!chuInicializovan) {
        std::cout << "Масив не ініціалізовано." << std::endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << ' ';
    }
    std::cout << std::endl;
}

void DynamicArray::sortovanPoZrosty() {
    if (!chuInicializovan) return;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] > array[j]) {
                std::swap(array[i], array[j]);
            }
        }
    }
    chuSorted = true;
    sortPoZrosty = true;
}

void DynamicArray::sortovanPoSpady() {
    if (!chuInicializovan) return;
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (array[i] < array[j]) {
                std::swap(array[i], array[j]);
            }
        }
    }
    chuSorted = true;
    sortPoZrosty = false;
}

void DynamicArray::addElement(char element) {
    if (!chuInicializovan) {
        array = new char[1];
        array[0] = element;
        size = 1;
        chuInicializovan = true;
    }
    else {
        char* newArray = new char[size + 1];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        newArray[size] = element;
        delete[] array;
        array = newArray;
        size++;
    }
    chuSorted = false;
}

void DynamicArray::addArray(const char* arr, int sz) {
    if (!chuInicializovan) {
        initialize(arr, sz);
    }
    else {
        char* newArray = new char[size + sz];
        for (int i = 0; i < size; i++) {
            newArray[i] = array[i];
        }
        for (int i = 0; i < sz; i++) {
            newArray[size + i] = arr[i];
        }
        delete[] array;
        array = newArray;
        size += sz;
    }
    chuSorted = false;
}

void DynamicArray::sortArray(bool zrostanie) {
    if (zrostanie) {
        sortovanPoZrosty();
    }
    else {
        sortovanPoSpady();
    }
}

bool DynamicArray::chuZapovnenoArray() {
    return chuInicializovan;
}

bool DynamicArray::chuSortedArray() {
    return chuSorted;
}

bool DynamicArray::chuSortedArrayPoZrosty() {
    return sortPoZrosty;
}