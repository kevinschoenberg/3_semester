#include "disjoint_sets.h"

/**
 * Construct the disjoint sets object.
 * numElements is the initial number of disjoint sets.
 */
DisjSets::DisjSets(int numElements):s(numElements, -1) {
	s = {3, 0, -1, -1, 2, 4, 5, 6, -1, -1};
}

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


int DisjSets::new_find(int x)
{
	int root = x;
	if(s[x] < 0)
	{
		return s[x];
	}

	while(s[root] != -1)
	{
		root = s[root];
	}
	s[x] = root;

	return root;
}
void DisjSets::print_s()
{
	for (int i = 0; i < 10; i++)
    {
        cout << s[i] << " ";
    }
}
