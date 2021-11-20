#include <iostream>
#include "binary_search_tree.h"
using namespace std;

	// Test program
int main() {
	BinarySearchTree<int> t;

	t.insert(10);
	t.insert(11);
	t.insert(7);
	t.insert(8);
	t.insert(4);
	t.insert(12);
	t.insert(15);

	t.printTree();

	return 0;
}
