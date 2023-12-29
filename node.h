#pragma once
#ifndef NODE
#define NODE

#include<iostream>
using namespace std;

class node {
public:
	string hash;
	int key;
	node* left;
	node* right;
	node();
	node(int);
	node(string, int);
	node(string, string);
	unsigned int doubleHashing(string, string);
	unsigned int singleHash(string);
};

#endif