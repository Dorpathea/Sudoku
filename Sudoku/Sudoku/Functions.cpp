// Functions used to play Sudoku
#include <iostream>
#include <vector>
#include <algorithm>
#include <random> 
using namespace std;

// Create a puzzle


bool check_row(vector<vector<int>>& temp, int current_val, int current_col) {

	for (int i = 0; i < 9; i++) {
		if (temp[i][current_col] == current_val) return false;
	}
	return true;
}

bool check_column(vector<vector<int>>& temp, int current_val, int current_row) {
	for (int j = 0; j < 9; j++) {
		if (temp[current_row][j] == current_val) return false;
	}
	return true;
}

bool check_box(vector<vector<int>>& temp, int current_val, int current_row, int current_col) {

	int offset_col, offset_row, row_val, col_val;

	switch (current_row) {
	case(0):
	case(3):
	case(6):
		offset_row = 0;
		break;
	case(1):
	case(4):
	case(7):
		offset_row = 1;
		break;
	case(2):
	case(5):
	case(8):
		offset_row = 2;
		break;
	}
	switch (current_col) {
	case(0):
	case(3):
	case(6):
		offset_col = 0;
		break;
	case(1):
	case(4):
	case(7):
		offset_col = 1;
		break;
	case(2):
	case(5):
	case(8):
		offset_col = 2;
		break;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			row_val = current_row - offset_row + i;
			col_val = current_col - offset_col + j;
			if (temp[row_val][col_val] == current_val) return false;
		}
		return true;
	}
}

bool not_valid(vector<vector<int>>& temp) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (temp[i][j] == 0) return true;
		}
	}
	return false;
}

//void generate_puzzle(vector<vector<int>> &correct, vector<vector<int>> &guess) {
void generate_puzzle() {

	// Variables
	vector<int> set = {1,2,3,4,5,6,7,8,9};
	int t1, t2, t3;


	// Set temp to correct
	vector<vector<int>> temp = {{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0} }; // Sudoku puzzle start template

	// To obtain a time based random seed
	// GeeksforGeeks
	unsigned seed = time(0);
	srand(seed);

	// Suffle elements of 9x9 squares on the diagonal (they don't interact with each other)
	for (int i = 0; i < 3; i++) {

		random_shuffle(set.begin(), set.end());

		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				t1 = j + (i * 3);
				t2 = k + (i * 3);
				t3 = k + (j * 3);
				temp[t1][t2] = set[t3];
			}
		}
	}

	// Fill in rest of puzzle
	for (int row = 0; row < 9; row++) {
		for (int col = 0; col < 9; col++) {
			for (int val = 1; val < 10; val++) {
				if (check_row(temp, val, col) && check_column(temp, val, row) && check_box(temp, val, row, col) && (temp[row][col] == 0)) {
					temp[row][col] = val;
				}
			}
		}
	}


	// Print current sudoku for error checking
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << temp[i][j];
			cout << " ";
		}
		cout << "\n";
	}

	if (not_valid(temp)) generate_puzzle();

}



void setup_game();

void display_puzzle();

void display_puzzle_map() {
	/*std::cout << "----------------------------\n";
	std::cout << "|01|02|03|04|05|06|07|08|09|\n";
	std::cout << "----------------------------\n";
	std::cout << "|10|11|12|13|14|15|16|17|18|\n";
	std::cout << "----------------------------\n";
	std::cout << "|19|20|21|22|23|24|25|26|27|\n";
	std::cout << "----------------------------\n";
	std::cout << "|28|29|30|31|32|33|34|35|36|\n";
	std::cout << "----------------------------\n";
	std::cout << "|37|38|39|40|41|42|43|44|45|\n";
	std::cout << "----------------------------\n";
	std::cout << "|46|47|48|49|50|51|52|53|54|\n";
	std::cout << "----------------------------\n";
	std::cout << "|55|56|57|58|59|60|61|62|63|\n";
	std::cout << "----------------------------\n";
	std::cout << "|64|65|66|67|68|69|70|71|72|\n";
	std::cout << "----------------------------\n";
	std::cout << "|73|74|75|76|77|78|79|80|81|\n";
	std::cout << "----------------------------\n";

	std::cout << "\n\n\n";*/


	/*std::cout << "------------------------------------\n";
	std::cout << "____________________________________\n";
	std::cout << "| |01|02|03| |04|05|06| |07|08|09| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "| |10|11|12| |13|14|15| |16|17|18| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "| |19|20|21| |22|23|24| |25|26|27| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "____________________________________\n";
	std::cout << "| |28|29|30| |31|32|33| |34|35|36| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "| |37|38|39| |40|41|42| |43|44|45| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "| |46|47|48| |49|50|51| |52|53|54| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "____________________________________\n";
	std::cout << "| |55|56|57| |58|59|60| |61|62|63| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "| |64|65|66| |67|68|69| |70|71|72| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "| |73|74|75| |76|77|78| |79|80|81| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "------------------------------------\n";


	std::cout << "\n\n\n";

	std::cout << "------------------------------------\n";
	std::cout << "____________________________________\n";
	std::cout << "| |A1|A2|A3| |B1|B2|B3| |C1|C2|C3| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "| |A4|A5|A6| |B4|B5|B6| |C4|C5|C6| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "| |A7|A8|A9| |B7|B8|B9| |C7|C8|C9| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "____________________________________\n";
	std::cout << "| |D1|D2|D3| |E1|E2|E3| |F1|F2|F3| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "| |D4|D5|D6| |E4|E5|E6| |F4|F5|F6| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "| |D7|D8|D9| |E7|E8|E9| |F7|F8|F9| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "____________________________________\n";
	std::cout << "| |G1|G2|G3| |H1|H2|H3| |I1|I2|I3| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "| |G4|G5|G6| |H4|H5|H6| |I4|I5|I6| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "| |G7|G8|G9| |H7|H8|H9| |I7|I8|I9| |\n";
	std::cout << "------------------------------------\n";
	std::cout << "------------------------------------\n";


	std::cout << "\n\n\n";

	std::cout << "---------------------------\n";
	std::cout << "|    A       B       C    |\n";
	std::cout << "___________________________\n";
	std::cout << "| |1|2|3| |1|2|3| |1|2|3| |\n";
	std::cout << "---------------------------\n";
	std::cout << "| |4|5|6| |4|5|6| |4|5|6| |\n";
	std::cout << "---------------------------\n";
	std::cout << "| |7|8|9| |7|8|9| |7|8|9| |\n";
	std::cout << "---------------------------\n";
	std::cout << "|    D       E       F    |\n";
	std::cout << "___________________________\n";
	std::cout << "| |1|2|3| |1|2|3| |1|2|3| |\n";
	std::cout << "---------------------------\n";
	std::cout << "| |4|5|6| |4|5|6| |4|5|6| |\n";
	std::cout << "---------------------------\n";
	std::cout << "| |7|8|9| |7|8|9| |7|8|9| |\n";
	std::cout << "---------------------------\n";
	std::cout << "|    G       H       I    |\n";
	std::cout << "___________________________\n";
	std::cout << "| |1|2|3| |1|2|3| |1|2|3| |\n";
	std::cout << "---------------------------\n";
	std::cout << "| |4|5|6| |4|5|6| |4|5|6| |\n";
	std::cout << "---------------------------\n";
	std::cout << "| |7|8|9| |7|8|9| |7|8|9| |\n";
	std::cout << "---------------------------\n";
	std::cout << "---------------------------\n";*/


}


// Solve a puzzle

	// Take in a puzzle