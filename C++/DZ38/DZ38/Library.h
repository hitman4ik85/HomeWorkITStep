#pragma once
#include <string>
using namespace std;

class Library {
private:
    string Book_title;

public:
    Library(const string& title);
    string getBookTitle() const;
    void setBookTitle(const string& title);
    friend void exchangeBooks(Library& lib1, Library& lib2);
};