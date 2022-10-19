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

        if(argument == "--gp"){     // generate file
            
            string fName;
            cout << "Iveskite faila i kuri sugeneruoti: "; cin >> fName;
            fName = fName + ".txt";
            int eilutes, poros, ilgis;
            cout << "Iveskite ilgi eilutes ir poras:"; cin >> ilgis; cin >> eilutes; cin >> poros;
            GeneratorPair(ilgis, eilutes, poros, fName);
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

        if (argument == "--ta"){
            vector<string> strings;
            vector<string> h;
            string fName;   double d = 0;

            cout << "Iveskite faila kuri suhashuoti: ";
            cin >> fName;
            fName = fName + ".txt";
            
            Read(fName, strings);

            vector<double> percentages;

            for(int i = 0; i < strings.size(); i++){
                
                int count = 0;

                if(i != 0){
                    // previous
                    Hash hash1;
                    hash1.makeHash(strings.at(i - 1));
                    string prev = hash1.getHash();

                    // current
                    Hash hash2;
                    hash2.makeHash(strings.at(i));
                    string curr = hash2.getHash();

                    // cout << hash1.getHash() << endl;
                    // cout << hash2.getHash() << endl;

                    for(int j = 0; j < 64; j++){
                        if(prev[j] == curr[j])
                            count++;
                    }
                }

                double perc = count * 100 / 64;
                percentages.push_back(perc);
                // cout << perc << "%" << endl;
            }

            double min = percentages[0]; double max = percentages[0];
            double avg = 0;
            for(int i = 0 ; i < percentages.size(); i++){
                avg += percentages.at(i);
                if(percentages.at(i) > max) max = percentages.at(i);
                if(percentages.at(i) < min) min = percentages.at(i);
            }

            cout << endl;
            cout << "Didziausias sutapimas: " << std::fixed << setprecision(2) << max << "%" << endl;
            cout << "Maziausias sutapimas: " << std::fixed << setprecision(2) << min << "%" << endl;
            cout << "Vidutinis sutapimas: " << std::fixed << setprecision(2) << avg/percentages.size() << "%" << endl;

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

void App::GeneratorPair(int l, int x1, int x2, string fName){

    string line;
    ofstream fout(fName);
    stringstream buffer;
    string word1, word2;
    for(int i = 0; i < x1; i++){
        for(int j = 0; j < x2; j++){
            word1 = Random(l);
            word2 = word1;
            for(int i = 0; i < 3; i++){
                word2[i] = '5';
            }
            
            buffer << word1 << " " << word2;
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

void App::Avalanche(vector<string>& h){
    
}


