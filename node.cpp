#include "node.h"
#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

/*
    Node constructor without hash or key
*/
node::node() {
    left = nullptr;
    right = nullptr;
}

/*
    Second node constructor with only a key
*/
node::node(int key) {
    this->key = key;
    left = new node;
    right = new node;
}

/*
    Third node constructor that takes a hash and a key, then creates a node that will be used for the Merkle Tree
*/
node::node(string hash, int key){
    this->hash = singleHash(hash);
    this->key = key;
}

/*
    Fourth node constructor made just for the parent nodes, since they need to be added then hashed
*/
node::node(string left, string right) {
    unsigned int h = doubleHashing(left, right);
    this->hash = h;
}

/*
    A method that returns a hash of type unsigned int
    This method takes in two strings that are added. Then the strings are made into a hash
*/
unsigned int node::doubleHashing(string leftHash, string rightHash) {
    unsigned int finalHashing;
    string a;
    string b;
    string c;
    a = leftHash;
    b = rightHash;
    c = a + b;
    finalHashing = std::hash<std::string>()(c);
    return finalHashing;
}

/*
    Similar to the doubleHashing method, but this method takes in a single string and hashes it
*/
unsigned int node::singleHash(string hash) {
    unsigned int newHash = std::hash<std::string>()(hash);
    return newHash;
}