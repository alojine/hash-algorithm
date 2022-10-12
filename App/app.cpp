#include "App.h"

void App::Args(int argc, char **argv)
{
    _argc = argc;
    _argv = argv;
    argument = argv[1];
}

App::~App() {}

void App::run()
{
    // string argument = _argv[1];

    if (_argc > 1)
    {

        if (_argv[0][1] == 'r')
        {

            string s = Random(524);
            cout << s << endl;

            Hash hash;
            Time t;

            t.start();
            hash.makeHash(s);
            double d = t.stop();
    
            cout << hash.getHash() << endl;
            cout << t.stop() << " s" << endl;
        }

        if(argument == "test"){

            string fName;
            vector<string> strings;
            vector<string> h;
            
            cout << "Iveskite failo pavadinima:" << endl;
            cin >> fName;

            Generator(10, 10, 10);
            Read(fName, strings);

            for(auto word : strings){
                Hash hash;
                hash.makeHash(word);
                h.push_back(hash.getHash());
            }
            
            Write(h);
        }

    }
}

string App::Random(int l){

    string c = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz";
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

    cout << "Generator" << endl;
}

void App::Read(string fName, vector<string>& strings){

    string line;
    stringstream buffer;

    ifstream fin(fName);
    buffer << fin.rdbuf();
    fin.close();

    while(buffer){
        if(!buffer.eof()){
            getline(buffer, line);
            strings.push_back(line);
        }
    }

    cout << "Reader" << endl;
} 

void App::Write(vector<string> s){

    cout << "Writer pradzia" << endl;

    ofstream fout("output.txt");
    stringstream buffer;

    for(auto words : s){
        buffer << words << endl;
    }

    fout << buffer.str();
    fout.close();

    cout << "Writer pabaiga" << endl;
}



