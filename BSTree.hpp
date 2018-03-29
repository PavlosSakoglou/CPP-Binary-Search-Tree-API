/*
*	© Superharmonic Technologies
*	Pavlos Sakoglou
*
*  =================================================
*
*	Standard Binary Search Tree API Definition
*
*/

#ifndef BSTREE_HPP
#define BSTREE_HPP

#include <iostream>

// Binary Tree Node
template <class Type>
struct BTreeNode {
	BTreeNode * left;
	BTreeNode * right;
	Type data;
	BTreeNode(Type d = 0) : data(d), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
template <class Type>
class BSTree {
public:
	BSTree();
	~BSTree();

	// Insert method
	void insert(Type key);

	// Delete tree
	void clear();

	// Search method
	bool find(Type key);

	// Get method
	BTreeNode<Type> * get(Type key);

	// Traverse in order
	void traverse();

private:

	// Private recursive methods
	BTreeNode<Type> * get(Type key, BTreeNode<Type> * r);
	void insert(Type key, BTreeNode<Type> * r);
	bool find(Type key, BTreeNode<Type> * r);
	void traverse(BTreeNode<Type> * r);
	void clear(BTreeNode<Type> * r);

	BTreeNode<Type> * root;
};

#ifndef BSTREE_CPP
#include "BSTree.cpp"
#endif

#endif //!BSTREE_HPP
