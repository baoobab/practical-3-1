#ifndef ARRAY_H
#define ARRAY_H

#include "number.h"


class TArray {
private:
    unsigned size = 0;
    number* arr =  0;

    void flushMemory(); // TODO: mb huynya
public:
    TArray();
    ~TArray();
    void appendElement(number el);
    void print();

    void fillArray(unsigned int amount);
    float mediumValue();
    void sort();
    void reverseSort();
    void replaceElement(unsigned int index, number value);
};

#endif // ARRAY_H
