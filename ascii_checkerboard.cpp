//------------------------------------------------------------------------------
// ascii_checkerboard.cpp
// 
// - use 2d array to prepare and display ascii art checkerboard
//------------------------------------------------------------------------------
#include <iostream>

// comment to omit debug output
//#define _LCDEBUG

using namespace std;

//------------------------------------------------------------------------------
// constants
//------------------------------------------------------------------------------
constexpr int BOARD_ROWS = 8;
constexpr int BOARD_COLS = 8;

const string MSG_SQUARE_COLOR = " square character? ";

//------------------------------------------------------------------------------
// globals
//------------------------------------------------------------------------------
namespace cb {

	// #TODO will this line init entire array??
	char ac2d_checkerboard[BOARD_ROWS][BOARD_COLS] { '.' };
	char lite { 'O' };
	char dark { 'X' };
}

//------------------------------------------------------------------------------
// local function prototypes
//------------------------------------------------------------------------------
void startup();
char get_user_char(const string&);
void prep_2d_array();
void display_2d_array();

//------------------------------------------------------------------------------
// entry point
//------------------------------------------------------------------------------
int main() {

	startup();
	prep_2d_array();
	display_2d_array();
}

//------------------------------------------------------------------------------
// display app banner, prompt for light and dark chars
//------------------------------------------------------------------------------
void startup() {

	// app banner
	cout << '\n' << BOARD_ROWS << 'x' << BOARD_ROWS << " Checkerboard\n\n";

	// prompt for light and dark square chars
	cb::lite = get_user_char("Light");
	cb::dark = get_user_char("Dark");
}

//------------------------------------------------------------------------------
// get char value from user
//------------------------------------------------------------------------------
char get_user_char(const string& msg) {

	cout << msg << MSG_SQUARE_COLOR;
	char color;
	cin >> color;

	return color;
}

//------------------------------------------------------------------------------
// init 2d array with checkerboard chars
//------------------------------------------------------------------------------
void prep_2d_array() {

	// set all array elements to light square value
	int num_bytes = BOARD_ROWS * BOARD_COLS;
	memset(cb::ac2d_checkerboard, cb::lite, num_bytes);

#ifdef _LCDEBUG
	// display array contents after memset
	display_2d_array();
#endif

	// set dark square elements
	for (int row = 0; row < BOARD_ROWS; ++row) {
		for (int col = 0; col < BOARD_ROWS; ++col) {

			// row even and col odd OR row odd and col even => DARK
			//if (row % 2 == 0 && col % 2 == 1 || row % 2 == 1 && col % 2 == 0)
			if (row % 2 != col % 2)
				cb::ac2d_checkerboard[row][col] = cb::dark;
		}
	}
}

//------------------------------------------------------------------------------
// displays each element of global 2d array of char
//------------------------------------------------------------------------------
void display_2d_array() {

	cout << '\n';

	for (int row = 0; row < BOARD_ROWS; ++row) {
		for (int col = 0; col < BOARD_COLS; ++col) {
			cout << cb::ac2d_checkerboard[row][col];
		}
		cout << '\n';
	}
	cout << '\n';
}
