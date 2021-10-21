#ifndef _DISJ_SETS_H_
#define _DISJ_SETS_H_

// DisjSets class
//
// CONSTRUCTION: with int representing initial number of sets
//
// ******************PUBLIC OPERATIONS*********************
// void union( root1, root2 ) --> Merge two sets
// int find( x )              --> Return set containing x
// ******************ERRORS********************************
// No error checking is performed

#include <vector>

using namespace std;

/**
 * Disjoint set class.
 * Use union by rank and path compression.
 * Elements in the set are numbered starting at 0.
 */
class DisjSets
{
public:
	DisjSets(int numElements);
	DisjSets();

	int find(int x) const;
	int find(int x);
	int new_find(int x);
	void unionSets(int root1, int root2);
	void print_s(int numElements);
	void printx(int x, size_t numElements);

private:
	vector<int> s;
};

class Maze
{
public:
	Maze();
	Maze(int rows, int cols);
private:
	vector<int> s;
	void generate(int rows, int cols);
}

#include "disjoint_sets.cpp"

#endif
