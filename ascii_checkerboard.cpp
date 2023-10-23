//------------------------------------------------------------------------------
// ascii_checkerboard.cpp
// 
// - use 2d array to prepare and display ascii art checkerboard
//------------------------------------------------------------------------------
#include "ansi_colors.h"
#include <iostream>
#include <sstream>

// comment to omit debug output
#define _MYDEBUG

using namespace std;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int BOARD_ROWS = 8;
constexpr int BOARD_COLS = 8;

// make each square 2 chars wide
const string STR_INVISIBLE = "  ";

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
namespace cb {

	// #TODO will this line init entire array??
	string ac2d_checkerboard[BOARD_ROWS][BOARD_COLS];
}

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void display_2d_array();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	stringstream ss_lite;
	ss_lite << FG_CYAN << BG_CYAN << STR_INVISIBLE;
	stringstream ss_dark;
	ss_dark << FG_RED << BG_RED << STR_INVISIBLE;

	for (int row = 0; row < BOARD_ROWS; row++) {
		for (int col = 0; col < BOARD_ROWS; col++) {
			cb::ac2d_checkerboard[row][col] = ss_lite.str();
		}
	}

#ifdef _MYDEBUG
	// display array contents after memset
	display_2d_array();
#endif

	// build array of lite and dark squares
	for (int row = 0; row < BOARD_ROWS; ++row) {

		for (int col = 0; col < BOARD_ROWS; ++col) {

			// row even and col odd OR row odd and col even => DARK
			//if (row % 2 == 0 && col % 2 == 1 || row % 2 == 1 && col % 2 == 0)
			if (row % 2 != col % 2)
				cb::ac2d_checkerboard[row][col] = ss_dark.str();
		}
	}

	// display array contents after checkerboarding
	display_2d_array();

	return 0;

}

//------------------------------------------------------------------------------
// displays each element of global 2d array of char
//------------------------------------------------------------------------------
void display_2d_array() {

	for (int row = 0; row < BOARD_ROWS; ++row) {
		for (int col = 0; col < BOARD_COLS; ++col) {
			cout << cb::ac2d_checkerboard[row][col];
		}
		cout << '\n';
	}
	cout << RESET << "\n\n";
}
