#include "person.h"
#include <iostream>
#include <string>
using namespace std;

/*
	Constructor responsible for creating a person object. 
	Takes in the person's first and last name
*/
person::person(string firstName, string lastName) {
	this->firstName = firstName;
	this->lastName = lastName;
}

/*
	Setter for the first name. Sets the passed first name into the firstName field.
*/
void person::setFirstName(string first) {
	firstName = first;
}

/*
	Setter for the last name. Sets the parameter's last name equal to the lastName field.
*/
void person::setLastName(string last) {
	lastName = last;
}

/*
	Getter for the firstName field.
	Returns a string.
*/
string person::getFirstName() {
	return firstName;
}

/*
	Getter for the lastName field.
	Returns a string.
*/
string person::getLastName() {
	return lastName;
}