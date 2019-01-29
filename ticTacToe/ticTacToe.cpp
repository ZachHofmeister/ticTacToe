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
	int turn = 0;
	char table[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	//printTable(table);
	cout << "Welcome to Tic-Tac-Toe!" << endl;
	cout << "=======================" << endl;

	do {
		cout << endl;
		int row, column;
		cout << "Player " << (turn % 2 == 0 ? '1' : '2') << "\'s turn \'" << (turn % 2 == 0 ? 'X' : 'O') << "\'" << endl;
		printTable (table);
		cout << "What row and column would you like? (Seperate with a space) :" << endl;
		cin >> row >> column;

		if (table[row][column] != ' ') {
			table[row][column] = (turn % 2 == 0 ? 'X' : 'O');
			turn++;
		} else {
			cout << "Invalid move - that space is occupied. Please choose another space." << endl;
		}
	} while (detectWin(table) == ' ');

	cout << endl <<  "Game over!" << endl;
	printTable(table);
	if (detectWin(table) == 'C') {
		cout << "Cat's game! Nobody wins! Better luck next time!" << endl;
	} else {
		cout << "Player " << (detectWin(table) == 'X' ? '1' : '2') << " wins!" << endl;
	}

	return 0;
}

void printTable(char table[3][3]) {	//Prints out the game board in it's current state.
	cout << table[0][0] << '|' << table[0][1] << '|' << table[0][2] << endl;
	cout << "-----" << endl;
	cout << table[1][0] << '|' << table[1][1] << '|' << table[1][2] << endl;
	cout << "-----" << endl;
	cout << table[2][0] << '|' << table[2][1] << '|' << table[2][2] << endl;
}

char detectWin(char table[3][3]) { //Detects if any winning combination has been played, if the game results in a draw, or if the game can continue.
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
	} else {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (table[i][j] == ' ') {
					return ' '; //Searches for an empty space, which if found means that the game can continue.
				}
			}
		}
		return 'C'; //If an empty space is not found in the for loops above, returns 'C' for "cat's game" (draw).
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
