// Functions used to play Sudoku header file

#pragma once
#include <vector>
using namespace std;

// Create a puzzle

//void generate_puzzle(vector<vector<int>> &correct, vector<vector<int>> &guess);
void generate_puzzle();

//vector<vector<int>> Get_puzzle();

bool Sudoku_solve(vector<vector<int>>& puzzle);

bool not_valid(vector<vector<int>>& temp);

void display_puzzle();

void display_puzzle_map();

void setup_game();

bool check_row(vector<vector<int>>& temp, int current_val, int current_col);

bool check_column(vector<vector<int>>& temp, int current_val, int current_row);

bool check_box(vector<vector<int>>& temp, int current_val, int current_row, int current_col);



// Solve a puzzle

	// Take in a puzzle