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

        if(argument == "--gf"){     // generate file
            
            string fName;
            cout << "Iveskite faila i kuri sugeneruoti: "; cin >> fName;
            fName = fName + ".txt";
            int eilutes, poros, ilgis;
            cout << "Iveskite ilgi eilutes ir poras:"; cin >> ilgis; cin >> eilutes; cin >> poros;
            Generator(ilgis, eilutes, poros, fName);
        }

        if(argument == "--hf"){     // hash file

            vector<string> strings;
            vector<string> h;
            string fName;   double d = 0;

            cout << "Iveskite faila kuri suhashuoti: ";
            cin >> fName;
            fName = fName + ".txt";

            Read(fName, strings);
            for(auto word : strings){
                Hash hash;
                Time t;

                t.start();
                hash.makeHash(word);
                d += t.stop();

                h.push_back(hash.getHash());
            }

            cout << "Hash laikas: " << d << " s" << endl;
            Collision(h);
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

    std::string s;
    s.reserve(l);
    while(l--)
        s += chrs[pick(rg)];

    return s;
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

void App::Write(vector<string> h){

    ofstream fout("output.txt");
    stringstream buffer;

    for(auto words : h){
        buffer << words << endl;
    }

    fout << buffer.str();
    fout.close();

}

void App::Collision(vector<string> &h){

    int match = 0;
    std::unordered_map<string, int> map;
    for(auto s: h){
        if(!map.count(s)){
            map[s] = 1;
        }
        else {
            map[s]++;
            match++;
        }

    }
    cout << "Colission has happened: " << match << " / " << h.size() << endl;

}



