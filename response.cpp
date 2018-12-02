#include <iostream>
#include <stdexcept>
#include <string>
#include "response.h"

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

Response::Response() : head(nullptr)
{
}

Response::~Response() 
{
    clear();
}

Response::Response(const Response& other) : Response()
{
    *this = other;
}

Response& Response::operator=(const Response& other)
{
    if(this != &other)
    {
        clear();
        Response temp;
        temp.copyReverse(other);
        copyReverse(temp);
    }
    
    return *this;
}
 
void Response::push(std::string c)
{  
    head = new Node(c, head);
}

std::string Response::pop()
{
    if(empty())
    {
        throw std::logic_error("No More Responses");
    }
  
    std::string c = peak();
    Node *temp;
    temp = head;
    head = head->next;
    delete temp;
    return c;
}

std::string Response::peak()
{
    if(empty())
    {
        throw std::logic_error("No More Responses");
    }
  
    return head->c;
}

bool Response::empty() const
{
    return head == nullptr;
}

void Response::clear()
{
    while(!empty())
    {
        pop();
    }
}

void Response::copyReverse(const Response& other)
{
    for(Node *p = other.head; p != nullptr; p = p->next)
    {
        push(p->c);
    }
}



