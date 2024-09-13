#include "array.h"
#include "number.h"
#include <cmath>
#include <iostream>

using namespace std;


TArray::TArray() {
    this->size = 0;
    this->arr = 0;
}

TArray::~TArray() {
    this->flushMemory();
}

unsigned TArray::getSize() {
    return this->size;
}
// number& TArray::operator[](unsigned index) {
//     if (!checkIndex(index)) {
//         throw out_of_range("Index out of range"); // TODO: починить
//     }
//     return *(this->arr + index);
// }

bool TArray::checkIndex(unsigned int index) {
    return (index < this->size);
}

void TArray::flushMemory() {
    cout << "Ya crestyanin\n";
    delete[] this->arr; // TODO: podumat"
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
    *(newArr + cnt) = el;

    delete[] this->arr;

    this->arr = newArr;
    this->size++;
}

void TArray::removeElementByIndex(unsigned index) {
    if (!checkIndex(index) || !this->size) return; // Если такого индекса нет, или массив пустой - выходим

    number* newArr = new number[this->size - 1];
    number cnt = 0;
    for (number* curr = this->arr; curr != (this->arr + this->size); curr++) {
        if (index-- == 0) continue; // скипаем удаляемый элемент
        *(newArr + cnt++) = *curr;
    }

    delete[] this->arr;

    this->arr = newArr;
    this->size--;
}

void TArray::print() {
    if (!this->size) {
        cout << "Array is empty" << "\n";
        return;
    }
    for (number* curr = this->arr; curr != (this->arr + this->size); curr++) {
        cout << *curr << " ";
    }
    cout << "\n";
}

number TArray::mediumValue() {
    if (!this->size) return 0; // baoobab: Или ошибку выкидывать - хз,
    // просто если будут отриц. числа то ретёрнить ноль такое

    number summ = 0;
    for (number* curr = this->arr; curr != (this->arr + this->size); curr++) {
        summ += *curr;
    }
    return summ/this->size;

}

number TArray::standardDeviation() {
    if (!this->size) return 0; // baoobab: Или ошибку выкидывать - хз

    number mediumValue = this->mediumValue();
    number standardSumm = 0;

    for (number* curr = this->arr; curr != (this->arr + this->size); curr++) {
        standardSumm += pow(*curr - mediumValue, 2);
    }

    return sqrt(standardSumm / (this->size - 1));
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
    if (j > low)
        this->quickSortHelper(low, j);
    if (i < high)
        this->quickSortHelper(i, high);
}

void TArray::quickSortReverseHelper(unsigned int low, unsigned int high) {
    if (this->size <= 1) return;

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
    if (!checkIndex(index)) {
        cout << "\nIndex out of range\n";
        return;
    }

    *(this->arr + index) = value;
}

void TArray::resizeArray(unsigned int newSize) {
    int elementsToAppend = newSize - this->size; // TODO: функция может возвращать кол-во созданных элементов

    /*if (elementsToAppend == 0) {
        cout << "Dimension is already like that" << "\n";
    } else if*/
    if (elementsToAppend < 0) {
        while (elementsToAppend++) {
            this->removeElementByIndex(this->size - 1);
        }
    } else if (elementsToAppend > 0) {
        while (elementsToAppend--) {
            this->appendElement(0); // baoobab: мб создать ДефолтЗначение для number как константу и импротировать её
        }
    }

    cout << "Current dimension is: " << newSize << "\n";
    return;
}


void TArray::defineArray(unsigned int size) {
    this->flushMemory();
    this->resizeArray(size);
}
