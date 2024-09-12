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
        cin.clear(); // Clearing the input stream from possible errors
        cin.sync();
        ch = menu();

        switch (ch) {
            case 7: {
                number bebra;
                cin >> bebra;

                if (!cin.good()) {
                    cout << "\nYou entered an incorrect value\n";
                    continue;
                }

                bebraArr.appendElement(bebra); // TODO: сделать норм инициализацию
                bebraArr.print();
                break;
            }
            case 6: {
                cout <<"Medium value: " << bebraArr.mediumValue() << "\n";
                break;
            }
            case 5: {
                cout << "SKO (standard deviation): " << bebraArr.standardDeviation() << "\n";
                break;
            }
            case 4: {
                short int sCh = 0;

                cout << "0. ascending order" << "\n";
                cout << "1. descending order" << "\n";
                cin >> sCh;

                if (!cin.good()) {
                    cout << "\nYou entered an incorrect value\n";
                    continue;
                }

                if (!sCh) {
                    bebraArr.sort();
                }
                else {
//                    bebraArr.reverseSort(); // TODO: починить
                }

                bebraArr.print();
                break;
            }
            case 3: {
                break;
            }
            case 2: {
                unsigned index;
                number value;

                cout << "index: ";
                cin >> index;
                if (!cin.good()) {
                    cout << "\nYou entered an incorrect value\n";
                    continue;
                }
                cout << "\n" << "value: ";
                cin >> value;
                if (!cin.good()) {
                    cout << "\nYou entered an incorrect value\n";
                    continue;
                }
                cout << "\n";
                bebraArr.replaceElement(index, value);
                break;
            }
            case 1: {
                bebraArr.print();
                break;
            }
            case 0: {
                return 0;
            }
            default: {
                cout << "\n" << "There is no case with this number" << "\n";
                break;
            }
        }
    }
    return 0;
}


int TApplication::menu() {
    int ch;

    cout << "Operations:" << "\n";
    cout << "7 - define array" << "\n";
    cout << "6 - SO" << "\n";
    cout << "5 - SK(V)O" << "\n";
    cout << "4 - sort array" << "\n";
    cout << "3 - change size of array" << "\n";
    cout << "2 - change element of array" << "\n";
    cout << "1 - print array" << "\n";
    cout << "0 - exit" << "\n" << "> ";

    cin >> ch;
    if (!cin.good()) return -1;

    return ch;
}
