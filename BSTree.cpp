/*
*	© Superharmonic Technologies
*	Pavlos Sakoglou
*
*  =======================================================
*
*	Standard Binary Search Tree API Implementation
*
*/

#ifndef BSTREE_CPP
#define BSTREE_CPP

#include "BSTree.hpp"

template <class Type>
BSTree<Type>::BSTree() : root(nullptr) {}

template <class Type>
BSTree<Type>::~BSTree() {
	clear(root);
	std::cout << "Tree Destroyed!\n";
}

// Insert method
template <class Type>
void BSTree<Type>::insert(Type key) {
	if (root == nullptr) {
		root = new BTreeNode<Type>(key);
		return;
	}
	insert(key, root);	
}

// Remove methods

template <class Type>
void BSTree<Type>::clear() {
	clear(root);	
	root = nullptr;
}

// Search method
template <class Type>
bool BSTree<Type>::find(Type key) {
	if (root == nullptr) return false;
	else return find(key, root);
}

// Get method
template <class Type>
BTreeNode<Type> * BSTree<Type>::get(Type key) {
	if (root == nullptr) return root;
	else return get(key, root);
}

// Traverse in order
template <class Type>
void BSTree<Type>::traverse() {
	traverse(root);
	std::cout << "\n";
}

// Private methods

// Insert
template <class Type>
void BSTree<Type>::insert(Type key, BTreeNode<Type> * r) {
	if (key <= r->data) {
		if (r->left == nullptr)
			r->left = new BTreeNode<Type>(key);
		else
			insert(key, r->left);
	}
	else {
		if (r->right == nullptr)
			r->right = new BTreeNode<Type>(key);
		else
			insert(key, r->right);
	}
}

// Traverse
template <class Type>
void BSTree<Type>::traverse(BTreeNode<Type> * r) {
	if (r == nullptr) return;

	traverse(r->left);

	std::cout << r->data << " ";

	traverse(r->right);
}

// Clear
template <class Type>
void BSTree<Type>::clear(BTreeNode<Type> * r) {
	if (r != nullptr) {
		clear(r->left);
		clear(r->right);
		delete r;
		r = nullptr;
	}
}

// Find
template <class Type>
bool BSTree<Type>::find(Type key, BTreeNode<Type> * r) {
	if (r != nullptr) {

		if (r->data == key)
			return true;

		if (r->data > key)
			return find(key, r->left);

		if (r->data < key)
			return find(key, r->right);
	}
	
	return false;
}

template <class Type>
BTreeNode<Type> * BSTree<Type>::get(Type key, BTreeNode<Type> * r) {
	if (r != nullptr) {

		if (r->data == key)
			return r;

		if (r->data > key)
			return get(key, r->left);

		if (r->data < key) 
			return get(key, r->right);
	}
}

#endif //!BSTREE_CPP
