/*****************************************
** File:    mytest.cpp
** Project: CMSC 341 Project 0, Summer 2020
** Author:  Rooklyn Kline
** Date:    5/29/20
** Section: 01
** E-mail:  rkline2@umbc.edu
**
** This file involves testing the functions
** written in stack.h. The primary functions are
** test if the copy constructor, overloaded assignment operator and
** destructor works efficiently and effectively.
**
***********************************************/
#include <iostream>
#include "stack.h"
using namespace std;

int main() {
	Stack<int> intStack_1;

	for (auto i = 1; i <= 10; i++) {
		intStack_1.push(i);
	}

	// Test 1: Tests if the copy constructor works  
	cout << "Push integers on Stack 1 completed\n";
	cout << "*****Test 1*****" << endl;

	cout << "Copy Constructor" << endl;
	Stack<int> intStack2(intStack_1);

	cout << "Stack 1" << endl;
	intStack_1.dump();

	cout << "Stack 2" << endl;
	intStack2.dump();

	// Test 2: Tests if the copy constructor is a deep copy 
	cout << "*****Test 2*****" << endl;
	cout << "Deep Copy Test" << endl;
	intStack_1.pop();

	cout << "Removed \"10\" From Stack 1" << endl;
	cout << "Stack 1" << endl;
	intStack_1.dump();

	cout << "Stack 2" << endl;
	intStack2.dump();

	// Test 3: Tests assignment operator
	// with edge cases
	cout << "*****Test 3*****" << endl;
	cout << "Empty Stack & Assignment Operator test" << endl;

	cout << "Removing all nodes from Stack 1" << endl;
	
	while (not intStack_1.empty()) {
		intStack_1.pop();
	}
	
	intStack2 = intStack_1;

	cout << "Stack 2 is now equal to empty Stack 1" << endl << endl;
	cout << "Displaying both Stack 1 & Stack 2" << endl;

	cout << "Stack 1 (should be empty)" << endl;
	intStack_1.dump();

	cout << "Stack 2 (should be empty)" << endl;
	intStack2.dump();

	// Test 4: Tests copy constructor
	// with edge cases
	cout << "*****Test 4*****" << endl;
	cout << "Empty Stack & Copy Constructor test" << endl;

	Stack<int>intStack3(intStack_1);
	cout << "Created a New Stack 3 and Copied Empty Stack 1" << endl << endl;
	cout << "Displaying both Stack 1 & Stack 3" << endl;

	cout << "Stack 1 (should be empty)" << endl;
	intStack_1.dump();

	cout << "Stack 3 (should be empty)" << endl;
	intStack3.dump();

	// Test 5: Tests if the assignment operator
	// performed a deep copy 
	cout << "*****Test 5*****" << endl;
	cout << "Deep Copy Test " << endl;
	cout <<"Filling up Stack 2" << endl;
	for (auto i = 1; i <= 10; i++) {
		intStack2.push(i);
	}
	cout << "Filling up Stack 3" << endl;
	for (auto i = 1; i <= 10; i++) {
		intStack3.push(i);
	}

	cout << "Stack 1 (should be empty)" << endl;
	intStack_1.dump();

	cout << "Stack 2" << endl;
	intStack2.dump();

	cout << "Stack 3" << endl;
	intStack3.dump();
	
	// Test 6: Tests if the assignment operator
	// guarded against self-assignment 
	cout << "*****Test 6*****" << endl;
	cout << "Self Assignment Test" << endl;

	cout << "Testing Stack 1" << endl;
	intStack_1 = intStack_1;
	cout << "Stack 1 (should be empty)" << endl;
	intStack_1.dump();

	cout << "Testing Stack 2" << endl;
	intStack2 = intStack2;
	cout << "Stack 2" << endl;
	intStack2.dump();

	// Test 7: Tests the assignment operator 
	// with a filled stack
	cout << "*****Test 7*****" << endl;
	cout << "Assignment Test (Cont.)" << endl;
	intStack_1 = intStack2;
	cout << "Empty Stack 1 is now equal to Stack 2" << endl;

	cout << "Stack 1" << endl;
	intStack_1.dump();

	cout << "Stack 2" << endl;
	intStack2.dump();

	// Test 8: Tests if the assignment operator is a deep copy 
	cout << "*****Test 8*****" << endl;
	cout << "Deep Copy Test" << endl;
	intStack_1.pop();

	cout << "Removed \"10\" From Stack 1" << endl;
	cout << "Stack 1" << endl;
	intStack_1.dump();

	cout << "Stack 2" << endl;
	intStack2.dump();

	cout << "End of Tests" << endl;
	cout << "Run Valgrind to Test the Destructor" << endl;
	return 0;
}
