#include "hash.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <random>
#include <chrono>
#include <bitset>
#include <vector>
// #include <bit>

#define INT_BITS 64

Hash::Hash(){ str_ = " " ;}

Hash::~Hash(){ str_.clear(); }

void Hash::setHash(string s){
    str_ = s;
}

const string &Hash::getHash() const { return str_; }

int Hash::rightRotate(int n, int d){
    return (n << d) | (n >> (INT_BITS - d));
}

int Hash::leftRotate(int n, int d){
    return (n >> d) | (n << (INT_BITS - d));
}

string Hash::leftRotate(string str1, int n){

    string temp = str1 + str1;
    int l1 = str1.size();
    string Lfirst = temp.substr(n, l1);

    return Lfirst;
}

string Hash::rightRotate(string str1, int n){
    return leftRotate(str1, str1.size() - n);
}


const string &Hash::makeHash(string s){

    string bitsOfString;
    bitset<8> b; bitset<8> e;
    int reverse = s.size();
    int random_int = 8;

    for(std::size_t i = 0; i < s.size(); i++){
        
        
        std::bitset<8> b(s.c_str()[i]);
        bitsOfString += b.flip().to_string();

        std::bitset<8> e(s.c_str()[reverse]);
        bitsOfString += e.to_string();


        int l = bitsOfString.length();
        reverse--;
    }

    cout << bitsOfString << endl;

    bitsOfString = rightRotate(bitsOfString, bitsOfString.length() - random_int);
    bitsOfString = rightRotate(bitsOfString, bitsOfString.length() - random_int - random_int);

    cout << bitsOfString << endl;



    // converting binary to hex
    string hexOfString = "", temp;
    for(std::size_t i = 0; i < bitsOfString.size(); i += 4){

        temp.append(1, bitsOfString[i]);
        temp.append(1, bitsOfString[i+1]);
        temp.append(1, bitsOfString[i+2]);
        temp.append(1, bitsOfString[i+3]);
        
        if(temp == "0000")
            hexOfString += "0";
        else if(temp == "0001")
            hexOfString += "1";
        else if(temp == "0010")
            hexOfString += "2";
        else if(temp == "0011")
            hexOfString += "3";
        else if(temp == "0100")
            hexOfString += "4";
        else if(temp == "0101")
            hexOfString += "5";
        else if(temp == "0110")
            hexOfString += "5";
        else if(temp == "0111")
            hexOfString += "6";
        else if(temp == "0111")
            hexOfString += "7";
        else if(temp == "1000")
            hexOfString += "8";
        else if(temp == "1001")
            hexOfString += "9";
        else if(temp == "1010")
            hexOfString += "a";
        else if(temp == "1011")
            hexOfString += "b";
        else if(temp == "1100")
            hexOfString += "c";
        else if(temp == "1101")
            hexOfString += "d";
        else if(temp == "1110")
            hexOfString += "e";
        else if(temp == "1111")
            hexOfString += "f";

        temp = "";

    }

    str_ = hexOfString;

};

