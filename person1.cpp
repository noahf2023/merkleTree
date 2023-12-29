#include "person.h"
#include "person1.h"
#include <iostream>
#include <string>
using namespace std;

/*
	Constructor for creating a person1 object.
	Takes in first name and last name(inherited from base class/person), and takes an ID
*/
person1::person1(string first, string last, int id):person(first, last){
	this->idNumber = id;
}

/*
	Setter for the ID field. Takes in an int ID and sets it equal to the field idNumber
*/
void person1::setID(int idNumber) {
	this->idNumber = idNumber;
}

/*
	Getter for the ID field. Returns an integer.
*/
int person1::getID() {
	return idNumber;
}
