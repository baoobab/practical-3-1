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


    // int test = 0;
    // for (int testCnt = 0; testCnt < this->size; testCnt++) {
    //     number* curr = (this->arr+testCnt);
    //     number* prevCurr = (curr - 1);
    //     if (test++ > 0) {
    //         cout << "flushed: " << *prevCurr << " " << *curr << "\n";
    //         delete prevCurr;
    //     }
    //     cout << "after: " << *curr << " " << curr << "\n";
    // }
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
    cout << "\ncount: " << cnt << "\n";
    *(newArr + cnt) = el;

    this->arr = newArr;
    this->size++;
}

void TArray::print() {
    cout << "Size: " << this->size << "\n";
    for (number* curr = this->arr; curr != (this->arr + this->size); curr++) {
        cout << "Elem: " << *curr << "\n";
    }
}
