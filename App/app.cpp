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

    if (_argc > 1)
    {

        if(argument == "--gf"){
            // ilgis eilutes zodziai
            cout << "i kuri faila sugeneruoti: " << endl;
            string fName;
            cin >> fName;
            Generator(10, 2, 1, fName);
        }

        if (argument == "--sw") // single word
        {

            string s = "";
            cout << "Iveskite zodi" << endl;
            cin >> s;
            Hash hash;
            Time t;

            t.start();
            hash.makeHash(s);
            double d = t.stop();
    
            cout << hash.getHash() << endl;
            cout << t.stop() << " s" << endl;
        }

        if(argument == "--ts"){

            string fName, fName2;
            vector<string> strings;
            vector<string> h;
            
            cout << "skaityti faila:" << endl;
            cin >> fName;

            cout << "rasyti faila:" << endl;
            cin >> fName2;

            Generator(10, 10, 10, fName2);
            Read(fName, strings);

            for(auto word : strings){
                Hash hash;
                hash.makeHash(word);
                h.push_back(hash.getHash());
            }
            
            Write(h);
        }

        if(argument == "--kt"){     // konstitucija
            string fName = "konstitucija.txt";
            vector<string> strings;
            vector<string> h;

            Read(fName, strings);

            double d = 0;

            for(auto word : strings){
                Hash hash;
                Time t;

                t.start();
                hash.makeHash(word);
                d += t.stop();

                h.push_back(hash.getHash());
            }
            
            cout << d << endl;

        }

    }
}

string App::Random(int l){

    // string c = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnopqrstuvwxyz";
    // std::random_device random_device;
    // std::mt19937 gen(random_device());
    // std::uniform_int_distribution<int> distribution(0, c.size() - 1);

    // string s;

    // for(std::size_t i = 0; i < l; i++){
    //     s += c[distribution(gen)];
    // }

    // return s;
    srand((unsigned)time(NULL));
    // srand((unsigned)time(NULL) * getpid());
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";
    std::string tmp_s;
    tmp_s.reserve(l);

    for (int i = 0; i < l; ++i) {
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    
    return tmp_s;

}

void App::Generator(int l, int x1, int x2, string fName){

    string line;
    ofstream fout(fName);
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

    // for(int i = 0; i < 512; i++){
    //     getline(buffer, line);
    //     strings.push_back(line);
    // }

} 

void App::Write(vector<string> s){


    ofstream fout("output.txt");
    stringstream buffer;

    for(auto words : s){
        buffer << words << endl;
    }

    fout << buffer.str();
    fout.close();

}



