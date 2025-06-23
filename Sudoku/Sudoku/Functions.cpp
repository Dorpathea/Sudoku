// Functions used to play Sudoku
#include <iostream>
#include <vector>
#include <algorithm>
#include <random> 
using namespace std;


// Create a puzzle

// Randomize from 1-9

// Check if the current number is already in the row
bool check_row(vector<vector<int>>& temp, int current_val, int current_col) {

	for (int i = 0; i < 9; i++) {
		if (temp[i][current_col] == current_val) return false;
	}
	return true;
}

// Check if the current number is already in the column
bool check_column(vector<vector<int>>& temp, int current_val, int current_row) {
	for (int j = 0; j < 9; j++) {
		if (temp[current_row][j] == current_val) return false;
	}
	return true;
}

// Check if the current number is already in the box
bool check_box(vector<vector<int>>& temp, int current_val, int current_row, int current_col) {

	int row_val, col_val;

	// More concise way of doing this
	int offset_row = current_row - (current_row % 3);
	int offset_col = current_col - (current_col % 3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			row_val = offset_row + i;
			col_val = offset_col + j;
			if (temp[row_val][col_val] == current_val) return false;
		}
		return true;
	}
}

// Take puzzle in from user
vector<vector<int>> Get_puzzle() {
	int value;
	vector<vector<int>> temp = {{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0},
								{0,0,0,0,0,0,0,0,0} }; // Sudoku puzzle start template

	// Use do while loop for error checking
	cout << "Please Enter the digits of your puzzle: \n";
	cin >> value;

	return temp;
}

// Solve the Sudoku puzzle (used also to create a puzzle)
bool Sudoku_solve(vector<vector<int>>& puzzle, int row = 0, int col = 0, bool remove = false, int ran_row = 0, int ran_col = 0, int ran_val = 0) {

	// Probably don't need this and can change to just remove where mode is
	bool mode = remove;

	// Check if @ end of matrix, if so done!
	if ((row == 8) && (col >= 9)) return true;

	// Check if @ end of row, if so increment row and restart column
	if (col >= 9) {
		row++;
		col = 0;
	}

	// Check if cell already full
	if (puzzle[row][col] != 0) return Sudoku_solve(puzzle, row, (col + 1), mode, ran_row, ran_col, ran_val);

	// For loop: Check if able to place number
	for (int val = 1; val < 10; val++) {
		if (check_row(puzzle, val, col) && check_column(puzzle, val, row) && check_box(puzzle, val, row, col)) {

			// Used to check if we're doing a remove number check (Could probably make this statement connected to the is it safe statement
			if ((remove == false) || ((remove == true) && !((row == ran_row) && (col == ran_col) && (val == ran_val)))) {

				// Set number
				puzzle[row][col] = val;

				// If statement: Recursively iterate with next in row (col + 1)
				if (Sudoku_solve(puzzle, row, (col + 1), mode, ran_row, ran_col, ran_val)) {
					// Return true in loop
					return true;
				}
				// Set matrix value to 0 out of loop to backtrack if needed
				puzzle[row][col] = 0;
			}
		}
	}

	// Return false out of loop
	return false;
}

// Remove numbers in puzzle while still having only 1 solution
bool remove_numbers(int num_remove, int remove_count, vector<vector<int>>& puzzle) {
	// Randomly pick 2 numbers for row and column
	// Remove number at that location and see if any other number works there
	// If one does, put it back to original
	// If one doesn't keep it removed and increment remove count
	// Check if remove count == num_remove (aka we're done)

	int ran_row, ran_col;
	int current_val;

	if (remove_count == num_remove) return true;

	// Pick a random row and column
	ran_row = (rand() % 9);
	ran_col = (rand() % 9);

	// Check if a number has already been removed from this spot
	if (puzzle[ran_row][ran_col] == 0) return remove_numbers(num_remove, remove_count, puzzle);

	current_val = puzzle[ran_row][ran_col];
	puzzle[ran_row][ran_col] = 0;


	// Check if the puzzle can be solved with a different value than the one in the square (more than one solution to the puzzle)
	if (Sudoku_solve(puzzle, 0, 0, true, ran_row, ran_col, current_val)) puzzle[ran_row][ran_col] = current_val;

	// Remove the value if no solution
	else remove_count++;

	// Do again until enough numbers have been removed from the puzzle
	if (remove_count != num_remove) return remove_numbers(num_remove, remove_count, puzzle);

	else return true;

	// return false out of loop
	return false;


}


// Check if the puzzle is not fully filled
bool not_valid(vector<vector<int>>& temp) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (temp[i][j] == 0) return true;
		}
	}
	return false;
}

// Generate a Sudoku puzzle for the user to solve
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


	// Fill in rest of Sudoku puzzle
	Sudoku_solve(temp, 0, 0, false, 0, 0, 0);

	// Remove enough numbers for only one solution at random

	// random number generator to pick location to remove
	// check if it can solve with not using the same removed number
	if (remove_numbers(9, 0, temp)) cout << "DONE!\n";
	else cout << "FAIL!\n";




	// Print current sudoku for error checking
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << temp[i][j];
			cout << " ";
		}
		cout << "\n";
	}

	//if (not_valid(temp)) generate_puzzle();

}



void setup_game();

// Display what the puzzle currently looks like
void display_puzzle();

// Display what value each square is associated with for the user to fill (Might not need if choosing to fill a different way)
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