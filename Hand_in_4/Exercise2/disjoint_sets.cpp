#include "disjoint_sets.h"

/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 */
DisjSets::DisjSets(int numElements):s(numElements, -1) {}

/**
 * Union two disjoint sets.
 * For simplicity, we assume root1 and root2 are distinct
 * and represent set names.
 * root1 is the root of set 1.
 * root2 is the root of set 2.
 */
void DisjSets::unionSets(int root1, int root2) {
	s[root2] = root1;
}

/**
 * Perform a find.
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find(int x) const {
	if (s[x] < 0)
		return x;
	else
		return find(s[x]);
}

/**
 * Perform a find, same as above..
 * Error checks omitted again for simplicity.
 * Return the set containing x.
 */
int DisjSets::find(int x) {
	if (s[x] < 0)
		return x;
	else
		return find(s[x]);
}

/**
 * Performs a no recursive find with buildin
 * path compression.
 **/
int DisjSets::new_find(int x)
{
	int root = x;

	if(s[x] < 0)
	{
		return s[x]; //O(1)
	}

	while(s[root] >= 0)
	{
		root = s[root]; //O(n)
	}
	int prev;
	int step = x;

	//Path compresion part.
	while(s[step] >= 0)
	{
		prev = step;
		step = s[step]; //O(n)
		unionSets(root,prev);
	}

	return root;
}

/*
Prints a given disjointed set.
*/
void DisjSets::print_s(int numElements)
{
	for (int i = 0; i < numElements; i++)
    {
        cout << s[i] << " ";
    }
	cout << endl;
}

/**
 * Locates all the sets with the same root as the given x.
 * And prints them all.
 * */
void DisjSets::printx(int x, size_t numElements)
{
	//Sets target root
	int target = find(x);
	cout << "printing all elements with the root: " << target << endl;
	//Locates all with same root.
	for (size_t i = 0; i < numElements; i++)
	{
		if (find(i)==target)
		{
			cout << i << " ";
		}
	}
	cout << endl;
}