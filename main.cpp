#include <iostream>
#include <string>
#include <fstream>
#include "hash.cpp"

using namespace std;


int main () {


    Hash hash;

    string s = "Helloworld!";

    hash.makeHash(s);

    cout << hash.getHash() << endl;



    return 0;
}