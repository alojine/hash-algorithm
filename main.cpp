#include <iostream>
#include <string>
#include <fstream>
#include "hash.cpp"
#include "time.cpp"

using namespace std;



int main(){

    string s = "";

    cout << "Iveskite zodi: " << endl;
    cin >> s;

    Hash hash;
    Time t;

    t.start();
    hash.makeHash(s);
    double d = t.stop();

    cout << hash.getHash() << endl;
    cout << t.stop() << endl;


    return 0;
}

