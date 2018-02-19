/*
*	© Superharmonic Technologies
*	Pavlos Sakoglou
*
*  =================================================
*
*	Standard Binary Search Tree API Test file
*
*/

#include <iostream>
#include "BSTree.hpp"

int main() {

	BSTree<int> bstree;

	bstree.insert(10);
	bstree.insert(14);
	bstree.insert(6);
	bstree.insert(16);
	bstree.insert(12);
	bstree.insert(8);
	bstree.insert(4);

	std::cout << std::boolalpha << bstree.find(101) << " " << bstree.find(6) << " " << bstree.find(41) << "\n";
	
	if (bstree.find(6)) {
		std::cout << "Element found: " << bstree.get(6)->data << "\n";
	}

	bstree.traverse();

	bstree.clear();

	return 0; 
}
