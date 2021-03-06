/*
	Zach Hofmeister		1/28/19
	ticTacToe			A game of tic-tac-toe made for two players.
*/

#include "pch.h"
#include <iostream>

using namespace std;

void printTable(char table[3][3]);	//Prints out the game board in it's current state.
char detectWin(char table[3][3]);	//Detects if any winning combination has been played, if the game results in a draw, or if the game can continue.

int main() {
	int turn = 0; //Keeps track of the number of turns played, and which player's turn it is.
	char table[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} }; //Empty tic-tac-toe array
	cout << "Welcome to Tic-Tac-Toe!" << endl;
	cout << "=======================" << endl;

	do { //do-while loop for turns
		cout << endl;
		int row, column; //holds player input
		cout << "Player " << (turn % 2 == 0 ? '1' : '2') << "\'s turn \'" << (turn % 2 == 0 ? 'X' : 'O') << "\'" << endl;
		printTable (table);
		cout << "What row and column would you like? Seperate them with a space: ";
		cin >> row >> column; //Accepts player input for row/column

		if (table[row][column] == ' ') { //If the space is empty, populate it and record the turn.
			table[row][column] = (turn % 2 == 0 ? 'X' : 'O');
			turn++;
		} else { //Loops again if the chosen space is occupied or the player selects a space that is out-of-bounds.
			cout << "Invalid move. Please choose another space." << endl;
		}
	} while (detectWin(table) == ' '); //Continue to loop as long as there is no winner and empty spaces.

	cout << endl <<  "Game over!" << endl;
	printTable(table);
	if (detectWin(table) == 'C') {
		cout << "Cat's game! Nobody wins! Better luck next time!" << endl;
	} else {
		cout << "Player " << (detectWin(table) == 'X' ? '1' : '2') << " wins!" << endl;
	}

	return 0;
}

void printTable(char table[3][3]) {	//Prints out the tic-tac-toe chart, takes the tic-tac-toe array as an input.
	cout << "\t   0 1 2" << endl;
	cout << "\t 0 " << table[0][0] << '|' << table[0][1] << '|' << table[0][2] << endl;
	cout << "\t   " << "-----" << endl;
	cout << "\t 1 " << table[1][0] << '|' << table[1][1] << '|' << table[1][2] << endl;
	cout << "\t   " << "-----" << endl;
	cout << "\t 2 " << table[2][0] << '|' << table[2][1] << '|' << table[2][2] << endl;
}

/*Detects if any winning combination has been played, if the game results in a draw, or if the game can continue,
	and returns that result in the form of a char.*/
char detectWin(char table[3][3]) {
	if (table[0][0] != ' ' && table[0][0] == table[0][1] && table[0][1] == table[0][2]) {
		return table[0][0];
	} else if (table[1][0] != ' ' && table[1][0] == table[1][1] && table[1][1] == table[1][2]) {
		return table[1][0];
	} else if (table[2][0] != ' ' && table[2][0] == table[2][1] && table[2][1] == table[2][2]) {
		return table[2][0];
	} else if (table[0][0] != ' ' && table[0][0] == table[1][0] && table[1][0] == table[2][0]) {
		return table[0][0];
	} else if (table[0][1] != ' ' && table[0][1] == table[1][1] && table[1][1] == table[2][1]) {
		return table[0][1];
	} else if (table[0][2] != ' ' && table[0][2] == table[1][2] && table[1][2] == table[2][2]) {
		return table[0][2];
	} else if (table[0][0] != ' ' && table[0][0] == table[1][1] && table[1][1] == table[2][2]) {
		return table[0][0];
	} else if (table[0][2] != ' ' && table[0][2] == table[1][1] && table[1][1] == table[2][0]) {
		return table[0][2];
	} else { //Winning combo not found.
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (table[i][j] == ' ') {
					return ' '; //Searches for an empty space, which if found means that the game can continue.
				}
			}
		}
		return 'C'; //If an empty space is not found in the for loop above, returns 'C' for "cat's game" (draw).
	}
}

/* EXAMPLE OUTPUT:
Welcome to Tic-Tac-Toe!
=======================

Player 1's turn 'X'
	  0 1 2
	0  | | 
	  -----
	1  | |
	  -----
	2  | | 
What row and column would you like ? Seperate them with a space : 1 1

Player 2's turn 'O'
	  0 1 2
	0  | |
	  -----
	1  |X|
	  -----
	2  | |
What row and column would you like ? Seperate them with a space : 0 1

Player 1's turn 'X'
	  0 1 2
	0  |O|
	  -----
	1  |X|
	  -----
	2  | |
What row and column would you like ? Seperate them with a space : 1 0

Player 2's turn 'O'
	  0 1 2
	0  |O|
	  -----
	1  |X|
	  -----
	2  |O|
What row and column would you like ? Seperate them with a space : 2 1

Player 1's turn 'X'
	  0 1 2
	0  |O|
	  -----
	1 X|X|
	  -----
	2  |O|
What row and column would you like ? Seperate them with a space : 1 2

Game over!
	  0 1 2
	0  |O|
	  -----
	1 X|X|X
	  -----
	2  |O|
Player 1 wins!
*/