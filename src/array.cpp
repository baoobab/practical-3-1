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
    for (number* curr = this->arr; curr != (this->arr + this->size); curr++) {
        cout << "flushed: " << *curr << "\n";
        delete curr;
    }
    this->size = 0;
    this->arr = 0;
}

void TArray::appendElement(number el) {
    number* newArr = new number[this->size + 1];
    number cnt = 0; // TODO: mb number zalupa nuzen unsigned hzhzhzh
    for (number* curr = this->arr; curr != (this->arr + this->size); curr++) {
        *(newArr + cnt++) = *curr;
    }
    cout << "\ncount: " << cnt << "\n";
    *(newArr + cnt) = el;

    this->arr = newArr;
    this->size++;
}

void TArray::print() {
    for (number* curr = this->arr; curr != (this->arr + this->size); curr++) {
        cout << "Elem: " << *curr << "\n";
    }
}
