#pragma once
class TicTacToe
{
	public:
		void displayWelcome();
		void displayTicTacToe();
		void setInitialPlayer(char);
		void switchCurrentPlayer();
		bool isCurrentPlayer(char);
		bool isValidTurn(int);
		void playTurn(int, char);
		bool checkTTT(char, char, char, char);
		void displayIfWinnerEndGame(char);
		void displayIfDrawEndGame();
		bool isGameEnd();
		void displayEndGame();
	private:
		char case1 = '1';
		char case2 = '2';
		char case3 = '3';
		char case4 = '4';
		char case5 = '5';
		char case6 = '6';
		char case7 = '7';
		char case8 = '8';
		char case9 = '9';
		bool isWinner = false;
		int remainingCases = 9;
		bool endOfGame = false;
		char currentPlayer = 'N';
};