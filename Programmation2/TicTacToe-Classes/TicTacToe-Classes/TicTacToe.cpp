#include <iostream>
#include "TicTacToe.h"

using namespace std;

void TicTacToe::displayWelcome()
{
	cout << "Welcome to TicTacToe!" << endl << endl;
}

void TicTacToe::displayTicTacToe()
{
	cout << case1 << " | " << case2 << " | " << case3 << endl;
	cout << "- + - + -" << endl;
	cout << case4 << " | " << case5 << " | " << case6 << endl;
	cout << "- + - + -" << endl;
	cout << case7 << " | " << case8 << " | " << case9 << endl << endl;
}

void TicTacToe::setInitialPlayer(char player)
{
	currentPlayer = player;

	if (player == 'C')
	{
		cout << "CPU starts first." << endl << endl;
	}
	else
	{
		cout << "Player starts first." << endl << endl;
	}
}

void TicTacToe::switchCurrentPlayer()
{
	if (currentPlayer == 'P')
	{
		currentPlayer = 'C';
	}
	else if (currentPlayer == 'C')
	{
		currentPlayer = 'P';
	}
}

bool TicTacToe::isCurrentPlayer(char player)
{
	return currentPlayer == player;
}

bool TicTacToe::isValidTurn(int number)
{
	switch (number)
	{
		case 1: return case1 == '1';
		case 2: return case2 == '2';
		case 3: return case3 == '3';
		case 4: return case4 == '4';
		case 5: return case5 == '5';
		case 6: return case6 == '6';
		case 7: return case7 == '7';
		case 8: return case8 == '8';
		case 9: return case9 == '9';
		default: return false;
	}
}

void TicTacToe::playTurn(int number, char mark)
{
	switch (number)
	{
		case 1: case1 = mark; break;
		case 2: case2 = mark; break;
		case 3: case3 = mark; break;
		case 4: case4 = mark; break;
		case 5: case5 = mark; break;
		case 6: case6 = mark; break;
		case 7: case7 = mark; break;
		case 8: case8 = mark; break;
		case 9: case9 = mark; break;
	}
	
	if (currentPlayer == 'C')
	{
		cout << "CPU plays: " << number << endl << endl;
	}

	if (currentPlayer == 'P')
	{
		cout << "Player plays: " << number << endl << endl;
	}

	remainingCases--;
}

bool TicTacToe::checkTTT(char case1, char case2, char case3, char mark)
{
	return case1 == case2 && case2 == case3 && case1 == mark;
}

void TicTacToe::displayIfWinnerEndGame(char mark)
{
	if (!isWinner && !endOfGame)
	{
		if (checkTTT(case1, case2, case3, mark) || checkTTT(case4, case5, case6, mark) ||
			checkTTT(case7, case8, case9, mark) || checkTTT(case1, case5, case9, mark) ||
			checkTTT(case3, case5, case7, mark) || checkTTT(case1, case4, case7, mark) ||
			checkTTT(case2, case5, case8, mark) || checkTTT(case3, case6, case9, mark))
		{
			isWinner = true;
			endOfGame = true;
		}

		// Display management Only displays once isWinner is triggered
		if (isWinner)
		{
			if (currentPlayer == 'C')
			{
				cout << "CPU WON!" << endl << endl;
			}
			if (currentPlayer == 'P')
			{
				cout << "Player WON!" << endl << endl;
			}

			TicTacToe::displayEndGame();
		}
	}
}

void TicTacToe::displayIfDrawEndGame()
{
	if (remainingCases == 0 && !isWinner)
	{
		endOfGame = true;
		cout << "DRAW!" << endl << endl;
		TicTacToe::displayEndGame();
	}
}

bool TicTacToe::isGameEnd()
{
	return remainingCases == 0 || endOfGame;
}

void TicTacToe::displayEndGame()
{
	cout << "Game Over!" << endl << endl;
}