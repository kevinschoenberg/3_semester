#include <iostream>
#include <stdexcept>
#include "matrix_class.h"
#include "stdlib.h"
using namespace std;

#define ROWS		15
#define COLS		10
#define MAX 		100

int main(void) {
	Matrix<int> mat(ROWS, COLS), id(COLS, COLS);
	srand(time(0));

	for (int i = 0; i < COLS; i++) id[i][i] = 1; // intialize id

	for (int i = 0; i < ROWS; i++) {             // randomize mat
		for (int j = 0; j < COLS; j++) {
			mat[i][j] = rand() % MAX;
		}
	}

	cout << "mat=" << endl << mat << endl;
	Matrix<int>& sorted = matsort(mat);
	cout << "sorted=" << endl << sorted << endl;

	bool out1 = matsearch(sorted, 1);
	bool out2 = matsearch(sorted, 10);
	bool out3 = matsearch(sorted, 50);
	bool out4 = matsearch(sorted, 75);
	bool out5 = matsearch(sorted, 90);


	delete &sorted;
}