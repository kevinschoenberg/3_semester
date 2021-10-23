/*
(3) An application of the disjoint sets data structure is the generation of random mazes,
such as the picture below. The starting point of the maze is the top-left corner, and
the maze is solvable if there is a path to reach the ending point in the bottom-right
corner. Cells are separated from their neighboring cells via walls.
A simple maze generation algorithm is to start with all possible walls in place, and
then progressively take down random walls to join paths until the starting and ending
cells are connected. It is actually better to continue knocking down walls until every
cell is reachable from every other cell (this generates more false leads in the maze).
Implement a Maze class with the following member functions:
(a) A zero-argument constructor that generates a trivial 1-by-1 maze.
(b) A private generate(int rows, int cols) function that generates a random maze of the
prescribed dimensions; and a non-trivial constructor that
receives the dimensions and calls the generation function.
(c) A print() function that prints the generated maze in the terminal.
(d) A solve() function that solves the generated maze and prints the path in the
terminal.
State the complexity of generating and solving the maze in terms of its dimensions.
*/

#include <iostream>
#include "disjoint_sets.h"

const int rows = 10;
const int cols = 20;

int main()
{
    //Construct maze.
    Maze mz(rows, cols);

    //Prints maze
    mz.print_maze(rows, cols);

    //Prints the solution:
    mz.print_solution(rows, cols);

    return 0;
}