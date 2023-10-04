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
	char ac2d_checkerboard[BOARD_ROWS][BOARD_COLS]{ '.' };
}

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void display_2d_array();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	// set each array element to known value
	int num_bytes = BOARD_ROWS * BOARD_COLS;
	memset(cb::ac2d_checkerboard, CH_LITE, num_bytes);

	// display array contents after memset
	display_2d_array();

	// build array of lite and dark squares
	for (int row = 0; row < BOARD_ROWS; ++row) {

		for (int col = 0; col < BOARD_ROWS; ++col) {

			// row even and col odd OR row odd and col even => DARK
			//if (row % 2 == 0 && col % 2 == 1 || row % 2 == 1 && col % 2 == 0)
			if (row % 2 != col % 2)
				cb::ac2d_checkerboard[row][col] = CH_DARK;
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
	cout << "\n\n";
}
