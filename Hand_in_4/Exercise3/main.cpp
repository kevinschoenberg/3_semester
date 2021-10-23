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

const int rows = 5;
const int cols = 5;

int main()
{


    Maze mz(rows, cols);

    std::cout << "print" << endl;
    mz.print_maze(rows, cols);

    mz.print_s2(rows, cols);

    //mz.printx(rows * cols - 1, rows * cols);
    mz.print_solution(rows, cols);


    return 0;
}