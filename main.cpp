#include <iostream>
#include <string>
#include <fstream>
#include "hash.cpp"

using namespace std;

int main()
{

    string s = "helloworld";

    Hash hash;

    hash.makeHash(s);
    cout << hash.getHash() << endl;


    return 0;
}