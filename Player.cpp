#include <iostream>
#include "Player.h"

using namespace std;

void Player::setMark(char mark)
{
	playerMark = mark;
}

char Player::getMark()
{
	return playerMark;
}

bool Player::startFirst()
{
	bool startFirst = false;
	int randomNumber = 1 + rand() % 2;
	randomNumber == 1 ? startFirst = false : startFirst = true;
	return startFirst;
}

int Player::getInput()
{
	int input = 0;
	cout << "Enter a valid case number: ";
	cin >> input;
	return input;
}