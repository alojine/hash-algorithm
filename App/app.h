#include <iostream>
#include "../Hash/hash.cpp"
#include "../Time/time.cpp"

class App{
    private: //
        int runner = 0;
        Time t;
        Hash h;


    public: // 
        App();
        ~App();

        void run();

};