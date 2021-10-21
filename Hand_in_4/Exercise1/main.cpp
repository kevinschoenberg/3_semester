#include <iostream>
#include "disjoint_sets.h"

using namespace std;
/*
(1) Write a non-recursive version of find with path compression and analyze 
 its worstcase time complexity
*/
// Test main; all finds on same output line should be identical
int main()
{
    int index;
    int size = 10;
    DisjSets ds{size};
    ds.unionSets(2, 4);
    ds.unionSets(4, 5);
    ds.unionSets(5, 6);
    ds.unionSets(6, 7);
    ds.unionSets(0, 1);
    ds.unionSets(3, 0);

    cout << "The original Disjoint set is:" << endl;
    ds.print_s(size);
    
    index = 1;
    cout << "The root of " << index << " is: " << ds.new_find(index) << endl;
    cout << "The disjoint set after path compression.:" << endl;
    ds.print_s(size);
    
    index = 5;
    cout << "The root of " << index << " is: " << ds.new_find(index) << endl;
    cout << "The disjoint set after path compression.:" << endl;
    ds.print_s(size);

    index = 7;
    cout << "The root of " << index << " is: " << ds.new_find(index) << endl;
    cout << "The disjoint set after path compression.:" << endl;
    ds.print_s(size);
    return 0;
}