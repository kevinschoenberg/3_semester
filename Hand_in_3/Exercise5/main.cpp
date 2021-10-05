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

	//Searching for specific values
	//bool out1 = matsearch(sorted, 1);
	//bool out2 = matsearch(sorted, 10);

	//Searching for all values on the interval
	bool out;
	for (int i = 0; i < MAX; i++)
	{
		out = matsearch(sorted, i);
	}


	delete &sorted;
}