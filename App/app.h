#include <iostream>
#include "../Hash/hash.cpp"
#include "../Time/time.cpp"

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