#include "App.h"

void App::Args(int argc, char **argv)
{
    _argc = argc;
    _argv = argv;
}

App::~App() {}

void App::run()
{

    if (_argc > 1)
    {

        if (_argv[1][0] == 'R')
        {

            string fName;
            cout << "Iveskite failo pavadinima: " << endl;
            cin >> fName;

            string s = Random(16);
            cout << s << endl;

            Hash hash;
            Time t;

            t.start();
            hash.makeHash(s);
            double d = t.stop();
    
            cout << hash.getHash() << endl;
            cout << t.stop() << " s" << endl;
        }

    }
}

string App::Random(int l){

    const string c = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz";
    std::random_device random_device;
    std::mt19937 gen(random_device());
    std::uniform_int_distribution<> distribution(0, c.size() - 1);

    string s;

    for(std::size_t i = 0; i < l; i++){
        s += c[distribution(gen)];
    }

    return s;
}

void App::Generator(int l, int x1, int x2){

    string line;
    ofstream fout("text.txt");
    stringstream buffer;

    for(int i = 0; i < x1; i++){
        for(int j = 0; j < x2; j++){
            buffer << Random(l);
            if(j + 1 != x2) buffer << " ";
        }
        if(i + 1 != x1) buffer << endl;
    }
    fout << buffer.str() << endl;
    fout.close();
}

