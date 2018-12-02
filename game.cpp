#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <thread>
#include <stdexcept>
#include "starttext.h"
#include "dialogue.h"
#include "response.h"
using namespace std;

//Purpose: To load and play a user generated text adventure game

//Input: files for dialogue/responses, response choices, pressing enter
//at end of game to exit

//Processing: read the files into their respective dialogue/response stacks,
//animate the first dialouge/responses to the screen to start the game,
//get the user's first choice, then enter the loop for the main game,
//play the game until the dialogue stack runs out, print the final 
//dialogue, print prompt to exit game, program ends

//Output: welcome message for game, prompt for files, dialogue/responses,
//prompt to end game and exit program

//responseTyped(): Preconditions: user input, first game option, second game
//option, array of responses in case the user types in an invalid response,
//Postconditions: boolean representing if first option (true) or second
//option (false) was chosen by the user
bool responseTyped(string userIn, string trueStatement, string falseStatement, 
const string incorrects[]);

//void animateText(): Preconditions: arrow string to preface game options,
//first game option, second game option, boolean representing whether or not
//the current line needs to keep being animated, integer counting characters 
//printed compared to length of each game option, Postconditions: no return type, 
//options for responses animated to screen
void animateText(string arrow, string optionOne, string optionTwo, 
bool& animate, int& animateCount);

//void sleepMilliseconds(): Preconditions: integer for amount of milliseconds
//to wait, Postconditions: no return type, pauses print for "int n" time 
void sleepMilliseconds(int n);


void checkFile(ifstream& in);

int main()
{
	//gets user input for option they choose
    string gameInput;
	//used for getline() when reading from file to response/dialogue objects
    string tempLine;
	//gets first dialogue for when game is initialized
	string firstDialogue;
	//gets last dialogue for when game is over
	string finalDialogue;
	//gets initial first option at beginning of game
	string firstTrue;
	//gets initial second option at beginning of game
	string firstFalse;
	//gets file directory for dialogue
	string dialogueFile = "C:\\Users\\gamin\\Desktop\\Previous Code\\Code - Quarter 2\\game Updated\\dialogue.txt";
	//gets file directory for responses
	string responsesFile = "C:\\Users\\gamin\\Desktop\\Previous Code\\Code - Quarter 2\\game Updated\\responses.txt";
	//array of responses for invalid input from user
	const string what[4] = { "I'm sorry, come again?", "I have no idea what that means.",
	"Uh, what?", "You're not making any sense." };
	//arrow used to list response options during game
	const string ARROW = "->";
	//final message to prompt exit to user at end of game
	const string QUIT = "(press ENTER to quit)";
	//length of the quit message used for animation
	const int QUIT_LENGTH = QUIT.length();
	//dummy counter for initial response print to screen
	int animateCount = 0;
	//boolean representing if the user chose option one or two
	bool dialogueOption = true;
	//boolean used to loop game until the end
	bool done = false;
	//boolean used to animate responses during the game
	bool animate = true;
	//boolean used to determine if the game just started to print first dialogue
	bool isFirst = true;
	//read in for dialogue
    ifstream dOpen;
	//read in for responses
    ifstream rOpen;

	//create object for initial welcome message
	StartText s1;

	//create objects for dialogue (one to 
	//copy reverse into so dialogue is in
	//order)
	Dialogue d1;
	Dialogue d2;

	//create objects for responses (one to 
	//copy reverse into so responses are in
	//order)
	Response r1;
	Response r2;

	//display initial welcome message
	s1.display();

	//get files, read them into respective objects
	cout << "Enter a directory for your dialogue: ";
	cin >> dialogueFile;
	cout << "Enter a directory for your responses: ";
	cin >> responsesFile;
	cout << endl;

	dOpen.open(dialogueFile);
	//checkFile(dOpen);

	while(getline(dOpen, tempLine))
	{
		d1.push(tempLine);
	}

	d2.copyReverse(d1);

	rOpen.open(responsesFile);
	//checkFile(rOpen);

	while(getline(rOpen, tempLine))
	{
		r1.push(tempLine);
	}
  
	r2.copyReverse(r1);

	//set initial and final dialogues
	firstDialogue = d2.pop();
	finalDialogue = d2.pop();

	//set first set of response options
	firstTrue = r2.pop();
	firstFalse = r2.pop();

	//animate initial dialogue to screen
	for (int i = 0; i < firstDialogue.length(); i++)
	{
		cout << firstDialogue[i];
		sleepMilliseconds(50);
	}
	cout << endl;

	//animate initial responses to screen and get user option
	animateText(ARROW, firstTrue, firstFalse, animate, animateCount);
	cout << endl;

	cin.ignore();

	dialogueOption = responseTyped(gameInput, firstTrue, firstFalse, what);
	cout << endl;

	//run the game until final dialogue is hit
	while (!done)
	{
		string optionOne;
		string optionTwo;
		animateCount = 0;
		animate = true;

		if (isFirst == true)
		{
			d2.dialoguePrint(dialogueOption);
			isFirst = false;
		}

		if (dialogueOption == true)
		{
			optionOne = r2.pop();
			optionTwo = r2.pop();
			r2.pop();
			r2.pop();

			animateText(ARROW, optionOne, optionTwo, animate, animateCount);
			cout << endl;
		}

		if (dialogueOption == false)
		{
			r2.pop();
			r2.pop();
			optionOne = r2.pop();
			optionTwo = r2.pop();

			animateText(ARROW, optionOne, optionTwo, animate, animateCount);
			cout << endl;
		}

		dialogueOption = responseTyped(gameInput, optionOne, optionTwo, what);

		cout << endl;

		if (!d2.empty())
		{
			d2.dialoguePrint(dialogueOption);
		}

		else
		{
			for (int i = 0; i < finalDialogue.length(); i++)
			{
				cout << finalDialogue[i];
				sleepMilliseconds(50);
			}

			cout << endl;

			done = true;
		}
	}

	//print message to quit game and end program
	for (int i = 0; i < QUIT_LENGTH; i++)
	{
		cout << QUIT[i];
		sleepMilliseconds(50);
	}

	cin.ignore();
	return 0;
}

bool responseTyped(string userIn, string trueStatement, string falseStatement, 
const string incorrects[])
{
	bool finalOption;
	bool repeat = false;
	string tempIn = userIn;
	string tempTrue = trueStatement;
	string tempFalse = falseStatement;
	srand(time((unsigned int)0));
	int option;

	//set game options and user input to lowercase so that user response
	//is not case sensitive
	for (int i = 0; i < tempTrue.length(); i++)
	{
		tempTrue[i] = tolower(tempTrue[i]);
	}

	for (int i = 0; i < tempFalse.length(); i++)
	{
		tempFalse[i] = tolower(tempFalse[i]);
	}

	//get user response, compare to two game options and take appropriate 
	//action
	while (!repeat)
	{
		getline(cin, tempIn);

		for (int i = 0; i < tempIn.length(); i++)
		{
			tempIn[i] = tolower(tempIn[i]);
		}

		if (tempIn == tempTrue)
		{
			finalOption = true;
			repeat = true;
		}

		else if (tempIn == tempFalse)
		{
			finalOption = false;
			repeat = true;
		}

		else
		{
			option = rand() % 4;
			cout << endl;
			cout << incorrects[option] << endl;
		}

	}

	//return the final option chosen by the user
	return finalOption;
}

void animateText(string arrow, string optionOne, string optionTwo, 
bool& animate, int& animateCount)
{
	for (int i = 0; i < 2; i++)
	{
		cout << arrow[i];
		sleepMilliseconds(50);
	}

	while (animate)
	{
		cout << optionOne[animateCount];
		animateCount++;
		sleepMilliseconds(50);

		if (animateCount == optionOne.length())
		{
			animate = false;
			cout << endl;
		}
	}

	animate = true;
	animateCount = 0;
	
	for (int i = 0; i < 2; i++)
	{
		cout << arrow[i];
		sleepMilliseconds(50);
	}

	while (animate)
	{
		cout << optionTwo[animateCount];
		animateCount++;
		sleepMilliseconds(50);

		if (animateCount == optionTwo.length())
		{
			animate = false;
			cout << endl;
		}
	}
}

void sleepMilliseconds(int n) 
{
	this_thread::sleep_for(chrono::milliseconds(n));
}

void checkFile(ifstream& in)
{
	if (!in.is_open())
	{
		throw logic_error("ERROR: one or more files could not be located");
	}
}