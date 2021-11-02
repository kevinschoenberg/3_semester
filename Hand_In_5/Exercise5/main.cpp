#include <iostream>
#include <sstream>
#include <string>

#include "binary_heap.h"
using namespace std;

// Test program
int main() {
	int minItem = 10;	// same number of digits
	int maxItem = 50;
	BinaryHeap<int> h;
	int x;

	/* Insert all integers i between min and max out of order. */
	for (int i = 23; i != 0; i = (i + 23) % maxItem) {
		if (i >= minItem) {
			h.insert(i);
		}
	}

    //h.buildHeap();
    h.print();

	for (int i = minItem; i < maxItem; ++i) {
		h.deleteMax(x);
		if (x != i) {
			cout << "Oops! " << i << endl;
		}
	}

    h.print();

	cout << "If nothing was printed before, no error!" << endl;

	return 0;
}
