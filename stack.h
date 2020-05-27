// CMSC 341 - Spring 2020 - Project 0
// stack.h: a templated, linked list-based stack implementation

// Assignment:
//   (1) Complete the copy constructor
//   (2) Complete the assignment operator
//   (3) Complete the destructor
//   (4) Write a test program (mytest.cpp) to test copy and assignment
//   (5) Verify destructor by running the test program in Valgrind

#ifndef _STACK_H
#define _STACK_H

#include <iostream>
#include <exception>

using std::ostream;
using std::cout;
using std::endl;
using std::range_error;

// Forward declarations
template <class T> class Stack;
template <class T> class Node;
template <class T> ostream& operator<<(ostream&, const Node<T>&);

// Node class for linked list
template <class T>
class Node {

    friend Stack<T>;

public:
    Node(T data = T(), Node<T>* next = nullptr) {
        _data = data;
        _next = next;
    }

    friend ostream& operator<< <T>(ostream& sout, const Node<T>& x);

private:
    T _data;
    Node* _next;
};

// Overloaded insertion operator.  Must be overloaded for the template
// class T, or this won't work!
template <class T>
ostream& operator<<(ostream& sout, const Node<T>& x) {
    sout << "Data: " << x._data;
    return sout;
}


// Stack class.  Linked-list implementation of a stack. Uses the Node
// class.
template <class T>
class Stack {
public:
    // Constructor
    Stack();

    // Copy constructor, assignment operator, and destructor
    // DO NOT IMPLEMENT HERE.  SEE BELOW.
    Stack(const Stack& rhs);
    const Stack& operator=(const Stack& rhs);
    ~Stack();

    // Stack operations: push(), top(), and pop()
    void push(const T& data);
    const T& top() const;
    void pop();

    // Helpful functions
    bool empty() const;  // Returns 'true' if stack is empty
    void dump() const;   // Dump contents of the linked list

private:
    Node<T>* _head;

    // ***************************************************
    // Any private helper functions must be delared here!
    // ***************************************************

};

template <class T>
Stack<T>::Stack() {
    _head = nullptr;
}

// Given a LL, creats a deep copy of the LL
template <class T>
Stack<T>::Stack(const Stack<T>& rhs) {
    // ********************************
    // Implement the copy constructor
    // ********************************
    _head = nullptr;
    Node<T>* rhs_curr = rhs._head;
    Node<T>* prev_cpy = _head, *curr_cpy = _head;

    // creates _head if the source is not a empty LL
    if (rhs_curr != nullptr) {
        _head = new Node<T>(rhs._head->_data);

        // rhs moves up one 
        rhs_curr = rhs_curr->_next;

        // sets up the two pointers for deep copying
        prev_cpy = _head;
        curr_cpy = _head->_next;
    }
    while (rhs_curr != nullptr) {

        // creates a new node and copy data  
        curr_cpy = new Node<T>(rhs_curr->_data);

        // have _next point to the new node  
        prev_cpy->_next = curr_cpy;

        // rhs & copy LL moves up one
        prev_cpy = curr_cpy;
        curr_cpy = curr_cpy->_next;
        rhs_curr = rhs_curr->_next;
        curr_cpy = nullptr;
    }
}

// Given a LL, returns a deep copy of the LL
template <class T>
const Stack<T>& Stack<T>::operator=(const Stack<T>& rhs) {

    // **********************************
    // Implement the assignment operator
    // **********************************
    if (this != &rhs) {
        Node<T>* rhs_curr = rhs._head;
        Node<T>* curr_cpy = _head, * prev_cpy = _head;
        
        // clears out the previous LL
        while (curr_cpy != nullptr) {
            Node<T>* prev = curr_cpy;
            curr_cpy = curr_cpy->_next;

            delete prev; 
            prev = nullptr;
        }
        _head = nullptr;

        // creates _head if the source is not a empty LL
        if (rhs_curr != nullptr) {
            _head = new Node<T>(rhs._head->_data);

            // rhs moves up one 
            rhs_curr = rhs_curr->_next;

            // sets up the two pointers for deep copying
            prev_cpy = _head;
            curr_cpy = _head->_next;
        }

        while (rhs_curr != nullptr) {

            // creates a new node and copy data  
            curr_cpy = new Node<T>(rhs_curr->_data);

            // have _next point to the new node  
            prev_cpy->_next = curr_cpy;

            // rhs & copy LL moves up one
            prev_cpy = curr_cpy;
            curr_cpy = curr_cpy->_next;
            rhs_curr = rhs_curr->_next;
            curr_cpy = nullptr;
        }

    }

    return *this;
}

// Deletes all nodes in the LL
template <class T>
Stack<T>::~Stack() {

    // *************************
    // Implement the destructor
    // *************************
    Node<T>* curr = _head;

    while (curr != nullptr) {
        Node<T>* prev = curr;
        curr = curr->_next;

        delete prev;
        prev = nullptr;
    }
}

template <class T>
void Stack<T>::push(const T& data) {
    Node<T>* tmpPtr = new Node<T>(data);
    tmpPtr->_next = _head;
    _head = tmpPtr;
}

template <class T>
const T& Stack<T>::top() const {
    if (empty()) {
        throw range_error("Stack<T>::top(): attempt to read empty stack.");
    }

    return _head->_data;
}

template <class T>
void Stack<T>::pop() {
    if (empty()) {
        throw range_error("Stack<T>::pop(): attempt to pop from an empty stack.");
    }

    Node<T>* tmpPtr = _head->_next;
    delete _head;
    _head = tmpPtr;
}

template <class T>
bool Stack<T>::empty() const {
    return _head == nullptr;
}

template <class T>
void Stack<T>::dump() const {
    Node<T>* nodePtr = _head;
    while (nodePtr != nullptr) {
        cout << nodePtr->_data << endl;
        nodePtr = nodePtr->_next;
    }
}

#endif
