#include <iostream>
#include "App/app.cpp"

using namespace std;



int main(int argc, char **argv){

    App app;
    app.Args(argc, argv);
    app.run();

    return 0;
}

