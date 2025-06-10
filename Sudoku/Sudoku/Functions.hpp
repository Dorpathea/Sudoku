// Functions used to play Sudoku header file

#pragma once
#include <vector>


// Create a puzzle


//void generate_puzzle(vector<vector<int>> &correct, vector<vector<int>> &guess);
void generate_puzzle();

void display_puzzle();

void display_puzzle_map();

void setup_game();

bool check_row(int value);

bool check_column(int value);

bool check_box(int value);


// Solve a puzzle

	// Take in a puzzle