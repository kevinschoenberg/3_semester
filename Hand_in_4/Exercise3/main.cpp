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

    Maze mz(5, 5);

    std::cout << "print" << endl;
    mz.print_s(5, 5);


    for(int i = 0; i < 25; i++)
    {
        cout << i << " ";
        int c = i % 5;
		int r = floor(i / 5);
		if (c == 5 - 1)
		{
			cout << endl;
		}
	}
	cout << endl;

    mz.printx(24, 25);

    return 0;
}