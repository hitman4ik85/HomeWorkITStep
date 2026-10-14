#pragma once
class Customer {
private:
    static int counter;

public:
    Customer();
    ~Customer();

    static int getCounter();
};
