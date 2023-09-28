//------------------------------------------------------------------------------
// ascii_checkerboard.cpp
// 
// - use 2d array to prepare and display ascii art checkerboard
//------------------------------------------------------------------------------
#include <iostream>

using namespace std;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int BOARD_ROWS = 8;
constexpr int BOARD_COLS = 8;

constexpr char CH_DARK = 'X';
constexpr char CH_LITE = 'O';

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
namespace cb {

	// #TODO will this line init entire array??
	char a2d_checkerboard[BOARD_ROWS][BOARD_COLS]{ '.' };
}

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void display_2d_array();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	// display initial array contents
	display_2d_array();

	// set each array element to known value
	memset(cb::a2d_checkerboard, CH_LITE, BOARD_ROWS * BOARD_COLS);

	// display array contents after memset
	display_2d_array();

	// build array of lite and dark squares
	for (int row = 0; row < BOARD_ROWS; ++row) {

		for (int col = 0; col < BOARD_ROWS; ++col) {

			// row even and col odd OR row odd and col even => DARK
			//if (row % 2 == 0 && col % 2 == 1 || row % 2 == 1 && col % 2 == 0)
			if (row % 2 != col % 2)
				cb::a2d_checkerboard[row][col] = CH_DARK;
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
			cout << cb::a2d_checkerboard[row][col];
		}
		cout << '\n';
	}
	cout << "\n\n";
}
