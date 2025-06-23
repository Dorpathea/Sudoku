// Functions used to play Sudoku header file

#pragma once
#include <vector>
using namespace std;

// Create a puzzle

// Generate a Sudoku puzzle for the user to solve
//void generate_puzzle(vector<vector<int>> &correct, vector<vector<int>> &guess);
void generate_puzzle();

// Take puzzle in from user
//vector<vector<int>> Get_puzzle();

// Solve the Sudoku puzzle (used also to create a puzzle)
bool Sudoku_solve(vector<vector<int>>& puzzle, int row = 0, int col = 0, bool remove = false, int ran_row = 0, int ran_col = 0, int ran_val = 0);

// Check if the puzzle is not fully filled
bool not_valid(vector<vector<int>>& temp);

// Display what the puzzle currently looks like
void display_puzzle();

// Display what value each square is associated with for the user to fill (Might not need if choosing to fill a different way)
void display_puzzle_map();

void setup_game();

// Check if the current number is already in the row
bool check_row(vector<vector<int>>& temp, int current_val, int current_col);

// Check if the current number is already in the column
bool check_column(vector<vector<int>>& temp, int current_val, int current_row);

// Check if the current number is already in the box
bool check_box(vector<vector<int>>& temp, int current_val, int current_row, int current_col);

// Remove numbers in puzzle while still having only 1 solution
bool remove_numbers(int num_remove, int remove_count, vector<vector<int>>& puzzle);



// Solve a puzzle

	// Take in a puzzle