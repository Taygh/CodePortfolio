#pragma once
#include <iostream>

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

class StartText
{

public:
	StartText();
	void display();

private:
	std::string lineOne;
	std::string lineTwo;
	std::string lineThree;
	std::string lineFour;
	std::string lineFive;
	std::string lineSix;
	
	void sleepMilliseconds(int n);
	std::string switchLine(int in);
};