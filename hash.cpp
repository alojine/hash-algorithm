#include "hash.h"

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

void Hash::fileHash() {

    

 }
