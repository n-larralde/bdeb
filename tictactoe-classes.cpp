#include <iostream>
#include "TicTacToe.h"
#include "Player.h"
#include "Computer.h"

using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	TicTacToe ticTacToe;
	Player player;
	Computer computer;

	ticTacToe.displayWelcome();
	ticTacToe.displayTicTacToe();

	bool playerStartsFirst = player.startFirst();

	if (playerStartsFirst)
	{
		player.setMark('X');
		computer.setMark('O');
		ticTacToe.setInitialPlayer('P');
	}
	else
	{
		player.setMark('O');
		computer.setMark('X');
		ticTacToe.setInitialPlayer('C');
	}

	while (!ticTacToe.isGameEnd())
	{
		if (ticTacToe.isCurrentPlayer('C'))
		{
			int index = 0;
			int cpuTurn = 0;
			bool isValidTurn = false;	

			while (!isValidTurn)
			{
				cpuTurn = computer.getRandomCase();
				isValidTurn = ticTacToe.isValidTurn(cpuTurn);
			}

			ticTacToe.playTurn(cpuTurn, computer.getMark());
			ticTacToe.displayTicTacToe();
		}
		else if (ticTacToe.isCurrentPlayer('P'))
		{
			bool isValidTurn = false;
			int playerTurn = 0;

			while (!isValidTurn)
			{
				playerTurn = player.getInput();
				isValidTurn = ticTacToe.isValidTurn(playerTurn);
			}

			ticTacToe.playTurn(playerTurn, player.getMark());
			ticTacToe.displayTicTacToe();
		}

		// WIN LOOSE DRAW MANAGEMENT
		ticTacToe.displayIfWinnerEndGame(player.getMark());
		ticTacToe.displayIfWinnerEndGame(computer.getMark());
		ticTacToe.displayIfDrawEndGame();

		// Next turn management
		ticTacToe.switchCurrentPlayer();
	}

	return 0;
}