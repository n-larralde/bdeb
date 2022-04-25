#include <iostream>
#include "Computer.h"

void Computer::setMark(char mark)
{
	markCPU = mark;
}

char Computer::getMark()
{
	return markCPU;
}

// A refaire pour optimiser
int Computer::getRandomCase()
{
	return 1 + rand() % 9;
}