// Dorothy Harris
// 05-31-2025
// Code to either play a game of Sudoku or input and solve a sudoku puzzle
// Referenced in part from GeeksforGeeks
// https://www.geeksforgeeks.org/program-sudoku-generator/


#include <iostream>
#include <vector>
#include "Functions.hpp"
using namespace std;


int main()
{
    int choice = 0;
    int option = 0;
    int misses = 0;


    vector<vector<int>> puzzle_correct = { {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0}}; // Correct Sudoku puzzle

    vector<vector<int>> puzzle_guess = {   {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0},
                                           {0,0,0,0,0,0,0,0,0} }; // Player guesssed Sudoku puzzle


    // Menu: Ask to play a game or solve a puzzle or quit
    cout << "Welcome to Sudoku Puzzle! Would you like to, 1: Play a game of Sudoku, 2: Solve a puzzle, or 3: Quit?\n";

    cin >> choice;

    // Checking for valid input
    while ((cin.fail()) || (choice > 3) || (choice == 0)) {
        cout << "Not a valid decision. Type 1, 2, or 3.\n";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> choice;
    }

    switch (choice) {

    // Play a game
    case(1):
        cout << "Let's Play a Game!\n";

        //generate_puzzle(puzzle_correct, puzzle_guess);
        generate_puzzle();

        //setup_game();

        //display_puzzle();

        cout << "Select which square you'd like to change.\n";

        display_puzzle_map();

        cin >> option;

        // Checking for valid input
        while ((cin.fail()) || (option > 81) || (option == 0)) {
            cout << "Not a valid decision. Select which square you'd like to change.\n";
            display_puzzle_map();
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> option;
        }



        break;

    // Solve a puzzle
    case(2):
        cout << "Let's Solve a Puzzle!\n";

        //puzzle_correct = Get_puzzle();

        //Sudoku_solve(puzzle_correct);

        break;

    // Quit
    case(3):
        cout << "Exiting out of Sudoku Puzzle.\n";
        return 0;
    }



}

