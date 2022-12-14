#include <iostream>
#include <cstdlib>
#include <algorithm>
#include "../Hash/hash.cpp"
#include "../Time/time.cpp"

static auto& chrs = "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

thread_local static std::mt19937 rg{std::random_device{}()};
thread_local static std::uniform_int_distribution<std::string::size_type> pick(0, sizeof(chrs) - 2);

class App{
    private: //
        int _argc;
        char **argv;
        string argument;

        // methods for testing
        string Random(int l);
        void Generator(int l, int x1, int x2, string fName);
        void Read(string fName, vector<string>& strings);
        void Write(vector<string> s);

    public: // 
        void Args(int argc, char **argv);
        void run();
        ~App();
        

};