#include <iostream>
#include <stdexcept>
#include <string>
#include <thread>
#include "dialogue.h"

//Purpose: Create stack for dialogue
//
//    Attributes:
//        struct Node: creates linked list for dialogue, including
//        a node constructor 
//        Node *head: track head of linked list
//
//    Member Functions:
//        Dialogue(): Preconditions: none,
//        Postconditions: none (constructs stack)
//        ~Dialogue(): Preconditions: stack exists, Postconditions:
//        none (destroys stack)
//        Dialogue(): Preconditions: a stack
//        exists to be passed in, Postconditions: none (constructs
//        second stack with attributes of passed in stack, copy
//        constructor)
//        Dialogue& operator=(): Preconditions:
//        two stacks exist to be compared, Postconditions: none
//        (sets the two stacks to have equal attributes,
//        overloaded assignment operator)
//        void push(): Preconditions: dialogue to push onto
//        top of stack, Postconditions: none (adds dialogue to top
//        of stack)
//        string pop(): Preconditions: none,
//        Posconditions: pops/removes dialogue at
//        top of the stack, returns that dialogue
//        string peak(): Preconditions: none.
//        Postconditions: returns top of stack
//        bool empty() const: Preconditions: none, Postconditions:
//        none (checks if stack is empty)
//        void copyReverse(): Preconditions: another Dialogue object,
//        Postconditions: copy dialogue in reverse order from passed in object
//        void dialoguePrint(): Preconditions: boolean representing what response
//        the user chose (first/true or second/false), Postconditions: none
//        (prints corresponding dialogue)
//        void clear(): Preconditions: none, Postconditions: none 
//        (pops off all dialogue to clear stack)
//        void sleepMilliseconds(): Preconditions: integer for amount of milliseconds
//        to wait, Postconditions: no return type, pauses print for "int n" time 

Dialogue::Dialogue() : head(nullptr)
{
}

Dialogue::~Dialogue() 
{
    clear();
}

Dialogue::Dialogue(const Dialogue& other) : Dialogue()
{
    *this = other;
}

Dialogue& Dialogue::operator=(const Dialogue& other)
{
    if(this != &other)
    {
        clear();
        Dialogue temp;
        temp.copyReverse(other);
        copyReverse(temp);
    }
    
    return *this;
}
 
void Dialogue::push(std::string c)
{  
    head = new Node(c, head);
}

std::string Dialogue::pop()
{
    if(empty())
    {
        throw std::logic_error("No More Dialogue");
    }
  
    std::string c = peak();
    Node *temp;
    temp = head;
    head = head->next;
    delete temp;
    return c;
}

std::string Dialogue::peak()
{
    if(empty())
    {
        throw std::logic_error("No More Dialogue");
    }
  
    return head->c;
}

bool Dialogue::empty() const
{
    return head == nullptr;
}

void Dialogue::clear()
{
    while(!empty())
    {
        pop();
    }
}

void Dialogue::copyReverse(const Dialogue& other)
{
    for(Node *p = other.head; p != nullptr; p = p->next)
    {
        push(p->c);
    }
}

void Dialogue::dialoguePrint(bool decision)
{
	std::string dialogue;
	int animateCount = 0;
	bool animate = true;

	if (decision == true)
	{
		dialogue = pop();

		while (animate)
		{
			std::cout << dialogue[animateCount];
			animateCount++;
			sleepMilliseconds(50);

			if (animateCount == dialogue.length())
			{
				animate = false;
				std::cout << std::endl;
			}
		}

		pop();
	}

	else
	{
		pop();
		dialogue = pop();

		while (animate)
		{
			std::cout << dialogue[animateCount];
			animateCount++;
			sleepMilliseconds(50);

			if (animateCount == dialogue.length())
			{
				animate = false;
				std::cout << std::endl;
			}
		}
	}
}

void Dialogue::sleepMilliseconds(int n) 
{
	std::this_thread::sleep_for(std::chrono::milliseconds(n));
}