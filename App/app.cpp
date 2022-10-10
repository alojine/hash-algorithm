#include "App.h"

App::App() { runner = 0; }

App::~App() { runner = 0; }

void App::run() {

    string s = "";

    cout << "Iveskite zodi: " << endl;
    cin >> s;

    Hash hash;
    Time t;

    t.start();
    hash.makeHash(s);
    double d = t.stop();

    cout << hash.getHash() << endl;
    cout << t.stop() << " s" << endl;

}