#pragma once

//Purpose: Create stack for responses
//
//    Attributes:
//        struct Node: creates linked list for responses, including
//        a node constructor 
//        Node *head: track head of linked list
//
//    Member Functions:
//        Response(): Preconditions: none,
//        Postconditions: none (constructs stack)
//        ~Response(): Preconditions: stack exists, Postconditions:
//        none (destroys stack)
//        Response(): Preconditions: a stack
//        exists to be passed in, Postconditions: none (constructs
//        second stack with attributes of passed in stack, copy
//        constructor)
//        Response& operator=(): Preconditions:
//        two stacks exist to be compared, Postconditions: none
//        (sets the two stacks to have equal attributes,
//        overloaded assignment operator)
//        void push(): Preconditions: response to push onto
//        top of stack, Postconditions: none (adds response to top
//        of stack)
//        string pop(): Preconditions: none,
//        Posconditions: pops/removes response at
//        top of the stack, returns that response
//        string peak(): Preconditions: none.
//        Postconditions: returns top of stack
//        bool empty() const: Preconditions: none, Postconditions:
//        none (checks if stack is empty)
//        void copyReverse(): Preconditions: another Response object,
//        Postconditions: copy responses in reverse order from passed in object
//        void clear(): Preconditions: none, Postconditions: none 
//        (pops off all responses to clear stack)

class Response
{

    public:
        Response();
        ~Response();
        Response(const Response& other);
        Response& operator=(const Response& other);

        void push(std::string c);
        std::string pop();
        std::string peak();
        bool empty() const;
        void copyReverse(const Response& other);
        
  
    private:

        struct Node
        {
            std::string c;
            Node *next;
            Node(std::string c, Node *next = nullptr) : c(c), next(next) {}
        };
        Node *head;

        void clear();
};
