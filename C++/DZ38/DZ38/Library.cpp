#include "Library.h"

Library::Library(const string& title) : Book_title(title) { }

string Library::getBookTitle() const {
    return Book_title;
}

void Library::setBookTitle(const string& title) {
    Book_title = title;
}

void exchangeBooks(Library& lib1, Library& lib2) {
    string temp = lib1.Book_title;
    lib1.Book_title = lib2.Book_title;
    lib2.Book_title = temp;
}