#include <iostream>
#include "hash_table_chaining.h"
using namespace std;

	// Simple main
int main() {
	HashTable<int> h1;
	
	h1.insert(3);
	h1.insert(5);
	h1.insert(7);
	h1.insert(25);
	h1.insert(1);
	h1.insert(20);
	h1.insert(14);
	h1.insert(10);
	

	cout << "Max is: " << h1.findMax() << endl;


	

	return 0;
}
