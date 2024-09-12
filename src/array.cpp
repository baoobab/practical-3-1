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

number TArray::mediumValue() {
    number summ = 0;
    for (number* curr = this->arr; curr != (this->arr + this->size); curr++) {
        summ += *curr;
    }
    return summ/this->size;

}

void TArray::quickSortHelper(unsigned int low, unsigned int high) {
    if (this->size <= 1) return;

    unsigned int i = low;
    unsigned int j = high;
    number pivot = *(this->arr+((i + j) / 2));
    number temp;

    while (i <= j) {
        while (*(this->arr+i) < pivot)
            i++;
        while (*(this->arr+j) > pivot)
            j--;
        if (i <= j) {
            temp = *(this->arr+i);
            *(this->arr+i) = *(this->arr+j);
            *(this->arr+j) = temp;
            i++;
            j--;
        }
    }
    cout << "\nrekur";
    if (j > low)
        this->quickSortHelper(low, j);
    if (i < high)
        this->quickSortHelper(i, high);
    cout << "\nkenec";
}

void TArray::quickSortReverseHelper(unsigned int low, unsigned int high) {
    unsigned int i = low;
    unsigned int j = high;
    number pivot = *(this->arr + ((i + j) / 2));
    number temp;

    while (i <= j) {
        while (*(this->arr + i) > pivot)
            i++;
        while (*(this->arr + j) < pivot)
            j--;
        if (i <= j) {
            temp = *(this->arr + i);
            *(this->arr + i) = *(this->arr + j);
            *(this->arr + j) = temp;
            i++;
            j--;
        }
    }

    if (j > low)
        this->quickSortReverseHelper(low, j);
    if (i < high)
        this->quickSortReverseHelper(i, high);
}

void TArray::sort() {
    this->quickSortHelper(0, this->size - 1);
}

void TArray::reverseSort() {
    this->quickSortReverseHelper(0, this->size - 1);
}

void TArray::replaceElement(unsigned int index, number value) {
    *(this->arr + index) = value;
}

