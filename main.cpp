#include <iostream>
#include "calc.h"

using namespace std;

int main(int argc , char *argv[]) {
    if (argc != 2) {
        cout << "Error: Too many args, need only one, use "" to fix that" << endl;
        return 1;
    }
    try {
        cout << calc(argv[1]) << endl;
    }
    catch (struct Exception &e) {
        cout << e.message << endl;
        return 1;
    }
    catch (...) {
        cout << "Unknown error" << endl;
        return 1;
    }


    return 0;
}