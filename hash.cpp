#include "hash.h"
#include <iomanip>
#include <sstream>
#include <string>
#include <random>
#include <chrono>

// random gen
using hrClock = std::chrono::high_resolution_clock;
using durationDouble = std::chrono::duration<double>;

Hash::Hash(){ str_ = " " ;}

Hash::~Hash(){ str_.clear(); }

void Hash::setHash(string s){
    str_ = s;
}

const string &Hash::getHash() const { return str_; }

const string &Hash::makeHash(string s){

    bool upper_case = true;
    ostringstream ret;
    string first;

    for (string::size_type i = 0; i < s.length(); ++i)
        ret << std::hex << std::setfill('0') << std::setw(2) << (upper_case ? std::uppercase : std::nouppercase) << (int)s[i];

    str_ = ret.str(); 
    first = ret.str();








    
    // grazinamas
    // return ret.str();
    
};