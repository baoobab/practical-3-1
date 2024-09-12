#ifndef ARRAY_H
#define ARRAY_H

#include "number.h"


class TArray {
private:
    unsigned size = 0;
    number* arr =  0;

    void flushMemory();
    void quickSortHelper(unsigned low, unsigned high);
    void quickSortReverseHelper(unsigned low, unsigned high);
    void copyArray();
    bool checkIndex(unsigned int index);
public:
    TArray();
    ~TArray();
    void appendElement(number el);
    void print();
    void resizeArray(unsigned newSize);
    number mediumValue();
    number standardDeviation();
    void sort();
    void reverseSort();
    void replaceElement(unsigned int index, number value);
    void removeElementByIndex(unsigned int index);
};

#endif // ARRAY_H
