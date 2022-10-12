#include "hash.h"
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <random>
#include <bitset>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <fstream>

#define BIT_LENGTH 512
#define HEX_LENGTH 64
#define SINGLE_BITSET 16

Hash::Hash() { str_ = " "; }

Hash::~Hash() { str_.clear(); }

void Hash::setHash(string s)
{
    str_ = s;
}

const string &Hash::getHash() const { return str_; }

int Hash::rightRotate(int n, int d)
{
    return (n << d) | (n >> (HEX_LENGTH - d));
}

int Hash::leftRotate(int n, int d)
{
    return (n >> d) | (n << (HEX_LENGTH - d));
}

string Hash::leftRotate(string str1, int n)
{

    string temp = str1 + str1;
    int l1 = str1.size();
    string Lfirst = temp.substr(n, l1);

    return Lfirst;
}

string Hash::rightRotate(string str1, int n)
{
    return leftRotate(str1, str1.size() - n);
}

const string &Hash::makeHash(string s)
{
    // 1. converting string to binary
    string bitsOfString;
    bitset<8> b; bitset<8> e;
    int reverse = s.length();

    for (std::size_t i = 0; i < s.size(); i++)
    {
        bitset<8> b(s.c_str()[i]);
        bitsOfString += b.to_string();

        bitset<8> e(s.c_str()[reverse]);
        bitsOfString += e.to_string();

        reverse--;
    }


    // 2. make binary 512
    int beforeLength = bitsOfString.length();
    if (bitsOfString.length() < BIT_LENGTH)
        bitsOfString += "1" + string(BIT_LENGTH - (bitsOfString.length() + 1), '0');

    else if(bitsOfString.length() > BIT_LENGTH){
        bitsOfString.substr(bitsOfString.length() - BIT_LENGTH, BIT_LENGTH);
    }


    // 3. mixing bit values
    bitset<16> f; bitset<16> r; bitset<16> connector;
    string cnv;
    int r_back = bitsOfString.length() - beforeLength;

    for (size_t i = beforeLength; i < bitsOfString.length(); i += 16){
        f = ((bitset<16>)rightRotate(bitsOfString.substr(i - beforeLength, SINGLE_BITSET), 13) & (bitset<16>)rightRotate(bitsOfString.substr(i - beforeLength, SINGLE_BITSET), 4) ^ (bitset<16>)rightRotate(bitsOfString.substr(i - beforeLength, SINGLE_BITSET), 9));
        r = (bitset<16>)rightRotate(bitsOfString.substr(r_back, SINGLE_BITSET), 9) & (bitset<16>)leftRotate(bitsOfString.substr(r_back, SINGLE_BITSET), 4) ^ (bitset<16>)rightRotate(bitsOfString.substr(r_back, SINGLE_BITSET), 13);
        connector = (bitset<16>)f.flip(5).flip(9).flip(13).to_string() ^ (bitset<16>)r.flip(13).flip(9).flip(5);
        r_back -= 16;

        cnv += leftRotate(connector.flip(5).flip(9).flip(13).to_string(), 6);
    }

    // 4. mixing final string
    int uniqueValue = 0;
    for(size_t i = 0; i < s.length(); i++){
        uniqueValue += (int)s[i];
    }

    unsigned seed = uniqueValue;
    srand(seed);

    int strLength = cnv.length();
    int len = strLength - 1;

    for(int i = 0; i < len; ++i) {
        int random_index = rand() % len;
        cnv[i] = cnv[i] + cnv[random_index] - (cnv[random_index] = cnv[i]); // we just swap two letters each time
    }


    // 5. converting binary to hex
    cnv = binToHex(cnv);

    for(size_t i = 0; i < 63; i++){
       str_ += cnv.at(i);
    }

};

string Hash::binToHex(string s)
{
    // converting binary to hex
    string bitsOfString = s;
    string hexOfString = "", temp;
    for (std::size_t i = 0; i < bitsOfString.size(); i += 4)
    {

        temp.append(1, bitsOfString[i]);
        temp.append(1, bitsOfString[i + 1]);
        temp.append(1, bitsOfString[i + 2]);
        temp.append(1, bitsOfString[i + 3]);

        if (temp == "0000")
            hexOfString += "0";
        else if (temp == "0001")
            hexOfString += "1";
        else if (temp == "0010")
            hexOfString += "2";
        else if (temp == "0011")
            hexOfString += "3";
        else if (temp == "0100")
            hexOfString += "4";
        else if (temp == "0101")
            hexOfString += "5";
        else if (temp == "0110")
            hexOfString += "5";
        else if (temp == "0111")
            hexOfString += "6";
        else if (temp == "0111")
            hexOfString += "7";
        else if (temp == "1000")
            hexOfString += "8";
        else if (temp == "1001")
            hexOfString += "9";
        else if (temp == "1010")
            hexOfString += "a";
        else if (temp == "1011")
            hexOfString += "b";
        else if (temp == "1100")
            hexOfString += "c";
        else if (temp == "1101")
            hexOfString += "d";
        else if (temp == "1110")
            hexOfString += "e";
        else if (temp == "1111")
            hexOfString += "f";

        temp = "";
    }

    return hexOfString;
}
