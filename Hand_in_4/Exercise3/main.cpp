/*
(2) Modify the DisjSets data structure to implement an operation print(x), which
is given a node x and prints all the members in the same set, in any order. Show
how we can add just a single attribute to each node in a disjoint-set forest so that
printing takes time linear in the number of members of the set to which x belongs,
and the asymptotic running times of the other operations are unchanged. Assume
that printing each member of the set in constant time. Do not forget to write testing
code to verify your modification works as expected.
*/

#include <iostream>
#include "disjoint_sets.h"

int main() 
{

    int size = 10;
    DisjSets ds{size};
    ds.unionSets(2, 4);
    ds.unionSets(4, 5);
    ds.unionSets(5, 6);
    ds.unionSets(6, 7);
    ds.unionSets(0, 1);
    ds.unionSets(3, 0);
    ds.print_s(size);
    
    ds.printx(1, size);
    ds.printx(4, size);
    ds.printx(9, size);
    return 0;
}