#ifndef HASH_H
#define HASH_H

#include <iostream>

using namespace std;

class Hash{
    private:
        std::string str_;
        char ch_;
    
    public:
        Hash();     //default c
        ~Hash();    //destructor

        void setHash(std::string);  // setter
        const string& getHash() const;  // getter


        const string& makeHash(std::string);


};

#endif