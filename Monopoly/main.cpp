// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "Game.h"

int _tmain(int argc, _TCHAR* argv[])
{
	std::string answer = "";
	Game *game = new Game();

	while (answer != "exit")
	{
		std::cout << "Please enter selection:\n";
		std::cin >> answer;
	}

	return 0;
}

