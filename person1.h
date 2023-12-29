#pragma once

#ifndef PERSON1
#define PERSON1

#include <iostream>
#include <string>
using namespace std;

class person1: public person{
public:

	person1(string first, string last, int id);

	void setID(int);
	int getID();

	/*
		Print virtual function/overriding the other print function in person
		Prints out a person's info
	*/
	void print() {
		cout << "Person #" << idNumber << endl;
		cout << "First name: " << getFirstName() << endl;
		cout << "Last name: " << getLastName() << endl;
	}

	/*
		Assignment operator for person1
	*/
	void operator=(const person1& p) {
		idNumber = p.idNumber;
	}

	/*
		Cout overloaded operator for person1.
		Different way of pritning out person1's info
	*/
	friend ostream& operator << (ostream& out, person1& p) {
		out << "Person #" << p.idNumber << ": " << endl;
		out << "First Name: " << p.getFirstName() << endl;
		out << "Last Name: " << p.getLastName() << endl;
		return out;
	}

private:
	int idNumber;
};

#endif