#pragma once

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

class Dialogue
{

    public:
        Dialogue();
        ~Dialogue();
        Dialogue(const Dialogue& other);
        Dialogue& operator=(const Dialogue& other);

        void push(std::string c);
        std::string pop();
        std::string peak();
        bool empty() const;
        void copyReverse(const Dialogue& other);
		void dialoguePrint(bool decision);
        
  
    private:

        struct Node
        {
            std::string c;
            Node *next;
            Node(std::string c, Node *next = nullptr) : c(c), next(next) {}
        };
        Node *head;

        void clear();
		void sleepMilliseconds(int n);
};
