#include <iostream>

using namespace std;

char case1 = '1';
char case2 = '2';
char case3 = '3';
char case4 = '4';
char case5 = '5';
char case6 = '6';
char case7 = '7';
char case8 = '8';
char case9 = '9';

enum Players { None = 0, CPU = 1, Player = 2 };

void displayTicTacToe();
Players chooseRandomPlayer();
bool isValidTurn(int);
void playTurn(int, char);
int getComputerAvailableCase();
bool checkTTT(char, char, char, char);
int validInputUser();
Players whoIsTheWinner(char);

int main()
{
	cout << "Welcome to TicTacToe!" << endl << endl;

	displayTicTacToe();

	srand(static_cast<unsigned int>(time(0)));

	Players currentPlayer = chooseRandomPlayer();
	char cpuMark = '0';
	char playerMark = '0';

	if (currentPlayer == CPU)
	{
		cpuMark = 'X';
		playerMark = 'O';
		cout << "CPU starts first." << endl << endl;
	}
	else
	{
		cpuMark = 'O';
		playerMark = 'X';
		cout << "Player starts first." << endl << endl;
	}

	int remainingCases = 9;
	bool endOfGame = false;

	while (!endOfGame)
	{
		if (currentPlayer == CPU)
		{
			int cpuTurn = getComputerAvailableCase();
			playTurn(cpuTurn, cpuMark);
			cout << "CPU plays: " << cpuTurn << endl << endl;
			displayTicTacToe();
			currentPlayer = Player;
		}
		else
		{
			int playerTurn = validInputUser();
			playTurn(playerTurn, playerMark);
			cout << endl << "Player plays: " << playerTurn << endl << endl;
			displayTicTacToe();
			currentPlayer = CPU;
		}

		--remainingCases;

		// WIN/LOOSE/DRAW Management
		Players winner = whoIsTheWinner(cpuMark);

		if (winner == CPU)
		{
			cout << "CPU WON!" << endl << endl;
			endOfGame = true;
		}
		else if (winner == Player)
		{
			cout << "Player WON!" << endl << endl;
			endOfGame = true;
		}
		else if (remainingCases == 0 && winner == None)
		{
			cout << "DRAW!" << endl << endl;
			endOfGame = true;
		}
	}

	cout << "Game Over!" << endl << endl;

	return 0;
}

void displayTicTacToe()
{
	cout << case1 << " | " << case2 << " | " << case3 << endl;
	cout << "- + - + -" << endl;
	cout << case4 << " | " << case5 << " | " << case6 << endl;
	cout << "- + - + -" << endl;
	cout << case7 << " | " << case8 << " | " << case9 << endl << endl;
}

Players  chooseRandomPlayer()
{
	Players player = None;
	int randomNumber = 1 + rand() % 2;
	randomNumber == 1 ? player = CPU : player = Player;
	return player;
}

int validInputUser()
{
	cout << "Enter case number: ";
	int inputUser = 0;	
	cin >> inputUser;

	while (!isValidTurn(inputUser))
	{
		cout << "Please enter a valid case number: ";
		cin >> inputUser;
	}

	return inputUser;
}

bool isValidTurn(int number)
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
	}

	return false;
}

void playTurn(int number, char playerMark)
{
	switch (number)
	{
		case 1: case1 = playerMark; break;
		case 2: case2 = playerMark; break;
		case 3: case3 = playerMark; break;
		case 4: case4 = playerMark; break;
		case 5: case5 = playerMark; break;
		case 6: case6 = playerMark; break;
		case 7: case7 = playerMark; break;
		case 8: case8 = playerMark; break;
		case 9: case9 = playerMark; break;
	}
}

int getComputerAvailableCase()
{
	bool isValid = false;
	int position = 0;
	int firstTry = 0;

	while (!isValid)
	{
		position = (firstTry + 1) + rand() % 9;
		isValid = isValidTurn(position);
	}

	return position;
}

bool checkTTT(char case1, char case2, char case3, char playerMark)
{
	return case1 == case2 && case2 == case3 && case1 == playerMark;
}

bool isWinner(char playerMark)
{
	bool isWinner = false;

	if (checkTTT(case1, case2, case3, playerMark) || checkTTT(case4, case5, case6, playerMark) || 
		checkTTT(case7, case8, case9, playerMark) || checkTTT(case1, case5, case9, playerMark) || 
		checkTTT(case3, case5, case7, playerMark) || checkTTT(case1, case4, case7, playerMark) || 
		checkTTT(case2, case5, case8, playerMark) || checkTTT(case3, case6, case9, playerMark))
	{
		isWinner = true;
	}

	return isWinner;
}

Players whoIsTheWinner(char _CPUMark)
{
	Players winner = None;

	if (isWinner('X'))
	{
		_CPUMark == 'X' ? winner = CPU : winner = Player;
	}
	else if (isWinner('O'))
	{
		_CPUMark == 'O' ? winner = CPU : winner = Player;
	}

	return winner;
}