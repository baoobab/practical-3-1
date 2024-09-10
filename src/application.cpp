#include "application.h"
#include "array.h"
#include "number.h"
#include <iostream>

using namespace std;


TApplication::TApplication() {

}

int TApplication::exec() {
    int ch;
    TArray bebraArr; // TODO: zamena na adekvatniy name
    while (true) {
        ch = menu();
        switch (ch) {
            case 7: {
                number bebra;
                cin >> bebra;
                bebraArr.appendElement(bebra);
                bebraArr.print();
                break;
            }
            case 6: {
                break;
            }
            case 5: {
                break;
            }
            case 4: {
                break;
            }
            case 3: {
                break;
            }
            case 2: {
                break;
            }
            case 1: {
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                break;
            }
        }
    }
    return 0;
}


int TApplication::menu() {
    int ch;

    cout << "Salam" << "\n";
    cout << "7 - define array" << "\n";
    cout << "6 - SO" << "\n";
    cout << "5 - SK(V)O" << "\n";
    cout << "4 - sort array" << "\n";
    cout << "3 - change size of array" << "\n";
    cout << "2 - change element of array" << "\n";
    cout << "1 - print array" << "\n";
    cout << "0 - exit" << "\n" << "> ";

    cin >> ch;
    return ch;
}
