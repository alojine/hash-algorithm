#include <iostream>
#include "../Hash/hash.cpp"
#include "../Time/time.cpp"

class App{
    private: //
        Time t;
        Hash h;
        int _argc;
        char **_argv;

        // methods for testing
        string Random(int l);
        void Generator(int l, int );

    public: // 
        void Args(int argc, char **argv);
        void run();
        ~App();
        

};