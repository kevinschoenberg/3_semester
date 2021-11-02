#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "binary_heap.h"
using namespace std;

// Test program
int main() {
	int minItem = 40;	// same number of digits
	int maxItem = 50;
    vector<int> input;// = {40, 41, 42, 43, 44, 45, 46, 47, 48, 49};

	//BinaryHeap<int> h;
	int x;

	/* Insert all integers i between min and max out of order. */
	for (int i = minItem; i < maxItem; i++) {
		input.push_back(i);
	}

    for (int i = 0; i < input.size(); i++)
    {
        cout << input[i] << " ";
        //h.insert(input[i]);
    }
    
    cout << endl;

    BinaryHeap<int> h(input);

    //h.buildHeap();
    h.print();

	for (int i = maxItem-1; i >= minItem; --i) {
		h.deleteMax(x);
		if (x != i) {
			cout << "Oops! " << i << endl;
		}
	}

    //h.print();

	cout << "If nothing was printed before, no error!" << endl;

	return 0;
}
