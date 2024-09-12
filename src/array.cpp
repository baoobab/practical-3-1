#include "array.h"
#include "number.h"
#include <iostream>

using namespace std;


TArray::TArray() {
    this->size = 0;
    this->arr = 0;
}

TArray::~TArray() {
    flushMemory();
}

void TArray::flushMemory() {
    cout << "Ya crestyanin\n";
    delete[] this->arr; // TODO: podumat'
    this->size = 0;
    this->arr = 0;
}

void TArray::appendElement(number el) {
    number* newArr = new number[this->size + 1];
    // number* newArr = (number*) malloc(sizeof(number) * (this->size + 1));
    number cnt = 0; // TODO: mb number zalupa nuzen unsigned hzhzhzh
    for (number* curr = this->arr; curr != (this->arr + this->size); curr++) {
        *(newArr + cnt++) = *curr;
    }
//    cout << "\ncount: " << cnt << "\n";
    *(newArr + cnt) = el;

    this->arr = newArr;
    this->size++;
}

void TArray::print() {
//    cout << "Size: " << this->size << "\n";
    for (number* curr = this->arr; curr != (this->arr + this->size); curr++) {
        cout << *curr << " ";
    }
    cout << '\n';
}

float TArray::mediumValue() {
    float summ = 0;
    for (number* curr = this->arr; curr != (this->arr + this->size); curr++) {
        summ += *curr;
    }
    return summ/this->size;

}

// TODO: mozhno li tak v oop hzhz
void quickSort(number *array, unsigned int low, unsigned int high) {
    unsigned int i = low;
    unsigned int j = high;
    number pivot = *(array+((i + j) / 2));
    number temp;

    while (i <= j) {
        while (*(array+i) < pivot)
            i++;
        while (*(array+j) > pivot)
            j--;
        if (i <= j) {
            temp = *(array+i);
            *(array+i) = *(array+j);
            *(array+j) = temp;
            i++;
            j--;
        }
    }
    if (j > low)
        quickSort(array, low, j);
    if (i < high)
        quickSort(array, i, high);
}

void quickSortReverse(number *array, unsigned int low, unsigned int high) {
    unsigned int i = low;
    unsigned int j = high;
    number pivot = *(array + ((i + j) / 2));
    number temp;

    while (i <= j) {
        while (*(array + i) > pivot)
            i++;
        while (*(array + j) < pivot)
            j--;
        if (i <= j) {
            temp = *(array + i);
            *(array + i) = *(array + j);
            *(array + j) = temp;
            i++;
            j--;
        }
    }

    if (j > low)
        quickSortReverse(array, low, j);
    if (i < high)
        quickSortReverse(array, i, high);
}

void TArray::sort() {
    quickSort(this->arr, 0, this->size);
}

void TArray::reverseSort() {
    quickSortReverse(this->arr, 0, this->size);
}

void TArray::replaceElement(unsigned int index, number value) {
    *(this->arr + index) = value;
}

