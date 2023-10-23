//------------------------------------------------------------------------------
// a3_1d_toy.cpp
//
// a start on checkerboard code for Assignment 3 with 1d array 
//------------------------------------------------------------------------------

#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int COLS = 8;

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

    char ac[COLS]{ };

    for (int k = 0; k < COLS; k++) {

        if (k % 2 != 0) {
            // dark square
            ac[k] = 'X';

            cout << "Index " << k << " is odd so X goes in this element\n";
        }
        else {
            // lite square
            ac[k] = 'O';

            cout << "Index " << k << " is even so O goes in this element\n";
        }
    }

    cout << "Goodbye!\n";

    return 0;
}
