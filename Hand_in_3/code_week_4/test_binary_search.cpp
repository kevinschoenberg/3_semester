#include <iostream>
#include <vector>
#include <algorithm>

#include "binary_search.h"

using namespace std;

#define N		100
#define MAX 	1000

int main(void) {
        int i, j;
        vector<int> v;
        vector<int>::iterator itr;

		srand(time(0));
        for (i = 0; i < N; i++) {
                v.push_back(rand() % MAX);
        }
        std::sort(v.begin(), v.end());

        /* Now let us print the vector through iterator */
        for(itr = v.begin(); itr != v.end(); itr++) {
            cout << *itr << " ";
        }
        cout << endl;

		j = rand() % MAX;

		/* Now search using binary search. */
        itr = binarySearch(v.begin(), v.end(), j);
        if (itr != v.end()) {
            cout << "Found element: " << *itr << endl;
        } else {
			cout << "Element not found: " << j << endl;
		}

		return 0;
}
