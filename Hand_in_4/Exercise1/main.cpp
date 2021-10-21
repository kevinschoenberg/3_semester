#include <iostream>
#include "disjoint_sets.h"

using namespace std;

// Test main; all finds on same output line should be identical
int main()
{
    DisjSets ds{10};

    ds.print_s();

    cout << endl;

    for (int i = 0; i < 10; i++)
    {
        cout << ds.new_find(i) << " ";
    }
    cout << endl;

    ds.print_s();

    return 0;
}
