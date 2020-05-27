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
	Stack<int> intStack_1, intStack2;

	for (auto i = 1; i <= 10; i++) {
		intStack_1.push(i);
	}
	
	// Test 1: Tests if the copy constructor works  
	cout << "Push integers on LL1 completed\n";
	cout << "*****Test 1*****" << endl;

	cout << "Copy Constructor" << endl;
	intStack2 = Stack<int>(intStack_1);

	cout << "*****Original Stack*****" << endl;
	intStack_1.dump();

	cout << "*****Copy Stack*****" << endl;
	intStack2.dump();
	
	// Test 2: Tests if the copy constructor is a deep copy 
	cout << "*****Test 2*****" << endl;
	cout << "Deep Copy Test" << endl;
	intStack_1.pop();

	cout << "Removed \"10\" From Original Stack" << endl;
	cout << "*****Original Stack*****" << endl;
	intStack_1.dump();

	cout << "*****Copy Stack*****" << endl;
	intStack2.dump();

	// Test 3: Tests assignment operator
	// and edge cases
	cout << "*****Test 3*****" << endl;
	cout << "Empty LL & Assignment Operator test" << endl;

	cout << "Removing all nodes from LL1" << endl;
	while (not intStack_1.empty()) {
		intStack_1.pop();
	}

	intStack2 = intStack_1;

	cout << "LL2 is now equal to empty LL1" << endl << endl; 
	cout << "Displaying both LL2 & LL1" << endl;

	cout << "LL2 (should be empty)" << endl;
	intStack2.dump(); 
	cout << "LL1 (should be empty)" << endl;
	intStack_1.dump();
	
	// Test 4: Tests if the assignment operator
	// performed a deep copy 
	cout << "*****Test 4*****" << endl;
	cout << "Deep Copy Test Filling up LL2" << endl;
	for (auto i = 1; i <= 10; i++) {
		intStack2.push(i);
	}

	cout << "LL2" << endl;
	intStack2.dump();
	cout << "LL1 (should be empty)" << endl;
	intStack_1.dump();

	// Test 5: Tests if the assignment operator
	// guarded against self-assignment 
	cout << "*****Test 5*****" << endl;
	cout << "Self Assignment Test" << endl;

	cout << "Testing LL2" << endl;
	intStack2 = intStack2;
	cout << "LL2" << endl;
	intStack2.dump();

	cout << "Testing LL1" << endl;
	intStack_1 = intStack_1;
	cout << "LL1 (should be empty)" << endl;
	intStack_1.dump();

	cout << "End of Tests" << endl; 
	cout << "Run Valgrind to Test the Destructor" << endl;
	return 0;
}
