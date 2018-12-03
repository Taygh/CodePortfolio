#include <iostream>
#include <thread>
#include "starttext.h"

//Purpose: To animate a welcome message to the screen 
//
//    Attributes:
//        	string lineOne: first line of animated welcome message
//        	string lineTwo: second line of animated welcome message
//        	string lineThree: third line of animated welcome message
//        	string lineFour: fourth line of animated welcome message
//        	string lineFive: fifth line of animated welcome message
//        	string lineSix: sixth line of animated welcome message
//
//    Member Functions:
//          StartText(): Preconditions: none, Postconditions: object created
//          void display(): Preconditions: none (object already created implied),
//          Postconditions: no return type, message animated to screen
//          void sleepMilliseconds(): Preconditions: integer for amount of milliseconds
//          to wait, Postconditions: no return type, pauses print for "int n" time 
//          string switchLine(): Preconditions: integer representing next line needed
//          for animating welcome message, Postconditions: line corresponding to 
//          integer inputed

StartText::StartText()
{
	lineOne = "___________              __      ________                        ___________              .__               ";
	lineTwo = "\\__    ___/___ ___  ____/  |_   /  _____/_____    _____   ____   \\_   _____/ ____    ____ |__| ____   ____  ";
	lineThree = "  |    |_/ __ \\\\  \\/  /\\   __\\ /   \\  ___\\__  \\  /     \\_/ __ \\   |    __)_ /    \\  / ___\\|  |/    \\_/ __ \\ ";
	lineFour = "  |    |\\  ___/ >    <  |  |   \\    \\_\\  \\/ __ \\|  Y Y  \\  ___/   |        \\   |  \\/ /_/  >  |   |  \\  ___/ ";
	lineFive = "  |____| \\___  >__/\\_ \\ |__|    \\______  (____  /__|_|  /\\___  > /_______  /___|  /\\___  /|__|___|  /\\___  >";
	lineSix = "             \\/      \\/                \\/     \\/      \\/     \\/          \\/     \\//_____/         \\/     \\/ ";
}

void StartText::display()
{
	std::string current;

	for (int i = 1; i < 7; i++)
	{
		current = switchLine(i);
		int length = 0;

		while (length < current.length())
		{
			std::cout << current[length];
			sleepMilliseconds(20);
			length++;
		}

		std::cout << std::endl;
	}

	std::cout << std::endl;
}

void StartText::sleepMilliseconds(int n) 
{
	std::this_thread::sleep_for(std::chrono::milliseconds(n));
}

std::string StartText::switchLine(int in)
{
	if (in == 1)
	{
		return lineOne;
	}

	if (in == 2)
	{
		return lineTwo;
	}

	if (in == 3)
	{
		return lineThree;
	}

	if (in == 4)
	{
		return lineFour;
	}

	if (in == 5)
	{
		return lineFive;
	}

	if (in == 6)
	{
		return lineSix;
	}

}