#include "Merkle.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<cstdlib>
#include "node.h"

using namespace std;

/*
    Constructor that creates a Merkle tree without a vector of hashes
*/
Merkle::Merkle(int id) {
    root = nullptr;
    this->id = id;
    root = new node(id);
    this->root->key = id;
    this->root->hash = "No hash yet";
}

/*
    Second constructor that handles the Merkle Tree construction(with a vector of hashes)
    This method is what will mainly be used to create the Merkle Tree. 
*/
Merkle::Merkle(vector<node*> hashVector, int idNumber) {

    //Creates the vector of hashes
    hashVector = openFileHash(hashVector);

    //Checks if the hashVector's size is appropriate
    if (hashVector.size() <= 1) {
        cout << "Size of vector needs to be more than one. " << endl;
        cout << "Terminating program." << endl;
        exit(1);
    }

    //Prepares for the parent nodes to be created, and hashed
    vector<node*> parents;
    hashVector = parentNodes(hashVector, parents);

    //Links the parent nodes to the root node, completing the creation of the Merkle Tree
    this->root = hashVector.at(0);
    this->root->key = idNumber;
    this->id = idNumber;
}

/*
    Prints the root's hash
*/
void Merkle::printRootHash() {
    cout << root->hash << endl;
}

/*
    This method collects data from a file and inserts the data's hashes into a vector of nodes
    This method returns a vector of hashNodes taken straight from the data in the file, which has been hashed
*/
vector<node*> Merkle::openFileHash(vector<node*> hashVector) {

    //Code that opens a file, which will then be hashed using the node's constructor
    ifstream infile;
    infile.open("hashFile.txt", ios_base::in);

    if (infile.fail()) {
        cout << "The file was not opened" << endl;
        exit(1);
    }

    string file;

    while (getline(infile, file)) {
        hashVector.push_back(new node(file, id));
    }

    infile.close();
    return hashVector;
}

/*
    Clears the Merkle Tree
    Calls the remove function, which is recursive, and then removes all the nodes in the root
*/
void Merkle::clear() {
    remove(root);
}

/*
    Assignment operator function used for setting two objects equal
    The root's hash, id, and key are what will be set equal to the other object
*/
void Merkle::operator=(const Merkle& m) {
    root->hash = m.root->hash;
    id = m.id;
    root->key = m.root->key;
}

/*
    Merkle Tree destructor
    Calls the clear function, which will clear/delete all the nodes in the Merkle Tree
*/
Merkle::~Merkle() {
    clear();
    cout << "Merkle Tree #" << id << " has been deleted" << endl;
}

/*
    Removes all the nodes in a Merkle Tree
    This recusrive function will go through the Merkle Tree, set each node to null, then delete them
*/
void Merkle::remove(node* f) {
    if(f != NULL){
        remove(f->left);
        remove(f->right);
        f = NULL;
        delete f;
    }
}

/*
    Prints all the hashes in a Merkle tree
    This function is recursive, and it will go through the entire Merkle Tree, printing out each node's hash
*/
void Merkle::printTree(node* f){
    if (f != NULL){
        printTree(f->left);
        cout << f->hash << endl;
        printTree(f->right);
    }
}

/*
    Creates a vector of parent nodes that are the parents of the children nodes created in openFileHash. 
    This method is important, since it builds upon the previously created hashVector, and this vector will link to the Merkle Tree's root node
    This method returns the newly created vector of parent nodes
*/
vector<node*> Merkle::parentNodes(vector<node*> hashVector, vector<node*> parents) {

    //Initializing variables for later for-loop
    unsigned int i = 0;
    unsigned int j = 0;

    while (hashVector.size() != 1) {

        //For loop that deals with the creation of the parent nodes vector
        for (i = 0, j = 0; i < hashVector.size(); i+=2, j++) {
            if (i != hashVector.size() - 1) {
                //Creates the parent node based on the left and right child nodes' hashes
                parents.push_back(new node(hashVector.at(i)->hash, hashVector.at(i + 1)->hash));
                
                //The left and the right children nodes are created. They point to their parent node
                parents.at(j)->left = hashVector.at(j);
                parents.at(j)->right = hashVector.at(static_cast<std::vector<node*, std::allocator<node*>>::size_type>(i) + 1);
            }else {
                parents.push_back(hashVector.at(i));
            }
        }

        //Sets the passed vector equal to the parent node vector. Then the parent node vector is cleared since it isn't needed anymore
        hashVector = parents;
        parents.clear();
    }

    //Return the final parent node vector
    return hashVector;
}