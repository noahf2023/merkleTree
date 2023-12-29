#pragma once
#ifndef PERSON
#define PERSON

#include <iostream>
#include <string>
using namespace std;

class person {
public:

	person(string, string);

	void setFirstName(string);
	void setLastName(string);
	string getFirstName();
	string getLastName();

	/*
		Virtual function for printing a person's info
	*/
	virtual void print() {
		cout << "First name: " << firstName << endl;
		cout << "Last name: " << lastName << endl;
	}

	/*
		Assignment operator for person object
	*/
	void operator=(const person& p) {
		firstName = p.firstName;
		lastName = p.lastName;
	}

	/*
		Cout overloaded operator function that prints out a person's info
		Different way of printing out person's info
	*/
	friend ostream& operator << (ostream& out, person& p) {
		out << "First name: " << p.firstName << endl;
		out << "Last name: " << p.lastName << endl;
		return out;
	}

private: 
	string firstName;
	string lastName;
};

#endif