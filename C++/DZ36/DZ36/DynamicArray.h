#pragma once
#include <iostream>

class DynamicArray {
private:
    char* array;
    int size;
    bool chuInicializovan;
    bool chuSorted;
    bool sortPoZrosty;

public:
    DynamicArray();
    DynamicArray(const char* arr, int size);

    ~DynamicArray();

    void drykArray();
    void sortovanPoZrosty();
    void sortovanPoSpady();
    void addElement(char element);
    void addArray(const char* arr, int size);
    void sortArray(bool zrostanie);
    bool chuZapovnenoArray();
    bool chuSortedArray();
    bool chuSortedArrayPoZrosty();

private:
    void initialize(const char* arr, int size);
};