#ifndef ARRAY_H
#define ARRAY_H

#include "number.h"


class TArray {
private:
    unsigned size = 0;
    number* arr =  0;

    void flushMemory();
    void quickSortHelper(int low, int high);
    void quickSortReverseHelper(int low, int high);
    void copyArray();
    bool checkIndex(unsigned int index);
public:
    TArray();
    ~TArray();
    unsigned getSize();
    void appendElement(number el);
    void print();
    void resizeArray(unsigned newSize);
    void defineArray(unsigned size);
    number mediumValue();
    number standardDeviation();
    void sort();
    void reverseSort();
    void replaceElement(unsigned int index, number value);
    void removeElementByIndex(unsigned int index);  
};

#endif // ARRAY_H
