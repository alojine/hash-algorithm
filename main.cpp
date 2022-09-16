#include <iostream>
#include <string>
#include <fstream>
#include "hash.h"

using namespace std;


// 256 bits long

int main () {

    cout << "Ar noretumete hashuoti faila? (y/n)" << endl;
    char choice;
    cin >> choice;

    if(choice == 'y') {
        string file;
        cout << "Iveskite failo pavadinima: " << endl;
        cin >> file;

        string value;
        ifstream fr(file);
        ofstream fw(file);
        fr >> value;
        cout << value;
        

    } else {

    }
    



    return 0;
}