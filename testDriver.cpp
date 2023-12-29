#include "person.h"
#include "person1.h"
#include "Merkle.h"
#include "node.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>

using namespace std;

int main(){

    
    //Creating the first person
    person1 firstPerson("Dante", "Alighieri", 1320);
    person* first = &firstPerson;

    //Creating the second person
    person1 secondPerson("Second", "Person", 1953);
    person* second = &secondPerson;

    //Using the setters to change the name of secondPerson
    secondPerson.setFirstName("Ray");
    secondPerson.setLastName("Bradbury");

    //Using the getter method to get the ids of both persons
    int idNum = firstPerson.getID();
    int idNum2 = secondPerson.getID();

    //Creating the third person
    person1 thirdPerson("Third", "Person", 2011);
    person* third = &thirdPerson;

    //Setting the first name, last name, and ID of the third person
    thirdPerson.setFirstName("William");
    thirdPerson.setLastName("Golding");
    thirdPerson.setID(1954);

    //Testing the getter methods
    thirdPerson.getFirstName();
    thirdPerson.getLastName();
    int idNum3 = thirdPerson.getID();

    //First person's details are printed
    first->print();
    cout << endl;

    //Second person's details are printed
    second->print();
    cout << endl;

    //Third person's details are printed
    third->print();
    cout << endl;

    //Testing the assignment operator
    firstPerson = secondPerson;
    first = second;

    //Printing the firstPerson's info after the assignment operator test
    first->print();
    cout << endl;

    //Creation of vector nodes that will be passed into Merkle constructor 
    vector<node*> hashVec;
    vector<node*> hashVec2;

    //Merkle trees are created
    Merkle merkleTree(hashVec, idNum);
    
    //This Merkle tree uses different constructor(Before assignment)
    Merkle merkleTree2(idNum2);

    //Prints the Merkle tree's root hash(main importance)
    cout << "Merkle Tree 2(before assignment): " << endl;
    cout << merkleTree2 << endl;

    //Merkle tree 3 is created
    Merkle merkleTree3(hashVec2, idNum3);

    //Merkletree2 is set equal to Merkletree using the assignment operator 
    merkleTree2 = merkleTree;

    //Testing the clear function
    merkleTree.clear();

    //Testing the remove function
    merkleTree3.remove(merkleTree3.root);

    //Printing all the Merkle trees; Merkle tree 2 prints again, but it's after the assignment(previous line)
    cout << "Merkle Tree 1 " << endl << merkleTree << endl;
    cout << "Merkle Tree 2(After assignment) " << endl << merkleTree2 << endl;
    cout << "Merkle Tree 3 " << endl << merkleTree3 << endl;

    //Testing the printRootHash method/Prints the root's hash
    cout << "Merkle Tree 2's root hash: ";
    merkleTree2.printRootHash();
    cout << endl;

    return 0;
}