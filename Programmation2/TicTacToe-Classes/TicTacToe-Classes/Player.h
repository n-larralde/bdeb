#pragma once
class Player
{
	public:
		void setMark(char);
		char getMark();
		bool startFirst();
		int getInput();
	private:
		char playerMark;
};