#include "Customer.h"

int Customer::counter = 0;

Customer::Customer() {
    ++counter;
}

Customer::~Customer() {
    --counter;
}

int Customer::getCounter() {
    return counter;
}