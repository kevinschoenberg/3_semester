#include <iostream>
#include <stdexcept>
#include "matrix_class.h"
#include "stdlib.h"
using namespace std;

//Define size of matrix
#define ROWS	10
#define COLS	5
#define MAX		100

int main(void) {
	//Create matrix with random values
	Matrix<double> mat(ROWS, COLS), id(COLS, COLS);
	srand(time(0));

	for (int i = 0; i < COLS; i++) id[i][i] = 1; // intialize id

	for (int i = 0; i < ROWS; i++) {             // randomize mat
		for (int j = 0; j < COLS; j++) {
			mat[i][j] = ((double) rand() / (RAND_MAX)) * MAX;
		}
	}
	//print matrix before transpose
	cout << "mat=" << endl << mat << endl;
	//test the transpose function
	mat.transpose();
	//print transposed matrix
	cout << "trans=" << endl << mat << endl;

}
