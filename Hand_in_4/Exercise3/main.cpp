#include <iostream>
#include "disjoint_sets.h"

using namespace std;

void maze_single()
{

}

void maze_rand(int num_rows, int num_cells)
{

}

void rand_maze {
  // begin with a rectangular maze of all closed cells
  // numrows = number of rows of cells;
  // numcols = number of columns of cells;
  start = cell at (0,0);
  goal  = cell at (numrows-1, numcols-1);
  numcells = numrows * numcols;
  Partition p(numcells); // p represents the maze components

  // goal is not reachable from start
  while (!p.Find(start, goal)) {
    edge = randomly select a wall;
    x = edge.x;
    y = edge.y;
    if(!p.Find(x,y)) {
      remove edge;
      // x and y now in same component
      p.Union(x,y);
    }
  }
}


int main()
{



}