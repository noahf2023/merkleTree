#pragma once
#ifndef MERKLE
#define MERKLE

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include "node.h"

using namespace std;

class Merkle {
public:
	Merkle(int);
	Merkle(vector<node*>, int);
	void printRootHash();
	vector<node*> openFileHash(vector<node*>);
	void clear();
	~Merkle();
	void operator= (const Merkle&);
	void remove(node*);
	void printTree(node* n);
	vector<node*> parentNodes(vector<node*>, vector<node*>);
	node* root;
	int id;

	/*
		Cout overloaded operator that prints out object fields, such as the root's key, and the root's hash.
		The root key will tell you whose Merkle tree this belongs to
		The root's hash will tell you the hash of the overall file
	*/
	friend ostream& operator << (ostream& out, Merkle& m) {
		out << "Root key: " << m.root->key << endl;
		out << "Hash: " << m.root->hash << endl;
		return out;
	}
};

#endif