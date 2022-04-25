#include <iostream>
#include <string>

using namespace std;

char case1 = '1';
string case2 = "2";
string case3 = "3";
string case4 = "4";
string case5 = "5";
string case6 = "6";
string case7 = "7";
string case8 = "8";
string case9 = "9";

string player1 = "0";
string player2 = "0";
string currentPlayer = "0";

void displayTicTacToe();
int chooseRandomPlayer();
bool isValidTurn(int);
void playTurn(int);
int getComputerAvailableCase(int);
int whoIsTheWinner();

int main()
{
	cout << "Welcome to TicTacToe!" << endl << endl;

	displayTicTacToe();

	srand(static_cast<unsigned int>(time(0)));

	int turn = chooseRandomPlayer();

	if (turn == 1)
	{
		currentPlayer = "Computer";
		cout << currentPlayer << " starts first." << endl << endl;
		player1 = "Computer";
		player2 = "Player";
	}
	else
	{
		currentPlayer = "Player";
		cout << currentPlayer << " starts first." << endl << endl;
		player1 = "Player";
		player2 = "Computer";
	}

	int remainingCases = 9;
	bool endOfGame = false;

	while (!endOfGame)
	{
		if (currentPlayer == "Computer")
		{
			int cpuCase = 0;
			int randomNumber = 0;
			randomNumber = 1 + rand() % remainingCases;
			cpuCase = getComputerAvailableCase(randomNumber);
			playTurn(cpuCase);
			cout << currentPlayer << " plays: " << cpuCase << endl << endl;
			displayTicTacToe();
			currentPlayer = "Player";
		}
		else
		{
			bool validTurn = false;
			int inputUser = 0;
			cout << "Enter case number: ";
			cin >> inputUser;
			cout << endl;
			validTurn = isValidTurn(inputUser);

			while (!validTurn)
			{
				displayTicTacToe();
				cout << "Please enter a valid case number: ";
				cin >> inputUser;
				cout << endl;
				validTurn = isValidTurn(inputUser);
			}

			playTurn(inputUser);

			cout << currentPlayer << " plays: " << inputUser << endl << endl;
			displayTicTacToe();
			currentPlayer = "Computer";
		}

		--remainingCases;

		// WIN/LOOSE/DRAW Management
		int winner = whoIsTheWinner();

		if (winner == 1)
		{
			cout << player1 << " WON!" << endl << endl;
			endOfGame = true;
		}

		if (winner == 2)
		{
			cout << player2 << " WON!" << endl << endl;
			endOfGame = true;
		}

		if (remainingCases == 0 && winner == 0)
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

int  chooseRandomPlayer()
{
	int randomNumber = 1 + rand() % 2;
	return randomNumber;
}

bool isValidTurn(int number)
{
	bool validTurn = false;

	switch (number)
	{
        case 1: return case1 == "1";
        case 2: return case2 == "2";
            
		case 1:

			if (case1 != "O" && case1 != "X")
				validTurn = true;

			break;

		case 2:

			if (case2 != "O" && case2 != "X")
				validTurn = true;

			break;

		case 3:

			if (case3 != "O" && case3 != "X")
				validTurn = true;

			break;

		case 4:

			if (case4 != "O" && case4 != "X")
				validTurn = true;

			break;

		case 5:

			if (case5 != "O" && case5 != "X")
				validTurn = true;

			break;

		case 6:

			if (case6 != "O" && case6 != "X")
				validTurn = true;

			break;

		case 7:

			if (case7 != "O" && case7 != "X")
				validTurn = true;

			break;

		case 8:

			if (case8 != "O" && case8 != "X")
				validTurn = true;

			break;

		case 9:

			if (case9 != "O" && case9 != "X")
				validTurn = true;

			break;
	}

	return validTurn;
}

void playTurn(string playerMark)
{
	switch (number)
	{
        case 1: case1 = playerMark; break;

			if (player1 == currentPlayer)
				case1 = "X";
			else
				case1 = "O";

			break;

		case 2:

			if (player1 == currentPlayer)
				case2 = "X";
			else
				case2 = "O";

			break;

		case 3:

			if (player1 == currentPlayer)
				case3 = "X";
			else
				case3 = "O";

			break;

		case 4:

			if (player1 == currentPlayer)
				case4 = "X";
			else
				case4 = "O";

			break;

		case 5:

			if (player1 == currentPlayer)
				case5 = "X";
			else
				case5 = "O";

			break;

		case 6:

			if (player1 == currentPlayer)
				case6 = "X";
			else
				case6 = "O";

			break;

		case 7:

			if (player1 == currentPlayer)
				case7 = "X";
			else
				case7 = "O";

			break;

		case 8:

			if (player1 == currentPlayer)
				case8 = "X";
			else
				case8 = "O";

			break;

		case 9:

			if (player1 == currentPlayer)
				case9 = "X";
			else
				case9 = "O";

			break;
	}
}

// Return the available case, given a random number between 1 and remainingCases
int getComputerAvailableCase(int randomNumber)
{
    int firstTry = rand() % 9;
    bool isValid = false;
    while(!isValid)
    {
        int pos = (firstTry + 1) % 9;
        isValid = isValid(pos);
    }
    return pos;
    
    
	int availableCaseNumber = 0;
	int dynamicCounter = 0;
	bool caseFound = false;

	for (int i = 1; i <= 9; i++)
	{
		if (!caseFound)
		{
			switch (i)
			{
				case 1:

					if (case1 != "O" && case1 != "X")
						dynamicCounter++;

					if (dynamicCounter == randomNumber)
					{
						availableCaseNumber = 1;
						caseFound = true;
					}

					break;

				case 2:

					if (case2 != "O" && case2 != "X")
						dynamicCounter++;

					if (dynamicCounter == randomNumber)
					{
						availableCaseNumber = 2;
						caseFound = true;
					}

					break;

				case 3:

					if (case3 != "O" && case3 != "X")
						dynamicCounter++;

					if (dynamicCounter == randomNumber)
					{
						availableCaseNumber = 3;
						caseFound = true;
					}

					break;

				case 4:

					if (case4 != "O" && case4 != "X")
						dynamicCounter++;

					if (dynamicCounter == randomNumber)
					{
						availableCaseNumber = 4;
						caseFound = true;
					}

					break;

				case 5:

					if (case5 != "O" && case5 != "X")
						dynamicCounter++;

					if (dynamicCounter == randomNumber)
					{
						availableCaseNumber = 5;
						caseFound = true;
					}

					break;

				case 6:

					if (case6 != "O" && case6 != "X")
						dynamicCounter++;

					if (dynamicCounter == randomNumber)
					{
						availableCaseNumber = 6;
						caseFound = true;
					}

					break;

				case 7:

					if (case7 != "O" && case7 != "X")
						dynamicCounter++;

					if (dynamicCounter == randomNumber)
					{
						availableCaseNumber = 7;
						caseFound = true;
					}

					break;

				case 8:

					if (case8 != "O" && case8 != "X")
						dynamicCounter++;

					if (dynamicCounter == randomNumber)
					{
						availableCaseNumber = 8;
						caseFound = true;
					}

					break;

				case 9:

					if (case9 != "O" && case9 != "X")
						dynamicCounter++;

					if (dynamicCounter == randomNumber)
					{
						availableCaseNumber = 9;
						caseFound = true;
					}

					break;
			}
		}
	}

	return availableCaseNumber;
}

bool checkTTT(string case1, string case2, string case3, string playerMark)
{
    return case1 == case2 && case2 == case3 && case1 == playerMark;
}

bool isWinner(string playerMark)
{
    if (checkTTT(case1, case2, case3, playerMark) || checkTTT(case4, case5, case6, playerMark))
        return true;
    else if (case4 == "X" && case5 == "X" && case6 == "X")
        winner = 1;
    else if (case7 == "X" && case8 == "X" && case9 == "X")
        winner = 1;
    else if (case1 == "X" && case5 == "X" && case9 == "X")
        winner = 1;
    else if (case3 == "X" && case5 == "X" && case7 == "X")
        winner = 1;
    else if (case1 == "X" && case4 == "X" && case7 == "X")
        winner = 1;
    else if (case2 == "X" && case5 == "X" && case8 == "X")
        winner = 1;
    else if (case3 == "X" && case6 == "X" && case9 == "X")
        winner = 1;
}

int whoIsTheWinner()
{
	int winner = 0;

    if(isWinner("X"))
    {
        return 1;//enum
    }
    else if(isWinner("O"))
    {
        
    }
    
	// player1 WIN Conditions
	if (case1 == "X" && case2 == "X" && case3 == "X")
		winner = 1;
	else if (case4 == "X" && case5 == "X" && case6 == "X")
		winner = 1;
	else if (case7 == "X" && case8 == "X" && case9 == "X")
		winner = 1;
	else if (case1 == "X" && case5 == "X" && case9 == "X")
		winner = 1;
	else if (case3 == "X" && case5 == "X" && case7 == "X")
		winner = 1;
	else if (case1 == "X" && case4 == "X" && case7 == "X")
		winner = 1;
	else if (case2 == "X" && case5 == "X" && case8 == "X")
		winner = 1;
	else if (case3 == "X" && case6 == "X" && case9 == "X")
		winner = 1;

	// player2 WIN Conditions
	if (case1 == "O" && case2 == "O" && case3 == "O")
		winner = 2;
	else if (case4 == "O" && case5 == "O" && case6 == "O")
		winner = 2;
	else if (case7 == "O" && case8 == "O" && case9 == "O")
		winner = 2;
	else if (case1 == "O" && case5 == "O" && case9 == "O")
		winner = 2;
	else if (case3 == "O" && case5 == "O" && case7 == "O")
		winner = 2;
	else if (case1 == "O" && case4 == "O" && case7 == "O")
		winner = 2;
	else if (case2 == "O" && case5 == "O" && case8 == "O")
		winner = 2;
	else if (case3 == "O" && case6 == "O" && case9 == "O")
		winner = 2;

	return winner;
}
